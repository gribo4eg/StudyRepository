#include "Creatures.h"

using namespace sf;
using namespace std;

Creatures::Creatures(string file, float x, float y,
                     float width, float height)
        {
            direction = 0;
            imageName = file;
            speed = 0;
            speed_x = 0;
            this->x = x;
            this->y = y;
            this->width = width;
            this->heigth = heigth;
            image.loadFromFile("images/" + imageName);
            image.createMaskFromColor(Color::White);

            texture.loadFromImage(image);

            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, this->width, this->heigth));
            sprite.setScale(0.4, 0.4);
        }

void Creatures::position(float time)
{
    switch(direction)
    {
        case 0: speed_x = speed; break;
        case 1: speed_x = -speed; break;
    }
        x += speed_x * time;

        speed = 0;
        sprite.setPosition(x, y);
}
Creatures::~Creatures()
{
    //dtor
}

