
#include "Enemy.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Enemy::Enemy( AEntity & shape, IWeapon *weapon, unsigned int hp, unsigned int color ): ASpaceShip(hp, shape, weapon), _color(color)
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
