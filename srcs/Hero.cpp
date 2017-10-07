#include <iostream>
#include "Hero.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Hero::Hero ( AEntity & shape, Weapon *weapon) : ASpaceShip(100, shape, weapon)
{
	std::cout << __func__ << std::endl;
	return ;
}
Hero::Hero ( AEntity & shape) : ASpaceShip(100 ,shape)
{
	std::cout << __func__ << std::endl;
	return ;
}

Hero::Hero( Hero const & src ) : ASpaceShip( src )
{
	std::cout << __func__ << std::endl;
	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
Hero::~Hero( void )
{
	std::cout << __func__ << std::endl;
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
/*
Hero & Hero::operator=( Hero const & rhs )
{
	return ;
}
*/
