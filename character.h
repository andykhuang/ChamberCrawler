#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
class Tile;

class Character {
	Tile *t;
	virtual bool attack(Character *c);
	virtual void move();	

	protected:
	int hp, atk, def;

	public:
	virtual void performAction();
	virtual bool isAttacked(Character *c);
	bool isDead();
};
#endif
