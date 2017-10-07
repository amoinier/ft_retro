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
		int				_posX;
		int				_posY;

	private :
		void			_initDefinition(int x, int y);
		static int 		_index;



	public :

		AEntity( void );

		~AEntity( void );

		AEntity( AEntity const & src );

		AEntity( int x, int y );

		int**	getDefinition() const;
		int		getEntityIndex(void) const;
		int		getSizeX(void) const;
		int		getSizeY(void) const;
		int		getPosX(void) const;
		int		getPosY(void) const;

		void 	setDefinition(int x, int y, int value);
		void 	setPosX(int x);
		void 	setPosY(int y);





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
