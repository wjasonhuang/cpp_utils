/*
http://www.cplusplus.com/reference/algorithm/

Sorting:
std::sort()             sorts [first,last) into ascending order using operator<
std::stable_sort()      preserves the relative order of the elements with equivalent values
std::is_sorted()        returns true if [first,last) is sorted into ascending order
std::is_sorted_until()  returns an iterator to the first element which does not follow an ascending order
std::nth_element()      rearranges [first,last) elements preceding nth are less than it and elements following it are greater


Heap:
std::push_heap()        extends heap range from [first, last-1) to [first,last)
std::pop_heap()         moves the element with the highest value in [first, last) to (last-1)
std::make_heap()        rearranges [first,last) to form a max heap
std::sort_heap()        sorts [first,last) into ascending order
std::is_heap()          returns true if [first,last) forms a heap
std::is_heap_until()    returns an iterator to the first element which is not in a valid heap position
*/

#include <algorithm>
#include <iostream>
#include <vector>

void print(auto a) { for (auto ai : a) std::cout << " " << ai; std::cout << '\n'; }

void sorting_examples() {
    std::cout << "\nSorting Examples:\n";
    std::vector<int> a{3, 2, 4, 1, 5};

    // using comp function instead of operator<
    std::sort(a.begin(), a.end(), [](int a, int b) { return a >= b; });
    print(a);

    std::cout << "Sorted? " << std::is_sorted(a.begin(), a.end()) << '\n';
    std::cout << "Sorted until: " << std::is_sorted_until(a.begin(), a.end()) - a.begin() << '\n';

    //first, nth, last
    std::nth_element(a.begin(), a.begin() + 2, a.end());
    print(a);
}

void heap_examples() {
    std::cout << "\nHeap Examples:\n";
    std::vector<int> a{3, 2, 4, 1, 5};

    // make a min heap by reversing < comp function
    std::make_heap(a.begin(), a.end(), [](int a, int b) { return a >= b; });
    print(a);

    // default make a max heap
    std::make_heap(a.begin(), a.end());
    print(a);

    a.push_back(6);
    std::push_heap(a.begin(), a.end());
    print(a);

    std::pop_heap(a.begin(), a.end());
    print(a);

    std::cout << "max heap? " << std::is_heap(a.begin(), a.end()) << '\n';
    std::cout << "max heap until: " << std::is_heap_until(a.begin(), a.end()) - a.begin();
}

int main() {
    sorting_examples();
    heap_examples();
}
