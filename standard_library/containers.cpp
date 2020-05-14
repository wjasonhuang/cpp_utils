/*
http://www.cplusplus.com/reference/stl/

Sequence containers:
array
vector
deque
forward_list
list

Container adaptors:
stack
queue
priority_queue

Associative containers:
set
multiset
map
multimap

Unordered associative containers:
unordered_set
unordered_multiset
unordered_map
unordered_multimap
*/


#include <iostream>
using namespace std;


/*
http://www.cplusplus.com/reference/vector/vector/

vector<type> name (size_type n, const value_type& val)
vector<type> name (const vector& x)
vector<type> name {element1, element2, ...}
vector<type>::iterator

vector::begin()         returns an iterator to point at the first element of a C++ vector
vector::end()           returns an iterator to point at past-the-end element of a C++ vector
vector::rbegin()        return reverse iterator to reverse beginning
vector::rend()          return reverse iterator to reverse end

vector::empty()         returns whether the vector is empty (i.e. whether its size is 0)
vector::size()          returns the number of elements in the vector

vector::front()         returns a reference to the first element in the vector
vector::back()          returns a reference to the last element in the vector
vector::push_back()     adds a new element after its current last element
vector::emplace_back()  inserts a new element (constructed in place using args as the arguments for its constructor) at the end
vector::insert()        inserts new elements to a specified location
vector::pop_back()      removes the last element in the vector, effectively reducing the container size by one
vector::erase()         removes from the vector either a single element ( position ) or a range of elements ( [first,last) )
vector::clear()         removes all elements
vector::assign()        assigns new contents, replacing its current contents, and modifying its size accordingly
*/

#include <vector>
void vector_examples() {
    cout << "vector examples:\n";
    vector<int> a = {101, 102, 103};
    for (auto i : a)
        cout << "1: " << i << "\n";
    a.back() = 104;
    a.insert(a.begin()+1, 200);
    a.push_back(105);
    for (int i = 0; i < a.size(); i++)
        cout << "2: " << a[i] << "\n";
    a.erase(a.begin(), a.begin() +3);
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
        cout << "3: " << *i << "\n";
}


/*
http://www.cplusplus.com/reference/map/
map:        ordered, unique keys, implemented using Red-Black tree
            insert / erase / find O(log N)
multimap:   similar to map except multiple elements can have equivalent keys

map<type, type> name {{key1, value1}, {key2, value2}, ...}
map<type, type>::iterator

map::begin() / map::end() / map::rbegin() / map::rend()

map::empty() / map::size()

map::insert(pair<type, type>(key, val))
map::erase(iterator position / const key_type& / iterator first, iterator last)
    removes a single element / removes all elements with target key / elements in range[first, last)
map::clear()

map::find(const key_type&)              returns an iterator to the element, map::end() if key is not found
map::count(const key_type&)             returns 1 if the element is found or 0 otherwise
map::lower_bound(const key_type&)       returns an iterator to the first element in the container whose key >= target key
map::upper_bound(const key_type&)       returns an iterator to the first element in the container whose key > target key
map::equal_range(const key_type&)       returns pair<map::lower_bound, map::upper_bound>
*/

#include <map>
void map_examples() {
    cout << "map examples:\n";
    map<char, int> a = {{'a', 1}, {'b', 2}, {'c', 3}};
    a.erase('b');
    a['d'] = 4;
    a.insert(pair<char, int>('z', 26));
    cout << "key 'e': count " << a.count('e') << ", value " << a['e'] << "\n";
    for (map<char, int>::iterator it = a.begin(); it != a.end(); it++)
        cout << it->first << " => " << it->second << "\n";

    cout << "multimap examples:\n";
    multimap<char, int> ma = {{'a', 1}, {'b', 1}, {'b', 2}, {'c', 3}};
    auto range = ma.equal_range('b');
    cout << "key 'b' range:" << range.first->first << " => " << range.first->second << "\n";
    cout << "              " << range.second->first << " => " << range.second->second << "\n";
    ma.erase('b');
    for (multimap<char, int>::iterator it = ma.begin(); it != ma.end(); it++)
        cout << it->first << " => " << it->second << "\n";
}


/*
http://www.cplusplus.com/reference/set/
set:        similar to map except value is also the key
multiset:   similar to multimap except value is also the key
*/
#include <set>
void set_examples() {
}


int main() {
    vector_examples();
    map_examples();
    set_examples();
}
