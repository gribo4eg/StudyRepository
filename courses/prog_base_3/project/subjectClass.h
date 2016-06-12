#ifndef SUBJECTCLASS_H_INCLUDED
#define SUBJECTCLASS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "level.h"
#include <vector>

using namespace sf;
using namespace std;

class Subject
{
public:
    vector<Object> obj;
    float width, height, speed_x, speed_y, speed, x, y, moveTime;
    float currentFrame;
    bool life, movement, gravity, stateEnemy;
    int health;
    Texture texture;
    Sprite sprite;
    string name;

    FloatRect getRect()
    {
        return FloatRect(x, y, width, height);
    }

    Subject(Image &image, float X, float Y, float Width, float Height);

    virtual void position(View *view, float time) = 0;
};

#endif // SUBJECTCLASS_H_INCLUDED
