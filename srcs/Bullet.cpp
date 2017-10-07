#include "Bullet.hpp"

Bullet::Bullet(void) :  _direction(1), _damage(35), _bullet(new AEntity(1, 1, 3, 1)), _next(NULL), _prev(NULL)
{

}

Bullet::Bullet(int direction, int x, int y) : _direction(direction),  _damage(35), _bullet(new AEntity(1, 1, 3, 1)), _next(NULL), _prev(NULL)
{

}

Bullet::Bullet(Bullet const & src)
{
	*this = src;
}

Bullet::~Bullet(void)
{

}


Bullet& Bullet::operator=(Bullet const & rhs)
{
	this->_damage = rhs.getDmg();
	this->_bullet = rhs.getBullet();
	this->_next = rhs.getNext();

	return *this;
}


int  		Bullet::getDmg(void) const
{
	return this->_damage;
}

int  		Bullet::getDir(void) const
{
	return this->_direction;
}

AEntity*  Bullet::getBullet(void) const
{
	return this->_bullet;
}

Bullet*  	Bullet::getNext(void) const
{
	return this->_next;
}

Bullet*  	Bullet::getPrev(void) const
{
	return this->_prev;
}


void  		Bullet::setDmg(int dmg)
{
	this->_damage = dmg;
}

void  		Bullet::setDir(int direction)
{
	this->_direction = direction;
}

void 		Bullet::setBullet(AEntity* bullet)
{
	this->_bullet = bullet;
}

void 		Bullet::setPrev(Bullet* prev)
{
	this->_prev = prev;

}
