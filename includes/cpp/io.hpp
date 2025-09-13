#ifndef CPP_IO_HPP
#define CPP_IO_HPP

#include <iostream>
#include <fstream>        // For ifstream, ofstream, filebuf
#include <print>          // For std::print, std::println
#include <format>         // For std::format, std::vformat
#include <filesystem>     // For file system operations
#include <ios>            // For std::ios_base, std::ios
#include <iomanip>        // For output manipulators
#include <streambuf>      // For std::streambuf (explicit inclusion)

namespace cpp::io {
    // Standard I/O streams
    using std::cout;
    using std::cerr;
    using std::cin;
    using std::endl;
    using std::flush;

    // Stream classes
    using std::ostream;
    using std::istream;
    using std::ifstream;
    using std::ofstream;
    using std::stringstream;
    using std::istringstream;
    using std::ostringstream;

    // Buffer-related
    using std::streambuf;
    using std::filebuf;

    // Formatting and printing
    using std::print;
    using std::println;
    using std::format;
    using std::vformat;

    // Stream manipulators (from <iomanip>)
    using std::setw;
    using std::setprecision;
    using std::fixed;
    using std::scientific;
    using std::hex;
    using std::oct;
    using std::dec;
    using std::left;
    using std::right;
    using std::internal;

    // Stream state and flags (from <ios>)
    using std::ios_base;
    using std::ios;

    // I/O synchronization control
    using std::sync_with_stdio;
    using std::tie;
}

#endif // CPP_IO_HPP