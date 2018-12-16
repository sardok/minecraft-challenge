#ifndef BLOCK_DATABASE_HPP
#define BLOCK_DATABASE_HPP
#include <array>
#include <memory>
#include <utils/singleton.hpp>
#include <texture/texture_atlas.hpp>
#include "block_id.hpp"
#include "types/block_type.hpp"

class BlockDatabase : public Singleton
{
  public:
    static BlockDatabase &get();

    const BlockType &get_block(BlockId id) const;
    const BlockData &get_data(BlockId id) const;

    TextureAtlas texture_atlas;

  private:
    BlockDatabase();

    std::array<std::unique_ptr<BlockType>, (unsigned)BlockId::NUM_TYPES> blocks;
};
#endif