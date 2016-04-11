#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(500, 500), "Terra! demo");

    Texture Hero;
    Hero.loadFromFile("variant2.0.png");

    double currentPict = 0;

    Sprite sprite;
    sprite.setTexture(Hero);
    sprite.setTextureRect(IntRect(0, 58, 40, 34));
    sprite.setPosition(50, 100);

    while (window.isOpen())
    {

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
                sprite.move(-0.1,   0);
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
                sprite.move(0.1,   0);

                currentPict += 0.09;
                if(currentPict >3)
                    currentPict -=3;
                sprite.setTextureRect(IntRect(42*int(currentPict), 58, 40, 34));
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
                sprite.move(0,  -0.1);
        }

        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
                sprite.move(0,   0.1);
        }

        window.clear(Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
