# Overview

This repository shows VTL-2 programming language interpreter in RSSB machine code.
RSSB has the only one machine instruction. This type of CPU is called OISC (only One Instruction Set Computer). 
Browing playground page (show link below) runs a RSSB IDE and starting this VTL-2 interpreter application, also provides assembly language with macro feature of RSSB, enables to try your RSSB program on RSSB Emulator, and to debug it by monitor/debugger


# OISC-RSSB

RSSB is one of OISC (Only one Instruction Set Computer). RSSB has only one instruction "Reverse Subtract and Skip if Borrow" that is subtraction from the contents of the accumulator from the contents of the operand address, put its result to both the operand address and the accumulator, and skip next instruction if its result is negative value (<0).
See [https://esolangs.org/wiki/RSSB](https://esolangs.org/wiki/RSSB) in detail.

# RSSB IDE

The rssbide.html SPA provides an Emurator of RSSB (Reverse Substract Skip if Borrow) CPU which is one of OISC (One Instruction Set Computer), its IDE including monitor, macro assembler, debugger in javascript.

This Emulator implements in JavaScript with refer to [https://github.com/electrodude/rssb](https://github.com/electrodude/rssb) (that is written in C).

## VTL-2 Interpreter in RSSB ##

This site has also VTL-2 Programming Language interpreter in native RSSB machine code. VTL-2 in RSSB is 18000 machine words long.

Copilot AI pointed out in May 2026 that this VTL-2 interpreter may be one of the largest class application so far in RSSB.

## PLAY GROUND ##
You can play programming RSSB machine on a playground site [https://ych4416.github.io/VTL2INRSSB/rssbide.html](https://ych4416.github.io/VTL2INRSSB/rssbide.html) by writing its assembly language with macro definition feature. 

# Basic Programming in RSSB

Sime exeamples of grouding up primitive operations programming in RSSB such as moving data, halting, basic arithmetics, jump, conditional jump, etc can be found in [https://note.com/kste9947/n/n65a22a2b80d6](https://note.com/kste9947/n/n65a22a2b80d6) and this following articles. They are written in Japanese as my native. Use translate them as you need.

# Detail description VTL-2 Intepreter in RSSB

Detail description of VTL-2 interpreter program in RSSB. This will be in the article series above.

