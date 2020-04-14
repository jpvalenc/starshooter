#include "../include/bullet.hpp"
#include "../include/asteroid.hpp"
#include "../include/boss.hpp"

Bullet::Bullet(float x, float y){

	this->damage = 10;
	posX = x;
	posY = y;
	isActive = false;

	bulletTexture.loadFromFile("../graphics/bullet.png");
	bulletPlayer.setTexture(bulletTexture);
	bulletPlayer.setScale(0.1,0.1);
	bulletPlayer.setOrigin(0, 0);
	bulletPlayer.setPosition(x, y);
};

void Bullet::setPos(float x, float y){
	bulletPlayer.setPosition(x, y);
}

sf::Sprite Bullet::getbulletPlayer(){
	return this->bulletPlayer;
}

void Bullet::setActive(){
	isActive = true;
}

void Bullet::bulletFired(){
	bulletPlayer.move(0, -2*SPEED);
	if(bulletPlayer.getPosition().y <= -100){
		isActive = false;
		return;
	}
}

bool Bullet::GetActiveStatus(){
	return isActive;
}


