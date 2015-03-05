#include "Config.h"

using namespace cocos2d;

Config* Config::m_instance = NULL;
Size Config::m_screenSize(0,0);
int Config::TOOL_BAR_HEIGHT = 0;
int Config::TOOL_BAR_BOTTOM_HEIGHT = 0;
int Config::ICON_HEIGHT = 0;
int Config::LABEL_SCALE = 0;
int Config::LEFT_MARGIN = 0;


Config* Config::getInstance()
{
	if(m_instance == NULL)
		m_instance = new Config();

	return m_instance;
}

void Config::releaseInstance()
{
	if(m_instance != NULL)
		delete m_instance;
}

void Config::init(void)
{
	Config::getInstance();
	m_screenSize = Director::sharedDirector()->getWinSize();

	TOOL_BAR_HEIGHT =  static_cast<int>(m_screenSize.height * 0.1) ; //10% of window height
	TOOL_BAR_BOTTOM_HEIGHT = static_cast<int>(m_screenSize.height * 0.08) ; //10% of window height

	ICON_HEIGHT = static_cast<int>(TOOL_BAR_BOTTOM_HEIGHT * 0.6) ;

    LABEL_SCALE = 2;
    LEFT_MARGIN  = 20;

	CCLOG("[Config] Config has been initialized.");
}
