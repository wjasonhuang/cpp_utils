/*
http://www.cplusplus.com/reference/utility/

pair<type1, type2> name
pair::first                     the first value in the pair
pair::second                    the second value in the pair
pair::swap(pr)                  exchanges the contents of the pair object with the contents of pr
operators <, >, <= and >=       compare the sequence formed by members first and second

std::swap(a, b)                 exchanges the values of a and b
std::make_pair(x, y)            constructs a pair object with its first element set to x and second set to y
*/

#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<string, double> product1;                      // default constructor
    pair<string, double> product2("tomatoes", 2.30);     // value init
    pair<string, double> product3(product2);            // copy constructor

    product1 = make_pair("light bulbs", 0.99);    // using make_pair (move)
    product2.first = "shoes";
    product2.second = 39.90;

    cout << "The price of " << product1.first << " is $" << product1.second << ".\n";
    cout << "The price of " << product2.first << " is $" << product2.second << ".\n";
    cout << "The price of " << product3.first << " is $" << product3.second << ".\n";
}
