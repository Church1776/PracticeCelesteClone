#ifndef CPP_MEMORY_HPP
#define CPP_MEMORY_HPP

#include <memory>
#include <memory_resource>

namespace cpp::memory {
    using std::unique_ptr;
    using std::shared_ptr;
    using std::make_unique;
    using std::make_shared;
    using std::weak_ptr;
    using std::allocate_shared;
    using std::dynamic_pointer_cast;
    using std::make_unique_for_overwrite;
    using std::make_shared_for_overwrite;
    using std::pmr::memory_resource;
    using std::pmr::polymorphic_allocator;
    using std::pmr::new_delete_resource;
}

#endif//CPP_MEMORY_HPP