
#pragma once

namespace utils {

// *****************************************************************************
// Textures
// *****************************************************************************

    ///\brief Path of the folder with the images
    ///\return std::string of the path
    #if defined(_WIN32)
        #define DIR_IMAGE       "assets\\image\\"
    #else
        #define DIR_IMAGE       "assets/image/"
    #endif

    ///\brief Extension uses for the images files
    ///\return std::string of the extension
    #define EXT_IMAGE           ".png"

    #define TEXTURE_NONE        utils.textures.getTexture("none")

    ///\brief Get a texture
    ///\param name The name of the texture
    ///\return The indicated texture, if doesn't exist returns the default texture
    #define IMAGE(name)         utils.textures.getTexture(name)

/// \brief Class with the list of all textures in DIR_IMAGE
class Textures
{
    public:
        /// \brief Load all the textures
        Textures();

        /// \brief Get a specific texture from the list
        /// \param name The name of the texture (without the root folder and the extension)
        /// \return non const sf::Texture
        sf::Texture &getTexture(std::string name);

        ~Textures();

    private:
        std::map<std::string, sf::Texture> m_texture;
};

// *****************************************************************************
// Fonts
// *****************************************************************************

    ///\brief Path of the folder with the fonts
    ///\return std::string of the path
    #if defined(_WIN32)
        #define DIR_FONT        "assets\\font\\"
    #else
        #define DIR_FONT        "assets/font/"
    #endif

    ///\brief Extension uses for the fonts files
    ///\return std::string of the extension
    #define EXT_FONT            ".ttf"

    #define FONT_NONE           utils.fonts.getFont("none")

    ///\brief Get a font
    ///\param name The name of the font
    ///\return The indicated font, if doesn't exist returns the default font
    #define FONT(name)          utils.fonts.getFont(name)

/// \brief Class with the list of all fonts in DIR_FONT
class Fonts
{
    public:
        ///\brief Load all the fonts
        Fonts();

        /// \brief Get a specific font from the list
        /// \param name The name of the font (without the root folder and the extension)
        /// \return non const sf::Font
        sf::Font &getFont(std::string name);

        ~Fonts();

    private:
        std::map<std::string, sf::Font> m_font;
};

// *****************************************************************************
// Sounds
// *****************************************************************************

    ///\brief Path of the folder with the sounds
    ///\return std::string of the path
    #if defined(_WIN32)
        #define DIR_SOUND       "assets\\sound\\"
    #else
        #define DIR_SOUND       "assets/sound/"
    #endif

    ///\brief Extension uses for the sounds files
    ///\return std::string of the extension
    #define EXT_SOUND           ".ogg"

/// \brief Class with the list of all sounds in DIR_SOUND
class Sounds
{
    public:
        ///\brief Load all the sounds
        Sounds();

        /// \brief Get a specific sound buffer from the list
        /// \param name The name of the sound buffer (without the root folder and the extension)
        /// \return non const sf::SoundBuffer
        sf::SoundBuffer &getBuffer(std::string name);
        /// \brief Get a specific sound from the list
        /// \param name The name of the sound (without the root folder and the extension)
        /// \return non const sf::Sound
        sf::Sound &getSound(std::string name);
        /// \brief Play a specific sound from the list
        /// \param name The name of the sound (without the root folder and the extension)
        void play(std::string name);

        ~Sounds();

    private:
        std::map<std::string, sf::SoundBuffer> m_buffer;
        std::map<std::string, sf::Sound> m_sound;
};

// *****************************************************************************
// Shader
// *****************************************************************************

    ///\brief Path of the folder with the fonts
    ///\return std::string of the path
    #if defined(_WIN32)
        #define DIR_SHADER      "assets\\shader\\"
    #else
        #define DIR_SHADER      "assets/shader/"
    #endif

    ///\brief Extension uses for the fonts files
    ///\return std::string of the extension
    #define EXT_SHADER          ".frag"

/// \brief Class with the list of all fonts in DIR_FONT
class Shaders
{
    public:
        ///\brief Load all the Shaders
        Shaders();

        /// \brief Get a specific Shader from the list
        /// \param name The name of the Shader (without the root folder and the extension)
        /// \return non const sf::Shader
        sf::Shader &getShader(std::string name);
        /// \brief Set parameter for all shaders
        void setParameter();

        ~Shaders();

    private:
        std::map<std::string, sf::Shader> m_shader;
        sf::Clock m_clock;
};

}; // namespace utils
