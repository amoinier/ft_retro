
#include "Enemy.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Enemy::Enemy(IEntity const & shape, unsigned int hp ): ASpaceShip (hp, shape), _color(0x0) //blank by default
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
