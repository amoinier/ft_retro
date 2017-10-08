#ifndef ASPACESHIP_HPP
# define ASPACESHIP_HPP

#include "Weapon.hpp"
#include "AEntity.hpp"

class ASpaceShip
{
	protected :
			unsigned int 	_hp;
			unsigned int 	_hpMax;
			AEntity			&_shape;
			Weapon			*_weapon;

	private :
			ASpaceShip( void );

	public :

		ASpaceShip( ASpaceShip const & src );
		ASpaceShip( unsigned int hp, AEntity & shape);
		ASpaceShip( unsigned int hp, AEntity & shape, Weapon * weapon);
		virtual ~ASpaceShip(void) {};

		AEntity & 	getShape( void ) const;
		Weapon*		getWeapon(void) const;
		int 		getHp(void) const;
		bool		isAlive ( void ) const;
		void 		setHp(int hp);

		void		setWeapon(Weapon* weapon);
		void		repaired ( unsigned int );

		ASpaceShip & operator=( ASpaceShip const & rhs);
};
#endif
