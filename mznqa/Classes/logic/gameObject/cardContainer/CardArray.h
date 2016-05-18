/*!
 * \file	Classes\logic\gameObject\cardContainer\CardArray.h
 *
 * \brief	������ CardArray
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
 * \brief	�̶���С�Ŀ�������
 *
 * \tparam	CardType	ָ����������
 * \tparam	Size		ָ��������С
 */
template <typename CardType, size_t Size>
class CardArray
{
private:
	/*! \brief	�ڽ����� */
	std::array<int, Size> cardIDArray;
	/*! \brief	���������Ϸ����� */
	const ArKCa::Range<int> indexRange;

	/*!
	 * \fn	bool CardArray::checkIndex(int index)
	 *
	 * \brief	��������Ƿ�Ϸ�
	 *
	 * \param	index	ָ������
	 *
	 * \return	���������Ƿ�Ϸ�
	 */
	bool checkIndex(int index)
	{
		return indexRange.isInclude(index);
	}

public:
	/*!
	 * \fn	CardArray::CardArray()
	 *
	 * \brief	���캯��
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
	 * \brief	�������캯��
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
	 * \brief	������ֵ�����
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
	 * \brief	��������
	 *
	 */
	~CardArray()
	{
	}

	/*!
	 * \fn	bool CardArray::isEmpty()const
	 *
	 * \brief	�ж��������Ƿ񲻺��κο���
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
	 * \brief	���������Ƿ�����
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
	 * \brief	�����еĵ�һ����λ���ָ��ID����
	 *
	 * \param	cardID	ָ������ӵĿ���ID
	 *
	 * \return	���ط��ÿ��Ƶ�λ�ã����޿�λ�Է��ÿ����򷵻� -1
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
	 * \brief	����ָ������λ���ϵĿ���
	 *
	 * \param	index 	ָ������
	 * \param	cardID	ָ������ID
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
	 * \brief	������������Ƴ�����
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
	 * \brief	���������Ƴ�����
	 *
	 * \param	index	ָ�����Ƴ��Ŀ��Ƶ�����
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
	 * \brief	�Ƴ���һ��IDΪָ������ID�Ŀ���
	 *
	 * \param	cardID	ָ������ID
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
	 * \brief	�������
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
	 * \brief	��ȡ����������
	 *
	 */
	int getSize()const
	{
		return cardIDArray.size();
	}

	/*!
	 * \fn	int CardArray::getCardCount()const
	 *
	 * \brief	��ȡ��ǰ�Ŀ�����
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
	 * \brief	����ָ��ID�Ŀ����������е�һ�γ��ֵ�λ��
	 *
	 * \param	cardID	ָ�������ҿ���ID
	 *
	 * \return	���ؿ��Ƶ�һ�γ��ֵ�λ�ã�δ�ҵ��򷵻� -1
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
	 * \brief	��ȡ���������п��Ƶ�ID
	 *
	 */
	const std::array<int, Size>& getCardIDArray()const
	{
		return cardIDArray;
	}
};

#endif
