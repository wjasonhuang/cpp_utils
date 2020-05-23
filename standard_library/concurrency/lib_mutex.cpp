/*
http://www.cplusplus.com/reference/mutex/

std::mutex
std::recursive_mutex            allows the same thread to acquire multiple levels of ownership (used in recursive functions)
mutex::lock()                   the calling thread locks the mutex, blocking if necessary
mutex::try_lock()               attempts to lock without blocking, returns false if currently locked by another thread
mutex::unlock()                 unlocks the mutex, releasing ownership over it

std::timed_mutex                supports timed try-lock requests
std::recursive_timed_mutex()    combines the features of recursive_mutex and timed_mutex
timed_mutex::lock()
timed_mutex::try_lock()
timed_mutex::try_lock_for()     attempts to lock the timed_mutex, blocking for rel_time at most
timed_mutex::try_lock_until()   attempts to lock the timed_mutex, blocking until abs_time at most
timed_mutex::unlock()

std::lock_guard<mutex_type>     locked only once by the calling thread on construction and unlocked on destruction
lock_guard(mutex_type& m)                      the object manages m, and locks it (by calling m.lock())
lock_guard(mutex_type& m, std::adopt_lock)     the object manages m, which is currently locked by the constructing thread

std::unique_lock<mutex_type>    std::lock_guard + mutex features + allow different locking strategies + transfer ownership with std::move

std::adopt_lock                 do not lock on construction, assuming instead that it is already locked
std::defer_lock                 do not lock on construction, initializing them as not owning a lock
std::try_to_lock                attempt to lock by calling its try_lock member instead of its lock member

std::lock                       locks all the objects passed as arguments using an unspecified sequence, blocking if necessary

*/

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex1, mutex2;

void ThreadA() {
    std::lock(mutex2, mutex1);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
    std::cout << "Thread A" << std::endl;
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
}

void ThreadB() {
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::cout << "Thread B" << std::endl;
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
}

int main() {
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);
    t1.join();
    t2.join();
    std::cout << "Finished" << std::endl;
}
