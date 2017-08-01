//
// Created by kuznetsov on 30.06.17.
//

#ifndef THREADSAFE_QUEUE_H
#define THREADSAFE_QUEUE_H

#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class threadsafe_queue
{
public:
    explicit threadsafe_queue() {}
    explicit threadsafe_queue(threadsafe_queue& obj)
    {
        std::lock_guard<std::mutex> lock(obj.m);
        data = obj.data;
    }

    virtual ~threadsafe_queue() {}

    threadsafe_queue& operator=(threadsafe_queue&) = delete;

    void push(T ptr)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(ptr);
        cond_var.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(m);
        cond_var.wait(lock, [this]{ return !data.empty();} );

        auto e = data.front();
        data.pop();

        return e;
    }

private:
    std::queue<T>           data;
    mutable std::mutex      m;
    std::condition_variable cond_var;

};

#endif // THREADSAFE_QUEUE_H
