#ifndef HERO_HPP
# define HERO_HPP

#include "AEntity.hpp"
#include "ASpaceShip.hpp"

class Hero : public ASpaceShip
{
	private :
		int _score;

		Hero( void );

	public :
		Hero ( AEntity & shape );
		Hero ( AEntity & shape , Weapon *weapon );
		Hero( Hero const & src );
		~Hero( void );

		Hero & operator=( Hero const & rhs);

		static int defaultDefinition[3][3];

		int 	getScore(void) const;

		void 	setScore(int score);
};
#endif
