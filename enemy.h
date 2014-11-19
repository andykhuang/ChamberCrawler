#ifndef ___ENEMY_H___
#define ___ENEMY_H___

class Enemy: public Character {
	void move();
	void dropItems();
	void die();
	void attack(Character *c);
	public:
	void performAction();
	bool isDead();
	bool isAttacked(Character *c);
};
#endif
