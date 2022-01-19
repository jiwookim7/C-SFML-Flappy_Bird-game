#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

//This is the backround class that inherits from the sprite function to use their constructor
class Backround : public sf::Sprite, public sf::Texture 
{
public:
		
	Backround(const sf::Texture& texture) : sf::Sprite(texture) {

	}


	};
