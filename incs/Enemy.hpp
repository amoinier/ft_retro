#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ASpaceShip.hpp"
#include "IWeapon.hpp"

class Enemy : ASpaceShip 
{
	protected :
		unsigned int _color;

	private :
		Enemy(void );

	public :
		Enemy( IEntity const & shape, IWeapon *Weapon, unsigned int hp, unsigned int color );
		//Enemy( IEntity const & shape, IWeapon *Weapon);
		Enemy( IEntity const & shape, unsigned int hp);
		//Enemy( IEntity const & shape, unsigned int hp);
		Enemy( Enemy const & src );
		~Enemy( void );

		Enemy & operator=( Enemy const & rhs);
};
#endif
