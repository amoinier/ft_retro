#include "Game.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Game::Game (void)
{
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	this->_box = stdscr;
	this->_map = new AEntity(getmaxx(stdscr) - 1, getmaxy(stdscr) - 1);
	this->_hero = new Hero(*new AEntity());

	this->_putEntity(this->_hero->getShape(), (this->_map->getSizeX() - this->_hero->getShape().getSizeX()) / 2,
	this->_map->getSizeY() - this->_hero->getShape().getSizeY());

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

	entity.setPosX(x);
	entity.setPosY(y);

	for (i = 0; i < entity.getSizeX(); i++) {
		for (j = 0; j < entity.getSizeY(); j++) {
			if (entity.getDefinition()[i][j] != 0) {
				this->_map->setDefinition(i + x, j + y, entity.getDefinition()[i][j]);
			}
		}
	}
}

void 		Game::_deleteEntity(AEntity &entity)
{
	int i = 0;
	int j = 0;
	int x = entity.getPosX();
	int y = entity.getPosY();

	for (i = 0; i < entity.getSizeX(); i++) {
		for (j = 0; j < entity.getSizeY(); j++) {
			if (entity.getDefinition()[i][j] != 0) {
				this->_map->setDefinition(i + x, j + y, 0);
			}
		}
	}
}

bool 		Game::_moveEntityUp(AEntity &entity)
{
	if (entity.getPosY() > 1) {
		entity.setPosY(entity.getPosY() - 1);

		return true;
	}
	else {
		return false;
	}
}

bool 		Game::_moveEntityDown(AEntity &entity)
{
	if (entity.getPosY() + entity.getSizeY() < this->_map->getSizeY()) {
		entity.setPosY(entity.getPosY() + 1);

		return true;
	}
	else {
		return false;
	}
}

bool 		Game::_moveEntityLeft(AEntity &entity)
{
	if (entity.getPosX() > 1) {
		entity.setPosX(entity.getPosX() - 1);

		return true;
	}
	else {
		return false;
	}
}

bool 		Game::_moveEntityRight(AEntity &entity)
{
	if (entity.getPosX() + entity.getSizeX() < this->_map->getSizeX()) {
		entity.setPosX(entity.getPosX() + 1);

		return true;
	}
	else {
		return false;
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
	int i = 0;
	int j = 0;

	for (i = 0; i < this->_map->getSizeX(); i++) {
		for (j = 0; j < this->_map->getSizeY(); j++) {
			if (this->_map->getDefinition()[i][j] != 0) {
				mvwaddch(this->getBox(), j, i, '@');
			}
			else {
				mvwaddch(this->getBox(), j, i, ' ');
			}
		}
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
		}
	}
}

void 		Game::moveEntity(AEntity &entity, int vecteur)
{
	this->_deleteEntity(entity);

	switch (vecteur)
	{
	case 1: // haut
		this->_moveEntityUp(entity);
		break;

	case 2: // bas
		this->_moveEntityDown(entity);
		break;

	case 3: // gauche
		this->_moveEntityLeft(entity);
		break;

	case 4: // droite
		this->_moveEntityRight(entity);
		break;
	default:
		break;
	}

	this->_putEntity(entity, entity.getPosX(), entity.getPosY());

	return ;

}

void Game::play(int ch)
{
	// if (ch == 27) {
	// 	break ;
	// }
	if (ch == 259) {
		this->moveEntity(this->_hero->getShape(), 1);
	}
	if (ch == 258) {
		this->moveEntity(this->_hero->getShape(), 2);
	}
	if (ch == 260) {
		this->moveEntity(this->_hero->getShape(), 3);
	}
	if (ch == 261) {
		this->moveEntity(this->_hero->getShape(), 4);
	}
}
