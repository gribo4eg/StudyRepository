#include <SFML/Graphics.hpp>

#include "Creatures.h"
#include "map.h"
#include "view.h"

using namespace std;
using namespace sf;

int main(void)
{
    RenderWindow window(VideoMode(1280, 720), "TerraX!");

    Image map_image;
    map_image.loadFromFile("images/map.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);

    view.reset(FloatRect(0, 0, 640, 480));

    float CurrentFrame = 0;

    Clock clock;

    Creatures enemy("mob.png", 200, 200, 115, 195);

    while (window.isOpen())
    {
        Event event;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/700;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            enemy.direction = 1; enemy.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            enemy.sprite.setTextureRect(IntRect(115 * int(CurrentFrame), 10, 115, 195));
            getPlayerCoordForView(enemy.getPlayerCoordX(), enemy.getPlayerCoordY());
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            enemy.direction = 0;
            enemy.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            enemy.sprite.setTextureRect(IntRect(115 * int(CurrentFrame), 210, 115, 195));
            getPlayerCoordForView(enemy.getPlayerCoordX(), enemy.getPlayerCoordY());
        }

        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            enemy.direction = 2; enemy.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            enemy.sprite.setTextureRect(IntRect(0 * int(CurrentFrame), 10, 115, 195));
            getPlayerCoordForView(enemy.getPlayerCoordX(), enemy.getPlayerCoordY());
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            enemy.direction = 3; enemy.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            enemy.sprite.setTextureRect(IntRect(0 * int(CurrentFrame), 10, 115, 195));
            getPlayerCoordForView(enemy.getPlayerCoordX(), enemy.getPlayerCoordY());
        }

        enemy.position(time);
        viewMap(time);

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

        window.draw(enemy.sprite);
        window.display();
    }

    return 0;
}
