# Style
- http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules
- https://google.github.io/styleguide/cppguide.html

# Header
- #include <bits/stdc++.h>
- It is basically a header file that includes every standard library.
- Using it would include a lot of unnecessary stuff and increases compilation time.

# Compile Multiple Files
- Compile command
    // Compile all at once
    g++ ./main.cpp ./code1.cpp ./code2.cpp && ./a.out
    
    // Compile in steps
    g++ -c *.cpp    // preprocessor runs and executes any statement beginning with #, such as #include statements
                    // only updated .cpp files need to recompile in this step
    g++ *.o         // object files are "linked" together to make a single executable
    ./a.out         // a.out is the executable

