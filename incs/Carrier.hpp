#ifndef CARRIER_HPP
# define CARRIER_HPP


#include "Enemy.hpp"

class Carrier : public Enemy
{
	private :
		Carrier( void );

	public :
		Carrier( Weapon *Weapon, unsigned int color);
		Carrier( Carrier const & src );
		~Carrier( void );

		Carrier & operator=( Carrier const & rhs);

};
#endif
