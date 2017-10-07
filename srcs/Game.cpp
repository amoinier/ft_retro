#include "Game.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Game::Game (void)
{

	freopen("box.log", "w", stderr);
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	this->_box = subwin(stdscr, COLS, LINES, 0, 0);
	this->_map = new AEntity(getmaxx(stdscr), getmaxy(stdscr));
	this->_hero = new Hero(*new AEntity());

	wborder(this->_box, '|', '|', '-', '-', '*', '*', '*', '*');
	std::cerr << this->_box << std::endl;

	this->_putEntity(this->_hero->getShape(), 5, 5);

	std::cout << "Init Game Constructor" << std::endl;

	return ;
}

Game::Game( Game const & src )
{
	std::cout << "Copy Game Constructor" << std::endl;
	*this = src;
	return ;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
Game::~Game( void )
{
	return ;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
Game & Game::operator=( Game const & rhs )
{
	this->_box = rhs._box;
	this->_map = rhs._map;
	this->_hero = rhs._hero;
	this->_enemy = rhs._enemy;
	this->_enemyNbr = rhs._enemyNbr;

	return *this;
}

/******************************************************************************
** 							PRIVATE MEMBER FUNCTION
******************************************************************************/
void 		Game::_putEntity(AEntity &entity, int x, int y)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < entity.getSizeX(); i++) {
		for (j = 0; j < entity.getSizeY(); j++) {
			this->_map->setDefinition(i + x, j + y, entity.getDefinition()[i][j]);
		}
	}
}

/******************************************************************************
** 								GETTEUR
******************************************************************************/
WINDOW*		Game::getBox(void)
{
	return this->_box;
}

/******************************************************************************
** 								GETTEUR
******************************************************************************/
void 		Game::setBox(WINDOW* box)
{
	this->_box = box;

	return ;
}

/******************************************************************************
** 							PUBLIC MEMBER FUNCTION
******************************************************************************/
void Game::printMap(void)
{
	freopen("error.log", "w", stderr);
	int i = 0;
	int j = 0;

	std::cerr << this->_map->getSizeX() << std::endl;
	std::cerr << this->_map->getSizeY() << std::endl;


	for (i = 0; i < this->_map->getSizeX(); i++) {
		for (j = 0; j < this->_map->getSizeY(); j++) {
			std::cerr << this->_map->getDefinition()[i][j];
			if (this->_map->getDefinition()[i][j] != 0) {
				mvwaddch(this->getBox(), j, i, '@');
			}
			else {
				mvwaddch(this->getBox(), j, i, '*');
			}
		}
		std::cerr << std::endl;
	}
}

void Game::eraseMap(void)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < this->_map->getSizeX(); i++) {
		for (j = 0; j < this->_map->getSizeY(); j++) {
			if (this->_map->getDefinition()[i][j] != 0) {
				mvwaddch(this->getBox(), j, i, ' ');
			}
			else {
				mvwaddch(this->getBox(), j, i, '=');
			}
		}
	}
}
