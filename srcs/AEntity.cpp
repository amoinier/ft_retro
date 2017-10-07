#include "AEntity.hpp"
#include <iostream>
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

AEntity::AEntity(void) : _sizeX(4), _sizeY(4)
{
	std::cout << "Empty AEntity Constructor" << std::endl;
	this->_entityIndex = AEntity::_index;
	this->_initDefinition(4, 4);

	std::cout << __func__ <<std::endl;
}


AEntity::AEntity(int x, int y) : _sizeX(x), _sizeY(y)
{
	std::cout << "Init AEntity Constructor" << std::endl;
	this->_entityIndex = AEntity::_index;
	this->_initDefinition(x, y);
	std::cout << "1 bis" << std::endl;
	std::cout << "2 bis" << std::endl;

	std::cout << __func__ <<std::endl;
}

AEntity::AEntity(AEntity const & src )
{
	std::cout << "Copy AEntity Constructor" << std::endl;
	*this = src;
}
/******************************************************************************
** 							DESTRUCTOR
******************************************************************************/
/******************************************************************************
** 							OPERATOR OVERLOAD
******************************************************************************/
AEntity & AEntity::operator=( AEntity const & rhs )
{
	this->_definition = rhs.getDefinition();
	this->_entityIndex = rhs.getEntityIndex();
	this->_sizeX = rhs.getSizeX();
	this->_sizeY = rhs.getSizeY();

	return *this;
}


/******************************************************************************
** 								GETTEUR
******************************************************************************/
int**		AEntity::getDefinition(void) const
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

	AEntity::_index++;
}

int AEntity::_index = 0;
