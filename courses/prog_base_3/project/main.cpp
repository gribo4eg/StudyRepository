#include <SFML/Graphics.hpp>

#include "Creatures.h"
#include "map.h"
#include "view.h"

using namespace std;
using namespace sf;

int main(void)
{
    RenderWindow window(VideoMode(1270, 700), "TerraX!");


    Image map_image;
    map_image.loadFromFile("images/map.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);

    view.reset(FloatRect(0, 0, 580, 460));//0,0,640,480

    float CurrentFrame = 0;

    Clock clock;

    Creatures hero("hero.png", 100, 100, 87.5, 60);

    while (window.isOpen())
    {
        Event event;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }



        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            hero.direction = 1; hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 4)
                CurrentFrame -= 4;
            hero.sprite.setTextureRect(IntRect(87.5 * int(CurrentFrame)+87.5, 0, -87.5, 65));
            getPlayerCoordForView(hero.getPlayerCoordX(), hero.getPlayerCoordY());
        }

        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            hero.direction = 0;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 4)
                CurrentFrame -= 4;
            hero.sprite.setTextureRect(IntRect(87.5 * int(CurrentFrame), 0, 87.5, 65));
            getPlayerCoordForView(hero.getPlayerCoordX(), hero.getPlayerCoordY());
        }

        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            hero.direction = 2; hero.speed = 0.1;
            hero.sprite.setTextureRect(IntRect(0, 252, 55, 63));
            getPlayerCoordForView(hero.getPlayerCoordX(), hero.getPlayerCoordY());
        }

        else if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            hero.direction = 3; hero.speed = 0.1;
            hero.sprite.setTextureRect(IntRect(0, 252, 55, 63));
            getPlayerCoordForView(hero.getPlayerCoordX(), hero.getPlayerCoordY());
        }

        else if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            hero.speed = 0;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 3)
                CurrentFrame -=3;
            if(hero.direction == 0)
                hero.sprite.setTextureRect(IntRect(91.3 * int(CurrentFrame), 130, 91.3, 78));
            else
                hero.sprite.setTextureRect(IntRect(91.3 * int(CurrentFrame)+91.3, 130, -91.3, 78));
            getPlayerCoordForView(hero.getPlayerCoordX(), hero.getPlayerCoordY());
        }

        else
        {
            hero.speed = 0;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 3)
                CurrentFrame -= 3;
            if(hero.direction == 0)
                hero.sprite.setTextureRect(IntRect(83.5 * int(CurrentFrame), 60, 83.5, 70));
            else //if(hero.direction == 1)
                hero.sprite.setTextureRect(IntRect(83.5 * int(CurrentFrame)+83.5, 60, -83.5, 70));
            getPlayerCoordForView(hero.getPlayerCoordX(), hero.getPlayerCoordY());
        }

        hero.position(time);

        window.setView(view);
        window.clear(Color(128,106,89));

        for(int i = 0; i<HEIGHT_MAP; i++)
            for(int j = 0; j<WIDTH_MAP; j++)
            {
                if(TileMap[i][j] == ' ')
                    s_map.setTextureRect(IntRect(0, 0, 32, 32));
                if(TileMap[i][j] == 's')
                    s_map.setTextureRect(IntRect(32, 0, 32, 32));
                if(TileMap[i][j] == '0')
                    s_map.setTextureRect(IntRect(64, 0, 32, 32));

                s_map.setPosition(j*32, i*32);
                window.draw(s_map);
            }

        window.draw(hero.sprite);
        window.display();
    }

    return 0;
}
