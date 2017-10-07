#include "Game.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Game::Game (int enemyNbr) :  _enemyNbr(0), _enemyNbrMax(enemyNbr)
{
	std::srand(std::time(NULL) + std::clock());
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	this->_box = stdscr;
	this->_map = new AEntity(getmaxx(stdscr) - 1, getmaxy(stdscr) - 1);
	this->_hero = new Hero(*new AEntity());
	this->_initEnemy();

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
	this->_enemies = rhs._enemies;
	this->_enemyNbr = rhs._enemyNbr;
	this->_enemyNbrMax = rhs._enemyNbrMax;

	return *this;
}

/******************************************************************************
** 							PRIVATE MEMBER FUNCTION
******************************************************************************/
void 		Game::_initEnemy(void)
{
	this->_enemies = new Enemy*[this->_enemyNbrMax];
	for (int i = 0; i < this->_enemyNbrMax; i++) {
		this->_enemies[i] = NULL;
	}

	return ;
}

void 		Game::_newWave(void)
{
	this->_enemyNbr = rand() % this->_enemyNbrMax;
	Enemy* (Game::*Func[])(void) const = {&Game::_callD7, &Game::_callVor_cha};

	for (int i = 0; i < this->_enemyNbr; i++) {
		if (!this->_enemies[i]) {
			this->_enemies[i] = (this->*Func[rand() % 2])();
			this->_putEntity(this->_enemies[i]->getShape(), ((this->_map->getSizeX() / (this->_enemyNbr)) * (i)) + 1, 5);
		}
	}

	return ;
}

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

Enemy*			Game::_callD7(void) const
{
	return new D7(new IWeapon(), 0x0);
}

Enemy*	Game::_callVor_cha(void) const
{
	return new Vor_cha(new IWeapon(), 0x0);
}


/******************************************************************************
** 								GETTEUR
******************************************************************************/
WINDOW*		Game::getBox(void)
{
	return this->_box;
}

/******************************************************************************
** 								SETTEUR
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

void 		Game::moveEnemies(void)
{
	int i = 0;

	for (i = 0; i < this->_enemyNbrMax; i++) {
		if (this->_enemies[i] != NULL && this->_enemies[i])
		{
			this->_deleteEntity(this->_enemies[i]->getShape());
			if (this->_enemies[i]->enemyMove(this->_map->getSizeX(), this->_map->getSizeY())) {
				this->_putEntity(this->_enemies[i]->getShape(), this->_enemies[i]->getShape().getPosX(), this->_enemies[i]->getShape().getPosY());
			}else{
				this->_enemyNbr--;
				delete this->_enemies[i];
				this->_enemies[i] = NULL;
			}
		}
	}

	return ;
}

void Game::play(int ch)
{
	if (ch == 27) {
		endwin();
		return exit(0);
	}
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

	if (this->_enemyNbr == 0) {
		this->_newWave();
	}
	else {
		this->moveEnemies();
	}

}
