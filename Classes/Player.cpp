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
	//���ض���
	ActionTimeline* action = CSLoader::createTimeline("player.csb");
	player->runAction(action);
	//���ж���
	action->gotoFrameAndPlay(0,60,true);
	this->addChild(player);

	return true;
}
void Player::addPlayerto(Node* parent){
	parent->addChild(this);
}
Player::Player(){}
Player::~Player(){}