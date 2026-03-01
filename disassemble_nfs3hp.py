import sys
sys.path.append('disasm')
from disasm import disassembler, dll


DATA_SEGMENTS = [(0x401004, 0x401010),
                 (0x405734, 0x405740),
                 (0x409ff0, 0x40a010),
                 (0x40cb00, 0x40cb20),
                 (0x412920, 0x412994),
                 (0x41a880, 0x41a8c8),
                 (0x420814, 0x420840),
                 (0x4212b0, 0x421360),
                 (0x423d50, 0x423d90),
                 (0x42d550, 0x42d618),
                 (0x42dd30, 0x42dd58),
                 (0x434ea0, 0x434f14),
                 (0x43f180, 0x43f1e4),
                 (0x44e150, 0x44e170),
                 (0x4489f0, 0x448ef2),
                 (0x454f10, 0x455020),
                 (0x45cb60, 0x45cdc0),
                 (0x465d10, 0x465d60),
                 (0x46ccb0, 0x46cce0),
                 (0x472160, 0x4721f0),
                 (0x478310, 0x478320),
                 (0x47ba70, 0x47bbb8),
                 (0x488030, 0x4880b0),
                 (0x489630, 0x4896f0),
                 (0x491110, 0x491120),
                 (0x493360, 0x493380),
                 (0x493370, 0x493380),
                 (0x49e060, 0x49e080),
                 (0x4975b0, 0x497620),
                 (0x49c3e0, 0x49c410),
                 (0x49e060, 0x49e080),
                 (0x4a2f50, 0x4a3050),
                 (0x4a4050, 0x4a4060),
                 (0x4a6f80, 0x4a7080),
                 (0x4af3b0, 0x4b0700),
                 (0x4b5580, 0x4b56d0),
                 (0x4b6a10, 0x4b6a10),
                 (0x4b7a10, 0x4b7a60),
                 (0x4c9a70, 0x4c9a80),
                 (0x4d0650, 0x4d06f0),
                 (0x4d5740, 0x4d5840),
                 (0x4dfae5, 0x4dfaf0),
                 (0x4f7fa5, 0x4f8020),
                 (0x51679d, 0x5167b3),
                 (0x52efb0, 0x52f318),
                 (0x533ef0, 0x534000),]


MERGE_ROUTINES = [(0x405740, 0x405791),
                  (0x405740, 0x4057a0),
                  (0x420840, 0x42088a),
                  (0x420840, 0x420a71),
                  (0x420840, 0x420a7a),
                  (0x420840, 0x420a83),
                  (0x420840, 0x420aac),
                  (0x420840, 0x420b53),]

KNOWN_SUBROUTINES = [0x4ff3d0,]

SKIP_INSTRUCTIONS = [0x4a3aec]


SPLIT_INSTRUCTIONS = [0x4e08af, 0x4e087a, 0x4eee0f]


THREAD_ROUTINES = []
THREAD_SEGMENTS = [0x43ac67, 0x43ac97, 0x46785e, 0x4f06f7, 0x4f2191, 0x495b68, 0x4d9158, 0x4c4e84, 0x4f7d0e]

if __name__ == '__main__':
    application = disassembler.disassemble('nfs3hp', 'nfs3hp/nfs3.exe', DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, SPLIT_INSTRUCTIONS,
                                           THREAD_ROUTINES, THREAD_SEGMENTS, MERGE_ROUTINES)
    eacsnd = disassembler.disassemble('eacsnd', 'nfs3hp/eacsnd.dll', type=dll.DLL,
                                      data_segments=[(0xa35749, 0xa3575f),
                                                     (0xa372bf, 0xa372dd)], rebase_after=application)
    softtria = disassembler.disassemble('softtria', 'nfs3hp/softtria.dll', type=dll.DLL,
                                        data_segments=[(0xa73e87, 0xa73f00),
                                                       (0xa78c09, 0xa78c1f),
                                                       (0xa3fc04, 0xa3fc10),], rebase_after=eacsnd)
    voodoo2a = disassembler.disassemble('voodoo2a', 'nfs3hp/voodoo2a.dll', type=dll.DLL,
                                        data_segments=[(0xa83204, 0xa83210),
                                                       (0xA86833, 0xA868A2)],
                                        known_subroutines=[0xA847D0, 0xA84810], rebase_after=softtria)
    application.write(THREAD_SEGMENTS, skip_instructions=SKIP_INSTRUCTIONS, dlls=[eacsnd, softtria, voodoo2a])
