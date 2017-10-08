#ifndef AENTITY_HPP
# define AENTITY_HPP

class AEntity {

	protected :
		int				_entityIndex;
		int**			_definition;
		int				_sizeX;
		int				_sizeY;
		int				_posX;
		int				_posY;
		int				_maxSpeed;
		int				_speed;

	private :
		void			_initDefinition(int x, int y);

	public :
		AEntity( void );
		AEntity( AEntity const & src );
		AEntity( int x, int y, int entityIndex, int maxSpeed);
		~AEntity( void );

		int**	getDefinition() const;
		int		getEntityIndex(void) const;
		int		getSizeX(void) const;
		int		getSizeY(void) const;
		int		getPosX(void) const;
		int		getPosY(void) const;
		int		getMaxSpeed(void) const;
		int		getSpeed(void) const;

		void 	setDefinition(int x, int y, int value);
		void 	setPosX(int x);
		void 	setPosY(int y);
		void 	setSizeX(int x);
		void 	setSizeY(int y);
		void 	setMaxSpeed(int maxSpeed);
		void 	setSpeed(int speed);

		AEntity & operator=( AEntity const & rhs);
};
#endif
