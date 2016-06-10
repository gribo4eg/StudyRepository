#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include <SFML/Graphics.hpp>

#include "subjectClass.h"
#include "view.h"

using namespace sf;
using namespace std;

class Player: public Subject
{
public:
    enum { LEFT, RIGHT, UP, DOWN, JUMP, STAY } state;
    int score;

    Player(Image &image, float X, float Y, float Width, float Height, string Name);

    void control();

    void position(View *view, float time);

    void interactiveWithMap(float dx, float dy);

};
#endif // PLAYERCLASS_H
