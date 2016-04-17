#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

int main(void)
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");

    float CurrentFrame = 0;

    Clock clock;

    Image Hero;
    Hero.loadFromFile("images/mob.png");
    Hero.createMaskFromColor(Color(0,0,0,0));

    Texture HeroTexture;
    HeroTexture.loadFromImage(Hero);

    Sprite HeroSprite;
    HeroSprite.setTexture(HeroTexture);// width.x = 115; width.y = 190
    HeroSprite.setTextureRect(IntRect(0, 10, 115, 190));
    HeroSprite.setPosition(900, 25);
    HeroSprite.setScale(0.4,0.4);

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
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            HeroSprite.setTextureRect(IntRect(115 * int(CurrentFrame), 10, 115, 190));
            HeroSprite.move(-0.1 * time, 0);
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            CurrentFrame += 0.005 * time;
            if(CurrentFrame > 6)
                CurrentFrame -= 6;
            HeroSprite.setTextureRect(IntRect(115 * int(CurrentFrame), 210, 115, 190));
            HeroSprite.move(0.1 * time, 0);
        }

        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            HeroSprite.move(0, 0.1 * time);
            HeroSprite.setTextureRect(IntRect(0, 10, 115, 190));
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            HeroSprite.move(0, -0.1 * time);
            HeroSprite.setTextureRect(IntRect(0, 10, 115, 190));
        }

        window.clear(Color::White);
        window.draw(HeroSprite);
        window.display();
    }

    return 0;
}

class Creatures
{
public:
    creatures(string file, float x, float width,
              float height);
    float x, width, heigth, speed_x, speed;
    int direction;
    string imageName;
    Image image;
    Texture texture;
    Sprite sprite;
};

Creatures::creatures(string file, float x, float width,
              float height)
              {
                    imageName = file;

              }
