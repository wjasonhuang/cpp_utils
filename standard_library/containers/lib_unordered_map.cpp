/*
http://www.cplusplus.com/reference/unordered_map/
unordered_map:          hash table, insert / erase / find O(1)
unordered_multimap:     similar to unordered_map except multiple elements can have equivalent keys

unordered_map<type, type> name {{key1, value1}, {key2, value2}, ...}
unordered_map<type, type>::iterator

unordered_map::begin() / unordered_map::end()
unordered_map::empty() / unordered_map::size()

unordered_map::erase(iterator position / const key_type& / iterator first, iterator last)
            removes a single element / removes all elements with target key / elements in range[first, last)
unordered_map::clear()                      all the elements in the unordered_map container are dropped
unordered_map::find(const key_type&)        returns an iterator to the element, unordered_map::end() if key is not found
unordered_map::count(const key_type& k)     returns the number of elements whose key is k
unordered_map::equal_range                  returns a pair, including pair::first, but not pair::second.

unordered_map::hash_function                returns the hash function object used

Differences:
unordered_map::operator[]                   does not exist in unordered_multimap
unordered_map::insert(pair(key, val) / InputIterator first, InputIterator last)
            insert (key, val) or copies of elements in [first, last), unordered_map does not inserted if key already in the container
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    cout << "unordered_map examples:\n";
    unordered_map<char, int> a = {{'a', 1}, {'b', 2}, {'c', 3}};
    a.erase('b');
    a['d'] = 4;
    a.insert(pair<char, int>('z', 26));
    cout << "key 'e': count " << a.count('e') << ", value " << a['e'] << "\n";
    for (unordered_map<char, int>::iterator it = a.begin(); it != a.end(); it++)
        cout << it->first << " => " << it->second << "\n";

    cout << "\nunordered_multimap examples:\n";
    unordered_multimap<char, int> ma = {{'a', 1}, {'b', 1}, {'b', 2}, {'c', 3}};
    auto range = ma.equal_range('b');
    for (auto it = range.first; it != range.second; it++)
        cout << it->first << " => " << it->second << "\n";
    ma.erase('b');
    for (unordered_multimap<char, int>::iterator it = ma.begin(); it != ma.end(); it++)
        cout << it->first << " => " << it->second << "\n";
}
