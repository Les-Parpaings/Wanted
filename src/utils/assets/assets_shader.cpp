
#include "utils/utils.hpp"
#include <filesystem>
#include <cstring>
#include <map>

namespace fs = std::filesystem;
namespace utils {

Shaders::Shaders()
{
    std::string name;
    std::string path;
    size_t len = 0;
    bool err = false;

    if (!sf::Shader::isAvailable())
        return;

    for (const auto &entry : fs::recursive_directory_iterator(DIR_SHADER)) {
        if (entry.is_regular_file()) {

            name = entry.path().string();
            len = name.length() - strlen(DIR_SHADER);
            name.erase(name.begin(), name.end() - len);
            if (name == ".gitkeep")
                continue;
            name.erase(name.end() - strlen(EXT_SHADER), name.end());
            path = std::string(DIR_SHADER + name + EXT_SHADER);

            // m_shader[name] = sf::Shader();
            err = m_shader[name].loadFromFile(path, sf::Shader::Type::Fragment);
            if (err == false) {
                m_shader.erase(name);
            }

            name.clear();
            path.clear();
            len = 0;
            err = false;
        }
    }
}

Shaders::~Shaders()
{
    m_shader.clear();
}

sf::Shader &Shaders::getShader(std::string name)
{
    auto it = m_shader.find(name);
    if (it == m_shader.end()) {
        return m_shader["none"];
    } else {
        return it->second;
    }
}

void Shaders::setParameter()
{
    for (auto &it : m_shader) {
        if (it.first == "none")
            continue;
        it.second.setUniform("time", m_clock.getElapsedTime().asSeconds());
    }
}

}
