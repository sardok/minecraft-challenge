#include <world/block/types/block_type.hpp>

BlockType::BlockType(const std::string &filename)
    : data(filename)
{
}

const BlockData &BlockType::get_data() const
{
    return data;
}