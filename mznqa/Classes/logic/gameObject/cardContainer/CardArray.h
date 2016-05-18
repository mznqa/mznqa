/*!
 * \file	Classes\logic\gameObject\cardContainer\CardArray.h
 *
 * \brief	定义类 CardArray
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDARRAY_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDARRAY_H_

#include <array>

#include "logic/gameObject/card/CardBase.h"
#include "helper/random/RandomGenerator.h"
#include "logic/data/static/card/CardSet.h"
#include "common/arkca/Range.h"

/*!
 * \class	CardArray
 *
 * \brief	固定大小的卡牌容器
 *
 * \tparam	CardType	指定卡牌类型
 * \tparam	Size		指定容器大小
 */
template <typename CardType, size_t Size>
class CardArray
{
private:
	/*! \brief	内建容器 */
	std::array<int, Size> cardIDArray;
	/*! \brief	保存索引合法区间 */
	const ArKCa::Range<int> indexRange;

	/*!
	 * \fn	bool CardArray::checkIndex(int index)
	 *
	 * \brief	检查索引是否合法
	 *
	 * \param	index	指定索引
	 *
	 * \return	返回索引是否合法
	 */
	bool checkIndex(int index)
	{
		return indexRange.isInclude(index);
	}

public:
	/*!
	 * \fn	CardArray::CardArray()
	 *
	 * \brief	构造函数
	 *
	 */
	CardArray() :
		cardIDArray(),
		indexRange(0, Size - 1)
	{
		for (int i = indexRange.min; i <= indexRange.max; ++i)
			cardIDArray[i] = CardBase::invalidCardID;
	}

	/*!
	 * \fn	CardArray::CardArray(const CardArray &cardArray)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardArray(const CardArray &cardArray) :
		cardIDArray(cardArray.getCardIDArray()),
		indexRange(0, Size - 1)
	{
	}

	/*!
	 * \fn	CardArray& CardArray::operator=(const CardArray &cardArray)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardArray& operator=(const CardArray &cardArray)
	{
		this->cardIDArray = cardArray.getCardIDArray();
		indexRange(0, Size - 1);
	}

	/*!
	 * \fn	CardArray::~CardArray()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardArray()
	{
	}

	/*!
	 * \fn	bool CardArray::isEmpty()const
	 *
	 * \brief	判断容器中是否不含任何卡牌
	 *
	 */
	bool isEmpty()const
	{
		auto it = cardIDArray.cbegin();
		auto itEnd = cardIDArray.cend();
		while (it != itEnd)
		{
			if (*it != CardBase::invalidCardID)
				return false;
			++it;
		}
		return true;
	}

	/*!
	 * \fn	bool CardArray::isFull()const
	 *
	 * \brief	返回容器是否填满
	 *
	 */
	bool isFull()const
	{
		auto it = cardIDArray.cbegin();
		auto itEnd = cardIDArray.cend();
		while (it != itEnd)
		{
			if (*it == CardBase::invalidCardID)
				return false;
			++it;
		}
		return true;
	}

	/*!
	 * \fn	int CardArray::add(int cardID)
	 *
	 * \brief	容器中的第一个空位添加指定ID卡牌
	 *
	 * \param	cardID	指定待添加的卡牌ID
	 *
	 * \return	返回放置卡牌的位置，若无空位以放置卡牌则返回 -1
	 */
	int add(int cardID)
	{
		auto it = cardIDArray.begin();
		auto itEnd = cardIDArray.end();
		int i = 0;
		while (it != itEnd)
		{
			if (*it == CardBase::invalidCardID)
			{
				set(i, cardID);
				return i;
			}
			++it;
			++i;
		}
		return -1;
	}

	/*!
	 * \fn	void CardArray::set(int index, int cardID)
	 *
	 * \brief	设置指定索引位置上的卡牌
	 *
	 * \param	index 	指定索引
	 * \param	cardID	指定卡牌ID
	 */
	void set(int index, int cardID)
	{
		if (!checkIndex(index))
			return;

		if (CardSet::Instance()->isCardType(CardType::cardType, cardID))
			cardIDArray[index] = cardID;
	}

	/*!
	 * \fn	int CardArray::removeByRandom()
	 *
	 * \brief	随机重容器中移除卡牌
	 *
	 */
	int removeByRandom()
	{
		int result = CardBase::invalidCardID;

		if (getCardCount() <= 0)
			return result;

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, getCardCount() - 1);
		if (checkIndex(luckyDog))
		{
			auto it = cardIDArray.begin();
			auto itEnd = cardIDArray.end();
			int count = 0;
			while (it != itEnd)
			{
				if (*it != CardBase::invalidCardID)
				{
					if (count == luckyDog)
					{
						result = *it;
						*it = CardBase::invalidCardID;
						return result;
					}
					++count;
				}
				++it;
			}
		}
		return result;
	}

	/*!
	 * \fn	int CardArray::removeByIndex(int index)
	 *
	 * \brief	根据索引移除卡牌
	 *
	 * \param	index	指定待移除的卡牌的索引
	 *
	 */
	int removeByIndex(int index)
	{
		int result = CardBase::invalidCardID;

		if (checkIndex(index))
		{
			result = cardIDArray[index];
			cardIDArray[index] = CardBase::invalidCardID;
		}

		return result;
	}

	/*!
	 * \fn	void CardArray::removeByCardID(int cardID)
	 *
	 * \brief	移除第一张ID为指定卡牌ID的卡牌
	 *
	 * \param	cardID	指定卡牌ID
	 */
	void removeByCardID(int cardID)
	{
		if (cardID == CardBase::invalidCardID)
			return;

		auto it = cardIDArray.begin();
		auto itEnd = cardIDArray.end();
		while (it != itEnd)
		{
			if (*it == cardID)
			{
				*it = CardBase::invalidCardID;
				return;
			}
			++it;
		}
	}

	/*!
	 * \fn	void CardArray::clear()
	 *
	 * \brief	清空容器
	 *
	 */
	void clear()
	{
		for (int i = indexRange.min; i <= indexRange.max; ++i)
			cardIDArray[i] = CardBase::invalidCardID;
	}

	/*!
	 * \fn	int CardArray::getSize()const
	 *
	 * \brief	获取容器的容量
	 *
	 */
	int getSize()const
	{
		return cardIDArray.size();
	}

	/*!
	 * \fn	int CardArray::getCardCount()const
	 *
	 * \brief	获取当前的卡牌数
	 *
	 */
	int getCardCount()const
	{
		auto it = cardIDArray.cbegin();
		auto itEnd = cardIDArray.cend();
		int count = 0;
		while (it != itEnd)
		{
			if (*it != CardBase::invalidCardID)
				++count;
			++it;
		}
		return count;
	}

	/*!
	 * \fn	int CardArray::find(int cardID)const
	 *
	 * \brief	查找指定ID的卡牌在容器中第一次出现的位置
	 *
	 * \param	cardID	指定待查找卡牌ID
	 *
	 * \return	返回卡牌第一次出现的位置，未找到则返回 -1
	 */
	int find(int cardID)const
	{
		for (int i = indexRange.min; i <= indexRange.max; ++i)
		{
			if (cardIDArray[i] == cardID)
				return i;
		}
		return -1;
	}

	/*!
	 * \fn	const std::array<int, Size>& CardArray::getCardIDArray()const
	 *
	 * \brief	获取容器中所有卡牌的ID
	 *
	 */
	const std::array<int, Size>& getCardIDArray()const
	{
		return cardIDArray;
	}
};

#endif
