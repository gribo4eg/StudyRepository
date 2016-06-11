#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "playerClass.h"
#include "enemyClass.h"
#include "level.h"
#include "view.h"
#include <vector>
#include <list>

using namespace std;
using namespace sf;

void drawText();

int main(void)
{
    RenderWindow window(VideoMode(1270, 700), "TerraX!");// Style::Fullscreen);

    Level level;
    level.LoadFromFile("map.tmx");

    View view;

    Font font;
    font.loadFromFile("quant.ttf");
    Text text("", font, 15);
    text.setColor(Color::Red);
    text.setStyle(Text::Bold);

    Image icon, help_image, hero_image, enemy_image;
    hero_image.loadFromFile("images/hero (2).png");
    enemy_image.loadFromFile("images/mob.png");


    icon.loadFromFile("images/icon.png");
    help_image.loadFromFile("images/help.png");

    Texture help_texture;
    help_texture.loadFromImage(help_image);

    Sprite s_help;
    s_help.setTexture(help_texture);
    s_help.setTextureRect(IntRect(0, 0, 1000, 626));
    s_help.setScale(0.3f, 0.3f);

    window.setIcon(32, 32, icon.getPixelsPtr());

    view.reset(FloatRect(0, 0, 580, 460));//0,0,640,480

    bool helpCheck = true;

    Clock clock;

    Object player = level.GetObject("Player");
    Object enemyObj = level.GetObject("Enemy");

    Player hero(hero_image, level, player.rect.left, player.rect.top, 76.2, 60, "Player");
    Enemy enemy(enemy_image, level, 600, 511, 110, 203, "Enemy1");

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


        hero.position(&view, time);
        enemy.position(time);

        window.setView(view);
        window.clear(Color(255, 255, 255));

        level.Draw(window);


        ostringstream heroScore, heroHealth;
        heroScore << hero.score;
        text.setString("Score:"+heroScore.str());
        text.setPosition(view.getCenter().x + 195, view.getCenter().y - 210);
        window.draw(text);

        heroHealth << hero.health;
        text.setString("Health:"+heroHealth.str());
        text.setPosition(view.getCenter().x - 268, view.getCenter().y - 210);
        window.draw(text);

        if(helpCheck)
        {
            text.setString("Press TAB while playing to get HELP!");
            text.setPosition(view.getCenter().x -250, view.getCenter().y -100);
            window.draw(text);
        }

        if(Keyboard::isKeyPressed(Keyboard::Tab) && hero.life)
            {
                helpCheck = false;
                s_help.setPosition(view.getCenter().x - 140,
                                   view.getCenter().y - 200);
                window.draw(s_help);
            }

        window.draw(hero.sprite);
        window.draw(enemy.sprite);
        window.display();
    }

    return 0;
}
