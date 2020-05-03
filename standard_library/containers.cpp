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

vector<type> variable_name (number_of_elements)
vector<type> variable_name {element1, element2, ...}
vector<type>::iterator iterator_name

vector::begin()         returns an iterator to point at the first element of a C++ vector
vector::end()           returns an iterator to point at past-the-end element of a C++ vector
vector::rbegin()        return reverse iterator to reverse beginning
vector::rend()          return reverse iterator to reverse end

vector::empty()         returns whether the vector is empty (i.e. whether its size is 0)
vector::size()          returns the number of elements in the vector

vector::front()         returns a reference to the first element in the vector
vector::back()          returns a reference to the last element in the vector
vector::push_back()     adds a new element after its current last element
vector::insert()        inserts new elements to a specified location
vector::pop_back()      removes the last element in the vector, effectively reducing the container size by one
vector::erase()         removes from the vector either a single element ( position ) or a range of elements ( [first,last) )
vector::clear()         removes all elements
*/

#include <vector>
void vector_examples() {
    cout << "Vector Examples:\n";
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
http://www.cplusplus.com/reference/map/map/

map<type, type> variable_name {{key1, value1}, {key2, value2}, ...}
map<type, type>::iterator iterator_name

map::begin() / map::end() / map::rbegin() / map::rend()

map::empty() / map::size()

map::insert(pair<type, type>(key, val))
map::erase(iterator position / const key_type& / iterator first, iterator last)   removes a single element or [first, last)
map::clear()

map::find(const key_type&)          returns an iterator to the element
map::count(const key_type&)         returns 1 if the element is found or 0 otherwise
*/

#include <map>
void map_examples() {
    cout << "Map Examples:\n";
    map<char, int> a = {{'a', 1}, {'b', 2}, {'c', 3}};
    a.erase('b');
    a['d'] = 4;
    a.insert(pair<char, int>('z', 26));
    for (map<char, int>::iterator it = a.begin(); it != a.end(); it++)
        cout << it->first << " => " << it->second << "\n";
    cout << "a['e'] count: " << a.count('e') << ", value: " << a['e'] << "\n";
}


int main() {
    vector_examples();
    map_examples();
}
