#ifndef UTILS_NON_COPYABLE_HPP
#define UTILS_NON_COPYABLE_HPP

struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable & operator=(const NonCopyable &) = delete;
};
#endif