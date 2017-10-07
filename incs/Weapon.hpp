#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "Bullet.hpp"

class Weapon {

public:

  Weapon(void);
  Weapon(Weapon const & src);
  ~Weapon(void);

  Weapon& operator=(Weapon const & rhs);

  Bullet*	shoot(int direction);

private:

};

#endif
