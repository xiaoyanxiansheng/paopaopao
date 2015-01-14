#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include "cocos2d.h" 
#include "ControllerListener.h"
USING_NS_CC;
class Controller : public Layer{
public :
	void setControllerListener(ControllerListener* mControllerListener);  
protected:
	ControllerListener* mControllerListener;  
};
#endif