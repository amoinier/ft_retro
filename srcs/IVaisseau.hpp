#ifndef AVAISSEAU_HPP
# define AVAISSEAU_HPP

#include "IEntity.hpp"

class AVaisseau
{
	private :

	public :
		virtual ~AVaisseau( void ) {};

		virtual	IEntity *getShape( void ) const ; // \XXX get the shape of the Spaceship
		virtual	int		getSpeed( void ) const ; //return the speed of  the Spaceship
		virtual void	attack ( void ) const ; // use is weapon 	
		virtual void	repaired ( unsigned int )  ; // repaired the Spaceship
		virtual bool	isAlive ( unsigned int )  ; // still Allive	 ?
		virtual AVaisseau & operator=( AVaisseau const & rhs) = 0;
};
#endif
