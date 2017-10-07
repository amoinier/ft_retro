#include "AEntity.hpp"
#include <iostream>
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

AEntity::AEntity(void) : _sizeX(4), _sizeY(4)
{
	this->_definition = new int[4][4];
	this->_entityIndex = index;
	this->_initDefinition();

	std::cout << __func__ <<std::endl;
}


AEntity::AEntity(int x, int y) : _sizeX(x), _sizeY(y)
{
	this->_definition = new int[x][y];
	this->_initDefinition();

	std::cout << __func__ <<std::endl;
}
 
AEntity::AEntity(AEntity const & src )
{
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

int		getSizeX(void) const
{
	return this->_sizeX;
}

int		getSizeY(void) const
{
	return this->_sizeY;
}

/******************************************************************************
** 								SETTEUR
******************************************************************************/
void	AEntity::_initDefinition(int x, int y)
{
	int i = 0;
	int j = 0;

	for (i; i < x; x++) {
		for (j; j < y; y++) {
			this->_definition[i][j] = this->getEntityIndex();
		}
	}

	_index++;
}

int _index = 0;
