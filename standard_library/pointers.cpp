/*
# References & Pointers
* The symbols & and * have a different meaning, depending on which side of an equation they appear.
* References &
    * if it appears on the left side of an equation (e.g. when declaring a variable), it means that the variable is declared as a reference
    * if the & appears on the right side of an equation (e.g. before a previously defined variable), it is used to return a memory address
* Pointers *
    * a pointer can be declared by using the * operator in the declaration to store memory address, e.g. `int *i`
    * in both C and C++, the * binds to the declarator, not the type specifier, e.g. `int *p, *q, *r;`
    * to retrieve the object a pointer is pointing tomthe * symbol can be used again, e.g. `*i`
    * cp a pointer to a object, cp->func() and (*cp).func() are equivalent
*/


#include <iostream>
#include <string>


/*
http://www.cplusplus.com/reference/memory/

unique_ptr<type> name(new type)
unique_ptr::get()		returns the stored pointer points to the object managed by the unique_ptr or nullptr if empty

shared_ptr<type> name(new type)
shared_ptr::get()
shared_ptr::reset()		deletes managed object and acquires new pointer
shared_ptr::use_count()	number of shared_ptr objects that share ownership over the same pointer, 0 if empty

weak_ptr<type> name(weak_ptr or shared_ptr)
weak_ptr::expired()		returns whether the weak_ptr object is either empty or no more shared_ptr it belongs to
weak_ptr::lock()		returns a shared_ptr with the information preserved by the weak_ptr object if not expired
*/

#include <memory>

class MyClass {
private:
    std::string _text;

public:
    MyClass() {}
    MyClass(std::string text) { _text = text; }
    ~MyClass() { std::cout << _text << " destroyed" << std::endl; }
    void setText(std::string text) { _text = text; }
};

void smart_pointers_examples() {
    {
        std::unique_ptr<MyClass> myClass1(new MyClass());
        std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));
        myClass1->setText("String 1");
        *myClass1 = *myClass2;
        std::cout << "Objects have stack addresses " << myClass1.get() << " and " << myClass2.get() << std::endl;
    }

    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    }
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    shared1.reset(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    // weak pointers do not increase the reference count
    std::shared_ptr<int> mySharedPtr(new int);
    std::cout << "new shared pointer count = " << mySharedPtr.use_count() << std::endl;
    std::weak_ptr<int> myWeakPtr1(mySharedPtr);
    std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
    std::cout << "after adding weak pointers, shared pointer count = " << mySharedPtr.use_count() << std::endl;
    mySharedPtr.reset(new int);
    if (myWeakPtr2.expired()) std::cout << "weak pointer expired!" << std::endl;

    // construct a unique pointer
    std::unique_ptr<int> uniquePtr(new int);
    // (1) shared pointer from unique pointer
    std::shared_ptr<int> sharedPtr1 = std::move(uniquePtr);
    // (2) shared pointer from weak pointer
    std::weak_ptr<int> weakPtr(sharedPtr1);
    std::shared_ptr<int> sharedPtr2 = weakPtr.lock();
    // (3) raw pointer from shared (or unique) pointer
    int *rawPtr = sharedPtr2.get();
    delete rawPtr;
}


int main() {
    smart_pointers_examples();
}
