#include <SFML/Graphics.hpp>

#include "Creatures.h"

using namespace std;
using namespace sf;

int main(void)
{
    RenderWindow window(VideoMode(1280, 720), "TerraX!");

    float CurrentFrame = 0;

    Clock clock;

    Creatures enemy("mob.jpg", 200, 200, 115, 195);

    while (window.isOpen())
    {
        Event event;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/500;

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
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            enemy.direction = 0;
            enemy.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            enemy.sprite.setTextureRect(IntRect(115 * int(CurrentFrame), 210, 115, 195));
        }

        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            enemy.sprite.move(0, 0.1 * time);
            enemy.sprite.setTextureRect(IntRect(0, 10, 115, 195));
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            enemy.sprite.move(0, -0.1 * time);
            enemy.sprite.setTextureRect(IntRect(0, 10, 115, 195));
        }

        enemy.position(time);

        window.clear(Color::White);
        window.draw(enemy.sprite);
        window.display();
    }

    return 0;
}
