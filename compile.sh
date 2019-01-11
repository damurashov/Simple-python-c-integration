#1/bin/sh

swig -python -I.  main.i

gcc ./main.c ./main.h ./main_wrap.c -shared -I. -I/usr/include/python3.6m -o _main.so -fpic
