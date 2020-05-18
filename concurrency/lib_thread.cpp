/*
http://www.cplusplus.com/reference/thread/thread/

thread name(fn, args)

thread::detach()                detaches the thread from the calling thread, allowing them to execute independently
thread::join()                  the function returns when the thread execution has completed
thread::joinable()              returns whether the thread object is joinable
thread::hardware_concurrency()  [static] returns the number of hardware thread contexts

namespace std::this_thread
this_thread::get_id()           returns the thread id of the calling thread
this_thread::sleep_until()      blocks the calling thread until abs_time
this_thread::sleep_for()        blocks the calling thread during the span of time specified by rel_time
*/

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void by_function() {
    std::cout << "\nExamples of starting threads with function\n";
    std::thread tf1([](){
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
        std::cout << std::this_thread::get_id() << ": finished work in thread function 1\n";
    });
    int ret = 0;
    std::thread tf2([](auto id, int& ret) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // simulate work
        std::cout << id << ": finished work in thread function 2\n";
        ret += 5;
    }, std::this_thread::get_id(), std::ref(ret));    // need to mark explicitly using std::ref when passing by reference
    tf1.join(); tf2.join();
    std::cout << "ret = " << ret << "\n\n";
}

class threadClass {
public:
    threadClass() : _id(0) {}
    void addId(int id) { _id = id; }
    void operator()() { std::cout << std::this_thread::get_id() << ": threadClass object has been created\n"; }
    void printId() { std::cout << "threadClass id = " << _id << std::endl; }

private:
    int _id;
};

void by_class() {
    std::cout << "\nExamples of starting threads with class\n";
    std::vector<std::thread> threads;

    // create thread with function objects
    // std::thread t(Vehicle()) would be interpreted as a regular function named t
    std::thread t1( (threadClass()) );              // Add an extra pair of parantheses
    std::thread t2 = std::thread( threadClass() );  // Use copy initialization
    std::thread t3{ threadClass() };                // Use uniform initialization with braces
    threads.push_back(std::move(t1)); threads.push_back(std::move(t2)); threads.push_back(std::move(t3));

    threadClass tc1, tc2;
    std::shared_ptr<threadClass> tc3(new threadClass);
    // remember to pass an instance of class first then arguments of the class member function
    threads.emplace_back(std::thread(&threadClass::addId, tc1, 1));
    threads.emplace_back(std::thread(&threadClass::addId, &tc2, 2));
    threads.emplace_back(std::thread(&threadClass::addId, tc3, 3));

    for (auto& t : threads) t.join();
    tc1.printId();
    tc2.printId();
    tc3->printId();
}

int main()
{
    std::cout << "Number of hardware thread contexts: " << std::thread::hardware_concurrency() << "\n";
    by_function();
    by_class();
}
