#ifndef BULLET_HPP
# define BULLET_HPP

# include "AEntity.hpp"
# include <iostream>

class Bullet {

public:

	Bullet(void);
	Bullet(int direction);
	Bullet(Bullet const & src);
	~Bullet(void);

	

	int  		getDmg(void) const;
	int  		getDir(void) const;
	AEntity&  	getBullet(void) const;
	Bullet*  	getNext(void) const;
	Bullet*  	getPrev(void) const;

	void  		setDmg(int dmg);
	void  		setDir(int direction);
	void 		 	setBullet(AEntity& bullet);
	void 			setNext(Bullet* next);
	void 			setPrev(Bullet* prev);

	bool			bulletMove(int sizeX, int sizeY);
	bool			move(void);

	Bullet& operator=(Bullet const & rhs);

private:
	int			_direction;
	int 		_damage;
	AEntity&	_bullet;
	Bullet*		_next;
	Bullet*		_prev;

};

#endif
