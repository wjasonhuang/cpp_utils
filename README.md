# Style
* http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules
* https://google.github.io/styleguide/cppguide.html

# `#include <bits/stdc++.h>`
* It is basically a header file that includes every standard library
* Using it would include a lot of unnecessary stuff and increases compilation time.

# MingW-64
* http://mingw-w64.org/doku.php/download -> MingW-W64-builds
* Add environment variable	C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin
```
    // Compile all at once
    g++ main.cpp code1.cpp code2.cpp
    
    // Compile in steps
    g++ -c *.cpp    // preprocessor runs and executes any statement beginning with #, such as #include statements
                    // only updated .cpp files need to recompile in this step
    g++ *.o         // object files are "linked" together to make a single executable
    ./a.out         // a.out is the executable

    // Compile multithreaded code
    g++ main.cpp -pthread -o main
    
    // Compile wtih debugging symbols
    g++ -g main.cpp
    gdb a.out
```

# CMake
* https://cmake.org/download/
