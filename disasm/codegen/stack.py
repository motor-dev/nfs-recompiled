from capstone import x86 as x86_const
from . import arguments


def cg_push(instruction, function_bounds, function_names, value):
    return ['app->getMemory<x86::reg%d>(cpu.esp-4) = %s;' % (value.size*8,
                                                              arguments.get_value(instruction, value)),
            'cpu.esp -= 4;']


def cg_pop(instruction, function_bounds, function_names, value):
    return ['%s = app->getMemory<x86::reg%d>(cpu.esp);' % (arguments.get_value(instruction, value),
                                                            value.size*8),
            'cpu.esp += 4;']


def cg_enter(instruction, function_bounds, function_names, alloc, nesting):
    if nesting.imm == 0:
        return ['{',
                '    cpu.esp -= 4;',
                '    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;',
                '    cpu.ebp = cpu.esp;',
                '    cpu.esp -= %d;' % alloc.imm,
                '}']
    else:
        return ['{',
                '    cpu.esp -= 4;',
                '    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;',
                '    x86::reg32 esp = cpu.esp;',] + [
                '    cpu.esp -= 4;',
                '    cpu.ebp -= 4;',
                '    app->getMemory<x86::reg32>(cpu.esp) =  app->getMemory<x86::reg32>(cpu.ebp);',
                    ]*(nesting.imm-1) + [
                '    cpu.esp -= 4;',
                '    app->getMemory<x86::reg32>(cpu.esp) = esp;',
                '    cpu.ebp = esp;',
                '    cpu.esp -= %d;' % alloc.imm,
                '}']


def cg_leave(instruction, function_bounds, function_names):
    return ['cpu.esp = cpu.ebp;',
            'cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);',
            'cpu.esp += 4;']


def cg_pushf(instruction, function_bounds, function_names):
    return ['cpu.esp -= 4;',
            'app->getMemory<x86::reg16>(cpu.esp) = cpu.flags.word;']


def cg_popf(instruction, function_bounds, function_names):
    return ['cpu.flags.word = app->getMemory<x86::reg16>(cpu.esp);',
            'cpu.esp += 4;']


def cg_pushfd(instruction, function_bounds, function_names):
    return ['cpu.esp -= 4;',
            'app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;']


def cg_popfd(instruction, function_bounds, function_names):
    return ['cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);',
            'cpu.esp += 4;']


def cg_pushal(instruction, function_bounds, function_names):
    return ['app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;',
            'app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;',
            'app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;',
            'app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;',
            'app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;',
            'app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;',
            'app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;',
            'app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;',
            'cpu.esp -= 32;']


def cg_popal(instruction, function_bounds, function_names):
    return ['{',
            '    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);',
            '    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);',
            '    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);',
            '    // skip esp',
            '    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);',
            '    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);',
            '    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);',
            '    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);',
            '    cpu.esp += 32;',
            '}']
