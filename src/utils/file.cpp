
#include "utils/utils.hpp"
#include <fstream>

namespace utils {

// ****************************************************************************
// READ FILE
// ****************************************************************************

bool charIsSeparator(char c, std::string separator)
{
    for (auto it : separator) {
        if (c == it) {
            return true;
        }
    }
    return false;
}

void readLine(std::string &buffer, std::vector<std::string> &content, std::string separator)
{
    size_t size = buffer.size();
    std::string data;

    // check if separtor is not defined
    if (separator == "")
        separator = ",";

    for (size_t i = 0; i <= size; i++) {
        if (i == size || charIsSeparator(buffer[i], separator)) {
            content.push_back(data);
            data.clear();
        } else {
            data.push_back(buffer[i]);
        }
    }
}

std::vector<std::string> readFile(std::string path)
{
    std::vector<std::string> content;
    std::string buffer;
    std::ifstream file;

    file.open(path);
    while (getline(file, buffer)) {
        content.push_back(buffer);
    }
    file.close();

    return content;
}

// ****************************************************************************
// WRITE FILE
// ****************************************************************************

void writeLine(std::ofstream &file, std::vector<std::string> &content, char separator)
{
    size_t size = content.size();

    for (size_t i = 0; i < size; i++) {
        file << content[i];
        if (i == size - 1) {
            file << std::endl;
        } else {
            file << separator;
        }
    }
}

void writeFile(std::string path, std::vector<std::string> &content, bool trunc)
{
    std::ofstream file;

    if (trunc) {
        file.open(path, std::ios::trunc);
    } else {
        file.open(path);
    }

    for (auto &it : content) {
        file << it << std::endl;
    }
    file.close();
}

// ****************************************************************************
// GET INFO
// ****************************************************************************

template std::streampos getFileLine<std::fstream &>(std::fstream &, size_t);
template std::streampos getFileLine<std::ifstream &>(std::ifstream &, size_t);

template <typename T>
std::streampos getFileLine(T &fs, size_t line)
{
    std::string buf;
    for (size_t i = 0; i < line; i++) {
        std::getline(fs, buf);
    }
    return fs.tellg();
}

}
