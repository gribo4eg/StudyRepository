#ifndef ENEMYCLASS_H_INCLUDED
#define ENEMYCLASS_H_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
public:
    float width, heigth, speed_x, speed_y, speed, x, y;
    float moveTime;
    bool life;
    int health;
    std::string name;
    Texture texture;
    Sprite sprite;

    Enemy(sf::Image &image, float X, float Y,
              float Width, float Height, std::string Name);

    void interactiveWithMap(float dx, float dy);
    void position(float time);

};

#endif // ENEMYCLASS_H_INCLUDED
