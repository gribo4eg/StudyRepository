#include <SFML/Graphics.hpp>
#include "view.h"


void getPlayerCoordForView(sf::View *view, float x, float y)
{
    float tmpX = x, tmpY = y;

    if(x < 300) tmpX = 300;
    if(x > 1750) tmpX = 1750;
    if(y < 240) tmpY = 240;
    if(y > 700) tmpY = 700;

    view->setCenter(tmpX, tmpY);
}
