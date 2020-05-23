/*
http://www.cplusplus.com/reference/future/

std::promise<type> name     type can be void
promise::get_future()       returns a future object associated with the object's shared state
promise::set_value()        stores val as the value in the shared state, which becomes ready
promise::set_exception()    stores the exception pointer p in the shared state, which becomes ready

std::future<type> name
future::get()               returns the value stored in the shared state (or throws its exception) when the shared state is ready
future::valid()             returns whether the future object is currently associated with a shared state
future::wait()              waits for the shared state to be ready
future::wait_for()          waits for the shared state to be ready for up to the time specified by rel_time
future::wait_until()        waits for the shared state to be ready, at most until abs_time

future<type> async(fn, args) / future<type> async(launch policy, fn, args)
    calls fn (with args as arguments) at some point, returning without waiting for fn to complete
    policy: launch::async / launch::deferred
*/

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

void divideByNumber(std::promise<double> &&prms, double num, double denom) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    try {
        if (denom == 0)
            throw std::runtime_error("Exception from thread: Division by zero!");
        else
            prms.set_value(num / denom);
    }
    catch (...) {
        prms.set_exception(std::current_exception());
    }
}

void promise_future_example() {
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();
    std::thread t(divideByNumber, std::move(prms), 42, 0);

    auto status = ftr.wait_for(std::chrono::milliseconds(500));
    if (status == std::future_status::ready) { // result is ready
        try {
            double result = ftr.get();
            std::cout << "Result = " << result << std::endl;
        }
        catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
        }
    } else if (status == std::future_status::timeout || status == std::future_status::deferred) {
    // timeout has expired or function has not yet been started
        std::cout << "Result unavailable" << std::endl;
    }
    t.join();
}

double divideByNumberAsync(double num, double denom)
{
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if (denom == 0) throw std::runtime_error("Exception from thread#: Division by zero!");
    return num / denom;
}

void async_example() {
    std::cout << "\nMain thread id = " << std::this_thread::get_id() << std::endl;
    std::future<double> ftr = std::async(std::launch::deferred, divideByNumberAsync, 42, 0);

    try {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }
    catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    promise_future_example();
    async_example();
}
