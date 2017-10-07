#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ASpaceShip.hpp"
#include "IWeapon.hpp"
#include "AEntity.hpp"

class Enemy : ASpaceShip
{
	protected :
		unsigned int _color;

	private :
		Enemy(void );

	public :
		Enemy( AEntity const & shape, IWeapon *weapon, unsigned int hp, unsigned int color );
		//Enemy( AEntity const & shape, IWeapon *Weapon);
		Enemy( AEntity const & shape, unsigned int hp);
		//Enemy( AEntity const & shape, unsigned int hp);
		Enemy( Enemy const & src );
		~Enemy( void );

		Enemy & operator=( Enemy const & rhs);
};
#endif
