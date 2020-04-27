# Style
- http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules
- https://google.github.io/styleguide/cppguide.html

# Header
- #include <bits/stdc++.h>
- It is basically a header file that includes every standard library.
- Using it would include a lot of unnecessary stuff and increases compilation time.

# Compile Multiple Files
```g++ ./code/main.cpp ./code/increment_and_sum.cpp ./code/vect_add_one.cpp && ./a.out```
OR
`g++ -c *.cpp`
`g++ *.o`
`./a.out`

