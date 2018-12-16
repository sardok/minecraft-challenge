#ifndef NON_MOVABLE_HPP
#define NON_MOVABLE_HPP

class NonMovable
{
  public:
    NonMovable(NonMovable &&) = delete;

    NonMovable &operator=(NonMovable &&) = delete;

  protected:
    NonMovable() = default;
};
#endif