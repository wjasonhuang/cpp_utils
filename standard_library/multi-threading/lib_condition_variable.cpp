/*
http://www.cplusplus.com/reference/condition_variable/

std::condition_variable
condition_variable::wait(unique_lock<mutex>& lck)                       blocked until notified
condition_variable::wait(unique_lock<mutex>& lck, Predicate pred)       the function only blocks if pred returns false
condition_variable::wait_for()                                          blocked during rel_time or until notified if the latter happens first
condition_variable::wait_until()                                        blocked either until notified or until abs_time, whichever happens first

condition_variable::notify_one()                                        unblocks one of the threads currently waiting for this condition
condition_variable::notify_all()                                        unblocks all threads currently waiting for this condition

Generally the function is notified by notify_one or notify_all, but certain implementations may produce spurious wake-up calls
 without any of these functions being called. Therefore, users shall ensure their condition for resumption is met (use Predicate).
*/

#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>

template <class T>
class MessageQueue {
public:
    T receive() {
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_messages.empty(); });
        T msg = std::move(_messages.back());
        _messages.pop_back();
        return msg; // will not be copied due to return value optimization (RVO) in C++
    }

    void send(T &&msg) {
        std::lock_guard<std::mutex> uLock(_mutex);
        std::cout << "Message " << msg << " has been sent to the queue" << std::endl;
        _messages.push_back(std::move(msg));
        _cond.notify_one();
    }

private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<T> _messages;
};

int main() {
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; i++) {
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
    }
    for (int i = 0; i < 10; i++) {
        int message = queue->receive();
        std::cout << "Message #" << message << " has been removed from the queue" << std::endl;
    }
    for (auto& ftr : futures) ftr.wait();
}
