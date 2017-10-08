
#include "Enemy.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Enemy::Enemy( AEntity & shape, Weapon *weapon, unsigned int hp, unsigned int color, int points ): ASpaceShip(hp, shape, weapon),
_points(points), _color(color), _rShoot(0), _rShootMax(30)
{
	this->_rShoot =  rand() % this->_rShootMax + 100;
}

Enemy::Enemy(AEntity & shape, unsigned int hp ): ASpaceShip (hp, shape, 0), _color(0x0) //blank by default
{

}

Enemy::Enemy( Enemy const & src ) : ASpaceShip (src)
{
	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/

Enemy & Enemy::operator=( Enemy const & rhs )
{
	this->_points = rhs._points;
	this->_color = rhs._color;
	this->_rShoot = rhs._rShoot;
	this->_rShootMax = rhs._rShootMax;

	return *this;
}


/******************************************************************************
** 							PUBLIC MEMBER FUNCTION
******************************************************************************/
Bullet*	Enemy::shoot( void )
{
	if (this->_rShoot == 0)
	{
		this->_rShoot =  rand() % this->_rShootMax + 100;
		return this->_weapon->shoot(2, false);

	}
	else
	{
		this->_rShoot--;
	}
	return 0;
}

bool 	Enemy::enemyMove(int sizeX, int sizeY)
{
	if (this->getShape().getPosY() + this->getShape().getSizeY() - 1 < sizeY) {
		this->getShape().setPosY(this->getShape().getPosY() + 1);

		sizeX *= 1;
		return true;
	}
	else {
		return false;
	}
}

bool 	Enemy::move(void)
{
	if (this->getShape().getSpeed() <= 0) {
		this->getShape().setSpeed(this->getShape().getMaxSpeed());

		return true;
	}
	else {
		this->getShape().setSpeed(this->getShape().getSpeed() - 1);

		return false;
	}
}

int 	Enemy::getPoints(void) const
{
	return this->_points;
}

void 	Enemy::setPoints(int points)
{
	this->_points = points;
}
