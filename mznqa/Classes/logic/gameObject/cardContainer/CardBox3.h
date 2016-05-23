/*!
 * \file	Classes\logic\gameObject\cardContainer\CardBox3.h
 *
 * \brief	定义类 CardBox3
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDBOX3_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDBOX3_H_

#include <list>

#include "logic/gameObject/card/CardBase.h"
#include "logic/data/static/card/CardSet.h"
#include "helper/random/RandomGenerator.h"

/*!
 * \class	CardBox3
 *
 * \brief	允许容纳三种不同类型的卡牌的卡牌容器
 *
 * \tparam	CardType0	指定卡牌类型
 * \tparam	CardType1	指定卡牌类型
 * \tparam	CardType2	指定卡牌类型
 */
template <typename CardType0, typename CardType1, typename CardType2>
class CardBox3
{
private:
	/*! \brief	内建卡牌容器 */
	std::list<int> cardIDSet;

	/*! \brief	0类卡牌总数 */
	int cardType0Count;
	/*! \brief	1类卡牌总数 */
	int cardType1Count;
	/*! \brief	2类卡牌容器 */
	int cardType2Count;

	/*!
	 * \fn	void CardBox3::minusCardCount(CardBase::CardType cardType)
	 *
	 * \brief	递减指定类型卡牌的张数
	 *
	 * \param	cardType	指定卡牌类型
	 */
	void minusCardCount(CardBase::CardType cardType)
	{
		if (cardType == CardType0::cardType)
			--cardType0Count;
		else if (cardType == CardType1::cardType)
			--cardType1Count;
		else if (cardType == CardType2::cardType)
			--cardType2Count;
	}

public:

	/*!
	 * \fn	CardBox3::CardBox3()
	 *
	 * \brief	构造函数
	 *
	 */
	CardBox3() :
		cardIDSet(),
		cardType0Count(0),
		cardType1Count(0),
		cardType2Count(0)
	{
	}

	/*!
	 * \fn	CardBox3::CardBox3(const CardBox3 &cardBox3): cardIDSet(cardBox3.getCardIDSet()), cardType0Count(cardBox3.getCardCountByCardType(CardType0::cardType)), cardType1Count(cardBox3.getCardCountByCardType(CardType1::cardType)), cardType2Count(cardBox3.getCardCountByCardType(CardType2::cardType))
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardBox3(const CardBox3 &cardBox3) :
		cardIDSet(cardBox3.getCardIDSet()),
		cardType0Count(cardBox3.getCardCountByCardType(CardType0::cardType)),
		cardType1Count(cardBox3.getCardCountByCardType(CardType1::cardType)),
		cardType2Count(cardBox3.getCardCountByCardType(CardType2::cardType))
	{
	}

	/*!
	 * \fn	CardBox3& CardBox3::operator=(const CardBox3 &cardBox3)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardBox3& operator=(const CardBox3 &cardBox3)
	{
		this->cardIDSet = cardBox3.getCardIDSet();
		this->cardType0Count = cardBox3.getCardCountByCardType(CardType0::cardType);
		this->cardType1Count = cardBox3.getCardCountByCardType(CardType1::cardType);
		this->cardType2Count = cardBox3.getCardCountByCardType(CardType2::cardType);
		return *this;
	}

	/*!
	 * \fn	CardBox3::~CardBox3()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardBox3()
	{
	}

	/*!
	 * \fn	bool CardBox3::checkCardType(CardBase::CardType cardType)const
	 *
	 * \brief	判断是否为容器允许的卡牌类型
	 *
	 * \param	cardType	指定卡牌类型
	 *
	 */
	bool checkCardType(CardBase::CardType cardType)const
	{
		return (cardType == CardType0::cardType || cardType == CardType1::cardType || cardType == CardType2::cardType);
	}

	/*!
	 * \fn	bool CardBox3::isEmpty()const
	 *
	 * \brief	返回容器是否为空
	 *
	 */
	bool isEmpty()const
	{
		return cardIDSet.empty();
	}

	/*!
	 * \fn	int CardBox3::getCardCount()const
	 *
	 * \brief	获取当前的卡牌总数
	 *
	 */
	int getCardCount()const
	{
		return cardIDSet.size();
	}

	/*!
	 * \fn	int CardBox3::getCardCountByCardType(CardBase::CardType cardType)const
	 *
	 * \brief	获取当前指定类型卡牌的总数
	 *
	 * \param	cardType	指定卡牌类型
	 *
	 */
	int getCardCountByCardType(CardBase::CardType cardType)const
	{
		if (cardType == CardType0::cardType)
			return cardType0Count;
		else if (cardType == CardType1::cardType)
			return cardType1Count;
		else if (cardType == CardType2::cardType)
			return cardType2Count;
		else
			return 0;
	}

	/*!
	 * \fn	bool CardBox3::add(int cardID)
	 *
	 * \brief	向容器中添加指定ID卡牌
	 *
	 * \param	cardID	指定待添加的卡牌ID
	 *
	 * \return	返回是否添加成功
	 */
	bool add(int cardID)
	{
		if (CardSet::Instance()->isCardType(CardType0::cardType, cardID))
		{
			cardIDSet.push_back(cardID);
			++cardType0Count;
			return true;
		}
		if (CardSet::Instance()->isCardType(CardType1::cardType, cardID))
		{
			cardIDSet.push_back(cardID);
			++cardType1Count;
			return true;
		}
		if (CardSet::Instance()->isCardType(CardType2::cardType, cardID))
		{
			cardIDSet.push_back(cardID);
			++cardType2Count;
			return true;
		}
		return false;
	}

	/*!
	 * \fn	int CardBox3::popByRandom(CardBase::CardType cardType)
	 *
	 * \brief	随机的从容器中弹出指定类型的卡牌
	 *
	 * \param	cardType	指定待随机弹出的卡牌类型
	 *
	 * \return	返回弹出的卡牌ID
	 */
	int popByRandom(CardBase::CardType cardType)
	{
		int result = CardBase::invalidCardID;
		if (checkCardType(cardType) == false)
			return result;
		int cardCount = getCardCountByCardType(cardType);
		if (cardCount <= 0)
			return result;

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, cardCount - 1);
		auto it = cardIDSet.begin();
		auto itEnd = cardIDSet.end();
		int i = 0;
		while (it != itEnd)
		{
			if (CardSet::Instance()->isCardType(cardType, *it))
			{
				if (i == luckyDog)
				{
					result = *it;
					cardIDSet.erase(it);
					minusCardCount(cardType);
					return result;
				}
				++i;
			}
			++it;
		}
		return result;
	}

	/*!
	 * \fn	int CardBox3::popByRandom(CardBase::CardType cardType0, CardBase::CardType cardType1)
	 *
	 * \brief	从容器中随机地的弹出指定类型的卡牌
	 *
	 * \param	cardType0	指定待随机弹出的卡牌类型
	 * \param	cardType1	指定待随机弹出的卡牌类型
	 *
	 * \return	返回弹出的卡牌ID
	 */
	int popByRandom(CardBase::CardType cardType0, CardBase::CardType cardType1)
	{
		int result = CardBase::invalidCardID;
		if (checkCardType(cardType0) == true && checkCardType(cardType1) == true)
		{
			int cardCount0 = getCardCountByCardType(cardType0);
			int cardCount1 = getCardCountByCardType(cardType1);
			if (cardCount0 > 0 && cardCount1 > 0)
			{
				int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, 1);
				if (luckyDog == 0)
					return popByRandom(cardType0);
				else if (luckyDog == 1)
					return popByRandom()(cardType1);
			}
			else if (cardCount0 <= 0 && cardCount1 <= 0)
				return result;
			else
			{
				if (cardCount0 > 0)
					return popByRandom(cardType0);
				else if (cardType1 > 0)
					return popByRandom(cardType1);
			}
		}
		else if (checkCardType(cardType0) == false && checkCardType(cardType1) == false)
			return result;
		else
		{
			if (checkCardType(cardType0))
				return popByRandom(cardType0);
			else if (checkCardType(cardType1))
				return popByRandom(cardType1);
		}
		return result;
	}

	/*!
	 * \fn	int CardBox3::popByRandom()
	 *
	 * \brief	无指定类型地从容器中弹出一张卡牌
	 *
	 * \return	返回弹出的卡牌的ID
	 */
	int popByRandom()
	{
		int result = CardBase::invalidCardID;
		if (cardIDSet.empty())
			return result;

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, cardIDSet.size() - 1);
		if (0 <= luckyDog && luckyDog < (int)(cardIDSet.size()))
		{
			auto it = cardIDSet.begin();
			advance(it, luckyDog);
			if (CardSet::Instance()->isCardType(CardType0::cardType, *it))
				minusCardCount(CardType0::cardType);
			else if (CardSet::Instance()->isCardType(CardType1::cardType, *it))
				minusCardCount(CardType1::cardType);
			else if (CardSet::Instance()->isCardType(CardType2::cardType, *it))
				minusCardCount(CardType2::cardType);
			else
				result;
			result = *it;
			cardIDSet.erase(it);
			return result;
		}
		return result;
	}

	/*!
	 * \fn	int CardBox3::popByIndex(int index)
	 *
	 * \brief	从容器中弹出指定索引卡牌
	 *
	 * \param	index	指定待弹出的卡牌的索引
	 *
	 * \return	返回弹出的卡牌的ID
	 */
	int popByIndex(int index)
	{
		int result = CardBase::invalidCardID;

		if (0 <= index && index < cardIDSet.size())
		{
			auto it = cardIDSet.begin();
			advance(it, index);
			if (CardSet::Instance()->isCardType(CardType0::cardType, *it))
				minusCardCount(CardType0::cardType);
			else if (CardSet::Instance()->isCardType(CardType1::cardType, *it))
				minusCardCount(CardType1::cardType);
			else if (CardSet::Instance()->isCardType(CardType2::cardType, *it))
				minusCardCount(CardType2::cardType);
			else
				return result;
			result = *it;
			cardIDSet.erase(it);
		}

		return result;
	}

	/*!
	 * \fn	int CardBox3::popByCardID(int cardID)
	 *
	 * \brief	从容器中弹出指定ID卡牌
	 *
	 * \param	cardID	指定待弹出的卡牌ID
	 *
	 * \return	返回弹出的卡牌ID
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
				if (CardSet::Instance()->isCardType(CardType0::cardType, result))
					minusCardCount(CardType0::cardType);
				else if (CardSet::Instance()->isCardType(CardType1::cardType, result))
					minusCardCount(CardType1::cardType);
				else if (CardSet::Instance()->isCardType(CardType2::cardType, result))
					minusCardCount(CardType2::cardType);
				else
					return result;
				cardIDSet.erase(it);
				return result;
			}
			++it;
		}
		return result;
	}

	/*!
	 * \fn	void CardBox3::clear()
	 *
	 * \brief	清空容器
	 *
	 */
	void clear()
	{
		cardIDSet.clear();
		cardType0Count = 0;
		cardType1Count = 0;
		cardType2Count = 0;
	}

	/*!
	 * \fn	int CardBox3::find(int cardID)const
	 *
	 * \brief	在容器中查找指定ID卡牌
	 *
	 * \param	cardID	指定待查找的卡牌的ID
	 *
	 * \return	返回指定ID卡牌第一次出现的索引，如若未找到则返回 -1
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
	 * \fn	const std::list<int>& CardBox3::getCardIDSet()const
	 *
	 * \brief	获取容器中所有卡牌的ID集合
	 *
	 */
	const std::list<int>& getCardIDSet()const
	{
		return cardIDSet;
	}
};

#endif
