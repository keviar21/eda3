flex EA3.l
bison -dyv EA3.y
gcc lex.yy.c y.tab.c -o Primera
pause
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h