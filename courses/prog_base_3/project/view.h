#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

using namespace sf;

View view;

void getPlayerCoordForView(float x, float y)
{
    float tmpX = x, tmpY = y;

    if(x < 300) tmpX = 300;
    if(y < 240) tmpY = 240;
    if(y > 554) tmpY = 554;

    view.setCenter(tmpX, tmpY);
}


#endif // VIEW_H_INCLUDED
