#ifndef AENTITY_HPP
# define AENTITY_HPP

#include "IWeapon.hpp"
#include "IEntity.hpp"

class AEntity : public IEntity
{
	protected : 
		int				_entityIndex;
		int**			_definition;
		int				_sizeX;
		int				_sizeY;

	private :
		void			_initDefinition(int x, int y);
		static int 		_index;



	public :

		AEntity( void );

		virtual ~AEntity( void ) {};

		AEntity( AEntity const & src );

		AEntity( int x, int y );

		int**	getDefinition() const;
		int		getEntityIndex(void) const;
		int		getSizeX(void) const;
		int		getSizeY(void) const;







		/**
		 * Ascessor
		 * */
		///////////////////////////////////////////////////

		/**
		 * Operator overload
		 * */
		AEntity & operator=( AEntity const & rhs);
};
#endif
