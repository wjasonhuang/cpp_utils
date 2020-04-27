# Style
* http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules
* https://google.github.io/styleguide/cppguide.html

# Header
* `#include <bits/stdc++.h>`
* It is basically a header file that includes every standard library.
* Using it would include a lot of unnecessary stuff and increases compilation time.

# Compile
    // Compile all at once
    g++ ./main.cpp ./code1.cpp ./code2.cpp && ./a.out
    
    // Compile in steps
    g++ -c *.cpp    // preprocessor runs and executes any statement beginning with #, such as #include statements
                    // only updated .cpp files need to recompile in this step
    g++ *.o         // object files are "linked" together to make a single executable
    ./a.out         // a.out is the executable

# References & Pointers
* The symbols & and * have a different meaning, depending on which side of an equation they appear.
* &
    * if it appears on the left side of an equation (e.g. when declaring a variable), it means that the variable is declared as a reference
    * if the & appears on the right side of an equation (e.g. before a previously defined variable), it is used to return a memory address
* \*
    * a pointer can be declared by using the * operator in the declaration to store memory address, e.g. int* i
    * to retrieve the object a pointer is pointing tomthe * symbol can be used again, e.g. *i
