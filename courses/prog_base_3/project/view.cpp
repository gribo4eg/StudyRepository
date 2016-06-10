#include <SFML/Graphics.hpp>
#include "view.h"


void getPlayerCoordForView(sf::View *view, float x, float y)
{
    float tmpX = x, tmpY = y;

    if(x < 300) tmpX = 300;
    if(y < 240) tmpY = 240;
    if(y > 554) tmpY = 554;

    view->setCenter(tmpX, tmpY);
}
