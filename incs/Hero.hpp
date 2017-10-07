#ifndef HERO_HPP
# define HERO_HPP

#include "AEntity.hpp"
#include "ASpaceShip.hpp"

class Hero : ASpaceShip
{
	private :
		Hero( void );

	public :
		Hero ( AEntity const & shape );
		Hero ( AEntity const & shape , IWeapon *weapon );
		Hero( Hero const & src );
		~Hero( void );

		//Hero & operator=( Hero const & rhs);
};
#endif
