#include "Vor_cha.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/
Vor_cha::Vor_cha ( Weapon * Weapon, unsigned int color): Enemy(*new AEntity(5, 5, 2, 10), Weapon, 50, color)
{
	return ;
}

/*
Vor_cha::Vor_cha( Vor_cha const & src )
{
	return ;
}
*/
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
Vor_cha::~Vor_cha( void )
{
	delete &_shape;
	delete _weapon;
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
/*
Vor_cha & Vor_cha::operator=( Vor_cha const & rhs )
{
	return ;
}
*/
