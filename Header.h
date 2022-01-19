#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Bird : public sf::Sprite, public sf::Texture {
public:
	

	Bird(const sf::Texture& texture) : sf::Sprite(texture)
	{
	};
	

};

//class run{
//	private:
//	Pipe pipe;
//
//	inline void update_objects();
//
//}
