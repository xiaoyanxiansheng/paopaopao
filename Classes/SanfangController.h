#ifndef __SANFANGCONTROLLER_H__
#define __SANFANGCONTROLLER_H__
#include "cocos2d.h"
#include "Controller.h"
USING_NS_CC;
class SanfangController : public Controller{
public :
	CREATE_FUNC(SanfangController);
	virtual bool init();
	virtual void update(float dt);

	/*´¥ÆÁÊÂ¼þ*/
	virtual bool onTouchBegan(Touch *touch, Event *unused_event); 
    virtual void onTouchMoved(Touch *touch, Event *unused_event); 
    virtual void onTouchEnded(Touch *touch, Event *unused_event);

	void setXSpeed(int speed);
	void setYSpeed(int speed);
private:
	int xSpeed;
	int ySpeed;
};
#endif