#include "Game.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/
Game::Game ( void )
{
	std::cout << "Empty Game Constructor" << std::endl;

	return ;
}

Game::Game ( WINDOW** box, int x, int y ):	_box(box), _map(new AEntity(x, y)), _hero(new Hero(*new AEntity()))
{
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
void 		Game::_putEntity(AEntity *entity, int x, int y)
{
	int i = 0;
	int j = 0;

	for (; i < entity->getSizeX(); i++) {
		for (; j < entity->getSizeY(); j++) {
			this->_map->setDefinition(i + x, j + y, entity->getDefinition()[i][j]);
		}
	}
}

/******************************************************************************
** 								GETTEUR
******************************************************************************/
WINDOW*		Game::getBox(void)
{
	return *this->_box;
}

/******************************************************************************
** 								GETTEUR
******************************************************************************/
void 		Game::setBox(WINDOW** box)
{
	this->_box = box;

	return ;
}

/******************************************************************************
** 							PUBLIC MEMBER FUNCTION
******************************************************************************/
void Game::printMap(void)
{
	int i = 0;
	int j = 0;

	for (; i < this->_map->getSizeX(); i++) {
		for (; j < this->_map->getSizeY(); j++) {
			if (this->_map->getDefinition()[i][j] != 0) {
				mvwaddch(this->getBox(), j, i, '@');
			}
			else {
				mvwaddch(this->getBox(), j, i, '*');
			}
		}
	}
}

void Game::eraseMap(void)
{
	int i = 0;
	int j = 0;

	for (; i < this->_map->getSizeX(); i++) {
		for (; j < this->_map->getSizeY(); j++) {
			if (this->_map->getDefinition()[i][j] != 0) {
				mvwaddch(this->getBox(), j, i, ' ');
			}
			else {
				mvwaddch(this->getBox(), j, i, '=');
			}
		}
	}
}
