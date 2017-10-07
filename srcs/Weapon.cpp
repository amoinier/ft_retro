#include "Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::Weapon(Weapon const & src)
{
	*this = src;
}

Weapon::~Weapon(void)
{

}


Weapon& Weapon::operator=(Weapon const & rhs)
{
	(void)rhs;

	return *this;
}

Bullet*	shoot(int direction)
{
	Bullet* bullet = new Bullet(direction);

	return bullet;
}
