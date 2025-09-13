#ifndef CPP_VARIANT_HPP
#define CPP_VARIANT_HPP

#include <variant>

namespace cpp::variant {
    using std::variant;
    using std::monostate;
    using std::visit;
    using std::get;
    using std::holds_alternative;
}

#endif//CPP_VARIANT_HPP