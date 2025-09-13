#ifndef CPP_RANDOM_HPP
#define CPP_RANDOM_HPP

#include <random>

namespace cpp::random {
    using std::mt19937;
    using std::uniform_int_distribution;
    using std::uniform_real_distribution;
    using std::default_random_engine;
    using std::random_device;
    using std::normal_distribution;
    using std::bernoulli_distribution;
    using std::generate_canonical;
}

#endif//CPP_RANDOM_HPP