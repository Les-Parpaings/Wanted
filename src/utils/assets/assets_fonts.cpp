
#include "utils/utils.hpp"
#include <filesystem>
#include <cstring>
#include <map>

namespace fs = std::filesystem;
namespace utils {

Fonts::Fonts()
{
    std::string name;
    std::string path;
    size_t len = 0;
    bool err = false;

    m_font["none"] = sf::Font();

    for (const auto &entry : fs::recursive_directory_iterator(DIR_FONT)) {
        if (entry.is_regular_file()) {

            name = entry.path().string();
            len = name.length() - strlen(DIR_FONT);
            name.erase(name.begin(), name.end() - len);
            if (name == ".gitkeep")
                continue;
            name.erase(name.end() - strlen(EXT_FONT), name.end());
            path = std::string(DIR_FONT + name + EXT_FONT);

            m_font[name] = sf::Font();
            err = m_font[name].loadFromFile(path);
            if (err == false) {
                m_font.erase(name);
            }

            name.clear();
            path.clear();
            len = 0;
            err = false;
        }
    }
}

Fonts::~Fonts()
{
    m_font.clear();
}

sf::Font &Fonts::getFont(std::string name)
{
    auto it = m_font.find(name);
    if (it == m_font.end()) {
        return m_font["none"];
    } else {
        return it->second;
    }
}

}
