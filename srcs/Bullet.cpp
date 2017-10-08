#include "Bullet.hpp"

Bullet::Bullet(void) :  _direction(1), _damage(35), _bullet(*new AEntity(1, 1, 3, 1)), _next(NULL), _prev(NULL)
{

}

Bullet::Bullet(int direction) : _direction(direction),  _damage(35), _bullet(*new AEntity(1, 1, 3, 1)), _next(NULL), _prev(NULL)
{

}

Bullet::Bullet(Bullet const & src) : _bullet(src.getBullet())
{
	*this = src;
}

Bullet::~Bullet(void)
{
	delete &_bullet;
}


Bullet& Bullet::operator=(Bullet const & rhs)
{
	this->_damage = rhs.getDmg();
	this->_direction = rhs.getDir();
	this->_bullet = rhs.getBullet();
	this->_next = rhs.getNext();
	this->_prev = rhs.getPrev();

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

AEntity&  Bullet::getBullet(void) const
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

void 		Bullet::setBullet(AEntity& bullet)
{
	this->_bullet = bullet;
}

void 		Bullet::setPrev(Bullet* prev)
{
	this->_prev = prev;

}

void 		Bullet::setNext(Bullet* next)
{
	this->_next = next;

}

bool			Bullet::bulletMove(int sizeX, int sizeY)
{
	if (this->getDir() == 2) {
		if (this->getBullet().getPosY() + this->getBullet().getSizeY() - 1 < sizeY) {
			this->getBullet().setPosY(this->getBullet().getPosY() + 1);

			sizeX *= 1;
			return true;
		}
		else {
			return false;
		}
	}
	else if (this->getDir() == 1) {
		if (this->getBullet().getPosY() > 0) {
			this->getBullet().setPosY(this->getBullet().getPosY() - 1);

			sizeX *= 1;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

bool			Bullet::move(void)
{
	if (this->getBullet().getSpeed() <= 0) {
		this->getBullet().setSpeed(this->getBullet().getMaxSpeed());

		return true;
	}
	else {
		this->getBullet().setSpeed(this->getBullet().getSpeed() - 1);

		return false;
	}
}
