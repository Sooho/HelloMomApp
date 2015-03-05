#ifndef __MESSAGE_SCENE_H__
#define __MESSAGE_SCENE_H__

#include "cocos2d.h"
#include "Config.h"
#include "ToolBarBottomLayer.h"
#include "TitleBarLayer.h"
#include "MessageLayer.h"

using namespace cocos2d;

class TitleBarLayer;
class ToolBarBottomLayer;
class MessageLayer;

class MessageScene : public cocos2d::Scene
{
private:
	TitleBarLayer*			m_titleBarLayer;
	ToolBarBottomLayer*		m_toolBarBottomLayer;
	MessageLayer*			m_messageLayer;

public:
	//MyPage* m_myPageValue;

    virtual bool init();  
    
    CREATE_FUNC(MessageScene);

};

#endif // __MESSAGE_SCENE_H__
