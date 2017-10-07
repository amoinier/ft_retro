#ifndef HERO_HPP
# define HERO_HPP

#include "IEntity.hpp"
#include "ASpaceShip.hpp"

class Hero : ASpaceShip
{
	private :
		Hero( void );

	public :
		Hero ( IEntity const & shpae );
		Hero ( IEntity const & shpae , IWeapon *weapon );
		Hero( Hero const & src );
		~Hero( void );

		//Hero & operator=( Hero const & rhs);
};
#endif
