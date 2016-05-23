/*!
 * \file	Classes\logic\gameObject\cardContainer\CardBox3.h
 *
 * \brief	������ CardBox3
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
 * \brief	�����������ֲ�ͬ���͵Ŀ��ƵĿ�������
 *
 * \tparam	CardType0	ָ����������
 * \tparam	CardType1	ָ����������
 * \tparam	CardType2	ָ����������
 */
template <typename CardType0, typename CardType1, typename CardType2>
class CardBox3
{
private:
	/*! \brief	�ڽ��������� */
	std::list<int> cardIDSet;

	/*! \brief	0�࿨������ */
	int cardType0Count;
	/*! \brief	1�࿨������ */
	int cardType1Count;
	/*! \brief	2�࿨������ */
	int cardType2Count;

	/*!
	 * \fn	void CardBox3::minusCardCount(CardBase::CardType cardType)
	 *
	 * \brief	�ݼ�ָ�����Ϳ��Ƶ�����
	 *
	 * \param	cardType	ָ����������
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
	 * \brief	���캯��
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
	 * \brief	�������캯��
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
	 * \brief	������ֵ�����
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
	 * \brief	��������
	 *
	 */
	~CardBox3()
	{
	}

	/*!
	 * \fn	bool CardBox3::checkCardType(CardBase::CardType cardType)const
	 *
	 * \brief	�ж��Ƿ�Ϊ��������Ŀ�������
	 *
	 * \param	cardType	ָ����������
	 *
	 */
	bool checkCardType(CardBase::CardType cardType)const
	{
		return (cardType == CardType0::cardType || cardType == CardType1::cardType || cardType == CardType2::cardType);
	}

	/*!
	 * \fn	bool CardBox3::isEmpty()const
	 *
	 * \brief	���������Ƿ�Ϊ��
	 *
	 */
	bool isEmpty()const
	{
		return cardIDSet.empty();
	}

	/*!
	 * \fn	int CardBox3::getCardCount()const
	 *
	 * \brief	��ȡ��ǰ�Ŀ�������
	 *
	 */
	int getCardCount()const
	{
		return cardIDSet.size();
	}

	/*!
	 * \fn	int CardBox3::getCardCountByCardType(CardBase::CardType cardType)const
	 *
	 * \brief	��ȡ��ǰָ�����Ϳ��Ƶ�����
	 *
	 * \param	cardType	ָ����������
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
	 * \brief	�����������ָ��ID����
	 *
	 * \param	cardID	ָ������ӵĿ���ID
	 *
	 * \return	�����Ƿ���ӳɹ�
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
	 * \brief	����Ĵ������е���ָ�����͵Ŀ���
	 *
	 * \param	cardType	ָ������������Ŀ�������
	 *
	 * \return	���ص����Ŀ���ID
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
	 * \brief	������������صĵ���ָ�����͵Ŀ���
	 *
	 * \param	cardType0	ָ������������Ŀ�������
	 * \param	cardType1	ָ������������Ŀ�������
	 *
	 * \return	���ص����Ŀ���ID
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
	 * \brief	��ָ�����͵ش������е���һ�ſ���
	 *
	 * \return	���ص����Ŀ��Ƶ�ID
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
	 * \brief	�������е���ָ����������
	 *
	 * \param	index	ָ���������Ŀ��Ƶ�����
	 *
	 * \return	���ص����Ŀ��Ƶ�ID
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
	 * \brief	�������е���ָ��ID����
	 *
	 * \param	cardID	ָ���������Ŀ���ID
	 *
	 * \return	���ص����Ŀ���ID
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
	 * \brief	�������
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
	 * \brief	�������в���ָ��ID����
	 *
	 * \param	cardID	ָ�������ҵĿ��Ƶ�ID
	 *
	 * \return	����ָ��ID���Ƶ�һ�γ��ֵ�����������δ�ҵ��򷵻� -1
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
	 * \brief	��ȡ���������п��Ƶ�ID����
	 *
	 */
	const std::list<int>& getCardIDSet()const
	{
		return cardIDSet;
	}
};

#endif
