;
;   BASIC.inc
;
;   STANDARD INCLUDE FILE
;
;   BASIC MACROS
;
PUTCH   DEFMACRO    SRC
        RSSB    ACC
        RSSB    SRC
        RSSB    COUT
        RSSB    ACC
        RSSB    ACC
        ENDMACRO
;
GETCH   DEFMACRO    DST
        MOVEM       CIN,DST
        ENDMACRO
;
MOVEM   DEFMACRO    SRC,DST
        CLEARM  DST
        RSSB    SRC
        RSSB    ZERO
        RSSB    ZERO
        RSSB    DST
        RSSB    ACC
        RSSB    ACC
        ENDMACRO
;
CLEARM  DEFMACRO DST
        RSSB    ACC         ; CLAER DST
        RSSB    DST
        RSSB    DST
        RSSB    DST
        RSSB    ACC
        ENDMACRO
;
NEG     DEFMACRO SRC,DST    ; DST=-SRC
        CLEARM  DST
        RSSB    ACC
        RSSB    SRC
        RSSB    DST         ; DST=0-SRC if SRC>=0, and skip 
        RSSB    DST         ; DST=0-SRC if SRC<0, no skip
        RSSB    ACC
        ENDMACRO
;
INC     DEFMACRO TARGET     ; TARGET++
        RSSB    ACC
        RSSB    MINUS1      ; ACC=-1
MINUS1  DC      -1          ; (ALWAYS SKIPPED)
        RSSB    TARGET      ; TARGET=TARGET-ACC(=-1)
        RSSB    ACC         ; SKIPPED IF TARGET <0
        RSSB    ACC         ; ACC=0 ANYWAY
        ENDMACRO
;
DEC     DEFMACRO TARGET     ; TARGET--
        RSSB    ACC
        RSSB    MINUS1
MINUS1  DC      -1          ; (ALWAYS SKIPPED)
        RSSB    ZERO        ; ACC=1
        RSSB    TARGET      ; TARGET=TARGET-ACC(=1)
        RSSB    ACC         ; SKIPPED IF TARGET <0
        RSSB    ACC         ; ACC=0 ANYWAY
        ENDMACRO
;
;
HALT    DEFMACRO
        RSSB    ACC         ; HALTING
HALT0   RSSB    HALT0+2
        RSSB    IP
        DC      HALT0
        ENDMACRO
;
JPIND   DEFMACRO    DST     ; JUMP TO (DST) (14 WORDS)
        CLEARM  WK1
        RSSB    ACC
        RSSB    OFFSTB      ; ALWAYS OFFST < 0
OFFSTB  DC      -(JP0+1)    ; ALWAYS SKIPPED, USING FOR OFFSET CONST
        RSSB    WK1         ; WK1 = -OFFST(=JP0+1) > 0
        RSSB    ACC
        RSSB    DST
        RSSB    WK1         ; ACC=WK1=OFFSET(=JP0+1)-DST
JP0     RSSB    IP          ; BACKWARD JUMP (IP=IP-ACC OFFSET>=DST)
        CLEARM  WK1
        RSSB    ACC
        RSSB    OFFSETF
OFFSETF DC      -(JP1+1)      ; ALWAYS SKIPPED
        RSSB    WK1
        RSSB    ACC
        RSSB    DST
        RSSB    WK1
        RSSB    ACC         ; ALWAYS SKIPPED
JP1     RSSB    IP          ; FORWARD JUMP (IP=IP-ACC(<0))
WK1     DS      1
        ENDMACRO
;
;
JMP     DEFMACRO    DST     ; JUMP TO DST
        RSSB        ACC
        RSSB        RDST
JMPB    RSSB        IP
JMPF    RSSB        IP
RDST    DC          JMPB>DST?(JMPB-DST+1):(JMPF-DST+1)
        ENDMACRO
;
JNEG    DEFMACRO    TGT,DST     ; JUMP TO DST IF (TGT)<0
        RSSB        ACC
        RSSB        TGT
        RSSB        ACC
        RSSB        ZERO
        RSSB        ZERO
        RSSB        RPASS
        RSSB        ACC
JNEG0   RSSB        IP
        JMP         DST
RPASS   DC          JNEG0-JNEG1+1
JNEG1   RSSB        ACC
        ENDMACRO
;
VJMP    DEFMACRO    X,N,OB,VEC
        JCMP        N,ZERO,OB,OB,L1
L1      JCMP        X,ZERO,OB,L2,L2
L2      JCMP        X,N,L3,OB,OB
L3      MOVEM       CVEC,DST
        ACCM        DST,X
        LINDR       DST,VDST
        JPIND       VDST
CVEC    DC          VEC
DST     DS          1
VDST    DS          1
        ENDMACRO
;
ACCM    DEFMACRO    TGT,VAL ; (TGT)+=(VAL)
        RSSB        ACC
        RSSB        VAL
        RSSB        ZERO
        RSSB        ZERO
        RSSB        TGT
        RSSB        ACC
        RSSB        ACC
        ENDMACRO
;
JCMP        DEFMACRO    D0,D1,LT,EQ,GT
            NEG         D1,JCMPW0
            ACCM        JCMPW0,D0
            JNEG        JCMPW0,LT
            NEG         JCMPW0,JCMPW1
            JNEG        JCMPW1,GT
            JMP         EQ
JCMPW0      DS          1
JCMPW1      DS          1
            ENDMACRO
;
;
LINDR   DEFMACRO PTR, DST
        CLEARM   DST
        MOVEM    PTR  LINDR0
        RSSB     ACC
LINDR0  DS       1
        RSSB     ZERO
        RSSB     ZERO
        RSSB     DST
        RSSB     ACC
        RSSB     ACC
        ENDMACRO
;
;
SINDR   DEFMACRO SRC, PTR
        MOVEM   PTR,SINDR0
        MOVEM   PTR,SINDR1
        MOVEM   PTR,SINDR2
        MOVEM   PTR,SINDR3
        RSSB    ACC
SINDR0  DC      0
SINDR1  DC      0
SINDR2  DC      0
        RSSB    ACC
        RSSB    SRC
        RSSB    ZERO
        RSSB    ZERO
SINDR3  DC      0
        RSSB    ACC
        RSSB    ACC
        ENDMACRO
;
PUSH    DEFMACRO    SRC,SP
        SINDR       SRC,SP
        DEC         SP
        ENDMACRO
;
POP    DEFMACRO    DST,SP
        INC         SP
        LINDR       SP,DST
        ENDMACRO
;
PUSHES      DEFMACRO    SRC,N,SP
            MOVEM       SRC,SRCP
            MOVEM       N,NN
PUSHES0     DEC         NN
            JNEG        NN,PUSHES9
            LINDR       SRCP,WK0
            PUSH        WK0,SP
            INC         SRCP
            JMP         PUSHES0
WK0         DS          1
SRCP        DS          1
NN          DS          1
PUSHES9     RSSB        ACC
            ENDMACRO
;
POPS        DEFMACRO    DST,N,SP
            MOVEM       DST,DSTP
            MOVEM       N,NN
            ACCM        DSTP,NN
            DEC         DSTP
POP0        DEC         NN
            JNEG        NN,POPS9
            POP         WK0,SP
            SINDR       WK0,DSTP
            DEC         DSTP
            JMP         POP0
WK0         DS          1
DSTP        DS          1
NN          DS          1
POPS9       RSSB        ACC
            ENDMACRO
;
;
;       END INCLDE FILE
;