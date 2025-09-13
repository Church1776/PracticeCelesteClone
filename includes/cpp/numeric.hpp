#ifndef CPP_NUMERIC_HPP
#define CPP_NUMERIC_HPP

#include <numeric>
#include <cmath>
#include <bit>
#include <bitset>
#include <complex>
#include <numbers>
#include <ratio>
#include <valarray>
#include <limits>

namespace cpp::numeric {
    using std::accumulate;
    using std::inner_product;
    using std::gcd;
    using std::lcm;
    using std::abs;
    using std::sqrt;
    using std::lerp;
    using std::midpoint;
    using std::bit_cast;
    using std::popcount;
    using std::bitset;
    using std::complex;
    using std::numbers::pi;
    using std::numbers::e;
    using std::ratio;
    using std::ratio_add;
    using std::sin;
    using std::cos;
    using std::exp;
    using std::log;
    using std::pow;
    using std::numbers::sqrt2;
    using std::numbers::phi;
    using std::reduce;
    using std::transform_reduce;
    using std::valarray;
    using std::slice;
    using std::numeric_limits;
}

#endif//CPP_NUMERIC_HPP