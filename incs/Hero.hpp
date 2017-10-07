#ifndef HERO_HPP
# define HERO_HPP

#include "AEntity.hpp"
#include "ASpaceShip.hpp"

class Hero : public ASpaceShip
{
	private :
		Hero( void );

	public :
		Hero ( AEntity & shape );
		Hero ( AEntity & shape , IWeapon *weapon );
		Hero( Hero const & src );
		~Hero( void );

		//Hero & operator=( Hero const & rhs);
};
#endif
