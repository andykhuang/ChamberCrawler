#ifndef ___PLAYER_H___
#define ___PLAYER_H___

class Player: public Character {
	void die();	

	public:
	void move(int dir);
	bool isDead();
	void use(int dir);
	void pickup(int dir);
};
#endif
