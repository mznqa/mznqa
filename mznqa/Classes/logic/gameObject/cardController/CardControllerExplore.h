/*!
 * \file	Classes\logic\gameObject\cardController\CardControllerExplore.h
 *
 * \brief	������ CardControllerExplore
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <list>
#include <array>

#include "logic/gameObject/cardContainer/CardBox3.h"
#include "logic/gameObject/cardContainer/CardArray3.h"
#include "logic/data/info/NumDefine.h"

/*!
 * \class	CardControllerExplore
 *
 * \brief	̽�������µĿ��ƿ�����
 *
 */
class CardControllerExplore
{
private:
	/*! \brief	�ڽ����� */
	CardBox3<CardRoad, CardTreasure, CardMonster> pool;
	/*! \brief	�ڽ�����վ */
	CardBox3<CardRoad, CardTreasure, CardMonster> recycleBin;
	/*! \brief	�ڽ��������� */
	CardArray3<CardRoad, CardTreasure, CardMonster, EXPLORE_CARDHOLDERSIZE> holder;
public:

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore();
	 *
	 * \brief	���캯��
	 *
	 */
	CardControllerExplore();

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	 *
	 * \brief	���캯��
	 *
	 * \param	poolCardIDSet	   	ָ�������еĿ���ID����
	 * \param	recycleBinCardIDSet	ָ���������Ŀ���ID����
	 * \param	holderCardIDSet	   	ָ���������Ŀ���ID����
	 */
	CardControllerExplore(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore(const CardControllerExplore &cardControllerExplore);
	 *
	 * \brief	�������캯��
	 *
	 */
	CardControllerExplore(const CardControllerExplore &cardControllerExplore);

	/*!
	 * \fn	CardControllerExplore& CardControllerExplore::operator=(const CardControllerExplore &cardControllerExplore);
	 *
	 * \brief	������ֵ�����
	 *
	 */
	CardControllerExplore& operator=(const CardControllerExplore &cardControllerExplore);

	/*!
	 * \fn	CardControllerExplore::~CardControllerExplore();
	 *
	 * \brief	��������
	 *
	 */
	~CardControllerExplore();

	/*!
	 * \fn	void CardControllerExplore::reset();
	 *
	 * \brief	���ÿ��ƿ����������п��ƽ��������ڿ�����
	 *
	 */
	void reset();

	/*!
	 * \fn	void CardControllerExplore::reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	 *
	 * \brief	���ݸ����Ŀ���ID�������ÿ��ƿ�����
	 *
	 * \param	poolCardIDSet	   	ָ���������Ŀ���ID����
	 * \param	recycleBinCardIDSet	ָ���������Ŀ���ID����
	 * \param	holderCardIDSet	   	ָ���������Ŀ���ID����
	 */
	void reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	 * \fn	void CardControllerExplore::addCardToPool(int cardID);
	 *
	 * \brief	�򿨳�����ӿ���
	 *
	 * \param	cardID	ָ������ӵĿ���ID
	 */
	void addCardToPool(int cardID);

	/*!
	 * \fn	int CardControllerExplore::drawCard();
	 *
	 * \brief	�ӿ�����������һ�ſ��Ƶ�������
	 *
	 * \return	���س鵽�Ŀ��Ƶ�ID
	 */
	int drawCard();

	/*!
	 * \fn	int CardControllerExplore::discard(int index);
	 *
	 * \brief	�������ж���ָ������λ���ϵĿ��Ƶ�������
	 *
	 * \param	index	ָ���������Ŀ��Ƶ�����
	 *
	 * \return	���ر������Ŀ��Ƶ�ID
	 */
	int discard(int index);

	/*!
	 * \fn	void CardControllerExplore::shuffle();
	 *
	 * \brief	ϴ�ƣ�����ǰ�����������п����Ƶ�������
	 *
	 */
	void shuffle();

	/*!
	 * \fn	void CardControllerExplore::clear();
	 *
	 * \brief	������ƿ�����
	 *
	 */
	void clear();

	/*!
	 * \fn	bool CardControllerExplore::isEmptyPool()const;
	 *
	 * \brief	�жϿ����Ƿ�Ϊ��
	 *
	 */
	bool isEmptyPool()const;

	/*!
	 * \fn	bool CardControllerExplore::isEmptyRecycleBin()const;
	 *
	 * \brief	�ж��������Ƿ�Ϊ��
	 *
	 */
	bool isEmptyRecycleBin()const;

	/*!
	 * \fn	bool CardControllerExplore::isEmptyHolder()const;
	 *
	 * \brief	�ж��������Ƿ�Ϊ��
	 *
	 */
	bool isEmptyHolder()const;

	/*!
	 * \fn	bool CardControllerExplore::isFullHolder()const;
	 *
	 * \brief	�ж��������Ƿ�����
	 *
	 */
	bool isFullHolder()const;

	/*!
	 * \fn	const std::list<int>& CardControllerExplore::getPoolCardIDSet()const;
	 *
	 * \brief	��ȡ�����е����п��Ƶ�ID
	 *
	 */
	const std::list<int>& getPoolCardIDSet()const;

	/*!
	 * \fn	const std::list<int>& CardControllerExplore::getRecycleBinCardIDSet()const;
	 *
	 * \brief	��ȡ�������е����п��Ƶ�ID
	 *
	 */
	const std::list<int>& getRecycleBinCardIDSet()const;

	/*!
	 * \fn	const std::array<int, EXPLORE_CARDHOLDERSIZE>& CardControllerExplore::getHolderCardIDSet()const;
	 *
	 * \brief	��ȡ���������п��Ƶ�ID
	 *
	 */
	const std::array<int, EXPLORE_CARDHOLDERSIZE>& getHolderCardIDSet()const;
};

#endif
