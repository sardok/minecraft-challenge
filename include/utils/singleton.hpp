#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include <utils/non_movable.hpp>
#include <utils/non_copyable.hpp>

class Singleton : public NonCopyable, public NonMovable
{

};
#endif