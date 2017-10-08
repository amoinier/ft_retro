#include "WeaponParticules.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/
WeaponParticules::WeaponParticules ( void ) :_damage(25), _type(1), _begin(0)
{
	return ;
}

WeaponParticules::WeaponParticules( WeaponParticules const & src )
{
	*this = src;
	return ;
}
/******************************************************************************
** 							DESTRUCTOR	
******************************************************************************/
WeaponParticules::~WeaponParticules( void )
{
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD	
******************************************************************************/
WeaponParticules & WeaponParticules::operator=( WeaponParticules const & rhs )
{
	this->_damage = rhs._damage;
	this->_type  = rhs._type;
	return *this;
}

/*****************************************************************************
*							Private method
********************************************************************************/

/*****************************************************************************
*							Public method
********************************************************************************/

void		WeaponParticules::shoot( void )
{
	t_bullet *bullet;

	bullet = new t_bullet();
	bullet->_entity = new AEntity(1, 1);
	if (!this->_begin)
	{
		this->_begin = new t_bullet();
	}
}
/******************************************************************************
** 							GETTEUR
******************************************************************************/

unsigned int		WeaponParticules::getDamage( void ) const
{
	return this->_damage;
}

unsigned int 		WeaponParticules::getType( void ) const		
{
	return this->_type;
}

/*
AEntity				*WeaponParticules::getEntity( void ) const
{
	return this->_entity;
}
*/


