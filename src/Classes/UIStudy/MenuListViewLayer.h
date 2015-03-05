#ifndef __LIST_VIEW_LAYER_H__
#define __LIST_VIEW_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "MenuScene.h"
//#include "MyPage.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class MenuScene;

class MenuListViewLayer : public cocos2d::LayerColor
{
private:
//	std::vector<WordListValue>* m_words;

	ListView*	m_lvLessonList;

	EventListenerTouchOneByOne* m_listener;

	int		_getCurrentItem_LessonId(void);
    void	_goToStudyScene(int lessonId);

public:
	static MenuScene* m_parentScene;

    static MenuListViewLayer*	createListViewLayer(void);
	virtual bool init();
    CREATE_FUNC(MenuListViewLayer);

    static void	setParentScene(MenuScene* parent);

//    void setWordsData(std::vector<WordListValue>* words) { m_words = words ; }

//    void onTouchEnded(Touch *touch, Event *event);
    void onLessonButtonTouched(Ref *pSender, Widget::TouchEventType type);

};

#endif // __MY_WORD_LAYER_H__
