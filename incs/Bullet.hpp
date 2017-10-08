#ifndef BULLET_HPP
# define BULLET_HPP

# include "AEntity.hpp"
# include <iostream>

class Bullet {

public:

	Bullet(void);
	Bullet(int direction, bool isHero);
	Bullet(Bullet const & src);
	~Bullet(void);



	int  		getDmg(void) const;
	int  		getDir(void) const;
	AEntity&  	getBullet(void) const;
	Bullet*  	getNext(void) const;
	Bullet*  	getPrev(void) const;
	bool 		isHeroBullet(void) const;

	void  		setDmg(int dmg);
	void  		setDir(int direction);
	void 		 	setBullet(AEntity& bullet);
	void 			setNext(Bullet* next);
	void 			setPrev(Bullet* prev);

	bool			bulletMove(int sizeX, int sizeY);
	bool			move(void);

	Bullet& operator=(Bullet const & rhs);

private:
	bool 		_heroBullet;
	int			_direction;
	int 		_damage;
	AEntity&	_bullet;
	Bullet*		_next;
	Bullet*		_prev;

};

#endif
