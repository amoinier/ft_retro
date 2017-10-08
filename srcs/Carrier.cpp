#include "Carrier.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/
Carrier::Carrier ( Weapon * Weapon, unsigned int color): Enemy(*new AEntity(7, 7, 2, 20), Weapon, 120, color, 30)
{
	this->getShape().setDefinition(2, 0, 0);
	this->getShape().setDefinition(3, 0, 0);
	this->getShape().setDefinition(4, 0, 0);
	this->getShape().setDefinition(0, 5, 0);
	this->getShape().setDefinition(0, 6, 0);
	this->getShape().setDefinition(1, 3, 0);
	this->getShape().setDefinition(1, 4, 0);
	this->getShape().setDefinition(1, 5, 0);
	this->getShape().setDefinition(1, 6, 0);
	this->getShape().setDefinition(2, 6, 0);
	this->getShape().setDefinition(4, 6, 0);
	this->getShape().setDefinition(5, 3, 0);
	this->getShape().setDefinition(5, 4, 0);
	this->getShape().setDefinition(5, 5, 0);
	this->getShape().setDefinition(5, 6, 0);
	this->getShape().setDefinition(6, 5, 0);
	this->getShape().setDefinition(6, 6, 0);

	return ;
}


Carrier::Carrier( Carrier const & src ) : Enemy(src)
{
	*this = src;

	return ;
}

/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
Carrier::~Carrier( void )
{
	delete &_shape;
	delete _weapon;
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/

Carrier & Carrier::operator=( Carrier const & rhs )
{
	(void)rhs;

	return *this;
}
