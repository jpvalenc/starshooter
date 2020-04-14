#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Asteroid{
    private:
        //the amount of damage dealt on contact
        int damage;

	float posX, posY;

        //The Asteroid skin
        sf::Texture textureAsteroid;

        //The asteroid body
        sf::Sprite spriteAsteroid;



    public:
        Asteroid();
        sf::Sprite getSprite();
        void sendAsteroid();
};
