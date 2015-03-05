#ifndef __TITLE_BAR_LAYER_H__
#define __TITLE_BAR_LAYER_H__

#include <string>
#include "cocos2d.h"
#include "WordCardScene.h"
#include "MyPageScene.h"

using namespace cocos2d;

class WordCardScene;
class MyPageScene;

//static const int STATUS_WORD_CARD_TITLE = 1;
//static const int STATUS_WORD_CARD = 2;
//static const int STATUS_WORD_CARD_ENDING = 3;
//static const int STATUS_MY_PAGE_MENU = 4;

class TitleBarLayer : public cocos2d::LayerColor
{
private:
	Label*		m_lblTitle;
	Sprite*		m_sprBack;
	Sprite*		m_sprQuit;

	int			m_contextLayer;

	EventListenerTouchOneByOne* m_listener;

    void _goBack(void);
    void _goQuit(void);

public:
	static WordCardScene* m_parentWordCardScene;
	static MyPageScene* m_parentMyPageScene;
	static void	setParentWordCardScene(WordCardScene* parent);
	static void	setParentMyPageScene(MyPageScene* parent);

	virtual bool init();
    bool onTouchBegan(Touch *touch, Event *event);

    CREATE_FUNC(TitleBarLayer);

    void setContext(int context);

    void setTitle(std::string title) { m_lblTitle->setString(title); }
    void setBackIconVisible(bool visible) { m_sprBack->setVisible(visible); }
    void setQuitIconVisible(bool visible) { m_sprQuit->setVisible(visible); }

};

#endif // __TITLE_BAR_LAYER_H__
