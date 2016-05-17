/*!
 * \file	Classes\logic\gameObject\cardContainer\CardBox.h
 *
 * \brief	������ CardBox
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
 * \brief	��������
 *
 * \tparam	CardType	ָ����������
 */
template <typename CardType>
class CardBox
{
private:
	/*! \brief	�ڽ����� */
	std::list<int> cardIDSet;

public:

	/*!
	 * \fn	CardBox::CardBox()
	 *
	 * \brief	���캯��
	 *
	 */
	CardBox()
	{
	}

	/*!
	 * \fn	CardBox::CardBox(const CardBox &cardBox)
	 *
	 * \brief	�������캯��
	 *
	 */
	CardBox(const CardBox &cardBox) :
		cardIDSet(cardBox.getCardIDSet())
	{
	}

	/*!
	 * \fn	CardBox& CardBox::operator=(const CardBox &cardBox)
	 *
	 * \brief	������ֵ�����
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
	 * \brief	��������
	 *
	 */
	~CardBox()
	{
	}

	/*!
	 * \fn	void CardBox::add(int cardID)
	 *
	 * \brief	����������ӿ���
	 *
	 * \param	cardID	ָ������ID
	 */
	void add(int cardID)
	{
		if (CardSet::Instance()->isCardType(CardType::cardType, cardID))
			cardIDSet.push_back(cardID);
	}

	/*!
	 * \fn	int CardBox::popByRandom()
	 *
	 * \brief	�����������е���һ�ſ���
	 *
	 * \return	���ص����Ŀ���
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
	 * \brief	���ݸ��������������Ե���һ�ſ���
	 *
	 * \param	index	ָ�������е�����
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
	 * \brief	ָ������ID�Ե�������
	 *
	 * \param	cardID	ָ������ID
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
	 * \brief	�������
	 *
	 */
	void clear()
	{
		cardIDSet.clear();
	}

	/*!
	 * \fn	int CardBox::getCardCount()const
	 *
	 * \brief	��ȡ������ǰ�Ŀ�������
	 *
	 */
	int getCardCount()const
	{
		return cardIDSet.size();
	}

	/*!
	 * \fn	int CardBox::find(int cardID)const
	 *
	 * \brief	����ָ������ID��һ�γ��ֵ�����
	 *
	 * \param	cardID	ָ�������ҵĿ���ID
	 *
	 * \return	����ָ��ID��һ�γ��ֵ�������δ�ҵ��򷵻� -1
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
	 * \brief	��ȡ���еĿ��Ƶ�ID
	 *
	 */
	const std::list<int>& getCardIDSet()const
	{
		return cardIDSet;
	}
};

#endif
