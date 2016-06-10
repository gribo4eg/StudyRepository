#include <SFML/Graphics.hpp>
#include <sstream>

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

    View view;

    Font font;
    font.loadFromFile("quant.ttf");
    Text text("", font, 15);
    text.setColor(Color::Red);
    text.setStyle(Text::Bold);

    Image map_image, icon, help_image, hero_image, enemy_image;
    hero_image.loadFromFile("images/hero.png");
    enemy_image.loadFromFile("images/4330675.png");
    hero_image.createMaskFromColor(Color(102, 17, 189));

    map_image.loadFromFile("images/map.png");
    icon.loadFromFile("images/icon.png");
    help_image.loadFromFile("images/help.png");

    Texture map, help_texture;
    map.loadFromImage(map_image);
    help_texture.loadFromImage(help_image);

    Sprite s_map, s_help;
    s_map.setTexture(map);
    s_help.setTexture(help_texture);
    s_help.setTextureRect(IntRect(0, 0, 1000, 626));
    s_help.setScale(0.3f, 0.3f);

    window.setIcon(32, 32, icon.getPixelsPtr());

    view.reset(FloatRect(0, 0, 580, 460));//0,0,640,480

    float CurrentFrame = 0;
    bool helpCheck = true;

    Clock clock;

    Player hero(hero_image, 100, 100, 87.5, 60, "Player");
    Enemy enemy(enemy_image, 600, 200, 124, 210, "Enemy1");

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
        window.clear(Color(128,106,89));

     /*   for(int i = 0; i<HEIGHT_MAP; i++)
            for(int j = 0; j<WIDTH_MAP; j++)
            {
                if(MyTileMap[i][j] == ' ')
                    s_map.setTextureRect(IntRect(0, 0, 32, 32));
                if(MyTileMap[i][j] == 's')
                    s_map.setTextureRect(IntRect(32, 0, 32, 32));
                if(MyTileMap[i][j] == '0')
                    s_map.setTextureRect(IntRect(64, 0, 32, 32));

                s_map.setPosition(j*32, i*32);
                window.draw(s_map);
            }
*/


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
            text.setPosition(view.getCenter().x -200, view.getCenter().y +100);
            window.draw(text);
        }

        if(Keyboard::isKeyPressed(Keyboard::Tab) && hero.life)
            {
                helpCheck = false;
                s_help.setPosition(view.getCenter().x - 100,
                                   view.getCenter().y );
                window.draw(s_help);
            }

        window.draw(hero.sprite);
        window.display();
    }

    return 0;
}
