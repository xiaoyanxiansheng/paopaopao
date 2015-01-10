#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "cocos2d.h"
USING_NS_CC;
class Player : Node{
public :
	Player();
	~Player();
	static Player* create();
	void addPlayerto(Node* parent);
	bool init();
};
#endif