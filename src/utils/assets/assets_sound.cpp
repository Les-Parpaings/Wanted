
#include "utils/utils.hpp"
#include <filesystem>
#include <cstring>
#include <map>

namespace fs = std::filesystem;
namespace utils {

Sounds::Sounds()
{
    std::string name;
    std::string path;
    size_t len = 0;
    bool err = false;

    m_buffer["none"] = sf::SoundBuffer();
    m_sound["none"] = sf::Sound();

    for (const auto &entry : fs::recursive_directory_iterator(DIR_SOUND)) {
        if (entry.is_regular_file()) {

            name = entry.path().string();
            len = name.length() - strlen(DIR_SOUND);
            name.erase(name.begin(), name.end() - len);
            if (name == ".gitkeep")
                continue;
            name.erase(name.end() - strlen(EXT_SOUND), name.end());
            path = std::string(DIR_SOUND + name + EXT_SOUND);

            m_buffer[name] = sf::SoundBuffer();
            err = m_buffer[name].loadFromFile(path);
            if (err == false) {
                m_buffer.erase(name);
            } else {
                m_sound[name] = sf::Sound();
                m_sound[name].setBuffer(m_buffer[name]);
            }

            name.clear();
            path.clear();
            len = 0;
            err = false;
        }
    }
}

Sounds::~Sounds()
{
    m_buffer.clear();
    // m_sound.clear();
}

sf::SoundBuffer &Sounds::getBuffer(std::string name)
{
    std::map<std::string, sf::SoundBuffer>::iterator it;

    it = m_buffer.find(name);
    if (it == m_buffer.end()) {
        return m_buffer["none"];
    } else {
        return it->second;
    }
}

sf::Sound &Sounds::getSound(std::string name)
{
    std::map<std::string, sf::Sound>::iterator it;

    it = m_sound.find(name);
    if (it == m_sound.end()) {
        return m_sound["none"];
    } else {
        return it->second;
    }
}

void Sounds::play(std::string name)
{
    auto it = m_sound.find(name);
    if (it != m_sound.end()) {
        it->second.play();
    }
}

}
