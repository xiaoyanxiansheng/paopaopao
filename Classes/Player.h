#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "cocos2d.h"
#include "Controller.h"  

#include "ControllerListener.h" 
#include "SanfangController.h"
USING_NS_CC;
class Player : Node,public ControllerListener{
public :
	Player();
	~Player();
	static Player* create();
	void playerRun();
	bool init();
	void setViewPointByPlayer() ;
	void setController( Controller* controller );
	 /* ʵ��SimpleMoveListener�ӿڵķ��� */  
    virtual void setSimplePosition(int x, int y);  
    virtual CCPoint getCurPosition();  
protected:  
    Controller* mController;  
};
#endif