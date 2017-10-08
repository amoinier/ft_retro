
#include "Enemy.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Enemy::Enemy( AEntity & shape, Weapon *weapon, unsigned int hp, unsigned int color ): ASpaceShip(hp, shape, weapon), _color(color), _rShoot(10)
{

}

Enemy::Enemy(AEntity & shape, unsigned int hp ): ASpaceShip (hp, shape, 0), _color(0x0) //blank by default
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
Bullet	* Enemy::shoot( void )
{
	if (!this->_weapon)
		exit(1);
	if (this->_rShoot == 0)
	{
		return this->_weapon->shoot(2);

	}else
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
