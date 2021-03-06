#ifndef ENEMYCLASS_H_INCLUDED
#define ENEMYCLASS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "level.h"
#include <vector>
#include "subjectClass.h"

using namespace sf;

class Enemy: public Subject
{
public:
    Enemy(Image &image, Level &level, float X, float Y, float Width, float Height);

    void interactiveWithMap(float dx, float dy);
    void position(View *view, float time);

};

#endif // ENEMYCLASS_H_INCLUDED
