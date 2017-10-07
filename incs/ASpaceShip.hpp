#ifndef ASPACESHIP_HPP
# define ASPACESHIP_HPP

#include "Weapon.hpp"
#include "AEntity.hpp"

class ASpaceShip
{
	protected :
			unsigned int _hp;
			unsigned int _hpMax;
			AEntity		&_shape; // XXX
			Weapon		*_weapon; //XXX interface ???

	private :

			ASpaceShip( void );

	public :

		virtual ~ASpaceShip( void ) {};

		ASpaceShip( ASpaceShip const & src );

		ASpaceShip( unsigned int hp, AEntity & shape);
		ASpaceShip( unsigned int hp, AEntity & shape, Weapon * weapon);




		void		attack ( void ) const ; // use is weapon



		/**
		 * Ascessor
		 * */
		AEntity & getShape( void ) const; // \XXX get the shape of the Spaceship
		Weapon*		getWeapon(void) const;
		bool	isAlive ( void ) const   ; // still Allive	 ?
		///////////////////////////////////////////////////

		void		setWeapon(Weapon* weapon);
		void	repaired ( unsigned int )  ; // repaired the Spaceship
		/**
		 * Operator overload
		 * */
		ASpaceShip & operator=( ASpaceShip const & rhs);
};
#endif
