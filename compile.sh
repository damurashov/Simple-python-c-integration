#1/bin/sh

gcc ./main.c -shared -DCPATH="/usr/include/python3.6m" -o hello.so
