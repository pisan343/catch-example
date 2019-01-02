# Catch Example

Expected Mark: 80
Time spent: 200 hours or maybe more
Compiled and tested on CSS Linux Lab: Yes

> g++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -o catch-example.exe
No warnings

> cpplint *.cpp *.h
No warnings

> cppcheck --enable=all --inconclusive --language=c++ --std=posix --suppress=missingIncludeSystem *.cpp *.h
No warnings

> valgrind ./catch-example.exe
"definitely lost: 16 bytes"


Implemented x, y, z, but did not have time for w, r

Program gives the following error, cannot find source or fix it
            blah blah blah

How will I improve next time:
    - Start assignment early
    - Build simpler test cases
    - Compile and test on CSS Linux lab earlier
    - use valgrind more frequently
    - integrate cpplint with CLion
    - My code is perfect, I rocked this assignment!




