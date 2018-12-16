#include <fstream>
#include <exception>
#include <world/block/block_data.hpp>

BlockData::BlockData(const std::string &filename)
{
    std::ifstream in_file("res/blocks/" + filename + ".block");
    if (!in_file.is_open())
        throw std::runtime_error("Unable to open block file: " + filename);

    std::string line;
    while (std::getline(in_file, line))
    {
        if (line == "TexTop")
        {
            int x, y;
            in_file >> x >> y;
            data.tex_top_coord = {x, y};
        }
        else if (line == "TexSide")
        {
            int x, y;
            in_file >> x >> y;
            data.tex_side_coord = {x, y};
        }
        else if (line == "TexBottom")
        {
            int x, y;
            in_file >> x >> y;
            data.tex_bottom_coord = {x, y};
        }
        else if (line == "TexAll")
        {
            int x, y;
            in_file >> x >> y;
            data.tex_top_coord = {x, y};
            data.tex_side_coord = {x, y};
            data.tex_bottom_coord = {x, y};
        }
    }
}

const BlockDataHolder &BlockData::get_block_data() const
{
    return data;
}