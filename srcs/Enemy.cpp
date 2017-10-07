
#include "Enemy.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Enemy::Enemy( AEntity & shape, Weapon *weapon, unsigned int hp, unsigned int color ): ASpaceShip(hp, shape, weapon), _color(color)
{

}

Enemy::Enemy(AEntity & shape, unsigned int hp ): ASpaceShip (hp, shape), _color(0x0) //blank by default
{

}
/*
Enemy::Enemy ( void )
{
	return ;
}
*/

Enemy::Enemy( Enemy const & src ) :ASpaceShip (src)
{
	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
Enemy::~Enemy( void )
{
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
/*
Enemy & Enemy::operator=( Enemy const & rhs )
{
	return ;
}
*/

/******************************************************************************
** 							PUBLIC MEMBER FUNCTION
******************************************************************************/
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
