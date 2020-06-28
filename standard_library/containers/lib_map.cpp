/*
http://www.cplusplus.com/reference/map/
map:        ordered, unique keys, Red-Black tree, insert / erase / find O(log N)
multimap:   similar to map except multiple elements can have equivalent keys

map<type, type> name {{key1, value1}, {key2, value2}, ...}
map<type, type>::iterator

map::begin() / map::end() / map::rbegin() / map::rend()
map::empty() / map::size()

map::erase(iterator position / const key_type& / iterator first, iterator last)
            removes a single element / removes all elements with target key / elements in range[first, last)
map::clear()
map::find(const key_type&)              returns an iterator to the element, map::end() if key is not found
map::count(const key_type& k)           returns the number of elements whose key is k
map::lower_bound(const key_type&)       returns an iterator to the first element in the container whose key >= target key
map::upper_bound(const key_type&)       returns an iterator to the first element in the container whose key > target key
map::equal_range(const key_type&)       returns pair<map::lower_bound, map::upper_bound>

Differences:
map::operator[]                         does not exist in multimap
map::insert(pair(key, val) / InputIterator first, InputIterator last)
            insert (key, val) or copies of elements in [first, last), map does not insert if key already exists
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    cout << "map examples:\n";
    map<char, int> a = {{'a', 1}, {'b', 2}, {'c', 3}};
    a.erase('b');
    a['d'] = 4;
    a.insert(pair<char, int>('z', 26));
    cout << "key 'e': count " << a.count('e') << ", value " << a['e'] << "\n";
    for (map<char, int>::iterator it = a.begin(); it != a.end(); it++)
        cout << it->first << " => " << it->second << "\n";

    cout << "\nmultimap examples:\n";
    multimap<char, int> ma = {{'a', 1}, {'b', 1}, {'b', 2}, {'c', 3}};
    auto range = ma.equal_range('b');
    for (auto it = range.first; it != range.second; it++)
        cout << it->first << " => " << it->second << "\n";
    ma.erase('b');
    for (multimap<char, int>::iterator it = ma.begin(); it != ma.end(); it++)
        cout << it->first << " => " << it->second << "\n";
}
