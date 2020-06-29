# Dependencies

## CMake
* https://cmake.org/download/

## MingW-64
* http://mingw-w64.org/doku.php/download goto MingW-W64-builds
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

## SDL
* https://libsdl.org/index.php goto Download SDL 2.0
* CodeBlocks Setup: https://www.youtube.com/watch?v=lJRgwbRVtP0

# Reference
http://www.cplusplus.com/reference/

## Style
* http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules
* https://google.github.io/styleguide/cppguide.html

## #include <bits/stdc++.h>
* A header file that includes every standard library
* Only exist in GCC compiler, need to manually add folder bits and file stdc++.h for Visual Studio
* VS C++ PATH: C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\include\bits
* Source code: http://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01541_source.html
