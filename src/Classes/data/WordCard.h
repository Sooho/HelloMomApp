#ifndef __WORD_CARD_H__
#define __WORD_CARD_H__

#include <string>
#include <vector>
#include "cocos2d.h"
#include "cJSON/cJSON.h"

using namespace cocos2d;

const std::string LESSON_PREFIX = "lesson_";


struct WordCardValue
{
	int lessonId;
	int wordId;
	std::string word;
	std::string meaning;
	std::string pronunciation;
	std::string picture;
	std::string word_sound;

	void print(void)
	{
		CCLOG("=== WordCardValue (lessonId:%d)\n", lessonId);
		CCLOG("wordId: %d\n", wordId);
		CCLOG("word: %s \n", word.c_str());
		CCLOG("meaning: %s \n", meaning.c_str());
		CCLOG("pronunciation: %s \n", pronunciation.c_str());
		CCLOG("picture: %s \n", picture.c_str());
		CCLOG("word_sound: %s \n", word_sound.c_str());
	}

};


class WordCard
{
private:
	int m_lessonId;
	std::string m_lessonTitle;
	std::string m_lessonTitlePicture;
	std::vector<WordCardValue> m_wordCards;

	void		_getWordsData(int lessonId);
	std::string	_getFileName(int lessonId);
	std::string	_getFolderPath(int lessonId);

	// json
	char*	_getJsonStream(std::string filename);
	void	_parseJsonToWordCard(const char* jsonStream);

	bool	_hasJsonError(cJSON* jsonElement, std::string elementName);

public:
	std::string m_folderPath;

	WordCard(int lessonId);
	virtual ~WordCard();

	int getFirstWordId(void);
	int getLastWordId(void);
	int getNextWordId(int currentWordId);

	std::string getLessonTitle(void) {
		CCLOG("getLessonTitle is called\n");
		CCLOG("m_lessonTitle:%s\n", m_lessonTitle.c_str());
		return m_lessonTitle;
	}

	std::string getLessonTitlePicture(void) { return m_lessonTitlePicture;}

	WordCardValue* getWordCardValue(int wordId);
	WordCardValue* getNextWordCardValue(int currentWordId);
	WordCardValue* getPrevWordCardValue(int currentWordId);

	void print(void)
	{
		CCLOG("=== WordCard.print() start \n");
		CCLOG("m_lessonId:%d\n", m_lessonId);
		CCLOG("m_lessonTitle:%s\n", m_lessonTitle.c_str());
		CCLOG("m_lessonTitlePicture:%s\n", m_lessonTitlePicture.c_str());
		CCLOG("m_folderPath:%s\n", m_folderPath.c_str());

		for (int i = 0 ; i < m_wordCards.size(); ++i)
			m_wordCards[i].print();

		CCLOG("=== WordCard.print() End \n");
	}
};

#endif // __WORD_CARD_H__
