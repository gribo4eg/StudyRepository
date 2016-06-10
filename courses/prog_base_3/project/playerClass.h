#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include <SFML/Graphics.hpp>

#include "view.h"

using namespace sf;
using namespace std;

class Player
{
public:
    enum { LEFT, RIGHT, UP, DOWN, JUMP, STAY } state;
    float width, heigth, speed_x, speed_y, speed, x, y;
    bool life, gravity;
    int health;
    int score;
    string imageName;
    Image image;
    Texture texture;
    Sprite sprite;

    Player(string file, float X, float Y,
              float Width, float Height);

    void control();

    void position(View *view, float time);

    void interactiveWithMap(float dx, float dy);

};
#endif // PLAYERCLASS_H
