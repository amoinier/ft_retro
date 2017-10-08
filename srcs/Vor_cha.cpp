#include "Vor_cha.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/
Vor_cha::Vor_cha ( Weapon * Weapon, unsigned int color): Enemy(*new AEntity(5, 5, 2, 10), Weapon, 50, color, 20)
{
	this->getShape().setDefinition(0, 0, 0);
	this->getShape().setDefinition(0, 1, 0);
	this->getShape().setDefinition(1, 0, 0);
	this->getShape().setDefinition(0, 3, 0);
	this->getShape().setDefinition(0, 4, 0);
	this->getShape().setDefinition(1, 4, 0);
	this->getShape().setDefinition(3, 0, 0);
	this->getShape().setDefinition(4, 0, 0);
	this->getShape().setDefinition(4, 1, 0);
	this->getShape().setDefinition(3, 4, 0);
	this->getShape().setDefinition(4, 3, 0);
	this->getShape().setDefinition(4, 4, 0);

	return ;
}


Vor_cha::Vor_cha( Vor_cha const & src ) : Enemy(src)
{
	*this = src;

	return ;
}

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

Vor_cha & Vor_cha::operator=( Vor_cha const & rhs )
{
	(void)rhs;

	return *this;
}
