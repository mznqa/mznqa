/*!
 * \file	Classes\logic\gameObject\cardContainer\CardBox.h
 *
 * \brief	定义类 CardBox
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDBOX_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDBOX_H_

#include <list>

#include "logic/gameObject/card/CardBase.h"
#include "helper/random/RandomGenerator.h"
#include "logic/data/static/card/CardSet.h"

/*!
 * \class	CardBox
 *
 * \brief	卡牌容器
 *
 * \tparam	CardType	指定卡牌类型
 */
template <typename CardType>
class CardBox
{
private:
	/*! \brief	内建容器 */
	std::list<int> cardIDSet;

public:

	/*!
	 * \fn	CardBox::CardBox()
	 *
	 * \brief	构造函数
	 *
	 */
	CardBox()
	{
	}

	/*!
	 * \fn	CardBox::CardBox(const CardBox &cardBox)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardBox(const CardBox &cardBox) :
		cardIDSet(cardBox.getCardIDSet())
	{
	}

	/*!
	 * \fn	CardBox& CardBox::operator=(const CardBox &cardBox)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardBox& operator=(const CardBox &cardBox)
	{
		this->cardIDSet.clear();
		this->cardIDSet = cardBox.getCardIDSet();
		return *this;
	}

	/*!
	 * \fn	CardBox::~CardBox()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardBox()
	{
	}

	/*!
	 * \fn	void CardBox::add(int cardID)
	 *
	 * \brief	向容器中添加卡牌
	 *
	 * \param	cardID	指定卡牌ID
	 */
	void add(int cardID)
	{
		if (CardSet::Instance()->isCardType(CardType::cardType, cardID))
			cardIDSet.push_back(cardID);
	}

	/*!
	 * \fn	int CardBox::popByRandom()
	 *
	 * \brief	随意中容器中弹出一张卡牌
	 *
	 * \return	返回弹出的卡牌
	 */
	int popByRandom()
	{
		int result = CardBase::invalidCardID;
		if (cardIDSet.empty())
			return result;

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, cardIDSet.size() - 1);
		if (0 <= luckyDog && luckyDog < cardIDSet.size())
		{
			auto it = cardIDSet.begin();
			for (int i = 0; i < luckyDog; ++i)
				++it;
			result = *it;
			cardIDSet.erase(it);
		}
		return result;
	}

	/*!
	 * \fn	int CardBox::popByIndex(int index)
	 *
	 * \brief	根据给定容器中索引以弹出一张卡牌
	 *
	 * \param	index	指定容器中的索引
	 *
	 */
	int popByIndex(int index)
	{
		int result = CardBase::invalidCardID;

		if (0 <= index && index < cardIDSet.size())
		{
			auto it = cardIDSet.begin();
			for (int i = 0; i < index; ++i)
				++it;
			result = *it;
			cardIDSet.erase(it);
		}

		return result;
	}

	/*!
	 * \fn	int CardBox::popByCardID(int cardID)
	 *
	 * \brief	指定卡牌ID以弹出卡牌
	 *
	 * \param	cardID	指定卡牌ID
	 */
	int popByCardID(int cardID)
	{
		int result = CardBase::invalidCardID;
		auto it = cardIDSet.begin();
		auto itEnd = cardIDSet.end();
		while (it != itEnd)
		{
			if (*it == cardID)
			{
				result = *it;
				cardIDSet.erase(it);
				return result;
			}
			++it;
		}
		return result;
	}

	/*!
	 * \fn	void CardBox::clear()
	 *
	 * \brief	清空容器
	 *
	 */
	void clear()
	{
		cardIDSet.clear();
	}

	/*!
	 * \fn	int CardBox::getCardCount()const
	 *
	 * \brief	获取容器当前的卡牌数量
	 *
	 */
	int getCardCount()const
	{
		return cardIDSet.size();
	}

	/*!
	 * \fn	int CardBox::find(int cardID)const
	 *
	 * \brief	查找指定卡牌ID第一次出现的索引
	 *
	 * \param	cardID	指定带查找的卡牌ID
	 *
	 * \return	返回指定ID第一次出现的索引，未找到则返回 -1
	 */
	int find(int cardID)const
	{
		auto it = cardIDSet.cbegin();
		auto itEnd = cardIDSet.cend();
		int index = 0;
		while (it != itEnd)
		{
			if (*it == cardID)
				return index;
			++it;
			++index;
		}
		return -1;
	}

	/*!
	 * \fn	const std::list<int>& CardBox::getCardIDSet()const
	 *
	 * \brief	获取所有的卡牌的ID
	 *
	 */
	const std::list<int>& getCardIDSet()const
	{
		return cardIDSet;
	}
};

#endif
