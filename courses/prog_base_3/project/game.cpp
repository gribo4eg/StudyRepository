#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

void menu(RenderWindow &window);

bool letsRock()
{
    RenderWindow window(VideoMode(1376, 768), "TerraX!");//sf::Style::Fullscreen);

    Level level;
    level.LoadFromFile("map.tmx");

    Music music;
    music.openFromFile("sounds/main.ogg");
    music.setLoop(true);
    music.play();

    Image icon;
    icon.loadFromFile("images/icon.png");
    window.setIcon(32, 32, icon.getPixelsPtr());


    menu(window);

    SoundBuffer jumpBuf, attackBuf;
    jumpBuf.loadFromFile("sounds/jump.ogg");
    attackBuf.loadFromFile("sounds/swordAttack.ogg");
    Sound jump(jumpBuf);
    Sound attack(attackBuf);

    View view;

    Font font;
    font.loadFromFile("quant.ttf");
    Text text("", font, 15);
    text.setColor(Color::Red);
    text.setStyle(Text::Bold);

    Image help_image, hero_image, enemy_image;
    help_image.loadFromFile("images/help.png");
    hero_image.loadFromFile("images/hero (2).png");
    enemy_image.loadFromFile("images/mob2.png");

    help_image.loadFromFile("images/help.png");

    Texture help_texture;
    help_texture.loadFromImage(help_image);

    Sprite s_help;
    s_help.setTexture(help_texture);
    s_help.setTextureRect(IntRect(0, 0, 1000, 626));
    s_help.setScale(0.3f, 0.3f);



    view.reset(FloatRect(0, 0, 580, 460));//0,0,640,480

    bool helpCheck = true;
    float attackTimer = 0;

    Clock clock;

    std::list<Subject*> subjects;
    std::list<Subject*>::iterator countOf;

    vector<Object> enemies = level.GetObjects("Enemy");
    for(int i = 0; i < enemies.size(); i++)
        subjects.push_back(new Enemy(enemy_image, level, enemies[i].rect.left, enemies[i].rect.top, 71, 106, "Enemy"));


    Object player = level.GetObject("Player");


    Player hero(hero_image, level, player.rect.left, player.rect.top, 76.2, 60, "Player");


    while (window.isOpen())
    {
        Event event;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        attackTimer += time;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

        }


        if(hero.life){
            hero.position(&view, time);

            if(Keyboard::isKeyPressed(Keyboard::Up))
                jump.play();
            if(Keyboard::isKeyPressed(Keyboard::Space))
                attack.play();
        }

        for(countOf = subjects.begin(); countOf != subjects.end();)
        {
            Subject *s = *countOf;
            s->position(&view, time);
            list<Subject*>::iterator countNew;
            if(s->life == false)
            {
                countOf = subjects.erase(countOf);
                delete s;
                hero.score++;
                if(hero.x > 650)
                {
                    subjects.push_back(new Enemy(enemy_image, level, 1000 + rand()%2129, 308, 71, 106, "Enemy"));
                    countNew = subjects.end();
                    countNew--;
                    Subject *sNew = *countNew;
                    sNew->health = 100;
                }
                else
                {
                    subjects.push_back(new Enemy(enemy_image, level, 1000 + rand()%2129, 22, 71, 106, "Enemy"));
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
                if(Keyboard::isKeyPressed(Keyboard::Space))
                {
                    s->health -= 5;

                }
                else
                {
                    if(attackTimer > 2500){
                        hero.health -= 20;
                        attackTimer = 0;
                    }
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

    if(hero.health >=0)
        heroHealth << hero.health;
    else
        heroHealth << "0";
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

        if(Keyboard::isKeyPressed(Keyboard::Escape))
            return false;
        if(Keyboard::isKeyPressed(Keyboard::F1))
            return true;

        window.display();
    }
    return false;
}

void gameIn()
{
    if(letsRock())
        gameIn();
}

void menu(RenderWindow &window)
{
    Texture menuBackG, startButText, exitButText;
    menuBackG.loadFromFile("images/menu/post.bmp");
    startButText.loadFromFile("images/menu/startButton.png");
    exitButText.loadFromFile("images/menu/exitButton.png");

    Sprite menuBG(menuBackG), start(startButText);
    Sprite exit(exitButText);

    bool isMenu = true;
    int menuNum = 0;
    menuBG.setPosition(0, 0);
    start.setPosition(530, 300);
    exit.setPosition(525, 500);

    while(isMenu)
    {
        start.setColor(Color::White);
        exit.setColor(Color::White);
        menuNum = 0;

        if(IntRect(530, 300, 300, 100).contains(Mouse::getPosition(window)))
        {
            start.setColor(Color::Red);
            menuNum = 1;
        }
        if(IntRect(525, 500, 300, 100).contains(Mouse::getPosition(window)))
        {
            exit.setColor(Color::Red);
            menuNum = 2;
        }


        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(menuNum == 1)
                isMenu = false;

            if(menuNum == 2)
            {
                window.close();
                isMenu = false;
            }
        }

        window.draw(menuBG);
        window.draw(start);
        window.draw(exit);

        window.display();
    }
}
