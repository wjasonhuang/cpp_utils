/*
http://www.cplusplus.com/reference/set/
set:        similar to map except value is also the key
multiset:   similar to multimap except value is also the key

set<type> name {value1, value2, ...}
set<type>::iterator
auto cmp = [](int a, int b) { return ... };
set<int, decltype(cmp)> s(cmp);

set::begin() / set::end() / set::rbegin() / map::rend()
set::empty() / set::size()


set::erase(iterator position / const value_type& / iterator first, iterator last)
            removes a single element / removes all elements with target value / elements in range[first, last)
set::clear()
set::find(const value_type&)              returns an iterator to the element, set::end() if key is not found
set::count(const value_type& k)           returns the number of elements whose key is k
set::lower_bound(const value_type&)       returns an iterator to the first element in the container whose key >= target key
set::upper_bound(const value_type&)       returns an iterator to the first element in the container whose key > target key
set::equal_range(const value_type&)       returns pair<map::lower_bound, map::upper_bound>

Differences:
set::insert(val / InputIterator first, InputIterator last)
            insert val or copies of elements in [first, last), set does not inserted if val already in the container
            
Tips:
to erase only one occurrence of the value in multiset, use set::erase(set::find(val))
to find the last element of the set, use *set::rbegin()
*/

#include <iostream>
#include <set>
using namespace std;

void print_set(auto &s) {
    for (auto it = s.begin(); it != s.end(); it++)
        cout << " " << *it;
    cout << endl;
}

int main() {
    cout << "set examples:\n";
    set<int> s = {4, 1, 3, 2};
    s.insert(5); s.erase(2);
    cout << *s.find(4) << endl;
    print_set(s);

    auto cmp = [](int a, int b) { return a >= b; };
    set<int, decltype(cmp)> ns(cmp);
    ns.insert(s.begin(), s.end());
    print_set(ns);

    cout << "\nmultiset examples:\n";
    multiset<int> ms = {3, 2, 2, 1, 1, 3};
    ms.erase(3);
    print_set(ms);
}
