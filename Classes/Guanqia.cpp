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
	//��ӱ���
	auto map = TMXTiledMap::create("level/level001.tmx");
	this->addChild(map);
	//���Ӣ��
	player = Player::create();
	((Node*)player)->setPosition(Point(winsize.width*0.1,winsize.height*0.5));
	this->addChild((Node*)player);	//����ط����Ǻܶ�

	return true;
}