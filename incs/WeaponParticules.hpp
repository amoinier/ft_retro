#ifndef WEAPONPARTICULES_HPP
# define WEAPONPARTICULES_HPP
/**
 * shoot on little cute particule
 *\XXX made a Super class
 * */

#include "AEntity.hpp"

class WeaponParticules
{

	private :
		typedef struct	s_bullet{
			AEntity		*_entity; // create an entity each type is shoot
			s_bullet	*next;
		}				t_bullet;
		unsigned int _damage;
		unsigned int _type;// type of shooting


		void new_bullet( void );
		t_bullet	*_begin;

	public :
		WeaponParticules( void );
		WeaponParticules( WeaponParticules const & src );
		~WeaponParticules( void );

		WeaponParticules & operator=( WeaponParticules const & rhs);


		void	shoot();
		/**
		 * 								GUETTEUR
		*/
		unsigned int getDamage( void ) const;
		unsigned int getType( void ) const;
//		AEntity *getEntity( void ) const;
};
#endif
