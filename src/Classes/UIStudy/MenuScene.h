#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "MenuListViewLayer.h"
#include "TitleBarLayer.h"
#include "ToolBarBottomLayer.h"

using namespace cocos2d;

class TitleBarLayer;
class ToolBarBottomLayer;
class MenuListViewLayer;

class MenuScene : public cocos2d::Scene
{
private:
	MenuListViewLayer*		m_menuListViewLayer;

	TitleBarLayer*			m_titleBarLayer;
	ToolBarBottomLayer*		m_toolBarBottomLayer;

	//WordCard*				m_wordCard;

public:
    virtual bool init();  
    
    CREATE_FUNC(MenuScene);
};

#endif // __MENU_SCENE_H__
