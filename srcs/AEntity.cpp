#include "AEntity.hpp"
#include <iostream>
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

AEntity::AEntity(void) : _sizeX(4), _sizeY(4), _maxSpeed(10), _speed(10)
{
	this->_entityIndex = -1;
	this->_initDefinition(4, 4);

}


AEntity::AEntity(int x, int y, int entityIndex, int maxSpeed) :  _entityIndex(entityIndex), _sizeX(x), _sizeY(y), _maxSpeed(maxSpeed), _speed(maxSpeed)
{
	this->_initDefinition(x, y);
}

AEntity::AEntity(AEntity const & src )
{
	*this = src;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
AEntity::~AEntity(void)
{
	for (int i = 0; i < this->getSizeX(); i++) {
		delete this->_definition[i];
	}
	delete [] this->_definition;
}
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
AEntity & AEntity::operator=( AEntity const & rhs )
{
	this->_definition = rhs.getDefinition();
	this->_entityIndex = rhs.getEntityIndex();
	this->_sizeX = rhs.getSizeX();
	this->_sizeY = rhs.getSizeY();
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_maxSpeed = rhs.getMaxSpeed();
	this->_speed = rhs.getSpeed();

	return *this;
}


/******************************************************************************
** 								GETTEUR
******************************************************************************/
int**	AEntity::getDefinition(void) const
{
	return this->_definition;
}

int		AEntity::getEntityIndex(void) const
{
	return this->_entityIndex;
}

int		AEntity::getSizeX(void) const
{
	return this->_sizeX;
}

int		AEntity::getSizeY(void) const
{
	return this->_sizeY;
}

int		AEntity::getPosX(void) const
{
	return this->_posX;
}

int		AEntity::getPosY(void) const
{
	return this->_posY;
}

int		AEntity::getSpeed(void) const
{
	return this->_speed;
}


int		AEntity::getMaxSpeed(void) const
{
	return this->_maxSpeed;
}


/******************************************************************************
** 								SETTEUR
******************************************************************************/
void 	AEntity::setPosX(int x)
{
	this->_posX = x;

	return ;
}

void 	AEntity::setPosY(int y)
{
	this->_posY = y;

	return ;
}

void 	AEntity::setSizeX(int x)
{
	this->_sizeX = x;

	return ;
}

void 	AEntity::setSizeY(int y)
{
	this->_sizeY = y;

	return ;
}


void 	AEntity::setSpeed(int speed)
{
	this->_speed = speed;

	return ;
}

void 	AEntity::setMaxSpeed(int maxSpeed)
{
	this->_maxSpeed = maxSpeed;

	return ;
}

void 	AEntity::setDefinition(int x, int y, int value)
{
	this->_definition[x][y] =  value;

	return ;
}
void	AEntity::_initDefinition(int x, int y)
{
	int i;
	int j;

	this->_definition = new int*[x];
	for (i = 0; i < x; i++) {
		this->_definition[i] = new int[y];
		for (j = 0; j < y; j++) {
			this->_definition[i][j] = this->getEntityIndex();
		}
	}

}
