#include "../include/asteroid.hpp"



Asteroid::Asteroid(){
    this->damage = 10;
    this->posX = (rand() % W_WIDTH);
    this->posY = (rand() % 200)*-1;

    textureAsteroid.loadFromFile("../graphics/8-bit_Asteroid.png");
    spriteAsteroid.setTexture(textureAsteroid);
    spriteAsteroid.setOrigin(0, 0);
    spriteAsteroid.setPosition(posX, posY);
};

sf::Sprite Asteroid :: getSprite(){
    return this->spriteAsteroid;
} 

void Asteroid::sendAsteroid(){
    spriteAsteroid.move(0, (rand() % SPEED + 1));
    if(spriteAsteroid.getPosition().y >= 1200){
	    spriteAsteroid.setPosition((rand() % W_WIDTH) , (rand() % 200)*-1);
    }
}
