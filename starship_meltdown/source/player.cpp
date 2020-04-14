#include "../include/player.hpp"

Player::Player(){
    this->score = 0;
    this->player_lives = 3;
    this->ship_health = 100;
    textureStarship.loadFromFile("../graphics/blueships1.png");
    spriteStarship.setTexture(textureStarship);
    spriteStarship.setOrigin(0, 0);
    spriteStarship.setPosition(W_WIDTH/2-50, 700);
};

Player::~Player(){
	std::vector<Bullet*>::iterator itr;
	for(itr = bVect.begin(); itr < bVect.end(); itr++)
		delete *itr;
}

//Returns the Ship/Player Image
sf::Sprite Player:: getSprite(){
    return this->spriteStarship;
}

//Moves the Player Right
void Player:: moveRight(){
    spriteStarship.move(SPEED, 0);
}

//Moves the Player Left
void Player::moveLeft(){
    spriteStarship.move(-SPEED,0);
}

//Moves the Player Up
void Player::moveUp(){
    spriteStarship.move(0,-SPEED);
    if(spriteStarship.getPosition().y <= 450){
	spriteStarship.move(0,SPEED);
    }
}

//Moves the Player Down
void Player::moveDown(){
    spriteStarship.move(0,SPEED);
}

void Player::stop(){
	if(spriteStarship.getPosition().y <= 450){
		spriteStarship.move(0,-SPEED);
	}
}

void Player::shoot(){
	bPtr = new Bullet(spriteStarship.getPosition().x, spriteStarship.getPosition().y);
	bVect.push_back(bPtr);

	bPtr->setActive();
}

void Player::update(sf::RenderWindow &window){
	std::vector<Bullet*>::iterator itr;
	for(itr = bVect.begin(); itr < bVect.end(); itr++)
		if((*itr)->GetActiveStatus()){
			(*itr)->bulletFired();
			window.draw((*itr)->bulletPlayer);
		}
}
