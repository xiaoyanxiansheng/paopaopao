#include "SanfangController.h"
bool SanfangController::init()  {
	xSpeed = 0;
	ySpeed = 0;


	//ע���¼�
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(SanfangController::onTouchBegan,this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SanfangController::onTouchMoved,this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SanfangController::onTouchEnded,this);
	dispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);

	scheduleUpdate();
	return true;
}
void SanfangController::setXSpeed( int iSpeed )  
{  
    xSpeed = iSpeed;  
}    
void SanfangController::setYSpeed( int iSpeed )  
{  
    ySpeed = iSpeed;  
}  
bool SanfangController::onTouchBegan(Touch *pTouch, Event *pEvent )  
{  
    return true;  
}
void SanfangController::onTouchMoved(Touch *pTouch, Event *pEvent ) 
{  
    /* ��ȡ��������� */  
	Point touchLocation = pTouch->getLocation();  
   // touchLocation = Director::sharedDirector()->convertToGL(touchLocation);  
  
    /* �����ƶ�������� */  
    Point pos = mControllerListener->getCurPosition();  
  
    /* �ж��������ƶ����������ƶ� */  
    int ySpeed = touchLocation.y > pos.y ? 1 : -1;  
	int xSpeed = touchLocation.x > pos.x ? 0 : -1;                          

    setYSpeed(ySpeed);
	setXSpeed(xSpeed);
}  
  
void SanfangController::onTouchEnded( Touch *pTouch, Event *pEvent )  
{  
    /* ֹͣY�����ϵ��ƶ� */  
    setYSpeed(0);  
}  

void SanfangController::update(float dt){
	CCPoint pos = mControllerListener->getCurPosition();  
    pos.y += ySpeed; 
	pos.x += xSpeed;
    mControllerListener->setSimplePosition(pos.x, pos.y);
}