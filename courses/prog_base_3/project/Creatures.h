#ifndef CREATURES_H
#define CREATURES_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Creatures
{
public:
    float x, y, width, heigth, speed_x, speed;
    int direction;
    string imageName;
    Image image;
    Texture texture;
    Sprite sprite;
    Creatures(string, float, float, float, float);
    void position(float);
    virtual ~Creatures();

protected:

private:
};

#endif // CREATURES_H
