#include <iostream>
#include "Hero.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Hero::Hero ( AEntity & shape, Weapon *weapon) : ASpaceShip(100, shape, weapon)
{
	return ;
}
Hero::Hero ( AEntity & shape) : ASpaceShip(100 ,shape)
{
	return ;
}

Hero::Hero( Hero const & src ) : ASpaceShip( src )
{
	*this = src;

	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
Hero::~Hero( void )
{
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/

Hero & Hero::operator=( Hero const & rhs )
{
	this->_score = rhs._score;

	return *this;
}

int 	Hero::getScore(void) const
{
	return this->_score;
}

void 	Hero::setScore(int score)
{
	this->_score = score;
}


int Hero::defaultDefinition[3][3] = {{0,1,1},{1, 1, 1}, {0, 1, 1}};
