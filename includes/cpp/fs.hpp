#ifndef CPP_FS_HPP
#define CPP_FS_HPP

#include <filesystem>

namespace cpp::fs {
    using std::filesystem::path;
    using std::filesystem::directory_entry;
    using std::filesystem::exists;
    using std::filesystem::create_directory;
    using std::filesystem::create_directories;
    using std::filesystem::remove;
    using std::filesystem::file_size;
    using std::filesystem::directory_iterator;
    using std::filesystem::recursive_directory_iterator;
    using std::filesystem::copy;
    using std::filesystem::file_status;
    using std::filesystem::remove_all;
    using std::filesystem::rename;
    using std::filesystem::last_write_time;
}

#endif//CPP_FS_HPP
