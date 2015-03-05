#ifndef __MESSAGE_LAYER_H__
#define __MESSAGE_LAYER_H__

#include "cocos2d.h"
#include "MyPageScene.h"
#include "MyPage.h"

using namespace cocos2d;
class MessageScene;

class MessageLayer : public cocos2d::LayerColor
{
private:
//	MyRecord	m_totalRecord;

	Label*	m_lblMessages;

	EventListenerTouchOneByOne* m_listener;

	void _setMessageData(void);

public:
	static MessageScene* m_parentScene;
    static void	setParentScene(MessageScene* parent);

    virtual bool init();
    bool onTouchBegan(Touch *touch, Event *event);

    CREATE_FUNC(MessageLayer);

};

#endif // __MESSAGE_LAYER_H__
