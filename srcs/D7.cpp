#include "D7.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

D7::D7( Weapon *Weapon, unsigned int color) : Enemy(*new AEntity(2, 2, 2, 7), Weapon, 25, color, 10)
{
	this->getShape().setDefinition(0, 0, 0);
	this->getShape().setDefinition(1, 1, 0);

	return ;
}

D7::D7( D7 const & src ) : Enemy(src)
{
	*this = src;

	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
D7::~D7( void )
{
	delete &_shape;
	delete _weapon;

	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/

D7 & D7::operator=( D7 const & rhs )
{
	(void)rhs;

	return *this;
}
