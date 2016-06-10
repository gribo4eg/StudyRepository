#include <SFML/Graphics.hpp>
#include "enemyClass.h"
#include "map.h"

using namespace std;
using namespace sf;

Enemy::Enemy(sf::Image &image, float X, float Y,
              float Width, float Height, std::string Name)
{
    x = X; y = Y; width = Width; heigth = Height;
    name = Name; moveTime = 0;
    speed = 0; health = 100; speed_x = 0; speed_y = 0;
    life = true;
    image.createMaskFromColor(Color::White);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setOrigin(width/2, heigth/2);
    sprite.setTextureRect(IntRect(0, 0, width, heigth));
    speed_x = 0.1;
}

void Enemy::interactiveWithMap(float dx, float dy)
{
    for(int i = y/32; i < (y + heigth)/32; i++)
        {
            for(int j = x/32; j < (x + width)/32; j++)
            {
                if(TileMap[i][j] == '0')
                {
                    if(dy > 0){
                        y = i*32 - heigth;
                    }
                    if(dy < 0){
                        y = i*32 + 32;
                    }
                    if(dx > 0){
                        x = j*32 - width;
                        speed_x = -0.1;
                        sprite.scale(-1, 1);
                    }
                    if(dx < 0){
                        x = j*32 + 32;
                        speed_x = 0.1;
                        sprite.scale(-1, 1);
                    }
                }
            }
        }
}

void Enemy::position(float time)
{
    moveTime += time;
    if(moveTime > 4000)
    {
        speed_x *=-1;
        moveTime = 0;
    }
    interactiveWithMap(speed_x, 0);
    x += speed_x * time;

    sprite.setPosition(x + width/2, y + heigth/2);
    if(health <=0)
        life = false;

}
