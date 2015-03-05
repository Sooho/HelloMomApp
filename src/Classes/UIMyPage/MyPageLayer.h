#ifndef __MY_PAGE_LAYER_H__
#define __MY_PAGE_LAYER_H__

#include "cocos2d.h"
#include "MyPageScene.h"
#include "MyPage.h"

using namespace cocos2d;
class MyPageScene;

class MyPageLayer : public cocos2d::LayerColor
{
private:
	MyRecord	m_totalRecord;

	Label*	m_lblSavings;
	Label*	m_lblProgress;

	EventListenerTouchOneByOne* m_listener;

	void _setMyPageData(void);

public:
	static MyPageScene* m_parentScene;
    static void	setParentScene(MyPageScene* parent);

    virtual bool init();
    bool onTouchBegan(Touch *touch, Event *event);

    CREATE_FUNC(MyPageLayer);

};

#endif // __MY_PAGE_LAYER_H__
