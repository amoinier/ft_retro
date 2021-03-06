#ifndef GAME_MAP
# define GAME_MAP

#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "AEntity.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "D7.hpp"
#include "Vor_cha.hpp"
#include "Bullet.hpp"
#include "Carrier.hpp"

class Game
{
	private :
		WINDOW* 	_box;
		AEntity*	_map;
		Hero* 		_hero;
		Enemy**	 	_enemies;
		int			_enemyNbr;
		int 		_enemyNbrMax;
		Bullet*		_bulletList;

		void 		_initEnemy(void);
		void 		_newWave(void);
		void 		_putEntity(Hero &hero, int x, int y);
		void 		_putEntity(Enemy &enemy, int x, int y);
		void 		_putEntity(Bullet &Bullet, int x, int y);
		void 		_deleteEntity(AEntity &entity);
		bool		_moveEntityUp(AEntity &entity);
		bool		_moveEntityDown(AEntity &entity);
		bool		_moveEntityLeft(AEntity &entity);
		bool		_moveEntityRight(AEntity &entity);
		void		_deleteBullet(Bullet* bullet);
		Bullet*		_findBullet(int posX, int posY);

		void		_pushBullet(Bullet *bullet, int x, int y);



		Bullet* 		_checkBullet(int index);
		Bullet* 		_checkBullet(void);

		Enemy*			_callD7(void) const;
		Enemy*			_callVor_cha(void) const;
		Enemy*			_callCarrier(void) const;

		Game( void );

	public :
		Game( int enemyNbr );
		Game( Game const & src );
		~Game( void );

		Game & operator=( Game const & rhs);

		void printMap(void);
		void eraseMap(void);
		void moveEntity(Hero &hero, int vecteur);
		void play(int ch);
		void moveEnemies(void);
		void shootEnemies(void);
		void moveBullet(void);
		void useWeapon(void);

		void gameOver(void);


		WINDOW* getBox();

		void 		setBox(WINDOW* box);
		void 		setSizeMap(int x, int y);

		static std::time_t countTime;

		static std::time_t timeGame;


};
#endif
