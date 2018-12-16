#include <world/block/block_database.hpp>

BlockDatabase::BlockDatabase()
: texture_atlas("DefaultPack")
{
    blocks[(unsigned)BlockId::Air] = std::make_unique<DefaultBlock>("Air");
    blocks[(unsigned)BlockId::Grass] = std::make_unique<DefaultBlock>("Grass");
    blocks[(unsigned)BlockId::Dirt] = std::make_unique<DefaultBlock>("Dirt");
    blocks[(unsigned)BlockId::Stone] = std::make_unique<DefaultBlock>("Stone");
}

BlockDatabase &BlockDatabase::get()
{
    static BlockDatabase db;
    return db;
}

const BlockType &BlockDatabase::get_block(BlockId id) const
{
    return *blocks[(unsigned) id];
}

const BlockData &BlockDatabase::get_data(BlockId id) const
{
    return get_block(id).get_data();
}