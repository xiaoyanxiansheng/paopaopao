#include "Guanqia.h"
Scene* Guanqia::createScene(){
	auto scene = Scene::create();
	auto layer = Guanqia::create();
	scene->addChild(layer);
	return scene;
}
bool Guanqia::init(){
	if (!Layer::init())
	{
		return false;
	}
	auto winsize = Director::getInstance()->getVisibleSize();
	//添加背景
	auto map = TMXTiledMap::create("level/level001.tmx");
	this->addChild(map);
	//添加英雄
	player = Player::create();
	((Node*)player)->setPosition(Point(winsize.width*0.1,winsize.height*0.5));
	this->addChild((Node*)player);	//这个地方不是很懂
	//让英雄跑起来
	player->playerRun();
	//创建玩家简单移动控制器
    SimpleMoveControll* mSMoveControll = SimpleMoveControll::create();  
    mSMoveControll->setiSpeed(1);  
	SanfangController* sanfang = SanfangController::create();
	sanfang->setTouchEnabled(true);
    /* 控制器要添加到场景中才能获得update事件 */  
    this->addChild(mSMoveControll);
	this->addChild(sanfang);
    player->setController(mSMoveControll);  
	player->setController(sanfang);

	return true;
}