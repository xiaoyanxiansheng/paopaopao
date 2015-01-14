#include "Player.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocostudio::timeline;
Player* Player::create(){
	auto player = new Player();
	if(player && player->init()){
		player->autorelease();
	}else{
		CC_SAFE_DELETE(player);
	}

	return player;
}
bool Player::init(){
	//������Դ
	auto player = CSLoader::createNode("player.csb");
	player->setTag(100);
	this->addChild(player);
	return true;
}
void Player::playerRun(){
	//���ض���
	ActionTimeline* action = CSLoader::createTimeline("player.csb");
	this->getChildByTag(100)->runAction(action);
	//���ж���
	action->gotoFrameAndPlay(0,35,true);
}
Player::Player(){}
Player::~Player(){}
void Player::setController( Controller* controller )  
{  
    this->mController = controller;  
    controller->setControllerListener(this);  
}  
  
  
void Player::setSimplePosition( int x, int y )  
{  
	this->setPosition(Point(x, y));  
	this->setViewPointByPlayer();
}  
  
Point Player::getCurPosition()  
{  
    return this->getPosition();    
}  
void Player::setViewPointByPlayer(){
	//�õ����ڵ�
	auto layer = this->getParent();
	auto winsize = Director::getInstance()->getVisibleSize();
	//��ͼ�ķ�������
	float x = this->getPositionX()-winsize.width/2>0?this->getPositionX()-winsize.width/2:0;
	layer->setPositionX(-x);
}