#include "ASpaceShip.hpp"
#include <iostream>
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

ASpaceShip::ASpaceShip( unsigned int hp, AEntity & shape, Weapon * weapon):
	_hp(hp), _hpMax(10) ,_shape(shape), _weapon(weapon)
{
}


ASpaceShip::ASpaceShip( unsigned int hp, AEntity & shape):
	_hp(hp), _hpMax(hp) , _shape(shape)
{
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
	return *this;
}


/******************************************************************************
** 								GETTEUR
******************************************************************************/

AEntity	& 	ASpaceShip::getShape( void ) const
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

Weapon*		ASpaceShip::getWeapon(void) const
{
	return this->_weapon;
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

void		ASpaceShip::setWeapon(Weapon* weapon)
{
	this->_weapon = weapon;

	return ;
}
