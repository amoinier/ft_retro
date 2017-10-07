#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ASpaceShip.hpp"
#include "Weapon.hpp"
#include "AEntity.hpp"

class Enemy : public ASpaceShip
{
	protected :
		unsigned int _color;

	private :
		Enemy(void );

	public :
		Enemy( AEntity & shape, Weapon *weapon, unsigned int hp, unsigned int color );
		//Enemy( AEntity const & shape, Weapon *Weapon);
		Enemy( AEntity & shape, unsigned int hp);
		//Enemy( AEntity const & shape, unsigned int hp);
		Enemy( Enemy const & src );
		~Enemy( void );

		Enemy & operator=( Enemy const & rhs);

		bool 	enemyMove(int sizeX, int sizeY);
		bool 	move(void);
};
#endif
