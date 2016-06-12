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
#include "godBlessRandom.h"
#include <vector>
#include <list>

using namespace std;
using namespace sf;

void menu(RenderWindow &window);


bool letsRock()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1376, 768), "TerraX!");//sf::Style::Fullscreen);

    Level level;
    level.LoadFromFile("map.tmx");

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

    Image help_image, hero_image, enemy_image, dead_image;

    hero_image.loadFromFile("images/hero (2).png");
    enemy_image.loadFromFile("images/mob2.png");
    dead_image.loadFromFile("images/Die/died.bmp");
    help_image.loadFromFile("images/help.png");

    Texture help_texture, dead_texture;
    help_texture.loadFromImage(help_image);
    dead_texture.loadFromImage(dead_image);

    Sprite s_help, s_dead;
    s_help.setTexture(help_texture);
    s_help.setTextureRect(IntRect(0, 0, 1000, 626));
    s_help.setScale(0.3f, 0.3f);

    s_dead.setTexture(dead_texture);
    s_dead.setTextureRect(IntRect(0,0,600,197));



    view.reset(FloatRect(0, 0, 580, 460));//0,0,640,480

    bool helpCheck = true;
    float attackTimer = 0;

    Clock clock;

    list<Subject*> subjects;
    list<Subject*>::iterator countOf;
    list<Subject*>::iterator iter;

    vector<Object> enemies = level.GetObjects("Enemy");
    for(int i = 0; i < enemies.size(); i++)
        subjects.push_back(new Enemy(enemy_image, level, enemies[i].rect.left, enemies[i].rect.top, 71, 106));


    Object player = level.GetObject("Player");


    Player hero(hero_image, level, player.rect.left, player.rect.top, 76.2, 60);//PLAYER


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

                int newX, newY;

                getCoords(hero.x, hero.y, &newX, &newY);

                subjects.push_back(new Enemy(enemy_image, level, newX, newY, 71, 106));
                countNew = subjects.end();
                countNew--;
                Subject *sNew = *countNew;
                sNew->health = 100;
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
                    s->health -= 10 + rand()%15;
                }
                else
                {
                    if(attackTimer > 2500){
                        hero.health -= rand()%16;
                        attackTimer = 0;
                    }
                }
            }

            for(iter = subjects.begin(); iter != subjects.end(); iter++)
            {
                Subject *i = *iter;
                if(s->getRect() != i->getRect())
                    if(s->getRect().intersects(i->getRect()))
                    {
                        s->speed_x *= -1;
                        s->stateEnemy = !s->stateEnemy;
                    }
            }
        }



        window.setView(view);
        window.clear(Color(255, 255, 255));

        level.Draw(window);


        ostringstream heroScore, heroHealth;

    if(hero.health >=0){
        heroScore << hero.score;
        text.setString("Score:"+heroScore.str());
        text.setPosition(view.getCenter().x + 195, view.getCenter().y - 210);
        window.draw(text);

        heroHealth << hero.health;
        text.setString("Health:"+heroHealth.str());
        text.setPosition(view.getCenter().x - 268, view.getCenter().y - 210);
        window.draw(text);
    }


        if(helpCheck && hero.life)
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

        if(!hero.life)
        {

            s_dead.setPosition(view.getCenter().x-305,
                               view.getCenter().y-100);
            window.draw(s_dead);

            heroScore << hero.score;
            text.setString("Your Score:"+heroScore.str() + ";  Your Health=-99999 *try better, Dude");
            text.setPosition(view.getCenter().x-220, view.getCenter().y+50);
            window.draw(text);

        }

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
