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

Iteration               for (auto ai : a) / for (int i = 0; i < a.size(); i++) / for (auto it = a.begin(); it != a.end(); it++)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {101, 102, 103};
    vector<vector<int>> b(2, vector<int>(3, 100));
    a.back() = 104;
    a.insert(a.begin()+1, 200);
    for (auto it = a.begin(); it != a.end(); it++)
        cout << "a: " << *it << "\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cout << "b " << i << " " << j << " : " << b[i][j] << endl;
}
