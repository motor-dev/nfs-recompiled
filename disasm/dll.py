import os
from .module import Module


class DLL(Module):
    def __init__(self, application_name, exe_path, rebase_after):
        Module.__init__(self, application_name, exe_path, rebase_after)

    def write(self, owner_name, thread_segments = [], function_names={}):
        try:
            os.makedirs('src/%s/disassembly/' % (owner_name))
        except OSError:
            pass
        with open('src/%s/disassembly/%s.cpp' % (owner_name, self.application_name), 'w') as src:
            with open('src/%s/disassembly/%s.h' % (owner_name, self.application_name), 'w') as h:
                app_name = self.application_name
                APP_NAME = self.application_name.upper()

                src.write('#include "%s.h"\n'
                          '#include <x86.h>\n'
                          '#include <winapi/wrapper.h>\n'
                          '\nnamespace %s\n'
                          '{\n\n' % (app_name, app_name))
                h.write('#ifndef %s_H_\n'
                        '#define %s_H_\n'
                        '#include <x86.h>\n'
                        '#include <lib/winapp.h>\n'
                        '#include <lib/library.h>\n'
                        '\nnamespace %s\n'
                        '{\n\n'  % (APP_NAME, APP_NAME, app_name))
                for data, address, length, name, ro, code in self.sections:
                    if data:
                        self._dump_raw_section(owner_name, name, data, length)
                        h.write('extern const x86::reg8 s_%sSegment[];\n' % name.decode())
                for index in range(0, 1+int(len(self.subroutines)/100)):
                    methods = open('src/%s/disassembly/%s.%d.cpp' % (owner_name, app_name, index), 'w')
                    methods.write('#include "%s.h"\n'
                                  '#include <lib/thread.h>\n\n'
                                  'namespace %s\n'
                                  '{\n\n' % (app_name, app_name))

                    for subroutine in self.subroutines[100*index:100*(index+1)]:
                        function_start = subroutine.get_start_address()
                        function_end = subroutine.get_end_address()
                        function_entry = subroutine.get_entry_point()
                        fallthrough = False
                        methods.write('/* align: skip %s */\n' % (' '.join(['0x%02x'%c for c in subroutine.skipped_blob])))
                        if subroutine.data_blob:
                            methods.write('/* data blob: %s */\n' % (''.join(['%02x'%c for c in subroutine.data_blob])))
                        for jump_entry in subroutine.jump_table:
                            methods.write('/* jump table: 0x%08x */\n' % jump_entry)
                        h.write('void sub_%x(win32::WinApplication* app, x86::CPU& cpu);\n' % function_entry)
                        methods.write('void sub_%x(win32::WinApplication* app, x86::CPU& cpu)\n'
                                      '{\n'
                                      '  NFS2_USE(cpu);\n'
                                      '  NFS2_USE(app);\n' % function_entry)
                        if subroutine.thread_unsafe:
                            methods.write('  win32::LockContext lock(*app);\n')
                        if subroutine.dynamic_labels:
                            methods.write('  goto start;\n'
                                            'dynamic_jump:\n'
                                            '  switch(cpu.ip)\n'
                                            '  {\n'
                                            'start:\n')
                        if function_entry != function_start:
                            methods.write('    goto L_entry_0x%08x;\n' % function_entry)
                        for instruction in subroutine.instructions:
                            if instruction.address in [x for _, x in subroutine.dynamic_labels]:
                                if fallthrough:
                                    methods.write('  [[fallthrough]];\n')
                                methods.write('  case 0x%08x:\n' % (instruction.address))
                            if instruction.address in [x for _, x in subroutine.static_labels]:
                                methods.write('L_0x%08x:\n' % (instruction.address))
                            if function_entry != function_start and instruction.address == function_entry:
                                methods.write('L_entry_0x%08x:\n' % (instruction.address))
                            if instruction.address in thread_segments:
                                methods.write('    app->unlockContext(cpu);\n'
                                              '    win32::Thread::sleep(0);\n'
                                              '    app->lockContext(cpu);\n')
                            methods.write('    // %s\n'
                                            '    %s\n'  % (self._raw(subroutine.section, instruction),
                                                            '\n    '.join(self.generate(instruction, (function_start, function_end), function_names))))
                            fallthrough = instruction.mnemonic not in ['jmp', 'ret']
                        if subroutine.dynamic_labels:
                            methods.write('  default:\n'
                                          '    NFS2_ASSERT(false);\n'
                                          '  }\n')
                        methods.write('}\n\n')
                    methods.write('}\n')
                h.write('\nextern win32::Library* s_registry;\n'
                        '\n'
                        '}\n\n'
                        '#endif /* !%s_H_ */\n' % (APP_NAME))
                src.write('win32::Library s_library = win32::Library("%s.dll");\n'
                          'win32::Library* s_registry = &(s_library\n' % app_name)
                for address, name in self.exported_symbols:
                    src.write('        .registerSymbol("%s", &sub_%x)\n' % (name.decode(), address))
                src.write('\n    );\n}\n')

    def _dump_raw_section(self, owner, name, section, length):
        name = name.decode()
        with open('src/%s/disassembly/%s.%s.cpp' % (owner, self.application_name, name), 'w') as src:
            data_lines = []
            for i in range(0, int((length+15)/16)):
                sub_data = section[i*16:(i+1)*16]
                data_lines.append(', '.join(['0x%02x'%d for d in sub_data]))
            src.write('#include "%s.h"\n\n'
                      'namespace %s\n'
                      '{\n\n' % (self.application_name, self.application_name))
            src.write('const x86::reg8 s_%sSegment[] = {\n    ' % name)
            src.write(',\n    '.join(data_lines))
            src.write('\n};\n'
                      '}\n')