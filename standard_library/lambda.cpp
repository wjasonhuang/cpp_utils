/*
Lambda Expressions

A lambda formally consists of three parts: a capture list [] , a parameter list () and a main part {}
[]          allows variables outside of lambda to be accessed
()          parameters passed to lambda, identical to calling a regular function
mutable     allows to modify the parameters captured by copy
*/

#include <iostream>
using namespace std;

int main() {
    int id = 0;

    //auto f = []() { cout << "ID = " << id << endl; };                // Error: 'id' cannot be accessed
    //auto f = [id]() { cout << "ID = " << ++id << endl; };            // Error, 'id' may not be modified
    auto f1 = [id]() { cout << "ID = " << id << endl; };               // OK, 'id' is captured by value
    auto f2 = [&id]() { id += 5; cout << "ID = " << id << endl; };     // OK, 'id' is captured by reference
    auto f3 = [id]() mutable { cout << "ID = " << ++id << endl; };     // OK, 'id' may be modified
    auto f4 = [](int id) { cout << "ID = " << ++id << endl; };

    f1();
    f2();   // f2 can modify id and will capture changes in id
    f3();   // f3 do not capture any changes of id post declaration
    f4(id);
}
