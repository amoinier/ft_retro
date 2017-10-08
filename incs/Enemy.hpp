#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ASpaceShip.hpp"
#include "Weapon.hpp"
#include "AEntity.hpp"
#include "Bullet.hpp"

class Enemy : public ASpaceShip
{
	protected :
		unsigned int _color;
		unsigned int _rShoot;
		unsigned int _rShootMax;

	private :
		Enemy(void );

	public :
		Enemy( AEntity & shape, Weapon *weapon, unsigned int hp, unsigned int color );
		//Enemy( AEntity const & shape, Weapon *Weapon);
		Enemy( AEntity & shape, unsigned int hp);
		//Enemy( AEntity const & shape, unsigned int hp);
		Enemy( Enemy const & src );
		
		virtual ~Enemy( void ) {};
		
		
		/**
		 * attack
		 **/
		
		Bullet *shoot( void ); // shoot a bullet each time rShoot is 0



		Enemy & operator=( Enemy const & rhs);

		bool 	enemyMove(int sizeX, int sizeY);
		bool 	move(void);
};
#endif
