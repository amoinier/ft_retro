#ifndef ASPACESHIP_HPP
# define ASPACESHIP_HPP

#include "IWeapon.hpp"
#include "IEntity.hpp"

class ASpaceShip
{
	protected :
			unsigned int _hp;
			unsigned int _hpMax;
			unsigned int _speed;
			IEntity		const &_shape; // XXX
			IWeapon		*_weapon; //XXX interface ???

	private :

			ASpaceShip( void );

	public :

		virtual ~ASpaceShip( void ) {};

		ASpaceShip( ASpaceShip const & src );

		ASpaceShip( unsigned int hp, IEntity const & shape);
		ASpaceShip( unsigned int hp, IEntity const & shape, IWeapon * weapon);




		void		attack ( void ) const ; // use is weapon 	



		/**
		 * Ascessor
		 * */
		IEntity const & getShape( void ) ; // \XXX get the shape of the Spaceship
		unsigned int		getSpeed( void ) const ; //return the speed of  the Spaceship
		bool	isAlive ( void ) const   ; // still Allive	 ?
		///////////////////////////////////////////////////

		void	repaired ( unsigned int )  ; // repaired the Spaceship
		/**
		 * Operator overload
		 * */
		ASpaceShip & operator=( ASpaceShip const & rhs);
};
#endif