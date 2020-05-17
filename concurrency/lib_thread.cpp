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

void threadFunction1() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
    std::cout << std::this_thread::get_id() << ": finished work in threadFunction1\n";
}

void threadFunction2(int id, int& ret) {
    std::this_thread::sleep_for(std::chrono::milliseconds(20)); // simulate work
    std::cout << id << ": finished work in threadFunction2\n";
    ret += 5;
}

class threadClass {
public:
    void operator()() { std::cout << std::this_thread::get_id() << ": threadClass object has been created\n"; }
};

int main()
{
    int ret = 0;

    std::cout << "Number of hardware thread contexts: " << std::thread::hardware_concurrency() << "\n";
    std::vector<std::thread> threads;

    // create thread with function
    std::thread tf1(threadFunction1);
    threads.push_back(std::move(tf1));
    std::thread tf2(threadFunction2, 77, std::ref(ret));    // need to mark explicitly using std::ref when passing by reference
    threads.push_back(std::move(tf2));

    // create thread with function objects
    // std::thread t(Vehicle()) would be interpreted as a regular function named t
    std::thread t1( (threadClass()) );              // Add an extra pair of parantheses
    std::thread t2 = std::thread( threadClass() );  // Use copy initialization
    std::thread t3{ threadClass() };                // Use uniform initialization with braces
    threads.push_back(std::move(t1)); threads.push_back(std::move(t2)); threads.push_back(std::move(t3));

    for (auto& it : threads) it.join();
    std::cout << "ret = " << ret << "\n";
}
