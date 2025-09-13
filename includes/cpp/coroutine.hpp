#ifndef CPP_COROUTINE_HPP
#define CPP_COROUTINE_HPP

#include <coroutine>

namespace cpp::coroutine {
    using std::coroutine_handle;
    using std::suspend_always;
    using std::suspend_never;
    using std::noop_coroutine;
}

#endif//CPP_COROUTINE_HPP