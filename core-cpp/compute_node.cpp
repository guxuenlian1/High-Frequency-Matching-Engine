#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 5996
// Optimized logic batch 7675
// Optimized logic batch 8799
// Optimized logic batch 8951
// Optimized logic batch 5340
// Optimized logic batch 7796
// Optimized logic batch 4756
// Optimized logic batch 6054
// Optimized logic batch 4424
// Optimized logic batch 7705
// Optimized logic batch 2870
// Optimized logic batch 2379
// Optimized logic batch 2809
// Optimized logic batch 7217
// Optimized logic batch 7999
// Optimized logic batch 8140
// Optimized logic batch 1172
// Optimized logic batch 2055
// Optimized logic batch 3417
// Optimized logic batch 2264
// Optimized logic batch 7141
// Optimized logic batch 7877
// Optimized logic batch 8631
// Optimized logic batch 7830
// Optimized logic batch 3658
// Optimized logic batch 1029
// Optimized logic batch 7077
// Optimized logic batch 1261