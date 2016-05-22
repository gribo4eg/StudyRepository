#ifndef CREATURES_H
#define CREATURES_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Creatures
{
private:
    float x, y;
public:
    float width, heigth, speed_x, speed_y, speed;
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
        speed = 0; speed_x = 0;
        speed_y = 0;
        x = X;
        y = Y;
        width = Width;
        heigth = Height;
        image.loadFromFile("images/" + imageName);
        image.createMaskFromColor(Color(255, 255, 255));

        texture.loadFromImage(image);

        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, width, heigth));
        sprite.setPosition(x, y);
        sprite.setScale(0.4, 0.4);
    }

    void position(float time)
    {
        switch(direction)
        {
        case 0:
            speed_x = speed;
            speed_y = 0;
            break;
        case 1:
            speed_x = -speed;
            speed_y = 0;
            break;
        case 2:
            speed_x = 0;
            speed_y = speed;
            break;
        case 3:
            speed_x = 0;
            speed_y = -speed;
            break;
        }

        x += speed_x * time;
        y += speed_y * time;

        speed = 0;
        sprite.setPosition(x, y);
    }

    float getPlayerCoordX()
    {
        return x;
    }

    float getPlayerCoordY()
    {
        return y;
    }

};
#endif // CREATURES_H