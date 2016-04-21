/*!
 * \file	Classes\cardController\CardBox.h
 *
 * \brief	������ CardBox
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_

#include <ctime>
#include <cstdlib>

#include <list>

#include "cocos2d.h"

#include "card/CardBase.h"
#include "staticData/CardSet.h"

/*!
 * \class	CardBox
 *
 * \brief	���浥һ�������͵Ŀ�������
 *
 * \tparam	CardType	��������
 */
template <typename CardType>
class CardBox
{
private:
	/*! \brief	���Ƽ��ϣ���Ϊ���Ƶ�id���ϣ� */
	std::list<int> cardSet;

	/*! \brief	��ʶ���������Ĵ�С������ֵΪ invalidSizeValue ʱ�����������޶� */
	int size;

	/*! \brief	��־��Ч��������Сֵ */
	static const int invalidSizeValue = -1;
public:

	/*!
	 * \fn	CardBox::CardBox()
	 *
	 * \brief	Ĭ�Ϲ��캯��������һ�����������Ŀ�������
	 *
	 */
	CardBox() :
		size(invalidSizeValue)
	{}

	/*!
	 * \fn	CardBox::CardBox(int size)
	 *
	 * \brief	���캯��������һ��ָ����С�Ŀ�������
	 *
	 * \param	size	ָ���Ŀ���������С��ӦΪһ�����������������������ֵ���Ϸ�ʱ������һ�����������Ŀ�������
	 */
	CardBox(int size) :
		size(size)
	{
		if (this->size <= 0)
			this->size = invalidSizeValue;
	}

	/*!
	 * \fn	CardBox::~CardBox()
	 *
	 * \brief	��������
	 *
	 */
	~CardBox()
	{}

	/*!
	 * \fn	int CardBox::getCardCount()const
	 *
	 * \brief	��ȡ��ǰ��������
	 *
	 * \return	The card count.
	 */
	int getCardCount()const
	{
		return cardSet.size();
	}

	/*!
	 * \fn	void CardBox::addCardByCard(const CardType& card)
	 *
	 * \brief	����һ������ʵ�������
	 *
	 * \param	card	����ʵ��
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invlidID
	 */
	int addCardByCard(const CardType& card)
	{
		// ���������������
		if (size != invalidSizeValue && (int)cardSet.size() >= size)
			return CardBase::invalidID;

		// ע�⣺���ڴ������ƺϷ����ж�����ֱ�����
		cardSet.push_back(card.getID());

		return card.getID();
	}

	/*!
	 * \fn	int CardBox::addCardByID(int id)
	 *
	 * \brief	����һ������id����ӣ�idָ��Ŀ��Ʊ�����Ч���ڿ��ƿ⣨CardSet�����Ѿ����
	 *
	 * \param	id	The identifier.
	 *
	 * \return	��ӳɹ������ز���������id��ʧ�ܽ����� CardBase::invalidID
	 */
	int addCardByID(int id)
	{
		// �ж�������������
		if (size != invalidSizeValue && (int)cardSet.size() >= size)
			return CardBase::invalidID;

		// ����ǵ��ο��������ڿ��ƿ��д���
		if (
			CardType::CARDTYPE == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// ����Ǳ��￨�������ڿ��ƿ��д���
		else if (
			CardType::CARDTYPE == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// ����ǹ��￨�������ڿ��ƿ��д���
		else if (
			CardType::CARDTYPE == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// ����Ǽ��ܿ��������ڿ��ƿ��д���
		else if (
			CardType::CARDTYPE == CardBase::CardType_Skill &&
			CardSet::Instance()->getCardSkillByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// ��Ч����δ�ڿ��ƿ��еĿ�
		else
		{
			cocos2d::log("[warning] �� CardBox ��ӿ���ʧ�ܣ�������id=%d���󣬻���δ���뵽���ƿ⣬����", id);
			return CardBase::invalidID;
		}
	}

	/*!
	 * \fn	int CardBox::removeCardByID(int id)
	 *
	 * \brief	���ݸ���id�Ƴ�������һ�ŵĿ��ƣ�����ʱ�䣩
	 *
	 * \param	id ָ�����Ƴ�����id
	 *
	 * \return	�ɹ����ظ�id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardByID(int id)
	{
		auto it = cardSet.begin();
		auto itEnd = cardSet.end();
		while (it != itEnd)
		{
			if (*it == id)
			{
				cardSet.erase(it);
				return id;
			}
			++it;
		}
		return CardBase::invalidID;
	}

	/*!
	 * \fn	int CardBox::removeCardByIndex(int index)
	 *
	 * \brief	���������Ƴ�ָ������
	 *
	 * \param	index	ָ����ɾ���Ŀ�������
	 *
	 * \return	�ɹ����ر�ɾ�����Ƶ�id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardByIndex(int index)
	{
		// ��ȡ��ǰ������
		int sTemp = cardSet.size();
		// �������Խ��
		if (!(0 <= index && index < sTemp))
			return CardBase::invalidID;

		// ����...
		// ���������ҵ�ָ�����Ʋ�ɾ��
		auto it = cardSet.begin();
		auto itEnd = cardSet.end();
		int i = 0;
		while (it != itEnd)
		{
			if (i == index)
			{
				int result = *it;
				cardSet.erase(it);
				return result;
			}
			++it;
			++i;
		}

		return CardBase::invalidID;
	}

	/*!
	 * \fn	int CardBox::removeCardByRandom()
	 *
	 * \brief	����Ƴ�һ�ſ���
	 *
	 * \return	�ɹ������ر�ɾ���Ŀ��Ƶ�id��ʧ���򷵻� CardBase::invalidID
	 */
	int removeCardByRandom()
	{
		if (cardSet.size() <= 0)
			return CardBase::invalidID;

		// TODO �ݷ�
		srand(unsigned(time(NULL)));

		int index = rand() % (cardSet.size());

		return removeCardByIndex(index);
	}

	/*!
	 * \fn	void CardBox::clear()
	 *
	 * \brief	�������
	 */
	void clear()
	{
		cardSet.clear();
	}

	/*!
	 * \fn	bool CardBox::isFull()
	 *
	 * \brief	�ж������Ƿ�����
	 *
	 * \return	���������Ƿ�������ע�⵱�����������ʱ��δָ����С�Ļ����ｫ��Զ���� false
	 */
	bool isFull()
	{
		if (size != invalidSizeValue && (int)cardSet.size() >= size)
			return true;
		else
			return false;
	}

	/*!
	 * \fn	const std::list<int>& CardBox::getCardSet()const
	 *
	 * \brief	��ȡһ�������ڵ����п��Ƶ�id����
	 *
	 * \return	��ȡһ�� const std::list&�����������������п��Ƶ�id����
	 */
	const std::list<int>& getCardSet()const
	{
		return cardSet;
	}
};

#endif