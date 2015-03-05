#ifndef __WORD_CARD_SCENE_H__
#define __WORD_CARD_SCENE_H__

#include "cocos2d.h"
#include "WordCardLayer.h"
#include "WordCardTitleLayer.h"
#include "ToolBarBottomLayer.h"
#include "TitleBarLayer.h"
#include "Config.h"

#define SWIPE_LEFT_RIGHT

class WordCardLayer;
class MenuLayer;
class WordCardTitleLayer;
class TitleBarLayer;
class ToolBarBottomLayer;

class WordCardScene : public cocos2d::Scene
{
private:

public:
	WordCardTitleLayer*		m_wordCardTitleLayer;
	TitleBarLayer*			m_titleBarLayer;
	ToolBarBottomLayer*		m_toolBarBottomLayer;

	WordCardLayer*			m_prevWordCardLayer;
	WordCardLayer*			m_currentWordCardLayer;
	WordCardLayer*			m_nextWordCardLayer;

	WordCard*				m_wordCard;

    static WordCardScene*	createWordCardScene(int lessonId);

    virtual bool init();  
    CREATE_FUNC(WordCardScene);

//#ifdef SWIPE_LEFT_RIGHT
//	Point getPrevWordCardLayerPosition(void) {return Point(-720,Config::TOOL_BAR_BOTTOM_HEIGHT);}
//	Point getCurrentWordCardLayerPosition(void) {return Point(0,Config::TOOL_BAR_BOTTOM_HEIGHT);}
//	Point getNextWordCardLayerPosition(void) {return Point( 720,Config::TOOL_BAR_BOTTOM_HEIGHT);}
//#else
    float l_prevY = Config::m_screenSize.height - Config::TOOL_BAR_HEIGHT;
    float l_nextY = Config::TOOL_BAR_BOTTOM_HEIGHT - (Config::m_screenSize.height - Config::TOOL_BAR_HEIGHT - Config::TOOL_BAR_BOTTOM_HEIGHT);
	Point getPrevWordCardLayerPosition(void) {return Point(0, l_prevY);}
	Point getCurrentWordCardLayerPosition(void) {return Point(0, Config::TOOL_BAR_BOTTOM_HEIGHT);}
	Point getNextWordCardLayerPosition(void) {return Point( 0, l_nextY);}

//#endif

};

#endif // __WORD_CARD_SCENE_H__
