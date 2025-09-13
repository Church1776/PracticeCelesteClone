#ifndef CPP_THREAD_HPP
#define CPP_THREAD_HPP

#include <thread>
#include <mutex>
#include <atomic>

namespace cpp::thread {
    using std::thread;
    using std::mutex;
    using std::lock_guard;
    using std::unique_lock;
    using std::atomic;
    using std::this_thread::sleep_for;
    using std::jthread;
    using std::stop_token;
    using std::condition_variable;
    using std::notify_all_at_thread_exit;
    using std::future;
    using std::promise;
    using std::async;
}

#endif//CPP_THREAD_HPP