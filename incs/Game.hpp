#ifndef GAME_MAP
# define GAME_MAP

#include <ncurses.h>
#include <iostream>
#include "AEntity.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "D7.hpp"
#include "Vor_cha.hpp"

class Game
{
	private :
		WINDOW* 	_box;
		AEntity*	_map;
		Hero* 		_hero;
		Enemy**	 	_enemies;
		int			_enemyNbr;
		int 		_enemyNbrMax;

		void 		_initEnemy(void);
		void 		_newWave(void);
		void 		_putEntity(AEntity &entity, int x, int y);
		void 		_deleteEntity(AEntity &entity);
		bool		_moveEntityUp(AEntity &entity);
		bool		_moveEntityDown(AEntity &entity);
		bool		_moveEntityLeft(AEntity &entity);
		bool		_moveEntityRight(AEntity &entity);

		Game( void );

	public :
		Game( int enemyNbr );
		Game( Game const & src );
		~Game( void );

		Game & operator=( Game const & rhs);

		void printMap(void);
		void eraseMap(void);
		void moveEntity(AEntity &entity, int vecteur);
		void play(int ch);
		void moveEnemies(void);


		WINDOW* getBox();

		void 		setBox(WINDOW* box);

};
#endif
