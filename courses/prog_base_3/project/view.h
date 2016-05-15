#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

using namespace sf;

sf::View view;

void getPlayerCoordForView(float x, float y)
{
    view.setCenter(x+100, y);
}

void viewMap(float time)
{
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        view.move(0.1 * time, 0);
    }
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        view.move(-0.1 * time, 0);
    }
    if(Keyboard::isKeyPressed(Keyboard::S))
    {
        view.move(0, 0.1 * time);
    }
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        view.move(0, -0.1 * time);
    }
}

#endif // VIEW_H_INCLUDED
