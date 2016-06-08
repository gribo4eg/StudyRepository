#ifndef CREATURES_H
#define CREATURES_H

#include <SFML/Graphics.hpp>
#include "map.h"

using namespace sf;
using namespace std;

class Creatures
{
private:
    float x, y;
public:
    float width, heigth, speed_x, speed_y, speed;
    int direction;
    int score;
    string imageName;
    Image image;
    Texture texture;
    Sprite sprite;
    //Creatures(string, float, float, float, float);

    Creatures(string file, float X, float Y,
            float Width, float Height)      //CONSTRUCTOR
    {
        direction = 0;
        score = 0;
        imageName = file;
        speed = 0; speed_x = 0;
        speed_y = 0;
        x = X;
        y = Y;
        width = Width;
        heigth = Height;
        image.loadFromFile("images/" + imageName);
        image.createMaskFromColor(Color(102, 17, 189));

        texture.loadFromImage(image);

        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, width, heigth));
        sprite.setPosition(x, y);
        sprite.setScale(1, 1);
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
        interactiveWithMap();
    }

    void interactiveWithMap()//collision with map
    {
        for(int i = y/32; i < (y + heigth)/32; i++)
        {
            for(int j = x/32; j < (x + width)/32; j++)
            {
                if(TileMap[i][j] == '0')
                {
                    if(speed_y > 0)
                        y = i*32 - heigth;
                    if(speed_y < 0)
                        y = i*32 + 32;
                    if(speed_x > 0)
                        x = j*32 - width;
                    if(speed_x < 0)
                        x = j*32 + 32;
                }

                if(TileMap[i][j] =='s' && Keyboard::isKeyPressed(Keyboard::Space))
                {
                    TileMap[i][j] = ' ';
                    score++;
                }
            }
        }
    }

    float getPlayerCoordX()//get x coord
    {
        return x;
    }

    float getPlayerCoordY()//get y coord
    {
        return y;
    }

};
#endif // CREATURES_H
