/*
http://www.cplusplus.com/reference/thread/thread/

thread name(Fn, Args)

thread::detach()			detaches the thread from the calling thread, allowing them to execute independently
thread::join()				the function returns when the thread execution has completed
thread::joinable()			returns whether the thread object is joinable
thread::hardware_concurrency()		[static] returns the number of hardware thread contexts

namespace std::this_thread
this_thread::get_id()			returns the thread id of the calling thread
this_thread::sleep_until()		blocks the calling thread until abs_time
this_thread::sleep_for()		blocks the calling thread during the span of time specified by rel_time
*/

#include <chrono>
#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in thread\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread\n";
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(20)); // simulate work
    std::cout << "Finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::cout << "Finished work 2 in main\n";

    // wait for thread to finish
    t.detach();
    if (t.joinable()) t.join();

    std::cout << "Main pausing for 200ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return 0;
}
