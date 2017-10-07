#ifndef GAME_MAP
# define GAME_MAP

#include "AEntity.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"

class Game
{
	private :
		WINDOW** 	_box;
		AEntity*	_map;
		Hero* 		_hero;
		Enemy** 	_enemy; 
		int			_enemyNbr;

		void 		_putEntity(AEntity *entity, int x, int y);

	public :
		Game( void );
		Game ( WINDOW** box, int x, int y );
		Game( Game const & src );
		~Game( void );

		Game & operator=( Game const & rhs);

		void printMap(void);
		void eraseMap(void);

		WINDOW* getBox();

};
#endif
