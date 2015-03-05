#include <stdlib.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Config.h"
#include "MenuScene.h"
#include "MenuListViewLayer.h"

using namespace cocos2d;
using namespace cocos2d::ui;

MenuScene* MenuListViewLayer::m_parentScene = NULL;

// on "init" you need to initialize your instance
bool MenuListViewLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }

    int l_thisHeight = Config::m_screenSize.height - Config::TOOL_BAR_HEIGHT - Config::TOOL_BAR_BOTTOM_HEIGHT;
    this->setContentSize(Size(Config::m_screenSize.width, l_thisHeight));

    // add word list
	log("MyWordLayer::init add m_listMyWords \n");
	m_lvLessonList = ListView::create();
	m_lvLessonList->setContentSize(Size(Config::m_screenSize.width - Config::LEFT_MARGIN*2, this->getContentSize().height));
	m_lvLessonList->setGravity(ListView::Gravity::CENTER_HORIZONTAL);
	m_lvLessonList->setAnchorPoint(Point(0,0));
	m_lvLessonList->setPosition(Vec2(Config::LEFT_MARGIN,0));
	m_lvLessonList->setDirection(ui::ScrollView::Direction::VERTICAL);
	m_lvLessonList->setTouchEnabled(true);

	m_lvLessonList->setBounceEnabled(true);
	m_lvLessonList->setBackGroundImage("background.jpg");
	m_lvLessonList->setBackGroundImageScale9Enabled(true);
	m_lvLessonList->ignoreContentAdaptWithSize(true);

	Size size = Size(getContentSize().width, Config::ICON_HEIGHT * 3);
	for (int i = 0; i < 2 /*m_words->size()*/ ; ++i)
	{
		//std::string l_lessonId = Config::numberToString(m_words->at(i).lessonId );
		std::string l_strlessonId;
		std::string l_strlessonName;
		std::string l_strlessonPicture;

		if (i == 0)
		{
			l_strlessonId = Config::numberToString(i+1);
			l_strlessonName = "Smart Phone";
			l_strlessonPicture = "lessons/smartphones.jpg";
		}
		else
		{
			l_strlessonId = Config::numberToString(i+1);
			l_strlessonName = "Cafe";
			l_strlessonPicture = "lessons/cafe.jpg";
		}

		//CCLog("myword index i = %d, lesson = %s \n", i, l_lessonId.c_str() );

		auto l_layout = Layout::create();
		l_layout->setContentSize(size);

		// add Picture button
		Button* l_btPicture = Button::create();
		l_btPicture->loadTextures(l_strlessonPicture, l_strlessonPicture, "");
		l_btPicture->setContentSize(Size(Config::ICON_HEIGHT, Config::ICON_HEIGHT));
		l_btPicture->setAnchorPoint(Point(0,0.5));
		l_btPicture->setPosition(Vec2(Config::LEFT_MARGIN *2, size.height/2));
		l_btPicture->setScaleX(Config::ICON_HEIGHT * 3 / l_btPicture->getContentSize().width);
		l_btPicture->setScaleY(Config::ICON_HEIGHT * 3 / l_btPicture->getContentSize().height);
		l_btPicture->setTitleText("recover");
		l_btPicture->addTouchEventListener(CC_CALLBACK_2(MenuListViewLayer::onLessonButtonTouched, this));
		l_layout->addChild(l_btPicture);

		// lessonId
		Text* l_lessonId = Text::create(l_strlessonId.c_str(), "", 48);
		l_lessonId->setContentSize(Size(50, Config::ICON_HEIGHT));
		l_lessonId->setAnchorPoint(Point(0,0.5));
		l_lessonId->setColor(Color3B::BLACK);
		l_lessonId->setPosition(Point(Config::LEFT_MARGIN * 3 + Config::ICON_HEIGHT * 3 + l_lessonId->getContentSize().width, size.height/2));
		l_layout->addChild(l_lessonId, 0, "lessonId");

		// lessonName
		Text* l_lessonName = Text::create(l_strlessonName.c_str(), "", 48);
		l_lessonName->setContentSize(Size(50, Config::ICON_HEIGHT));
		l_lessonName->setAnchorPoint(Point(0,0.5));
		l_lessonName->setColor(Color3B::BLACK);
		l_lessonName->setPosition(Point(Config::LEFT_MARGIN * 5 + Config::ICON_HEIGHT * 3 + l_lessonId->getContentSize().width, size.height/2));
		l_layout->addChild(l_lessonName, 0, "lessonName");

		m_lvLessonList->addChild(l_layout);
	}

	m_lvLessonList->setItemsMargin(10);

	this->addChild(m_lvLessonList);

 	this->setTouchEnabled(true);
  	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
  	m_listener = EventListenerTouchOneByOne::create();
  	m_listener->setSwallowTouches(true);
  	m_listener->onTouchEnded = CC_CALLBACK_2(MenuListViewLayer::onTouchEnded, this);
  	dispatcher->addEventListenerWithSceneGraphPriority(m_listener, this);

    return true;
}

MenuListViewLayer* MenuListViewLayer::createListViewLayer(void)
{
	auto l_lvLayer = MenuListViewLayer::create();
//	l_lvLayer->setWordsData(m_parentScene->getMyWords());

	return l_lvLayer;
}

void MenuListViewLayer::onLessonButtonTouched(Ref *pSender, Widget::TouchEventType type)
{
	if( type == Widget::TouchEventType::ENDED)
	{
		log("onTouchEnded");
		_goToStudyScene(_getCurrentItem_LessonId());
	}
}

void MenuListViewLayer::_goToStudyScene(int lessonId)
{
	log("_goToStudyScene");

	Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	auto hScene = WordCardScene::createWordCardScene(lessonId);
	auto pScene = TransitionFade::create(0.5f, hScene);

	Director::getInstance()->replaceScene(pScene);
}

int MenuListViewLayer::_getCurrentItem_LessonId(void)
{
	Layout* l_layout = static_cast<Layout*>(m_lvLessonList->getItem(m_lvLessonList->getCurSelectedIndex()));
	Text* l_lessonIdText = static_cast<Text*>(l_layout->getChildByName("lessonId"));

	return atoi(l_lessonIdText->getString().c_str());
}

void MenuListViewLayer::setParentScene(MenuScene* parent)
{
	//if (NULL == m_parentScene)
		m_parentScene = parent;
}

