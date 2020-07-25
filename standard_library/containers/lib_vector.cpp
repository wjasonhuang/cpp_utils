/*
http://www.cplusplus.com/reference/vector/vector/

vector<type> name (size_type n, const value_type& val)
vector<type> name (const vector& x)
vector<type> name {element1, element2, ...}
vector<type>::iterator

vector::begin()         returns an iterator to point at the first element
vector::end()           returns an iterator to point at past-the-end element
vector::rbegin()        reverse iterator
vector::rend()
vector::empty()         true if size is 0
vector::size()
vector::resize()        resizes the container so that it contains n elements

vector::front()         returns a reference to the first element
vector::back()          returns a reference to the last element
vector::push_back()
vector::emplace_back()  inserts a new element (constructed in place using args as the arguments for its constructor) at the end
vector::insert()        inserts new elements to a specified location
vector::pop_back()
vector::erase()         removes from the vector either a single element ( position ) or a range of elements ( [first,last) )
vector::clear()
vector::assign()        assigns new contents, replacing its current contents, and modifying its size accordingly

iteration               for (auto ai : a) / for (int i = 0; i < a.size(); i++) / for (auto it = a.begin(); it != a.end(); it++)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {101, 102, 103};
    vector<vector<int>> b(2, vector<int>(4, 1));
    a.back() = 104;
    a.insert(a.begin()+1, 200);
    for (auto it = a.begin(); it != a.end(); it++)
        cout << "a: " << *it << "\n";
    b.resize(4, vector<int>(2, 2));
    for (int i = 0; i < b.size(); i++) {
        cout << "b " << i << ":";
        for (int j = 0; j < b[i].size(); j++)
            cout << " " << b[i][j];
        cout << endl;
    }
}
