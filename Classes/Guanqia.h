#ifndef __GUANQIA_H__
#define __GUANQIA_H__
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;
class Guanqia:public Layer{
public :
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Guanqia);
private:
	Player* player;
};
#endif