#include "MyPageScene.h"
#include "MyPageLayer.h"
#include "ToolBarBottomLayer.h"
#include "TitleBarLayer.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool MyPageScene::init()
{
    //////////////////////////////
    // super init first
    if ( !Scene::init() )
    {
        return false;
    }
    

    //////////////////////////////
	// create wordCards for the lessonId from json data
	m_myPageValue = MyPage::getInstance();

    /////////////////////////////
    // add Layer
	// add my page layer
	MyPageLayer::setParentScene(this);
	m_myPageLayer = MyPageLayer::create();
	m_myPageLayer->setAnchorPoint(Point(0,0));
	m_myPageLayer->setPosition(Point(0, Config::TOOL_BAR_BOTTOM_HEIGHT));
	this->addChild(m_myPageLayer, 0);

    // add titlebar
	//ToolBarLayer::setParentMyPageScene(this);
	m_titleBarLayer = TitleBarLayer::create();
	m_titleBarLayer->setAnchorPoint(Point(0,0));
	m_titleBarLayer->setPosition(Point(0, Config::m_screenSize.height - Config::TOOL_BAR_HEIGHT));
	//m_toolBarLayer->setContext(STATUS_MY_PAGE_MENU);
	m_titleBarLayer->setTitle("My Page");
	m_titleBarLayer->setBackIconVisible(false);
	m_titleBarLayer->setQuitIconVisible(false);
	this->addChild(m_titleBarLayer, 2);

	// add toolbarbottom
	ToolBarBottomLayer::setParentMyPageScene(this);
	m_toolBarBottomLayer = ToolBarBottomLayer::create();
	m_toolBarBottomLayer->setAnchorPoint(Point(0,0));
	m_toolBarBottomLayer->setPosition(Point(0, 0));
	//m_toolBarBottomLayer->setContext(STATUS_MY_PAGE_MENU);
	this->addChild(m_toolBarBottomLayer, 2);

    return true;
}
