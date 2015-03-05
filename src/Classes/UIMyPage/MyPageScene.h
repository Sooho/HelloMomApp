#ifndef __MY_PAGE_SCENE_H__
#define __MY_PAGE_SCENE_H__

#include "cocos2d.h"
#include "Config.h"
#include "ToolBarBottomLayer.h"
#include "TitleBarLayer.h"
#include "MyPageLayer.h"
#include "MyPage.h"


using namespace cocos2d;

class TitleBarLayer;
class ToolBarBottomLayer;
class MyPageLayer;


const static int MY_PAGE_TYPE_MY_WORD = 1;
const static int MY_PAGE_TYPE_ARCHIVE = 2;


class MyPageScene : public cocos2d::Scene
{
private:
	TitleBarLayer*			m_titleBarLayer;
	ToolBarBottomLayer*		m_toolBarBottomLayer;
	MyPageLayer*			m_myPageLayer;

public:
	MyPage* m_myPageValue;

    virtual bool init();  
    
    CREATE_FUNC(MyPageScene);

};

#endif // __MY_PAGE_SCENE_H__
