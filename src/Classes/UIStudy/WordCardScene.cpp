#include "cocos2d.h"

#include "WordCard.h"
#include "WordCardLayer.h"
#include "WordCardTitleLayer.h"
#include "WordCardScene.h"
#include "TitleBarLayer.h"
#include "ToolBarBottomLayer.h"

USING_NS_CC;

bool WordCardScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    m_wordCard= NULL;

    return true;
}

WordCardScene* WordCardScene::createWordCardScene(int lessonId)
{
	auto scene = WordCardScene::create();

	// create wordCards for the lessonId from json data
	scene->m_wordCard = new WordCard(lessonId);
	scene->m_wordCard->print();

	// add toolbar
	CCLOG("m_titleBarLayer\n");
	scene->m_titleBarLayer = TitleBarLayer::create();
	scene->m_titleBarLayer->setAnchorPoint(Point(0,0));
	scene->m_titleBarLayer->setPosition(Point(0, Config::m_screenSize.height- Config::TOOL_BAR_HEIGHT));
	scene->m_titleBarLayer->setTitle("study");
	scene->m_titleBarLayer->setBackIconVisible(false);
	scene->addChild(scene->m_titleBarLayer, 1);

	// add toolbarbottom
	CCLOG("m_toolBarBottomLayer\n");
	scene->m_toolBarBottomLayer = ToolBarBottomLayer::create();
	scene->m_toolBarBottomLayer->setAnchorPoint(Point(0,0));
	scene->m_toolBarBottomLayer->setPosition(Point(0, 0));
	scene->addChild(scene->m_toolBarBottomLayer, 1);

	// add word card title for the lessonId
	CCLOG("m_wordCardTitleLayer\n");
	WordCardTitleLayer::setParentScene(scene);
	scene->m_wordCardTitleLayer = WordCardTitleLayer::create();
	scene->m_wordCardTitleLayer->setAnchorPoint(Point(0,0));
	scene->m_wordCardTitleLayer->setPosition(Point(0, Config::TOOL_BAR_BOTTOM_HEIGHT));
	scene->addChild(scene->m_wordCardTitleLayer, 1);

	// add current word card
	CCLOG("m_currentWordCardLayer\n");
	WordCardLayer::setParentScene(scene);
	scene->m_currentWordCardLayer = WordCardLayer::create();
	scene->m_currentWordCardLayer->setAnchorPoint(Point(0,0));
	scene->m_currentWordCardLayer->setPosition(scene->getCurrentWordCardLayerPosition());
	int l_firstWordId = scene->m_wordCard->getFirstWordId();
	scene->m_currentWordCardLayer->setWordCardValue(l_firstWordId);
	scene->addChild(scene->m_currentWordCardLayer, 0);

	// add next word card
	CCLOG("m_nextWordCardLayer\n");
	scene->m_nextWordCardLayer = WordCardLayer::create();
	scene->m_nextWordCardLayer->setAnchorPoint(Point(0,0));
	scene->m_nextWordCardLayer->setPosition(scene->getNextWordCardLayerPosition());
	scene->m_nextWordCardLayer->setWordCardValue(scene->m_wordCard->getNextWordId(l_firstWordId));
	scene->addChild(scene->m_nextWordCardLayer, 0);

	// add prev word card
	CCLOG("m_prevWordCardLayer\n");
	scene->m_prevWordCardLayer = WordCardLayer::create();
	scene->m_prevWordCardLayer->setAnchorPoint(Point(0,0));
	scene->m_prevWordCardLayer->setPosition(scene->getPrevWordCardLayerPosition());
	scene->addChild(scene->m_prevWordCardLayer, 0);

	return scene;
}

