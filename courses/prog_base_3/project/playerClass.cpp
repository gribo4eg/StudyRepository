#include <SFML/Graphics.hpp>
#include "playerClass.h"
#include "map.h"

using namespace sf;

Player::Player(string file, float X, float Y,
              float Width, float Height)
    {
        state = STAY;
        score = 0;
        life = true;
        gravity = false;
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
        case JUMP:
            break;
        case STAY:
            break;
        }

        x += speed_x * time;
        interactiveWithMap(speed_x, 0);
        y += speed_y * time;
        interactiveWithMap(0, speed_y);

        sprite.setPosition(x + width/2, y + heigth/2);

        if(health <= 0)
            life = false;

        if(life)
            getPlayerCoordForView(view, x, y);

        speed_y += 0.0015 * time;
    }

  void  Player::interactiveWithMap(float dx, float dy)//collision with map
    {
        for(int i = y/32; i < (y + heigth)/32; i++)
        {
            for(int j = x/32; j < (x + width)/32; j++)
            {
                if(TileMap[i][j] == '0')
                {
                    if(dy > 0){
                        y = i*32 - heigth;
                        speed_y = 0;
                        gravity = true;
                    }
                    if(dy < 0){
                        y = i*32 + 32;
                        speed_y = 0;
                    }
                    if(dx > 0)
                        x = j*32 - width;
                    if(dx < 0)
                        x = j*32 + 32;
                }
                //else
                    //gravity = false;
            }
        }
    }
