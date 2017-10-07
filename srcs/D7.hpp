#ifndef D7_HPP
# define D7_HPP

#include "Enemy.hpp"

class D7 : public Enemy
{
	private :
		D7( void );

	public :
		D7( IEntity const & shape, IWeapon *Weapon, unsigned int color);
		D7( D7 const & src );
		~D7( void );
		D7 & operator=( D7 const & rhs);
};
#endif
