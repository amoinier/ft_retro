#include "Game.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/
Game::Game ( void )
{
	return ;
}

Game::Game ( WINDOW** box, int x, int y ):
	_box(box), _map(new AEntity(x, y)), _Hero(new Hero(new AEntity())
{

	return ;
}

Game::Game( Game const & src ) 
{
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
	return ;
}

/******************************************************************************
** 							PRIVATE MEMBER FUNCTION
******************************************************************************/
void 		Game::_putEntity(AEntity *entity, int x, int y)
{
	int i = 0;
	int j = 0;

	for (i; i < entity.getSizeX(); i++) {
		for (j; j < entity.getSizeY(); j++) {
			this->_map[i + x][j + y] = entity[i][j];
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
** 							PUBLIC MEMBER FUNCTION
******************************************************************************/
void Game::printMap(void)
{
	int i = 0;
	int j = 0;

	for (i; i < this->_map->getSizeX(); i++) {
		for (j; j < this->_map->getSizeY(); j++) {
			if (this->_map->_definition[i][j] != 0) {
				mvwaddch(this->_box, j, i, '@');
			}
		}
	}
}

void Game::eraseMap(void)
{
	int i = 0;
	int j = 0;

	for (i; i < this->_map->getSizeX(); i++) {
		for (j; j < this->_map->getSizeY(); j++) {
			if (this->_map->_definition[i][j] != 0) {
				mvwaddch(this->_box, j, i, ' ');
			}
		}
	}
}
