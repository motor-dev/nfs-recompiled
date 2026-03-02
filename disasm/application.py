import os
from .module import Module

class Application(Module):
    def __init__(self, application_name, exe_path, rebase_after):
        Module.__init__(self, application_name, exe_path, rebase_after)

    def write(self, thread_segments=[], skip_instructions=[], dlls=[], function_names={}):
        try:
            os.makedirs('src/%s/disassembly' % (self.application_name))
        except OSError:
            pass
        with open('src/%s/disassembly/%s.cpp' % (self.application_name, self.application_name), 'w') as src:
            with open('src/%s/disassembly/%s.h' % (self.application_name,  self.application_name), 'w') as h:
                app_name = self.application_name
                APP_NAME = self.application_name.upper()
                src.write('#include "%s.h"\n'
                          '#include <x86.h>\n'
                          '#include <winapi/wrapper.h>\n' % (app_name))
                for dll in dlls:
                    src.write('#include "%s.h"\n' % (dll.application_name))
                for dll_name, dll_methods in self.dll_imports:
                    src.write('#include <winapi/%s.h>\n' % dll_name.decode())
                for dll in dlls:
                    for dll_name, dll_methods in dll.dll_imports:
                        src.write('#include <winapi/%s.h>\n' % dll_name.decode())
                src.write('\nnamespace %s\n'
                            '{\n\n' % (app_name))
                h.write('#ifndef %s_H_\n'
                        '#define %s_H_\n'
                        '#include <x86.h>\n'
                        '#include <lib/winapp.h>\n'
                        '#include <lib/memmap.h>\n'
                        '#include <map>\n'  % (APP_NAME, APP_NAME))
                h.write('\nnamespace %s\n'
                        '{\n\n'
                        'class Application : public win32::WinApplication\n'
                        '{\n'
                        'public:\n'
                        '    Application(const char* appName);\n'
                        '    void execute();\n'
                        'private:\n' % (app_name))
                for data, address, length, name, ro, code in self.sections:
                    if data:
                        self._dump_raw_section(name, data, length)
                        h.write('    static const x86::reg8 s_%sSegment[];\n' % name.decode())
                section_segments = ['{ %s, 0x%x, %d }' % (('s_%sSegment'%name.decode()) if data else 'nullptr',
                                                           address,
                                                           length) for data, address, length, name, ro, code in self.sections]
                for dll in dlls:
                    section_segments += ['{ %s, 0x%x, %d }' % (('%s::s_%sSegment'%(dll.application_name, name.decode())) if data else 'nullptr',
                                                                address,
                                                                length) for data, address, length, name, ro, code in dll.sections]
                sections = ', '.join(section_segments)
                src.write('Application::Application(const char* appName)\n'
                            '    :   WinApplication(appName, 0x%x, { %s })\n'
                            '{\n' % (self.sections[0][1], sections))
                for dll in dlls:
                    print(dll)
                    src.write('        %s::s_registry->registerSymbols(this);\n' % dll.application_name)
                for subroutine in self.subroutines:
                    function_entry = subroutine.get_entry_point()
                    name = function_names.get(function_entry, 'sub_%x' % function_entry)
                    src.write('    registerMethod(0x%08x, {"<Application>%s", &Application::%s});\n' % (function_entry, name, name))
                for dll in dlls:
                    for subroutine in dll.subroutines:
                        function_entry = subroutine.get_entry_point()
                        name = function_names.get(function_entry, 'sub_%x' % function_entry)
                        src.write('    registerMethod(0x%08x, {"<%s>%s", &%s::%s});\n' % (function_entry, dll.application_name, name, dll.application_name, name))
                for dll_name, dll_methods in self.dll_imports:
                    for method, address in dll_methods:
                        src.write('    registerMethod(0x%08x, {"<%s>%s", &win32::Wrapper<decltype(&win32::%s::%s), &win32::%s::%s>::stdcall});\n' % (address, dll_name.decode(), method.decode(), dll_name.decode(), method.decode(), dll_name.decode(), method.decode()))
                for dll in dlls:
                    for dll_name, dll_methods in dll.dll_imports:
                        for method, address in dll_methods:
                            src.write('    registerMethod(0x%08x, {"<%s>%s", &win32::Wrapper<decltype(&win32::%s::%s), &win32::%s::%s>::stdcall});\n' % (address, dll_name.decode(), method.decode(), dll_name.decode(), method.decode(), dll_name.decode(), method.decode()))

                src.write('}\n\n')
                src.write('void Application::execute()\n'
                            '{\n'
                            '    runThread(m_cpu, 0x%x);\n'
                            '}\n\n' % (self.entry_point))
                src.write('}\n')

                for index in range(0, 1+int(len(self.subroutines)/100)):
                    methods = open('src/%s/disassembly/%s.%d.cpp' % (app_name, app_name, index), 'w')
                    methods.write('#include "%s.h"\n'
                                  '#include <lib/thread.h>\n\n'
                                  'namespace %s\n'
                                  '{\n\n' % (app_name, app_name))
                    for subroutine in self.subroutines[100*index:100*(index+1)]:

                        function_start = subroutine.get_start_address()
                        function_end = subroutine.get_end_address()
                        function_entry = subroutine.get_entry_point()
                        name = function_names.get(function_entry, 'sub_%x' % function_entry)
                        fallthrough = False
                        methods.write('/* align: skip %s */\n' % (' '.join(['0x%02x'%c for c in subroutine.skipped_blob])))
                        if subroutine.data_blob:
                            methods.write('/* data blob: %s */\n' % (''.join(['%02x'%c for c in subroutine.data_blob])))
                        for jump_entry in subroutine.jump_table:
                            methods.write('/* jump table: 0x%08x */\n' % jump_entry)
                        h.write('    static void %s(WinApplication* app, x86::CPU& cpu);\n' % name)
                        methods.write('void Application::%s(WinApplication* app, x86::CPU& cpu)\n'
                                      '{\n'
                                      '  NFS2_USE(cpu);\n'
                                      '  NFS2_USE(app);\n' % name)
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
                                          '    %s%s\n'  % (self._raw(subroutine.section, instruction),
                                                           (instruction.address in skip_instructions) and '//' or '',
                                                           '\n    '.join(self.generate(instruction, (function_start, function_end), function_names))))
                            fallthrough = instruction.mnemonic not in ['jmp', 'ret']
                        if subroutine.dynamic_labels:
                            methods.write('  default:\n'
                                          '    NFS2_ASSERT(false);\n'
                                          '  }\n')
                        methods.write('}\n\n')
                    methods.write('}\n')
                h.write('};\n\n'
                        '}\n\n'
                        '#endif /* !%s_H_ */\n' % (APP_NAME))
        for dll in dlls:
            dll.write(self.application_name, thread_segments, function_names)