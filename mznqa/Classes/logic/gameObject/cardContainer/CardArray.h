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
		return indexRange.within(index);
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

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(indexRange.min, indexRange.max);
		if (checkIndex(luckyDog))
		{
			result = cardIDArray[luckyDog];
			cardIDArray[luckyDog] = CardBase::invalidCardID;
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
