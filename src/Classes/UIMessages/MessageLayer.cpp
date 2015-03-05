#include <string>
#include "cocos2d.h"
#include "MessageScene.h"
#include "MessageLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

MessageScene* MessageLayer::m_parentScene = NULL;

// on "init" you need to initialize your instance
bool MessageLayer::init()
{
    if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
    int l_thisHight = Config::m_screenSize.height - Config::TOOL_BAR_HEIGHT - Config::TOOL_BAR_BOTTOM_HEIGHT ;
    this->setContentSize(Size(Config::m_screenSize.width, l_thisHight));

	////////////////////////////////
	// add labels

	// add my words
	auto l_label1 = Label::create("My messages: ",  "Arial", 40, Size(Config::m_screenSize.width - Config::LEFT_MARGIN , 40 * 1.5),  TextHAlignment::LEFT, TextVAlignment::CENTER);
	l_label1->setAnchorPoint(Point(0,0));
	l_label1->setPosition(Vec2(Config::LEFT_MARGIN * 3, l_thisHight - 70 * 1.5 - 40 * 1.5));
	l_label1->setColor(Color3B::BLACK);
	this->addChild(l_label1, 1);

	m_lblMessages = Label::create("0 ",  "Arial", 40,
    								Size(Config::m_screenSize.width - Config::LEFT_MARGIN * 2 , 40 * 1.5),  TextHAlignment::RIGHT, TextVAlignment::CENTER);
	m_lblMessages->setAnchorPoint(Point(0,0));
	m_lblMessages->setPosition(Vec2(Config::LEFT_MARGIN, l_thisHight - 70 * 1.5 - 40 * 1.5 * 2));
	m_lblMessages->setColor(Color3B::BLACK);
	this->addChild(m_lblMessages, 2);

	_setMessageData();

   /////////////////////////////
    // 2. init listener
	this->setTouchEnabled(true);
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	m_listener = EventListenerTouchOneByOne::create();
	m_listener->setSwallowTouches(true);
	m_listener->onTouchBegan = CC_CALLBACK_2(MessageLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(m_listener, this);

	return true;
}

void MessageLayer::_setMessageData(void)
{
	m_lblMessages->setString("Hi Mom!!!");
}

void MessageLayer::setParentScene(MessageScene* parent)
{
//	if (NULL == m_parentScene)
		m_parentScene = parent;
}


bool MessageLayer::onTouchBegan(Touch* touch, Event* event)
{
	CCLOG("[MessageLayer::onTouchBegan] MessageLayer has been clicked!!\n");
//	if (this->getBoundingBox().containsPoint(touch->getStartLocation()))
//	{
//		CCLOG("MessageLayer has been clicked!!");
//	}
//	else
//		CCLOG("Out of m_listMyWords has been clicked!!");

    return true;
}


