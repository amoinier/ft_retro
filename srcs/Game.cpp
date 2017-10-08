#include "Game.hpp"
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

Game::Game (int enemyNbr) :  _enemyNbr(0), _enemyNbrMax(enemyNbr), _bulletList(NULL)
{
	std::srand(std::time(NULL) + std::clock());
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	this->_box = stdscr;
	this->_map = new AEntity(getmaxx(stdscr) - 1, getmaxy(stdscr) - 1, 0, 1);
	this->_hero = new Hero(*new AEntity(3, 3, 1, 5), new Weapon());
	this->_initEnemy();

	this->_putEntity(*this->_hero, (this->_map->getSizeX() - this->_hero->getShape().getSizeX()) / 2,
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
	this->_enemyNbr = rand() % (this->_map->getSizeX() / 6); // 6 == LARGEST SPACESHIP X
	Enemy* (Game::*Func[])(void) const = {&Game::_callD7, &Game::_callVor_cha};

	for (int i = 0; i < this->_enemyNbr; i++) {
		if (!this->_enemies[i]) {
			this->_enemies[i] = (this->*Func[rand() % 2])();
			this->_putEntity(*this->_enemies[i], ((this->_map->getSizeX() / (this->_enemyNbr)) * (i)) + 1, 0);
		}
	}

	return ;
}

void 		Game::_putEntity(Hero &hero, int x, int y)
{
	int i = 0;
	int j = 0;

	hero.getShape().setPosX(x);
	hero.getShape().setPosY(y);

	for (i = 0; i < hero.getShape().getSizeX(); i++) {
		for (j = 0; j < hero.getShape().getSizeY(); j++) {

			if (hero.getShape().getDefinition()[i][j] != this->_map->getDefinition()[i + x][j + y] && this->_map->getDefinition()[i + x][j + y] != 0) { //TOCHANGE

				endwin();
				return exit(0);
			}

			if (hero.defaultDefinition[i][j] != 0) {

				this->_map->setDefinition(i + x, j + y, hero.getShape().getDefinition()[i][j]);
			}

		}
	}
}

void 		Game::_putEntity(Enemy &enemy, int x, int y)
{
	int i = 0;
	int j = 0;

	enemy.getShape().setPosX(x);
	enemy.getShape().setPosY(y);

	for (i = 0; i < enemy.getShape().getSizeX(); i++) {
		for (j = 0; j < enemy.getShape().getSizeY(); j++) {

			if (enemy.getShape().getDefinition()[i][j] != this->_map->getDefinition()[i + x][j + y] && this->_map->getDefinition()[i + x][j + y] == 1) {
				endwin();
				return exit(0);
			}

			if (enemy.getShape().getDefinition()[i][j] != 0) {
				this->_map->setDefinition(i + x, j + y, enemy.getShape().getDefinition()[i][j]);
			}

		}
	}
}

void 		Game::_putEntity(Bullet &bullet, int x, int y)
{
	int i = 0;
	int j = 0;

	bullet.getBullet().setPosX(x);
	bullet.getBullet().setPosY(y);

	for (i = 0; i < bullet.getBullet().getSizeX(); i++) {
		for (j = 0; j < bullet.getBullet().getSizeY(); j++) {

			if (bullet.getBullet().getDefinition()[i][j] != this->_map->getDefinition()[i + x][j + y] && this->_map->getDefinition()[i + x][j + y] != 0) {
			}

			if (bullet.getBullet().getDefinition()[i][j] != 0) {
				this->_map->setDefinition(i + x, j + y, bullet.getBullet().getDefinition()[i][j]);
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
	return new D7(new Weapon(), 0x0);
}

Enemy*	Game::_callVor_cha(void) const
{
	return new Vor_cha(new Weapon(), 0x0);
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

void 		Game::setSizeMap(int x, int y)
{
	int tmpX = ((this->_map->getSizeX() < x - 1) ? this->_map->getSizeX() : x - 1);
	int tmpY = ((this->_map->getSizeY() < y - 1) ? this->_map->getSizeY() : y - 1);

	for (int i = 0; i < this->_enemyNbrMax; i++) {
		if (this->_enemies[i] != NULL) {
			if (this->_enemies[i]->getShape().getPosX() + this->_enemies[i]->getShape().getSizeX() > x - 1 ||
			this->_enemies[i]->getShape().getPosY() + this->_enemies[i]->getShape().getSizeY() > y - 1) {
				this->_deleteEntity(this->_enemies[i]->getShape());
				this->_enemyNbr--;
				delete this->_enemies[i];
				this->_enemies[i] = NULL;
			}
		}
	}



	if (this->_hero->getShape().getPosX() + this->_hero->getShape().getSizeX() > x - 1 ||
	this->_hero->getShape().getPosY() + this->_hero->getShape().getSizeY() > y - 1) {
		endwin();
		return exit(0);
	}



	Bullet *tmpBullet = this->_bulletList;
	Bullet *tmp2;

	if (tmpBullet) {
		while (tmpBullet) {
			if (tmpBullet->getBullet().getPosX() + tmpBullet->getBullet().getSizeX() > x - 1 ||
			tmpBullet->getBullet().getPosY() + tmpBullet->getBullet().getSizeY() > y - 1) {
				this->_deleteEntity(tmpBullet->getBullet());
				if (tmpBullet->getNext()) {
					tmpBullet->getNext()->setPrev(tmpBullet->getPrev());
				}
				if (tmpBullet->getPrev()) {
					tmpBullet->getPrev()->setNext(tmpBullet->getNext());
				}

				if (tmpBullet == this->_bulletList) {
					this->_bulletList = tmpBullet->getNext();
				}
				tmp2 = tmpBullet->getNext();

				delete tmpBullet;
				tmpBullet = NULL;
				tmpBullet = tmp2;
				continue;
			}

			tmpBullet = tmpBullet->getNext();
		}
	}


	int** tmp = this->_map->getDefinition();
	delete this->_map;
	this->_map = NULL;
	this->_map = new AEntity(x - 1, y - 1, 0, 1);

	for (int i = 0; i < tmpX; i++) {
		for (int j = 0; j < tmpY; j++) {
			if (tmp[i][j] != 0) {
				this->_map->setDefinition(i, j, tmp[i][j]);
			}
		}
	}


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
			if (this->_map->getDefinition()[i][j] == 1) {
				mvwaddch(this->getBox(), j, i, '#');
			}
			else if (this->_map->getDefinition()[i][j] == 2) {
				mvwaddch(this->getBox(), j, i, '@');
			}
			else if (this->_map->getDefinition()[i][j] == 3) {
				mvwaddch(this->getBox(), j, i, '*');
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

void 		Game::moveEntity(Hero &hero, int vecteur)
{
	this->_deleteEntity(hero.getShape());

	switch (vecteur)
	{
	case 1: // haut
		this->_moveEntityUp(hero.getShape());
		break;

	case 2: // bas
		this->_moveEntityDown(hero.getShape());
		break;

	case 3: // gauche
		this->_moveEntityLeft(hero.getShape());
		break;

	case 4: // droite
		this->_moveEntityRight(hero.getShape());
		break;
	default:
		break;
	}

	this->_putEntity(hero, hero.getShape().getPosX(), hero.getShape().getPosY());

	return ;

}

int Game::_checkBullet(int index)
{
	int i = 0;
	int j = 0;


	for (i = 0; i < this->_enemies[index]->getShape().getSizeX(); i++) {
		for (j = 0; j < this->_enemies[index]->getShape().getSizeY(); j++) {

			if (this->_map->getDefinition()[i + this->_enemies[index]->getShape().getPosX()][j + this->_enemies[index]->getShape().getPosY()] == 3) {
				return this->_deleteBullet(i + this->_enemies[index]->getShape().getPosX(), j + this->_enemies[index]->getShape().getPosY());
			}

		}
	}

	return 0;
}

int Game::_deleteBullet(int posX, int posY)
{
	Bullet *tmp = this->_bulletList;
	int dmg = 0;

	if (!tmp) {
		return dmg;
	}
	else {
		while (tmp) {
			if (tmp->getBullet().getPosX() == posX && tmp->getBullet().getPosY() == posY) {
				dmg = tmp->getDmg();
				this->_deleteEntity(tmp->getBullet());
				if (tmp->getNext()) {
					tmp->getNext()->setPrev(tmp->getPrev());
				}
				if (tmp->getPrev()) {
					tmp->getPrev()->setNext(tmp->getNext());
				}

				if (tmp == this->_bulletList) {
					this->_bulletList = tmp->getNext();
				}
				delete tmp;
				tmp = NULL;
				return dmg;
			}

			tmp = tmp->getNext();
		}
		return dmg;
	}
}

void 		Game::moveEnemies(void)
{
	int i = 0;
	int dmg = 0;

	for (i = 0; i < this->_enemyNbrMax; i++) {
		if (this->_enemies[i] != NULL) {
			if (!(dmg = this->_checkBullet(i))) {
				if (this->_enemies[i]->move())
				{
					this->_deleteEntity(this->_enemies[i]->getShape());
					if (this->_enemies[i]->enemyMove(this->_map->getSizeX(), this->_map->getSizeY())) {
						this->_putEntity(*this->_enemies[i], this->_enemies[i]->getShape().getPosX(), this->_enemies[i]->getShape().getPosY());
					}
					else {
						this->_enemyNbr--;
						delete this->_enemies[i];
						this->_enemies[i] = NULL;
					}
				}
			}
			else {
				this->_enemies[i]->setHp(this->_enemies[i]->getHp() - dmg);
				if (this->_enemies[i]->getHp() <= 0) {
					this->_deleteEntity(this->_enemies[i]->getShape());
					this->_enemyNbr--;
					delete this->_enemies[i];
					this->_enemies[i] = NULL;
				}
			}
		}
	}

	return ;
}


void 		Game::moveBullet(void)
{
	Bullet *tmp = this->_bulletList;
	Bullet *tmp2 = this->_bulletList;

	if (!tmp) {
		return ;
	}
	else {
		while (tmp) {
			if (tmp->move()) {
				this->_deleteEntity(tmp->getBullet());
				if (tmp->bulletMove(this->_map->getSizeX(), this->_map->getSizeY())) {
					this->_putEntity(*tmp, tmp->getBullet().getPosX(), tmp->getBullet().getPosY());
				}
				else {
					if (tmp->getNext()) {
						tmp->getNext()->setPrev(tmp->getPrev());
					}

					if (tmp->getPrev()) {
						tmp->getPrev()->setNext(tmp->getNext());
					}
					if (tmp == this->_bulletList) {
						this->_bulletList = tmp->getNext();
					}
					tmp2 = tmp->getNext();

					delete tmp;
					tmp = NULL;
					tmp = tmp2;
					continue;
				}
			}
			tmp = tmp->getNext();
		}
	}
}

void Game::useWeapon(void)
{
	Bullet *tmp = this->_bulletList;

	if (!tmp) {
		this->_bulletList = this->_hero->getWeapon()->shoot(1);
		this->_putEntity(*this->_bulletList, this->_hero->getShape().getPosX() + 1, this->_hero->getShape().getPosY() - 1);

		return ;
	}

	while (tmp->getNext()) {
		tmp = tmp->getNext();
	}

	tmp->setNext(this->_hero->getWeapon()->shoot(1));
	tmp->getNext()->setPrev(tmp);
	this->_putEntity(*tmp->getNext(), this->_hero->getShape().getPosX() + 1, this->_hero->getShape().getPosY() - 1);

	return ;
}


void Game::play(int ch)
{
	if (ch == 410) {
		this->setSizeMap(getmaxx(this->getBox()), getmaxy(this->getBox()));
		clear();
	}
	if (ch == 27) {
		endwin();
		return exit(0);
	}
	else if (ch == 259) {
		this->moveEntity(*this->_hero, 1);
	}
	else if (ch == 258) {
		this->moveEntity(*this->_hero, 2);
	}
	else if (ch == 260) {
		this->moveEntity(*this->_hero, 3);
	}
	else if (ch == 261) {
		this->moveEntity(*this->_hero, 4);
	}

	else if (ch == 32) {
		this->useWeapon();
	}

	if (this->_enemyNbr == 0) {
		this->_newWave();
	}
	else {
		this->moveEnemies();
	}

	this->moveBullet();

}
