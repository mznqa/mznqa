/*!
 * \file	Classes\logic\gameObject\cardContainer\CardArray3.h
 *
 * \brief	������ CardArray3
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDARRAY3_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTAINER_CARDARRAY3_H_

#include <array>

#include "common/arkca/Range.h"
#include "logic/gameObject/card/CardBase.h"
#include "logic/data/static/card/CardSet.h"
#include "helper/random/RandomGenerator.h"

/*!
 * \class	CardArray3
 *
 * \brief	�����������ֲ�ͬ���͵Ŀ��ƵĿ�������
 *
 * \tparam	CardType0	ָ����������
 * \tparam	CardType1	ָ����������
 * \tparam	CardType2	ָ����������
 * \tparam	Size	 	ָ����������
 */
template <typename CardType0, typename CardType1, typename CardType2, size_t Size>
class CardArray3
{
private:
	/*! \brief	�ڽ����� */
	std::array<int, Size> cardIDArray;

	/*! \brief	�Ϸ���������Χ */
	const ArKCa::Range<int> indexRange;

	/*! \brief	CardType0���͵Ŀ������� */
	int cardType0Count;
	/*! \brief	CardType1���͵Ŀ������� */
	int cardType1Count;
	/*! \brief	CardType2���͵Ŀ������� */
	int cardType2Count;

	/*!
	 * \fn	bool CardArray3::checkIndex(int index)const
	 *
	 * \brief	�����������Ƿ�Ϸ�
	 *
	 * \param	index	ָ������������
	 *
	 */
	bool checkIndex(int index)const
	{
		return indexRange.isInclude(index);
	}

public:

	/*!
	 * \fn	CardArray3::CardArray3()
	 *
	 * \brief	���캯��
	 *
	 */
	CardArray3() :
		cardIDArray(),
		indexRange(0, Size - 1),
		cardType0Count(0),
		cardType1Count(0),
		cardType2Count(0)
	{
		auto it = cardIDArray.begin();
		auto itEnd = cardIDArray.end();
		while (it != itEnd)
		{
			*it = CardBase::invalidCardID;
			++it;
		}
	}

	/*!
	 * \fn	CardArray3::CardArray3(const CardArray3 &cardArray3) : cardIDArray(cardArray3.getCardIDSet()), indexRange(0, Size - 1), cardType0Count(cardArray3.getCardCountByCardType(CardType0::cardType)), cardType1Count(cardArray3.getCardCountByCardType(CardType1::cardType)), cardType2Count(cardArray3.getCardCountByCardType(CardType2::cardType))
	 *
	 * \brief	�������캯��
	 *
	 */
	CardArray3(const CardArray3 &cardArray3) :
		cardIDArray(cardArray3.getCardIDSet()),
		indexRange(0, Size - 1),
		cardType0Count(cardArray3.getCardCountByCardType(CardType0::cardType)),
		cardType1Count(cardArray3.getCardCountByCardType(CardType1::cardType)),
		cardType2Count(cardArray3.getCardCountByCardType(CardType2::cardType))
	{
	}

	/*!
	 * \fn	CardArray3& CardArray3::operator=(const CardArray3 &cardArray3)
	 *
	 * \brief	������ֵ�����
	 *
	 */
	CardArray3& operator=(const CardArray3 &cardArray3)
	{
		this->cardIDArray = cardArray3.getCardIDSet();
		this->indexRange.set(0, Size - 1);
		this->cardType0Count = cardArray3.getCardCountByCardType(CardType0::cardType);
		this->cardType1Count = cardArray3.getCardCountByCardType(CardType1::cardType);
		this->cardType2Count = cardArray3.getCardCountByCardType(CardType2::cardType);
		return *this;
	}

	/*!
	 * \fn	CardArray3::~CardArray3()
	 *
	 * \brief	��������
	 *
	 */
	~CardArray3()
	{
	}

	/*!
	 * \fn	bool CardArray3::checkCardType(CardBase::CardType cardType)const
	 *
	 * \brief	��鿨������
	 *
	 * \param	cardType	ָ�������Ŀ�������
	 *
	 */
	bool checkCardType(CardBase::CardType cardType)const
	{
		return (cardType == CardType0::cardType || cardType == CardType1::cardType || cardType == CardType2::cardType);
	}

	/*!
	 * \fn	int CardArray3::getSize()const
	 *
	 * \brief	��ȡ��������
	 *
	 */
	int getSize()const
	{
		return cardIDArray.size();
	}

	/*!
	 * \fn	int CardArray3::getCardCount()const
	 *
	 * \brief	��ȡ�ܿ�����
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
	 * \fn	int CardArray3::getCardCountByCardType(CardBase::CardType cardType)const
	 *
	 * \brief	��ȡ������ָ�����Ϳ�������
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
	 * \fn	int CardArray3::add(int cardID)
	 *
	 * \brief	����������ӿ���
	 *
	 * \param	cardID	ָ������ID
	 *
	 * \return	�������λ�õ�����
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
	 * \fn	bool CardArray3::set(int index, int cardID)
	 *
	 * \brief	����ָ��λ�õĿ���
	 *
	 * \param	index 	ָ������
	 * \param	cardID	ָ������ID
	 *
	 * \return	�����Ƿ�ɹ�
	 */
	bool set(int index, int cardID)
	{
		if (!checkIndex(index))
			return false;
		if (CardSet::Instance()->isCardType(CardType0::cardType, cardID))
		{
			cardIDArray[index] = cardID;
			++cardType0Count;
			return true;
		}
		if (CardSet::Instance()->isCardType(CardType1::cardType, cardID))
		{
			cardIDArray[index] = cardID;
			++cardType1Count;
			return true;
		}
		if (CardSet::Instance()->isCardType(CardType2::cardType, cardID))
		{
			cardIDArray[index] = cardID;
			++cardType2Count;
			return true;
		}
		return false;
	}

	/*!
	 * \fn	int CardArray3::removeByRandom(CardBase::CardType cardType)
	 *
	 * \brief	����ش��������Ƴ�ָ�����͵Ŀ���һ��
	 *
	 * \param	cardType	ָ����������
	 *
	 * \return	�����Ƴ��Ŀ���ID
	 */
	int removeByRandom(CardBase::CardType cardType)
	{
		int result = CardBase::invalidCardID;
		if (!checkIndex(cardType))
			return result;

		int cardCount = getCardCountByCardType(cardType);
		if (cardCount <= 0)
			return result;

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, cardCount - 1);
		auto it = cardIDArray.begin();
		auto itEnd = cardIDArray.end();
		auto i = 0;
		while (it != itEnd)
		{
			if (CardSet::Instance()->isCardType(cardType, *it))
			{
				if (i == luckyDog)
				{
					if (cardType == CardType0::cardType)
						--cardType0Count;
					else if (cardType == CardType1::cardType)
						--cardType1Count;
					else if (cardType == CardType2::cardType)
						--cardType2Count;
					else
						return result;
					result = *it;
					*it = CardBase::invalidCardID;
					return result;
				}
				++i;
			}

			++it;
		}
		return result;
	}

	/*!
	 * \fn	int CardArray3::removeByRandom(CardBase::CardType cardType0, CardBase::CardType cardType1)
	 *
	 * \brief	���������Ƴ�ָ�����ֿ������͵Ŀ�һ��
	 *
	 * \param	cardType0	ָ����������
	 * \param	cardType1	ָ����������
	 *
	 * \return	�����Ƴ��Ŀ��Ƶ�ID
	 */
	int removeByRandom(CardBase::CardType cardType0, CardBase::CardType cardType1)
	{
		int result = CardBase::invalidCardID;
		if (checkCardType(cardType0) == true && checkCardType(cardType1) == true)
		{
			int cardCount0 = getCardCountByCardType(cardType0);
			int cardCount1 = getCardCountByCardType(cardType1);
			if (cardCount0 > 0 && cardCount1 > 0)
			{
				int i = RandomGenerator::Instance()->getRandomNumber(0, 1);
				if (i == 0)
					return removeByRandom(cardType0);
				else (i == 1)
					return removeByRandom(cardType1);
			}
			else if (cardCount0 <= 0 && cardCount1 <= 0)
				return result;
			else
			{
				if (cardCount0 > 0)
					return removeByRandom(cardType0);
				else if (cardCount1 > 0)
					return removeByRandom(cardType1);
			}
		}
		else if (checkCardType(cardType0) == false && checkCardType(cardType1) == false)
			return result;
		else
		{
			if (checkCardType(cardType0))
				return removeByRandom(cardType0);
			else (checkCardType(cardType1))
				return removeByRandom(cardType1);
		}
		return result;
	}

	/*!
	 * \fn	int CardArray3::removeByRandom()
	 *
	 * \brief	����ش��������Ƴ�һ�ſ�
	 *
	 * \return	�����Ƴ��Ŀ��Ƶ�ID
	 */
	int removeByRandom()
	{
		int result = CardBase::invalidCardID;
		if (getCardCount() <= 0)
			return result;

		int luckyDog = RandomGenerator::Instance()->getRandomNumber(0, getCardCount() - 1);
		if (indexRange.isInclude(luckyDog))
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
						if (cardType == CardType0::cardType)
							--cardType0Count;
						else if (cardType == CardType1::cardType)
							--cardType1Count;
						else if (cardType == CardType2::cardType)
							--cardType2Count;
						else
							return result;
						result = *it;
						*it = result;
						return result;
					}
				}
				++it;
			}
		}
		return result;
	}

	/*!
	 * \fn	int CardArray3::removeByIndex(int index)
	 *
	 * \brief	���������Ƴ�ָ������λ���ϵĿ���
	 *
	 * \param	index	ָ�����Ƴ��Ŀ��Ƶ�����
	 *
	 * \return	�����Ƴ��Ŀ��Ƶ�ID
	 */
	int removeByIndex(int index)
	{
		int result = CardBase::invalidCardID;
		if (!checkIndex(index))
			return result;

		result = cardIDArray[index];
		cardIDArray[index] = CardBase::invalidCardID;
		return result;
	}

	/*!
	 * \fn	int CardArray3::removeByCardID(int cardID)
	 *
	 * \brief	���ݸ�������ID�Ƴ���һ��IDΪ����ID�Ŀ���
	 *
	 * \param	cardID	ָ������ID
	 *
	 * \return	�����Ƴ��Ŀ��Ƶ�ID
	 */
	int removeByCardID(int cardID)
	{
		int result = CardBase::invalidCardID;

		auto it = cardIDArray.begin();
		auto itEnd = cardIDArray.end();
		while (it != itEnd)
		{
			if (*it == cardID)
			{
				result = *it;
				*it = CardBase::invalidCardID;
				return result;
			}
			++it;
		}
		return result;
	}

	/*!
	 * \fn	void CardArray3::clear()
	 *
	 * \brief	�������
	 *
	 */
	void clear()
	{
		auto it = cardIDArray.begin();
		auto itEnd = cardIDArray.end();
		while (it != itEnd)
		{
			*it = CardBase::invalidCardID;
			++it;
		}

		cardType0Count = 0;
		cardType1Count = 0;
		cardType2Count = 0;
	}

	/*!
	 * \fn	int CardArray3::find(int cardID)const
	 *
	 * \brief	����ָ��ID����
	 *
	 * \param	cardID	ָ������ID
	 *
	 * \return	���ز��ҵ���������δ�ҵ��򷵻� -1
	 */
	int find(int cardID)const
	{
		auto it = cardIDArray.cbegin();
		auto itEnd = cardIDArray.cend();
		int index = 0;
		while (it != itEnd)
		{
			if (*it == cardID)
			{
				return index;
			}
			++it;
			++index;
		}
		return CardBase::invalidCardID;
	}

	/*!
	 * \fn	const std::array<int, Size>& CardArray3::getCardIDSet()const
	 *
	 * \brief	��ȡ���������п��Ƶ�ID
	 */
	const std::array<int, Size>& getCardIDSet()const
	{
		return cardIDArray;
	}
};

#endif
