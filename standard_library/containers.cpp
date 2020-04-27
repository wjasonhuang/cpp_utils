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


/*
http://www.cplusplus.com/reference/vector/vector/
vector<type> variable_name (number_of_elements)
vector<type> variable_name {element1, element2, ...}
vector<type>::iterator iterator_name

vector::push_back()     pushes elements from the back
vector::insert()        inserts new elements to a specified location
vector::pop_back()      removes elements from the back
vector::erase()         removes a range of elements from a specified location
vector::clear()         removes all elements

vector::begin()         returns an iterator to point at the first element of a C++ vector
vector::end()           returns an iterator to point at past-the-end element of a C++ vector

vector::size()          returns the number of elements in the vector
vector::capacity()      returns the size of the storage space currently allocated for the vector, expressed in terms of elements
vector::max_size()      maximum potential size the container can reach due to known system or library implementation limitations
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {101, 102, 103};
    for (auto i : a)
        cout << i << "\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\n";
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
        cout << *i << "\n";
}
