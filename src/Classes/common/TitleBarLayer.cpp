#include "cocos2d.h"
#include "Config.h"
#include "WordCardScene.h"
#include "TitleBarLayer.h"
#include "MyPageScene.h"

USING_NS_CC;

WordCardScene* TitleBarLayer::m_parentWordCardScene = NULL;
MyPageScene* TitleBarLayer::m_parentMyPageScene = NULL;

// on "init" you need to initialize your instance
bool TitleBarLayer::init()
{
	if ( !LayerColor::initWithColor(Color4B::WHITE))
	{
        return false;
    }

	this->setContentSize(Size(Config::m_screenSize.width, Config::TOOL_BAR_HEIGHT));

	// add Title
	m_lblTitle = Label::create("",  "Arial", 40,
			Size(Config::m_screenSize.width - Config::LEFT_MARGIN - Config::ICON_HEIGHT*2, 32 * 1.5),  TextHAlignment::CENTER, TextVAlignment::BOTTOM);
	m_lblTitle->setPosition(Vec2(Config::m_screenSize.width/2, this->getContentSize().height/2));
	m_lblTitle->setColor(Color3B::BLACK);
	this->addChild(m_lblTitle, 1);


    m_sprBack = Sprite::create(ICON_BACK);
    m_sprBack->setPosition(Vec2(Config::LEFT_MARGIN + Config::ICON_HEIGHT/2, Config::TOOL_BAR_HEIGHT/2));
    m_sprBack->setScaleX(Config::ICON_HEIGHT/ m_sprBack->getContentSize().width);
    m_sprBack->setScaleY(Config::ICON_HEIGHT/ m_sprBack->getContentSize().height);
 	this->addChild(m_sprBack, 1);

 	m_sprQuit = Sprite::create(ICON_QUIT);
 	m_sprQuit->setPosition(Vec2(Config::m_screenSize.width - Config::LEFT_MARGIN - Config::ICON_HEIGHT/2, Config::TOOL_BAR_HEIGHT/2));
 	m_sprQuit->setScaleX(Config::ICON_HEIGHT/ m_sprQuit->getContentSize().width);
 	m_sprQuit->setScaleY(Config::ICON_HEIGHT/ m_sprQuit->getContentSize().height);
 	this->addChild(m_sprQuit, 1);

	this->setTouchEnabled(true);
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	m_listener = EventListenerTouchOneByOne::create();
	m_listener->setSwallowTouches(true);
	m_listener->onTouchBegan = CC_CALLBACK_2(TitleBarLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(m_listener, this);

    return true;
}


bool TitleBarLayer::onTouchBegan(Touch* touch, Event* event)
{
	Point pos = touch->getStartLocation();
    //CCLOG("ToolBarLayer (pos.x:%f, pox.y:%f) \n", pos.x, pos.y);

	if (!this->getBoundingBox().containsPoint(pos))
	{
	   // CCLOG("[ERROR] ToolBarLayer, Out of bounds! (pos.x:%f, pox.y:%f) \n", pos.x, pos.y);
	    return false;
	}

	Point relativePos = Point(pos.x, pos.y - (Config::m_screenSize.height - Config::TOOL_BAR_HEIGHT));
	if (m_sprBack->getBoundingBox().containsPoint(relativePos))
	{
		CCLOG("m_sprBack has been clicked!!");
		_goBack();
	}
	else if (m_sprQuit->getBoundingBox().containsPoint(relativePos))
	{
		CCLOG("m_sprFavorite has been clicked!!");
		_goQuit();
	}
	else
	{
		CCLOG("Out of icons has been clicked!!");
	}

	return true;
}

void TitleBarLayer::_goBack(void)
{
	switch (m_contextLayer)
	{
//	case STATUS_WORD_CARD_TITLE:
//		CCLOG("TitleBarLayer::_goBack(void), context: STATUS_WORD_CARD_TITLE");
//		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
//		delete m_parentWordCardScene->m_wordCard;
//		CCLOG("m_parentWordCardScene->m_wordCard is deleted.\n");
//		Director::getInstance()->replaceScene(MenuScene::create());
//		break;
//
//	case STATUS_WORD_CARD:
//		CCLOG("TitleBarLayer::_goBack(void), context: STATUS_WORD_CARD");
//		m_parentWordCardScene->goBackToWordCardTitle();
//		break;
//
//	case STATUS_MY_PAGE_MENU:
//		CCLOG("TitleBarLayer::_goBack(void), context: STATUS_MY_PAGE_MENU");
//		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
//		Director::getInstance()->replaceScene(MenuScene::create());
//		break;

	default:
		CCLOG("TitleBarLayer::_goBack(void)");
	}

}

void TitleBarLayer::_goQuit(void)
{
	CCLOG("TitleBarLayer::_goQuit(void)");
}

void TitleBarLayer::setContext(int context)
{
	m_contextLayer = context;

	switch (m_contextLayer)
	{
//	case STATUS_WORD_CARD_TITLE:
//	case STATUS_WORD_CARD_ENDING:
//	case STATUS_MY_PAGE_MENU:
//		CCLOG("TitleBarLayer::setContext(void), context: STATUS_WORD_CARD_TITLE");
////		m_sprFavorite->setVisible(false);
////		m_sprArchive->setVisible(false);
//
//		break;
//
//	case STATUS_WORD_CARD:
//		CCLOG("TitleBarLayer::_goBack(void), context: STATUS_WORD_CARD");
//		m_sprFavorite->setVisible(true);
//		m_sprArchive->setVisible(true);
//		break;

	default:
		CCLOG("TitleBarLayer::_goBack(void)");
	}

}

void TitleBarLayer::setParentWordCardScene(WordCardScene* parent)
{
	if (NULL == m_parentWordCardScene)
		m_parentWordCardScene = parent;
}

void TitleBarLayer::setParentMyPageScene(MyPageScene* parent)
{
	if (NULL == m_parentMyPageScene)
		m_parentMyPageScene = parent;
}

//void TitleBarLayer::_goFavorite(void)
//{
//	m_parentWordCardScene->m_currentWordCardLayer->addMyWord();
//}
//
//
//void TitleBarLayer::_goAchive(void)
//{
//	m_parentWordCardScene->m_currentWordCardLayer->addArchive();
//}

