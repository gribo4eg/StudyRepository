#ifndef ENEMYCLASS_H_INCLUDED
#define ENEMYCLASS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "subjectClass.h"

using namespace sf;

class Enemy: public Subject
{
public:
    Enemy(Image &image, float X, float Y, float Width, float Height, string Name);

    void interactiveWithMap(float dx, float dy);
    void position(float time);

};

#endif // ENEMYCLASS_H_INCLUDED
