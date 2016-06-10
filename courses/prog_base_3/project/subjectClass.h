#ifndef SUBJECTCLASS_H_INCLUDED
#define SUBJECTCLASS_H_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Subject
{
public:
    float width, height, speed_x, speed_y, speed, x, y, moveTime;
    bool life, movement, gravity;
    int health;
    Texture texture;
    Sprite sprite;
    string name;

    Subject(Image &image, float X, float Y,int Width,int Height, string Name);
};

#endif // SUBJECTCLASS_H_INCLUDED
