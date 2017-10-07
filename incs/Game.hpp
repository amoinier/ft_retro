#ifndef GAME_MAP
# define GAME_MAP

#include <ncurses.h>
#include <iostream>
#include "AEntity.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"

class Game
{
	private :
		WINDOW* 	_box;
		AEntity*	_map;
		Hero* 		_hero;
		Enemy** 	_enemy;
		int			_enemyNbr;

		void 		_putEntity(AEntity &entity, int x, int y);
		void 		_deleteEntity(AEntity &entity);
		bool		_moveEntityUp(AEntity &entity);
		bool		_moveEntityDown(AEntity &entity);
		bool		_moveEntityLeft(AEntity &entity);
		bool		_moveEntityRight(AEntity &entity);

	public :
		Game( void );
		Game( Game const & src );
		~Game( void );

		Game & operator=( Game const & rhs);

		void printMap(void);
		void eraseMap(void);
		void moveEntity(AEntity &entity, int vecteur);
		void play(int ch);

		WINDOW* getBox();

		void 		setBox(WINDOW* box);

};
#endif
