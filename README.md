# Style
- http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules
- https://google.github.io/styleguide/cppguide.html

# Header
- #include <bits/stdc++.h>
- It is basically a header file that includes every standard library.
- Using it would include a lot of unnecessary stuff and increases compilation time.

# Compile Multiple Files
    // Compile all at once
    g++ ./code/main.cpp ./code/increment_and_sum.cpp ./code/vect_add_one.cpp && ./a.out
    
    // Compile in steps
    g++ -c *.cpp    // preprocessor runs and executes any statement beginning with #, such as #include statements
    g++ *.o         // object files are "linked" together to make a single executable
    ./a.out         // a.out is the executable

