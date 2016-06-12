#include <SFML/Graphics.hpp>
#include "playerClass.h"
#include "TinyXML/tinyxml.h"
#include "subjectClass.h"
#include "level.h"
#include <vector>

using namespace sf;

Player::Player(Image &image, Level &level, float X, float Y, float Width, float Height, string Name):
    Subject(image, X, Y, Width, Height, Name)
    {
        obj = level.GetAllObjects();
        state = STAY;
        score = 0;
        currentFrame = 0;

        sprite.setTextureRect(IntRect(0, 50, width, height));
    }

   void Player::control()
    {
        if(Keyboard::isKeyPressed){
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                state = LEFT;
                speed = 0.1;
            }

            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                state = RIGHT;
                speed = 0.1;
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                state = DOWN;
                speed = 0.2;
            }

            else if(Keyboard::isKeyPressed(Keyboard::Up) && gravity)
            {
                state = JUMP;
                speed_y = -0.6;
                gravity = false;
            }
        }
    }

   void Player::position(View *view, float time)
    {
        control();
        switch(state)
        {
        case RIGHT:
            speed_x = speed;
            //speed_y = 0;
            break;
        case LEFT:
            speed_x = -speed;
            //speed_y = 0;
            break;
        case DOWN:
            //speed_x = 0;
            speed_y = speed;
            break;
        case JUMP:
            break;
        case UP:
            //speed_x = 0;
            speed_y = -speed;
            break;
        case STAY:
            break;
        }

        x += speed_x * time;
        interactiveWithMap(speed_x, 0);
        y += speed_y * time;
        interactiveWithMap(0, speed_y);

        sprite.setPosition(x + width/2, y + height/2);

        if(health <= 0){
            life = false;
            sprite.setTextureRect(IntRect(0, 210, 85, 42));
            sprite.setPosition(x, y + 60);
            getPlayerCoordForView(view, x, y);
        }

        if(!movement)
            speed = 0;

        getPlayerCoordForView(view, x, y);

        if(life){
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                state = LEFT;
                speed = 0.1;
                gravity = false;
                currentFrame += 0.005 * time;
                if(currentFrame > 4)
                    currentFrame -= 4;
                sprite.setTextureRect(IntRect(74.25 * int(currentFrame)+74.25, 0, -74.25, 48));
                sprite.setPosition(x + 45, y + 50);

            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                state = RIGHT;
                speed = 0.1;
                gravity = false;
                currentFrame += 0.005 * time;
                if(currentFrame > 4)
                    currentFrame -= 4;
                sprite.setTextureRect(IntRect(74.25 * int(currentFrame), 0, 74.25, 48));
                sprite.setPosition(x + 45, y + 50);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                speed = 0;
                currentFrame += 0.005 * time;
                if(currentFrame > 3)
                    currentFrame -= 3;
                if(state == RIGHT)
                    sprite.setTextureRect(IntRect(82*int(currentFrame), 112,82, 76));
                else
                    sprite.setTextureRect(IntRect(82*int(currentFrame) + 82, 112, -82, 76));
            }
            else
            {
                speed = 0;
                currentFrame += 0.005 * time;
                if(currentFrame > 3)
                    currentFrame -= 3;
                if(state == RIGHT)
                    sprite.setTextureRect(IntRect(76 * int(currentFrame), 50, 76, 61));
                else //if(hero.direction == 1)
                    sprite.setTextureRect(IntRect(76 * int(currentFrame)+76, 50, -76, 61));
            }

            getPlayerCoordForView(view, x, y);
        }
        speed_y += 0.0015 * time;
    }

  void  Player::interactiveWithMap(float dx, float dy)//collision with map
    {
        for(int i = 0; i<obj.size(); i++)
        {
            if(getRect().intersects(obj[i].rect))
            {
                if(obj[i].name == "Stair" )
                {
                    if(dy > 0)
                    {
                        y += speed_y;
                        speed_y = 0;
                        gravity = true;
                    }
                    if(dy < 0)
                    {
                        y -= speed_x;
                    }
                }
                if(obj[i].name == "Solid")
                {

                    if(dy > 0)
                    {
                        y = obj[i].rect.top - height;
                        speed_y = 0;
                        gravity = true;
                    }
                    if(dy < 0)
                    {
                        y = obj[i].rect.top + obj[i].rect.height;
                        speed_y = 0;
                    }
                    if(dx > 0)
                    {
                        x = obj[i].rect.left - width;
                    }
                    if(dx < 0)
                    {
                        x = obj[i].rect.left + obj[i].rect.width;
                    }
                }
            }
        }
    }
