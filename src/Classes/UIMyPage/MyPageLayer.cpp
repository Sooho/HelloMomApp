#include <string>
#include "cocos2d.h"
#include "MyPageScene.h"
#include "MyPageLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

MyPageScene* MyPageLayer::m_parentScene = NULL;

// on "init" you need to initialize your instance
bool MyPageLayer::init()
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
	auto l_label1 = Label::create("My Savings: ",  "Arial", 40, Size(Config::m_screenSize.width - Config::LEFT_MARGIN , 40 * 1.5),  TextHAlignment::LEFT, TextVAlignment::CENTER);
	l_label1->setAnchorPoint(Point(0,0));
	l_label1->setPosition(Vec2(Config::LEFT_MARGIN * 3, l_thisHight - 70 * 1.5 - 40 * 1.5));
	l_label1->setColor(Color3B::BLACK);
	this->addChild(l_label1, 1);

	m_lblSavings = Label::create("0 ",  "Arial", 40,
    								Size(Config::m_screenSize.width - Config::LEFT_MARGIN * 2 , 40 * 1.5),  TextHAlignment::RIGHT, TextVAlignment::CENTER);
	m_lblSavings->setAnchorPoint(Point(0,0));
	m_lblSavings->setPosition(Vec2(Config::LEFT_MARGIN, l_thisHight - 70 * 1.5 - 40 * 1.5 * 2));
	m_lblSavings->setColor(Color3B::BLACK);
	this->addChild(m_lblSavings, 2);

	// add archived words
	auto l_label2 = LabelTTF::create("Progress: ",  "Arial", 40,
    								Size(Config::m_screenSize.width - Config::LEFT_MARGIN , 40 * 1.5),  TextHAlignment::LEFT, TextVAlignment::CENTER);
	l_label2->setAnchorPoint(Point(0,0));
	l_label2->setPosition(Vec2(Config::LEFT_MARGIN * 3, l_thisHight - 70 * 1.5 - 40 * 1.5 * 3));
	l_label2->setColor(Color3B::BLACK);
	this->addChild(l_label2, 1);

	m_lblProgress = Label::create("",  "Arial", 40,
    								Size(Config::m_screenSize.width - Config::LEFT_MARGIN * 2, 40 * 1.5),  TextHAlignment::RIGHT, TextVAlignment::CENTER);
	m_lblProgress->setAnchorPoint(Point(0,0));
	m_lblProgress->setPosition(Vec2(Config::LEFT_MARGIN, l_thisHight - 70 * 1.5 - 40 * 1.5 * 4));
	m_lblProgress->setColor(Color3B::BLACK);
	this->addChild(m_lblProgress, 2);

	_setMyPageData();

   /////////////////////////////
    // 2. init listener
	this->setTouchEnabled(true);
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	m_listener = EventListenerTouchOneByOne::create();
	m_listener->setSwallowTouches(true);
	m_listener->onTouchBegan = CC_CALLBACK_2(MyPageLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(m_listener, this);

	return true;
}

void MyPageLayer::_setMyPageData(void)
{
//    m_totalRecord = m_parentScene->getTotalRecord();
//
//    CCLOG("[%s] m_totalRecord \n", __func__);
//    m_totalRecord.print();
//
	m_lblSavings->setString("500,000");
	m_lblProgress->setString("Lesson 2");
//	m_lblSavings->setString(Config::numberToString(m_totalRecord.numOfMyWords).c_str());
//	m_lblProgress->setString(Config::numberToString(m_totalRecord.numOfArchivedWords).c_str());
//	m_lblNumOfAvgReviews->setString(Config::numberToString(m_totalRecord.numOfAvgReviews).c_str());
//	m_lblQuizePassRate->setString(Config::numberToString(m_totalRecord.quizePassRate).c_str());
}

void MyPageLayer::setParentScene(MyPageScene* parent)
{
//	if (NULL == m_parentScene)
		m_parentScene = parent;
}


bool MyPageLayer::onTouchBegan(Touch* touch, Event* event)
{
	CCLOG("[MyPageLayer::onTouchBegan] MyPageLayer has been clicked!!\n");
//	if (this->getBoundingBox().containsPoint(touch->getStartLocation()))
//	{
//		CCLOG("MyPageLayer has been clicked!!");
//	}
//	else
//		CCLOG("Out of m_listMyWords has been clicked!!");

    return true;
}


