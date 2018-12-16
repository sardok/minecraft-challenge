#ifndef BLOCK_TYPE_HPP
#define BLOCK_TYPE_HPP
#include <utils/non_copyable.hpp>
#include <world/block/block_data.hpp>

class BlockType : public NonCopyable
{
  public:
    BlockType(const std::string &filename);
    virtual ~BlockType() = default;

    const BlockData &get_data() const;

  private:
    BlockData data;
};

class DefaultBlock : public BlockType
{
  public:
    DefaultBlock(const std::string &filename)
        : BlockType(filename)
    {
    }
};
#endif