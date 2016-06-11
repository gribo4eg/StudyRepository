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
                speed = 0.1;
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
        case JUMP:
            break;
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
            //speed_y = speed;
            break;
        case UP:
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
            getPlayerCoordForView(view, x, y);
        }

        if(!movement)
            speed = 0;

        getPlayerCoordForView(view, x, y);

        if(life)
            getPlayerCoordForView(view, x, y);

        speed_y += 0.0015 * time;
    }

  void  Player::interactiveWithMap(float dx, float dy)//collision with map
    {
        for(int i = 0; i<obj.size(); i++)
        {
            if(getRect().intersects(obj[i].rect))
            {
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
