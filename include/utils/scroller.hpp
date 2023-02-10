
#pragma once

namespace utils {

typedef struct scrollDiff {
    int min;
    int max;
    int diff;
} scrollDiff;

    #define HORIZONTAL      0
    #define VERTICAL        1

class Scroller : public Button
{
    public:
        Scroller();
        void create(sf::Texture &texture, sf::IntRect rect, ButtonRect rect_info, sf::Vector2f pos, int direction, int pos_min, int pos_max, int value_min, int value_max, int value_result);
        void createBackground(sf::Texture &texture, sf::IntRect rect_side, sf::IntRect rect_bar);
        void createText(sf::Font &font, sf::Vector2f pos);
        virtual void draw(sf::RenderWindow &window);
        void getEvent(sf::RenderWindow &window);
        void getEvent(sf::RenderWindow &window, sf::View &view);
        void setCursorPosition(float x, bool create = false);
        void setCursorValue();
        int getResult() const;
        void changeMaxPos(int value);
        void changeMaxValue(int value);
        scrollDiff getPosInfo() const;
        scrollDiff getValueInfo() const;
        virtual ~Scroller();

    private:
        sf::Sprite *left;
        sf::Sprite *right;
        sf::Sprite *bar;
        sf::String str;

        int direction;
        scrollDiff pos;
        scrollDiff value;
        int result;

        sf::Clock clock;

        void getEventScroller(sf::RenderWindow &window);
};

};
