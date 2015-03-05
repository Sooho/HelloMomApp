#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__

#include "cocos2d.h"
#include <iostream>
#include <string>

using namespace cocos2d;

//icons
static std::string ICON_QUIT = "icons/quit.jpg";
static std::string ICON_BACK = "icons/back.png";
static std::string ICON_HOME = "icons/home.jpg";
static std::string ICON_MESSAGE = "icons/message.png";
static std::string ICON_MY_PAGE = "icons/mypage.png";
static std::string ICON_SETTING = "icons/setting.jpg";


class Config
{
private:
    static Config* m_instance;

    Config() {}
    ~Config() {}

public:

    static Size m_screenSize;

    static int TOOL_BAR_HEIGHT ;
    static int TOOL_BAR_BOTTOM_HEIGHT ;
    static int ICON_HEIGHT ;

    static int LABEL_SCALE;
    static int LEFT_MARGIN;


    static void init(void);
    static Config* getInstance(void);
	static void releaseInstance(void);

	static std::string numberToString(int i)
	{
		std::stringstream ss;
		ss << i;

		std::string str;
		ss >> str;

		return str;

	}

	static std::string numberToString(float i)
	{
		std::stringstream ss;
		ss << i;

		std::string str;
		ss >> str;

		return str;

	}

};


#endif // __CONFIGURE_H__
