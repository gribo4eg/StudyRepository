#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "playerClass.h"
#include "enemyClass.h"
#include "subjectClass.h"
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
    enemy_image.loadFromFile("images/mob(3).png");


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

    std::list<Subject*> subjects;
    std::list<Subject*>::iterator countOf;

    vector<Object> enemies = level.GetObjects("Enemy");
    for(int i = 0; i < enemies.size(); i++)
        subjects.push_back(new Enemy(enemy_image, level, enemies[i].rect.left, enemies[i].rect.top, 75.8, 108, "Enemy"));


    Object player = level.GetObject("Player");


    Player hero(hero_image, level, player.rect.left, player.rect.top, 76.2, 60, "Player");


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

        if(hero.life)
            hero.position(&view, time);

        for(countOf = subjects.begin(); countOf != subjects.end();)
        {
            Subject *s = *countOf;
            s->position(&view, time);
            list<Subject*>::iterator countNew;
            if(s->life == false)
            {
                countOf = subjects.erase(countOf);
                delete s;
                if(hero.x > 650)
                {
                    subjects.push_back(new Enemy(enemy_image, level, rand()%100 + 60, 750, 75.8, 108, "Enemy"));
                    countNew = subjects.end();
                    countNew--;
                    Subject *sNew = *countNew;
                    sNew->health = 100;
                }
                else
                {
                    subjects.push_back(new Enemy(enemy_image, level, rand()%100 + 60, 750, 75.8, 108, "Enemy"));
                    countNew = subjects.end();
                    countNew--;
                    Subject *sNew = *countNew;
                    sNew->speed_x = -0.1;
                    sNew->health = 100;
                }
            }

            else
                countOf++;
        }

        for(countOf = subjects.begin(); countOf != subjects.end(); countOf++)
        {
            Subject *s = *countOf;
            if(s->getRect().intersects(hero.getRect()))
            {
                if(hero.speed_y > 0 && hero.gravity == false)
                {
                    s->speed_x = 0;
                    hero.speed_y = -0.2;
                    s->health /= 2;
                }
                else
                {
                    hero.health /= 2;
                }
            }
        }



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

        for(countOf = subjects.begin(); countOf != subjects.end(); countOf++)
           window.draw((*countOf)->sprite);

        window.display();
    }

    return 0;
}
