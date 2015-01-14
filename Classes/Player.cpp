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
	//加载资源
	auto player = CSLoader::createNode("player.csb");
	player->setTag(100);
	this->addChild(player);
	return true;
}
void Player::playerRun(){
	//加载动画
	ActionTimeline* action = CSLoader::createTimeline("player.csb");
	this->getChildByTag(100)->runAction(action);
	//运行动画
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
	//得到父节点
	auto layer = this->getParent();
	auto winsize = Director::getInstance()->getVisibleSize();
	//地图的方块数量
	float x = this->getPositionX()-winsize.width/2>0?this->getPositionX()-winsize.width/2:0;
	layer->setPositionX(-x);
}