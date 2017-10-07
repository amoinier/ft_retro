#ifndef VOR_CHA_HPP
# define VOR_CHA_HPP


#include "Enemy.hpp"

class Vor_cha : public Enemy
{
	private :

	public :
		Vor_cha( IWeapon *Weapon, unsigned int color);
		Vor_cha( Vor_cha const & src );
		~Vor_cha( void );

//		Vor_cha & operator=( Vor_cha const & rhs);
};
#endif
