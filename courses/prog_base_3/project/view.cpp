#include <SFML/Graphics.hpp>
#include "view.h"


void getPlayerCoordForView(sf::View *view, float x, float y)
{
    float tmpX = x, tmpY = y;

    //if(x < 300) tmpX = 300;
    //if(x > 1290) tmpX = 1290;
    //if(y < 240) tmpY = 240;
    if(y > 624) tmpY = 624;

    view->setCenter(tmpX, tmpY);
}
