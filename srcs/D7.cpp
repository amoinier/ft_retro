#include "D7.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

D7::D7( AEntity & shape, IWeapon *Weapon, unsigned int color) : Enemy(shape, Weapon, 25, color)
{
	return ;
}

D7::D7( D7 const & src ) : Enemy(src)
{
	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
D7::~D7( void )
{
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
/*
D7 & D7::operator=( D7 const & rhs ) Enemy
{
	return ;
}
*/
