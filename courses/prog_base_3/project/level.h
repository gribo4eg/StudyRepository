/*********************************************************************
Quinn Schwab
16/08/2010

SFML Tiled Map Loader

The zlib license has been used to make this software fully compatible
with SFML. See http://www.sfml-dev.org/license.php

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.
*********************************************************************/

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TinyXML/tinyxml.h"

struct Object
{
	int GetPropertyInt(std::string name);
	float GetPropertyFloat(std::string name);
	std::string GetPropertyString(std::string name);

	std::string name;
	std::string type;
	sf::Rect<float> rect;
	std::map<std::string, std::string> properties;

	sf::Sprite sprite;
};

struct Layer
{
	int opacity;
	std::vector<sf::Sprite> tiles;
};

class Level
{
public:
	bool LoadFromFile(std::string filename);
	Object GetObject(std::string name);
	std::vector<Object> GetObjects(std::string name);
	std::vector<Object> GetAllObjects();
	void Draw(sf::RenderWindow &window);
	sf::Vector2i GetTileSize();

private:
	int width, height, tileWidth, tileHeight;
	int firstTileID;
	sf::Rect<float> drawingBounds;
	sf::Texture tilesetImage;
	std::vector<Object> objects;
	std::vector<Layer> layers;
};

int GetPropertyInt(std::string name);
float GetPropertyFloat(std::string name);

std::string GetPropertyString(std::string name);

bool LoadFromFile(std::string filename);

Object GetObject(std::string name);

std::vector<Object> GetObjects(std::string name);
std::vector<Object> GetAllObjects();

sf::Vector2i GetTileSize();

void Draw(sf::RenderWindow &window);

#endif

