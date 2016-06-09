#ifndef CREATURES_H
#define CREATURES_H

#include <SFML/Graphics.hpp>
#include "map.h"

using namespace sf;
using namespace std;

enum
{
    LEFT, RIGHT, UP, DOWN, STAY
} state;

class Creatures
{
private:
    float x, y;
public:
    float width, heigth, speed_x, speed_y, speed;
    bool life;
    int health;
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
        direction = STAY;
        score = 0;
        life = 1;
        health = 100;
        imageName = file;
        speed = 0;
        speed_x = 0;
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
        sprite.setOrigin(width/2, heigth/2);
    }

    void control()
    {
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            state = LEFT;
            speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 4)
                CurrentFrame -= 4;
            sprite.setTextureRect(IntRect(87.5 * int(CurrentFrame)+87.5, 0, -87.5, 65));

        }

        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            state = RIGHT;
            speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 4)
                CurrentFrame -= 4;
            sprite.setTextureRect(IntRect(87.5 * int(CurrentFrame), 0, 87.5, 65));

        }

        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            state = DOWN;
            speed = 0.1;
            sprite.setTextureRect(IntRect(0, 252, 55, 63));

        }

        else if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            state = UP;
            speed = 0.1;
            sprite.setTextureRect(IntRect(0, 252, 55, 63));

        }

        else if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            speed = 0;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 3)
                CurrentFrame -=3;
            if(state == RIGHT)
                sprite.setTextureRect(IntRect(91.3 * int(CurrentFrame), 130, 91.3, 78));
            else
                sprite.setTextureRect(IntRect(91.3 * int(CurrentFrame)+91.3, 130, -91.3, 78));
        }

        else
        {
            speed = 0;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 3)
                CurrentFrame -= 3;
            if(state == RIGHT)
                sprite.setTextureRect(IntRect(83.5 * int(CurrentFrame), 60, 83.5, 70));
            else //if(hero.direction == 1)
                sprite.setTextureRect(IntRect(83.5 * int(CurrentFrame)+83.5, 60, -83.5, 70));
        }

        getPlayerCoordForView(getPlayerCoordX(), getPlayerCoordY());

        if(hero.health <= 0)
            hero.life = !hero.life;
    }

    void position(float time)
    {
        switch(state)
        {
        case RIGHT:
            speed_x = speed;
            speed_y = 0;
            break;
        case LEFT:
            speed_x = -speed;
            speed_y = 0;
            break;
        case DOWN:
            speed_x = 0;
            speed_y = speed;
            break;
        case UP:
            speed_x = 0;
            speed_y = -speed;
            break;
        }

        x += speed_x * time;
        y += speed_y * time;

        speed = 0;
        sprite.setPosition(x + width/2, y + heigth/2);
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

                if(TileMap[i][j] == 's' && !Keyboard::isKeyPressed(Keyboard::Space))
                {
                    TileMap[i][j] = ' ';
                    health -= 20;
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
