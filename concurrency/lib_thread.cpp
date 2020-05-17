/*
http://www.cplusplus.com/reference/thread/thread/

thread name(Fn, Args)

thread::detach()                detaches the thread from the calling thread, allowing them to execute independently
thread::join()				    the function returns when the thread execution has completed
thread::joinable()			    returns whether the thread object is joinable
thread::hardware_concurrency()  [static] returns the number of hardware thread contexts

namespace std::this_thread
this_thread::get_id()			returns the thread id of the calling thread
this_thread::sleep_until()		blocks the calling thread until abs_time
this_thread::sleep_for()		blocks the calling thread during the span of time specified by rel_time
*/

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
    std::cout << std::this_thread::get_id() << ": finished work in threadFunction\n";
}

class threadClass {
public:
    void operator()() { std::cout << std::this_thread::get_id() << ": threadClass object has been created\n"; }
};

int main()
{
    std::cout << "Number of hardware thread contexts: " << std::thread::hardware_concurrency() << "\n";
    std::vector<std::thread> threads;

    // create thread with function
    std::thread t(threadFunction);
    threads.push_back(std::move(t));

    // create thread with function objects
    // std::thread t0(Vehicle()) would be interpreted as a function t0 with input Vehicle() and output std::thread
    std::thread t1( (threadClass()) );              // Add an extra pair of parantheses
    std::thread t2 = std::thread( threadClass() );  // Use copy initialization
    std::thread t3{ threadClass() };                // Use uniform initialization with braces
    threads.push_back(std::move(t1)); threads.push_back(std::move(t2)); threads.push_back(std::move(t3));

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(20)); // simulate work
    std::cout << std::this_thread::get_id() << ": finished work in main\n";

    for (auto& it : threads) it.join();
}
