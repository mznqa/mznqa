/*!
 * \file	Classes\cardController\CardBoxRTM.h
 *
 * \brief	������ CardBoxRTM
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOXRTM_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOXRTM_H_

#include <ctime>
#include <cstdlib>

#include <map>

#include "cardController/CardBox.h"
#include "card/CardRoad.h"
#include "card/CardTreasure.h"
#include "card/CardMonster.h"

/*!
 * \class	CardBoxRTM
 *
 * \brief	��ͬʱ�������ο������￨�͹��￨�Ŀ�������
 *
 */
class CardBoxRTM
{
private:
	/*! \brief	�����������ڴ�ŵ����� */
	CardBox<CardRoad> cardBoxRoad;
	/*! \brief	�����������ڴ�ű��￨ */
	CardBox<CardTreasure> cardBoxTreasure;
	/*! \brief	�����������ڴ�Ź��￨ */
	CardBox<CardMonster> cardBoxMonster;

	/*! \brief	�������Ŀ������������������������Ŀ���id */
	std::map<int, int> index2ID;

	/*! \brief	������С */
	int size;

	/*! \brief	��־��Ч��������Сֵ */
	static const int invalidSizeValue = -1;

	/*!
	 * \fn	int CardBoxRTM::insertIndexByID(int id)
	 *
	 * \brief	���ݸ���id���������������
	 *
	 * \param	id ָ��id
	 *
	 * \return	�ɹ�����������ʧ�ܷ���-1
	 */
	int insertIndexByID(int id)
	{
		// ���������id���Ϸ�
		if (id == CardBase::invalidID)
			return -1;

		// ��������
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, id));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));

		return index2ID.rbegin()->first;
	}

	/*!
	 * \fn	void CardBoxRTM::removeIndexByID(int id)
	 *
	 * \brief	���ݸ���id�Ƴ��������Ķ�Ӧ������ע���Ƴ�������������Ӧ��id�������id��ͬ������£�����С��ֵ��
	 *
	 * \param	id	ָ��id
	 * \return	�ɹ�����������ʧ�ܷ���-1
	 */
	int removeIndexByID(int id);
public:

	/*!
	 * \fn	CardBoxRTM::CardBoxRTM()
	 *
	 * \brief	Ĭ�Ϲ��캯����������һ�����޴�С������ͬʱ��ŵ��ο������￨�͹��￨������
	 */
	CardBoxRTM() :
		size(invalidSizeValue)
	{}

	/*!
	 * \fn	CardBoxRTM::CardBoxRTM(int size)
	 *
	 * \brief	����ָ����С�ģ�����ͬʱ��ŵ��ο������￨�͹��￨������
	 *
	 * \param	size	ָ���������������Ĵ�С��ֵӦ����0���򽫹���һ�����޴�С������
	 */
	CardBoxRTM(int size) :
		size(size)
	{
		if (this->size <= 0)
			this->size = invalidSizeValue;
	}

	/*!
	 * \fn	CardBoxRTM::~CardBoxRTM()
	 *
	 * \brief	��������
	 *
	 */
	~CardBoxRTM()
	{}

	/*!
	 * \fn	int CardBoxRTM::getCardCount()const
	 *
	 * \brief	��ȡ��ǰ�Ŀ�����
	 *
	 * \return	���ص�ǰ�Ŀ�����
	 */
	int getCardCount()const
	{
		return cardBoxRoad.getCardCount() + cardBoxTreasure.getCardCount() + cardBoxMonster.getCardCount();
	}

	/*!
	 * \fn	int CardBoxRTM::getCardRoadCount()const
	 *
	 * \brief	��ȡ�����е��ο��Ŀ�����
	 *
	 * \return	���������е��ο��Ŀ�����
	 */
	int getCardRoadCount()const
	{
		return cardBoxRoad.getCardCount();
	}

	/*!
	 * \fn	int CardBoxRTM::getCardTreasureCount()const
	 *
	 * \brief	��ȡ�����б��￨�Ŀ�����
	 *
	 * \return	���������б��￨�Ŀ�����
	 */
	int getCardTreasureCount()const
	{
		return cardBoxTreasure.getCardCount();
	}

	/*!
	 * \fn	int CardBoxRTM::getCardMonsterCount()const
	 *
	 * \brief	��ȡ�����й��￨�Ŀ�����
	 *
	 * \return	���������й��￨�Ŀ�����
	 */
	int getCardMonsterCount()const
	{
		return cardBoxMonster.getCardCount();
	}

	/*!
	 * \fn	void CardBoxRTM::addCardByCard(const CardRoad& card)
	 *
	 * \brief	����һ�����ο�ʵ�������
	 *
	 * \param	card	ָ�����ο�ʵ��
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int addCardByCard(const CardRoad& card);

	/*!
	 * \fn	int CardBoxRTM::addCardByCard(const CardTreasure& card)
	 *
	 * \brief	����һ�����￨ʵ�������
	 *
	 * \param	card	ָ�����￨ʵ��
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */

	int addCardByCard(const CardTreasure& card);

	/*!
	 * \fn	int CardBoxRTM::addCardByCard(const CardMonster& card)
	 *
	 * \brief	����һ�����￨ʵ�������
	 *
	 * \param	card	ָ�����￨ʵ��
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int addCardByCard(const CardMonster& card);

	/*!
	 * \fn	int CardBoxRTM::addCardByID(int id)
	 *
	 * \brief	��������id�����
	 *
	 * \param	id	ָ��id
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int addCardByID(int id);

	/*!
	 * \fn	int CardBoxRTM::removeCardByID(int id)
	 *
	 * \brief	���߸���id�Ƴ������еĿ��ƣ���ע���Ƴ�������������Ӧ��id�������id��ͬ������£�����С��ֵ������ʱ�䣩
	 *
	 * \param	id ָ�����Ƴ��Ŀ���id
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardByID(int id);

	/*!
	 * \fn	int CardBoxRTM::removeCardByIndex(int index)
	 *
	 * \brief	���ݸ���������ɾ�����ƣ�����ʱ�䣩
	 *
	 * \param	index	��������
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardByIndex(int index);

	/*!
	 * \fn	int CardBoxRTM::removeCardByRandom()
	 *
	 * \brief	����ش��������Ƴ�һ�ſ�
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardByRandom()
	{
		if (index2ID.size() <= 0)
			return CardBase::invalidID;

		// TODO �ݷ�
		srand(unsigned(time(NULL)));

		int index = rand() % (index2ID.size());

		return removeCardByIndex(index);
	}

	/*!
	 * \fn	int CardBoxRTM::removeCardRoadByRandom()
	 *
	 * \brief	����ش��������Ƴ�һ�ŵ��ο�
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardRoadByRandom()
	{
		int id = cardBoxRoad.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}

	/*!
	 * \fn	int CardBoxRTM::removeCardTreasureByRandom()
	 *
	 * \brief	����ش��������Ƴ�һ�ű��￨
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardTreasureByRandom()
	{
		int id = cardBoxTreasure.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}

	/*!
	 * \fn	int CardBoxRTM::removeCardMonsterByRandom()
	 *
	 * \brief	������������Ƴ�һ�Ź��￨
	 *
	 * \return	�ɹ����ؿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int removeCardMonsterByRandom()
	{
		int id = cardBoxMonster.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}

	/*!
	 * \fn	void CardBoxRTM::clear()
	 *
	 * \brief	�������
	 *
	 */
	void clear()
	{
		cardBoxRoad.clear();
		cardBoxTreasure.clear();
		cardBoxMonster.clear();
		index2ID.clear();
	}

	/*!
	 * \fn	bool CardBoxRTM::isFull()
	 *
	 * \brief	�ж������Ƿ�����
	 *
	 * \return	���������Ƿ�����������������ʱδָ��������С����Զ����false
	 */
	bool isFull()
	{
		if (size != CardBase::invalidID && getCardCount() >= size)
			return true;
		else
			return false;
	}

	/*!
	 * \fn	const std::map<int, int>& CardBoxRTM::getCardSet()const
	 *
	 * \brief	��ȡ���������п��Ƶ�id
	 *
	 * \return	�������������п��Ƶ�id
	 */
	const std::map<int, int>& getCardSet()const
	{
		return index2ID;
	}
};

#endif
