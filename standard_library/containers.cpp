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

vector::front()         returns a reference to the first element in the vector
vector::back()          returns a reference to the last element in the vector
vector::push_back()     adds a new element after its current last element
vector::insert()        inserts new elements to a specified location
vector::pop_back()      removes the last element in the vector, effectively reducing the container size by one
vector::erase()         removes from the vector either a single element ( position ) or a range of elements ( [first,last) )
vector::clear()         removes all elements

vector::begin()         returns an iterator to point at the first element of a C++ vector
vector::end()           returns an iterator to point at past-the-end element of a C++ vector

vector::empty()         returns whether the vector is empty (i.e. whether its size is 0)
vector::size()          returns the number of elements in the vector
vector::capacity()      returns the size of the storage space currently allocated for the vector, expressed in terms of elements
vector::max_size()      maximum potential size the container can reach due to known system or library implementation limitations
*/

#include <vector>

void vector_examples()
{
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

int main()
{
    vector_examples();
}
