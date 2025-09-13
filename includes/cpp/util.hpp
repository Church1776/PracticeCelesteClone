#ifndef CPP_UTIL_HPP
#define CPP_UTIL_HPP

#include <utility>
#include <functional>
#include <tuple>

namespace cpp::util {
    using std::move;
    using std::forward;
    using std::pair;
    using std::function;
    using std::make_pair;
    using std::tuple;
    using std::get;
    using std::bind;
    using std::invoke;
    using std::move_if_noexcept;
    using std::is_same;
    using std::conditional;
    using std::enable_if;
}

#endif//CPP_UTIL_HPP