
#include <SFML/Graphics.hpp>

#include "subjectClass.h"

using namespace std;
using namespace sf;

Subject::Subject(Image &image, float X, float Y,int Width,int Height, string Name){
		x = X; y = Y; width = Width; height = Height; name = Name; moveTime = 0;
		speed = 0; health = 100; speed_x = 0; speed_y = 0;
		life = true; gravity = false; movement = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(width / 2, height / 2);
}
