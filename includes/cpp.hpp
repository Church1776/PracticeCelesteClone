#ifndef CPP_HPP
#define CPP_HPP

#include "cpp/cstdlib.hpp"
#include "cpp/io.hpp"
#include "cpp/string.hpp"
#include "cpp/containers.hpp"
#include "cpp/memory.hpp"
#include "cpp/util.hpp"
#include "cpp/iterator.hpp"
#include "cpp/optional.hpp"
#include "cpp/chrono.hpp"
#include "cpp/thread.hpp"
#include "cpp/algo.hpp"
#include "cpp/fs.hpp"
#include "cpp/random.hpp"
#include "cpp/numeric.hpp"
#include "cpp/regex.hpp"
#include "cpp/concepts.hpp"
#include "cpp/variant.hpp"
#include "cpp/valarray.hpp"
#include "cpp/coroutine.hpp"
#include "cpp/expected.hpp"
#include "cpp/cctype.hpp"
#include "cpp/cstring.hpp"
#include "cpp/clocale.hpp"
#include "cpp/cwchar.hpp"
#include "cpp/cwctype.hpp"
#include "cpp/cassert.hpp"
#include "cpp/cerrno.hpp"
#include "cpp/cinttypes.hpp"
#include "cpp/climits.hpp"
#include "cpp/cfloat.hpp"
#include "cpp/cstdint.hpp"
#include "cpp/cstdio.hpp"
#include "cpp/ctime.hpp"
#include "cpp/cstdarg.hpp"
#include "cpp/cstddef.hpp"
#include "cpp/charconv.hpp"
#include "cpp/functional.hpp"
#include "cpp/clocale.hpp"
#include "cpp/cwchar.hpp"
#include "cpp/cwctype.hpp"
#include "cpp/cassert.hpp"
#include "cpp/cerrno.hpp"
#include "cpp/cinttypes.hpp"
#include "cpp/climits.hpp"
#include "cpp/cfloat.hpp"
#include "cpp/cstdint.hpp"
#include "cpp/cstdio.hpp"
#include "cpp/ctime.hpp"
#include "cpp/cstdarg.hpp"
#include "cpp/cstddef.hpp"

// Unified namespace for all features
namespace cpp {
    using namespace cpp::clib;
    using namespace cpp::ios;
    using namespace cpp::strings;
    using namespace cpp::containers;
    using namespace cpp::mem;
    using namespace cpp::utilities;
    using namespace cpp::time;
    using namespace cpp::concurrency;
    using namespace cpp::numerics;
    using namespace cpp::types;
    using namespace cpp::variants;
    using namespace cpp::regex;
    using namespace cpp::diagnostics;
    using namespace cpp::localization;
    using namespace cpp::args;
}

// General Purpose C Library Utilities
namespace cpp::clib {
    using namespace cpp::library;
}

// Category: I/O Systems (I/O & file system operations)
namespace cpp::ios {
    using namespace cpp::io;
    using namespace cpp::cstdio;
    using namespace cpp::fs;
}

// Category: Strings (string and character handling)
namespace cpp::strings {
    using namespace cpp::string;
    using namespace cpp::cstring;
    using namespace cpp::charconv;
    using namespace cpp::cctype;
    using namespace cpp::cwchar;
    using namespace cpp::cwctype;
}

// Category: Containers (data structures and iterators)
namespace cpp::containers {
    using namespace cpp::containers;
    using namespace cpp::iterator;
}

// Category: mem (memory management)
namespace cpp::mem {
    using namespace cpp::memory;
}

// Category: Utilities (algorithms, utilities, and function objects)
namespace cpp::utilities {
    using namespace cpp::util;
    using namespace cpp::algo;
    using namespace cpp::funcional;
}

// Category: Time (time-related operations)
namespace cpp::time {
    using namespace cpp::chrono;
    using namespace cpp::ctime;
}

// Category: Concurrency (threading and coroutines)
namespace cpp::concurrency {
    using namespace cpp::thread;
    using namespace cpp::coroutine;
}

// Category: Numerics (numerical computations and random numbers)
namespace cpp::numerics {
    using namespace cpp::numeric;
    using namespace cpp::random;
    using namespace cpp::valarray;
}

// Category: Types (type traits, concepts, and type definitions)
namespace cpp::types {
    using namespace cpp::concepts;
    using namespace cpp::cinttypes;
    using namespace cpp::climits;
    using namespace cpp::cfloat;
    using namespace cpp::cstdint;
    using namespace cpp::cstddef;
}

// Category: Variants (optional, variant, and expected types)
namespace cpp::variants {
    using namespace cpp::optional;
    using namespace cpp::variant;
    using namespace cpp::expected;
}

// Category: Regex (regular expressions)
namespace cpp::regex {
    using namespace cpp::regex;
}

// Category: Diagnostics (error handling and assertions)
namespace cpp::diagnostics {
    using namespace cpp::cerrno;
    using namespace cpp::cassert;
}

// Category: Localization (locale-specific operations)
namespace cpp::localization {
    using namespace cpp::clocale;
}

// Category: Args (variable arguments)
namespace cpp::args {
    using namespace cpp::cstdarg;
}



#endif//CPP_HPP



