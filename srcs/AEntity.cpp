#include "AEntity.hpp"
#include <iostream>
/******************************************************************************
** 								CONSTRUCTOR
******************************************************************************/

AEntity::AEntity(void) : _sizeX(4), _sizeY(4)
{
	std::cout << "Empty AEntity Constructor" << std::endl;
	this->_initDefinition(4, 4);
	this->_entityIndex = _index;

	std::cout << __func__ <<std::endl;
}


AEntity::AEntity(int x, int y) : _sizeX(x), _sizeY(y)
{
	std::cout << "Init AEntity Constructor" << std::endl;
	this->_initDefinition(x, y);
	std::cout << "1 bis" << std::endl;
	this->_entityIndex = _index;
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

/******************************************************************************
** 								SETTEUR
******************************************************************************/
void 	AEntity::setDefinition(int x, int y, int value)
{
	this->_definition[x][y] =  value;

	return ;
}
void	AEntity::_initDefinition(int x, int y)
{
	int i = 0;
	int j = 0;

	std::cout << "initDefinition 1" << std::endl;
	this->_definition = new int*[x];
	std::cout << "initDefinition 2" << std::endl;
	for (; i < x; i++) {
		this->_definition[i] = new int[y];
		std::cout << "initDefinition 3" << std::endl;
		for (; j < y; j++) {
			this->_definition[i][j] = this->getEntityIndex();
		}
	}

	_index++;
}

int AEntity::_index = 0;
