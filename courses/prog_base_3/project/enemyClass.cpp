#include <SFML/Graphics.hpp>
#include "enemyClass.h"
#include "subjectClass.h"
#include "map.h"

using namespace std;
using namespace sf;

Enemy::Enemy(sf::Image &image, float X, float Y,
              float Width, float Height, string Name):
                  Subject(image, X, Y, Width, Height, Name)
{
    sprite.setTextureRect(IntRect(0, 0, width, height));
    speed_x = 0.1;
}

void Enemy::interactiveWithMap(float dx, float dy)
{
    for(int i = y/32; i < (y + height)/32; i++)
        {
            for(int j = x/32; j < (x + width)/32; j++)
            {
              /*  if(MyTileMap[i][j] == '0')
                {
                    if(dy > 0){
                        y = i*32 - height;
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
                }*/
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

    sprite.setPosition(x + width/2, y + height/2);
    if(health <=0)
        life = false;

}
