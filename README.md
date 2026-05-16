# <div style="text-align:center"> OISC-RSSB IDE </div>

RSSB is one of OISC (Only one Instruction Set Computer). RSSB has only one instruction "Reverse Subtract and Skip if Borrow" that is subtraction from the contents of the accumulator from the contents of the operand address, put its result to both the operand address and the accumulator, and skip if its result is negative.
See https://esolangs.org/wiki/RSSB in detail.

This site provides an Emurator of RSSB (Reverse Substract Skip if Borrow) CPU which is one of OISC (One Instruction Set Computer), its IDE including monitor, assembler, debugger, and VTL-2 Programming Language interpreter in RSSB machine code as its middle-size application. VTL-2 in RSSB is 18000 machine words long. 

This Emulator implements in JavaScript with refer to https://github.com/electrodude/rssb (written in C).

You can play programming RSSB machine on a playground site https://ych4416.github.io/VTL2INRSSB/ by writing its assembly language with macro definition feature. 

## UNDER CONSTRUCTION ##
Follwing documents are under construction:
1. How to use IDE.

2. The exeample of grouding up primitive operations programming in RSSB such as moving data, halting, basic arithmetics, jump, contional jump, etc. See https://note.com/kste9947/n/n65a22a2b80d6 and this following articles. They are written in Japanese as my native. Use translate them as you need.

3. Detail description of VTL-2 interpreter program in RSSB. This will be in the article series of 2.

