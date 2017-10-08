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
	*this = src;
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

Hero & Hero::operator=( Hero const & rhs )
{
	(void)rhs;

	return *this;
}


int Hero::defaultDefinition[3][3] = {{0,1,1},{1, 1, 1}, {0, 1, 1}};
