/*
http://www.cplusplus.com/reference/queue/priority_queue/
priority_queue<type> name (size_type n, const value_type& val)

priority_queue::empty()
priority_queue::size()
priority_queue::top()           Returns a constant reference to the top element in the priority_queue.
priority_queue::push(val)       Inserts a new element (val) in the priority_queue.
priority_queue::emplace(args)   Adds a new element to the priority_queue.
                                This new element is constructed in place passing args as the arguments for its constructor.
priority_queue::pop()           Removes the element on top (highest value) of the priority_queue, reducing its size by one.
priority_queue::swap(priority_queue& x)          
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int a[] = { 1, 2, 3, 4 };
    priority_queue<int> first(a, a + 4);
    while (!first.empty()) {
        cout << "first: " << first.top() << endl;
        first.pop();
    }
    priority_queue<int, vector<int>, std::greater<int>> second(a, a + 4);
    while (!second.empty()) {
        cout << "second: " << second.top() << endl;
        second.pop();
    }
}