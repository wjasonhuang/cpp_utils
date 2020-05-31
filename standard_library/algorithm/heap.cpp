/*
http://www.cplusplus.com/reference/algorithm/

std::push_heap()        extends heap range from [first, last-1) to [first,last)
std::pop_heap()         moves the element with the highest value in [first, last) to (last-1)
std::make_heap()        rearranges the elements in [first,last) to form a max heap
std::sort_heap()        sorts the elements in [first,last) into ascending order
std::is_heap()          returns true if the range [first,last) forms a heap
std::is_heap_until()    returns an iterator to the first element which is not in a valid heap position
*/

#include <algorithm>
#include <iostream>
#include <vector>

void print_vector(auto a) { for (auto ai : a) std::cout << " " << ai; std::cout << '\n'; }

bool comp(int a, int b) { return a >= b; }

void heap_examples() {
    std::vector<int> a{3, 2, 4, 1, 5};
    // make a min heap by reversing < comp function
    std::make_heap(a.begin(), a.end(), comp);
    print_vector(a);

    // default make a max heap
    std::make_heap(a.begin(), a.end());
    print_vector(a);

    a.push_back(6);
    std::push_heap(a.begin(), a.end());
    print_vector(a);

    std::pop_heap(a.begin(), a.end());
    print_vector(a);

    std::cout << "max heap? " << std::is_heap(a.begin(), a.end()) << '\n';
    std::cout << "max heap bound: " << std::is_heap_until(a.begin(), a.end()) - a.begin();
}

int main() {
    heap_examples();
}
