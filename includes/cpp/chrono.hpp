#ifndef CPP_CHRONO_HPP
#define CPP_CHRONO_HPP

#include <chrono>

namespace cpp::chrono {
    using std::chrono::steady_clock;
    using std::chrono::system_clock;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    using std::chrono::seconds;
    using std::chrono::time_point;
    using std::chrono::high_resolution_clock;
    using std::chrono::minutes;
    using std::chrono::hours;
    using std::chrono::duration_cast;
    using std::chrono::floor;
    using std::chrono::ceil;
}

#endif//CPP_CHRONO_HPP