#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ASpaceShip.hpp"
#include "Weapon.hpp"
#include "AEntity.hpp"
#include "Bullet.hpp"

class Enemy : public ASpaceShip
{
	protected :
		int 			_points;
		unsigned int 	_color;
		unsigned int 	_rShoot;
		unsigned int 	_rShootMax;

	private :
		Enemy( void );

	public :
		Enemy( AEntity & shape, Weapon *weapon, unsigned int hp, unsigned int color, int points );
		Enemy( AEntity & shape, unsigned int hp);
		Enemy( Enemy const & src );
		virtual ~Enemy( void ) {};

		Enemy & operator=( Enemy const & rhs);

		Bullet *shoot( void );
		bool 	enemyMove(int sizeX, int sizeY);
		bool 	move(void);

		int 	getPoints(void) const;
		void 	setPoints(int points);
};
#endif
