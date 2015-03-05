#include "MenuScene.h"
#include "MenuListViewLayer.h"
#include "TitleBarLayer.h"
#include "ToolBarBottomLayer.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    // create wordCards for the lessonId from json data
//	m_wordCard = new WordCard(lessonId);
//	CCLOG("m_wordCard:%x\n", m_wordCard);
//	m_wordCard->print();

	/////////////////////////////
    // 2. add Layer
    // add toolbar
//	ToolBarLayer::setParentWordCardScene(scene);
	m_titleBarLayer = TitleBarLayer::create();
	m_titleBarLayer->setAnchorPoint(Point(0,0));
	m_titleBarLayer->setPosition(Point(0, Config::m_screenSize.height- Config::TOOL_BAR_HEIGHT));
//	m_toolBarLayer->setContext(STATUS_WORD_CARD_TITLE);
	m_titleBarLayer->setTitle("menu");
	m_titleBarLayer->setBackIconVisible(false);
	m_titleBarLayer->setQuitIconVisible(false);
	addChild(m_titleBarLayer, 1);

	// add toolbarbottom
	//ToolBarBottomLayer::setParentWordCardScene(this);
	m_toolBarBottomLayer = ToolBarBottomLayer::create();
	m_toolBarBottomLayer->setAnchorPoint(Point(0,0));
	m_toolBarBottomLayer->setPosition(Point(0, 0));
	addChild(m_toolBarBottomLayer, 1);

	// add word card title for the lessonId
	CCLOG("m_menuListViewLayer\n");
	MenuListViewLayer::setParentScene(this);
	m_menuListViewLayer = MenuListViewLayer::create();
	m_menuListViewLayer->setAnchorPoint(Point(0,0));
	m_menuListViewLayer->setPosition(Point(0, Config::TOOL_BAR_BOTTOM_HEIGHT));
	addChild(m_menuListViewLayer, 0);

    return true;
}
