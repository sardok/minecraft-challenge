#include <utils/file_utils.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string get_file_contents(const std::string &file_path)
{
    std::ifstream in_file(file_path);
    if (!in_file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + file_path);
    }

    std::stringstream stream;
    stream << in_file.rdbuf();
    return stream.str();
}