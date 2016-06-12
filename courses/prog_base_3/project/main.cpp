#include "game.h"
#include "SFML/Audio.hpp"

int main(void)
{
    sf::Music music;
    music.openFromFile("sounds/main.ogg");
    music.setLoop(true);
    music.play();

    gameIn();
    return 0;
}
