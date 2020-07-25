/*
http://www.cplusplus.com/reference/deque/
deque:      double-ended queue (implemented with a circular buffer)

extra member functions vs vector:
    deque::push_front(const value_type& val)
    deque::pop_front()
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> first;                                   // empty deque of ints
    deque<int> second(4, 100);                          // four ints with value 100
    deque<int> third(second.begin(), second.end());     // iterating through second
    deque<int> fourth(third);                           // a copy of third
    deque<int> fifth = { 101, 102, 103 };
    third.push_front(-1);
    for (auto x : third) cout << " " << x; cout << endl;
    fifth.pop_front();
    for (auto x : fifth) cout << " " << x; cout << endl;
}