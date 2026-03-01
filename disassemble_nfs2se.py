import sys
sys.path.append('disasm')
from disasm import disassembler, dll


DATA_SEGMENTS = [(0x401004, 0x401080),
                 (0x406080, 0x4060f0),
                 (0x40a150, 0x40a3f0),
                 (0x40ec60, 0x40ec70),
                 (0x411070, 0x411080),
                 (0x4119e0, 0x411c10),
                 (0x413210, 0x413220),
                 (0x414c10, 0x414d00),
                 (0x41a2c0, 0x41a350),
                 (0x41bae0, 0x41bc20),
                 (0x420014, 0x420030),
                 (0x4233e0, 0x423420),
                 (0x425430, 0x425500),
                 (0x42aa50, 0x42aa60),
                 (0x42f060, 0x42f150),
                 (0x437c30, 0x437d90),
                 (0x43ba40, 0x43ba60),
                 (0x448210, 0x448230),
                 (0x44b590, 0x44b5f0),
                 (0x44bc70, 0x44bc80),
                 (0x4502d0, 0x450330),
                 (0x45ff60, 0x45ff80),
                 (0x460ec0, 0x460f00),
                 (0x4621d0, 0x462280),
                 (0x464200, 0x464220),
                 (0x465ed0, 0x465f40),
                 (0x469680, 0x469730),
                 (0x469ea0, 0x469ee0),
                 (0x46e120, 0x46e130),
                 (0x470ea0, 0x470eb0),
                 (0x470ea0, 0x470eb0),
                 (0x471c10, 0x471cc0),
                 (0x476330, 0x476334),
                 (0x4808eb, 0x4808ec),
                 (0x48b375, 0x48b3e4),
                 (0x49c365, 0x49c366),
                 (0x4a4c11, 0x4a4c12),
                 (0x4b4670, 0x4b49d8),
                 (0x4b4db6, 0x4d4e00),
    ]


KNOWN_SUBROUTINES = [
    ]


SPLIT_INSTRUCTIONS = [0x48c058, 0x48c08d, 0x49658a]


#THREAD_ROUTINES = [0x477b48, 0x4865cc]
#THREAD_SEGMENTS = [(0x485296, 0x4852b4)]
THREAD_ROUTINES = []
THREAD_SEGMENTS = [0x478095, 0x47bbdd, 0x422ec9, 0x4772ee]

FUNCTION_NAMES = {
    0x422dd0: 'main_loop',
    0x4a1498: 'bresenham_texture_sampler',
    0x4782c0: 'crt_exit',
    0x4a9520: 'strdup',
    0x495b53: 'malloc',
}

if __name__ == '__main__':
    application = disassembler.disassemble('nfs2se', 'nfs2se/nfs2sen.exe', DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, SPLIT_INSTRUCTIONS, THREAD_ROUTINES)
    eacsnd = disassembler.disassemble('eacsnd', 'nfs2se/eacsnd.dll', type=dll.DLL, rebase_after=application)
    application.write(THREAD_SEGMENTS, dlls=[eacsnd], function_names=FUNCTION_NAMES)
