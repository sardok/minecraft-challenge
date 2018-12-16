#ifndef BLOCK_DATA_HPP
#define BLOCK_DATA_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <utils/non_copyable.hpp>


struct BlockDataHolder : public NonCopyable
{
    sf::Vector2i tex_top_coord;
    sf::Vector2i tex_side_coord;
    sf::Vector2i tex_bottom_coord;
};

class BlockData : public NonCopyable
{
  public:
    BlockData(const std::string &filename);

    const BlockDataHolder &get_block_data() const;

  private:
    BlockDataHolder data;
};
#endif