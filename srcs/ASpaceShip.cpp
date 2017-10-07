#include "ASpaceShip.hpp"
#include <iostream>
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

ASpaceShip::ASpaceShip( unsigned int hp, IEntity const & shape, IWeapon * weapon):
	_hp(hp), _hpMax(10) ,_shape(shape), _weapon(weapon)
{
	std::cout << __func__ <<std::endl;
}


ASpaceShip::ASpaceShip( unsigned int hp, IEntity const & shape):
	_hp(hp), _hpMax(hp) , _shape(shape)
{
	std::cout << __func__ <<std::endl;
}

ASpaceShip::ASpaceShip(ASpaceShip const & src ): _shape(src._shape)
{
	*this = src;
}
/******************************************************************************
** 							DESTRUCTOR	
******************************************************************************/
/******************************************************************************
** 							OPERATOR OVERLOAD	
******************************************************************************/
ASpaceShip & ASpaceShip::operator=( ASpaceShip const & rhs )
{
	this->_hp = rhs._hp;
	this->_weapon = rhs._weapon;
	this->_hpMax = rhs._hpMax;
	this->_speed = rhs._speed;
	return *this;
}


/******************************************************************************
** 								GETTEUR
******************************************************************************/

IEntity  const	& 	ASpaceShip::getShape( void )
{
	return this->_shape;
}

bool		ASpaceShip::isAlive( void ) const
{
	if (this->_hp)
		return (true);
	else 
		return (false);
}

unsigned int	ASpaceShip::getSpeed(void) const
{
	return (this->_speed);
}

/******************************************************************************
** 								SETTEUR
******************************************************************************/

void		ASpaceShip::repaired ( unsigned int  hp)
{
	this->_hp = hp;
	if (this->_hpMax > this->_hp)
		this->_hp = this->_hpMax;
}