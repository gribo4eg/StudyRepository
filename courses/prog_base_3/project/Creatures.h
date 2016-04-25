#ifndef CREATURES_H
#define CREATURES_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Creatures
{
public:
    float x, y, width, heigth, speed_x, speed;
    int direction;
    string imageName;
    Image image;
    Texture texture;
    Sprite sprite;
    //Creatures(string, float, float, float, float);

    Creatures(string file, float X, float Y,
              float Width, float Height)
    {
        direction = 0;
        imageName = file;
        speed = 0;
        speed_x = 0;
        x = X;
        y = Y;
        width = Width;
        heigth = Height;
        image.loadFromFile("images/" + imageName);
        image.createMaskFromColor(Color::White);

        texture.loadFromImage(image);

        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, this->width, this->heigth));
        sprite.setPosition(x, y);
        sprite.setScale(0.4, 0.4);
    }

    void position(float time)
    {
        switch(direction)
        {
        case 0:
            speed_x = speed;
            break;
        case 1:
            speed_x = -speed;
            break;
        }
        x += speed_x * time;

        speed = 0;
        sprite.setPosition(x, y);
    }

};
#endif // CREATURES_H
