#!/bin/bash

# make this file executable
# command line: chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# command line: ./simplecompile.sh > output.txt 2>&1


date

echo "*** Compiling"
g++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram.exe

echo "*** cpplint"
cpplint *.cpp *.h

echo "*** cppcheck"
cppcheck --enable=all --inconclusive --language=c++ --std=posix --suppress=missingIncludeSystem *.cpp *.h

echo "*** running"
./myprogram.exe

echo "*** running with valgrind"
valgrind ./myprogram.exe

echo "*** cleaning up"
rm myprogram.exe

date

