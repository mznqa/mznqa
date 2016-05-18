/*!
* \file	Classes\logic\gameObject\cardController\CardControllerCombat.h
*
* \brief	������ CardControllerCombat
*/

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTROLLER_CARDCONTROLLERCOMBAT_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARDCONTROLLER_CARDCONTROLLERCOMBAT_H_

#include <list>
#include <array>

#include "logic/gameObject/cardContainer/CardBox.h"
#include "logic/gameObject/cardContainer/CardArray.h"
#include "logic/data/info/NumDefine.h"

/*!
* \class	CardControllerCombat
*
* \brief	ս�������µĿ��ƿ�����
*
*/
class CardControllerCombat
{
private:
	/*! \brief	�ڽ����� */
	CardBox<CardSkill> pool;
	/*! \brief	�ڽ�����վ */
	CardBox<CardSkill> recycleBin;
	/*! \brief	�ڽ��������� */
	CardArray<CardSkill, EXPLORE_CARDHOLDERSIZE> holder;
public:

	/*!
	* \fn	CardControllerCombat::CardControllerCombat();
	*
	* \brief	���캯��
	*
	*/
	CardControllerCombat();

	/*!
	* \fn	CardControllerCombat::CardControllerCombat(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	*
	* \brief	���캯��
	*
	* \param	poolCardIDSet	   	ָ�������еĿ���ID����
	* \param	recycleBinCardIDSet	ָ���������Ŀ���ID����
	* \param	holderCardIDSet	   	ָ���������Ŀ���ID����
	*/
	CardControllerCombat(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	* \fn	CardControllerCombat::CardControllerCombat(const CardControllerCombat &cardControllerCombat);
	*
	* \brief	�������캯��
	*
	*/
	CardControllerCombat(const CardControllerCombat &cardControllerCombat);

	/*!
	* \fn	CardControllerCombat& CardControllerCombat::operator=(const CardControllerCombat &cardControllerCombat);
	*
	* \brief	������ֵ�����
	*
	*/
	CardControllerCombat& operator=(const CardControllerCombat &cardControllerCombat);

	/*!
	* \fn	CardControllerCombat::~CardControllerCombat();
	*
	* \brief	��������
	*
	*/
	~CardControllerCombat();

	/*!
	* \fn	void CardControllerCombat::reset();
	*
	* \brief	���ÿ��ƿ����������п��ƽ��������ڿ�����
	*
	*/
	void reset();

	/*!
	* \fn	void CardControllerCombat::reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	*
	* \brief	���ݸ����Ŀ���ID�������ÿ��ƿ�����
	*
	* \param	poolCardIDSet	   	ָ���������Ŀ���ID����
	* \param	recycleBinCardIDSet	ָ���������Ŀ���ID����
	* \param	holderCardIDSet	   	ָ���������Ŀ���ID����
	*/
	void reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	* \fn	void CardControllerCombat::addCardToPool(int cardID);
	*
	* \brief	�򿨳�����ӿ���
	*
	* \param	cardID	ָ������ӵĿ���ID
	*/
	void addCardToPool(int cardID);

	/*!
	* \fn	int CardControllerCombat::drawCard();
	*
	* \brief	�ӿ�����������һ�ſ��Ƶ�������
	*
	* \return	���س鵽�Ŀ��Ƶ�ID
	*/
	int drawCard();

	/*!
	* \fn	int CardControllerCombat::discard(int index);
	*
	* \brief	�������ж���ָ������λ���ϵĿ��Ƶ�������
	*
	* \param	index	ָ���������Ŀ��Ƶ�����
	*
	* \return	���ر������Ŀ��Ƶ�ID
	*/
	int discard(int index);

	/*!
	* \fn	void CardControllerCombat::shuffle();
	*
	* \brief	ϴ�ƣ�����ǰ�����������п����Ƶ�������
	*
	*/
	void shuffle();

	/*!
	* \fn	void CardControllerCombat::clear();
	*
	* \brief	������ƿ�����
	*
	*/
	void clear();

	/*!
	* \fn	bool CardControllerCombat::isEmptyPool()const;
	*
	* \brief	�жϿ����Ƿ�Ϊ��
	*
	*/
	bool isEmptyPool()const;

	/*!
	* \fn	bool CardControllerCombat::isEmptyRecycleBin()const;
	*
	* \brief	�ж��������Ƿ�Ϊ��
	*
	*/
	bool isEmptyRecycleBin()const;

	/*!
	* \fn	bool CardControllerCombat::isEmptyHolder()const;
	*
	* \brief	�ж��������Ƿ�Ϊ��
	*
	*/
	bool isEmptyHolder()const;

	/*!
	* \fn	bool CardControllerCombat::isFullHolder()const;
	*
	* \brief	�ж��������Ƿ�����
	*
	*/
	bool isFullHolder()const;

	/*!
	* \fn	const std::list<int>& CardControllerCombat::getPoolCardIDSet()const;
	*
	* \brief	��ȡ�����е����п��Ƶ�ID
	*
	*/
	const std::list<int>& getPoolCardIDSet()const;

	/*!
	* \fn	const std::list<int>& CardControllerCombat::getRecycleBinCardIDSet()const;
	*
	* \brief	��ȡ�������е����п��Ƶ�ID
	*
	*/
	const std::list<int>& getRecycleBinCardIDSet()const;

	/*!
	* \fn	const std::array<int, EXPLORE_CARDHOLDERSIZE>& CardControllerCombat::getHolderCardIDSet()const;
	*
	* \brief	��ȡ���������п��Ƶ�ID
	*
	*/
	const std::array<int, EXPLORE_CARDHOLDERSIZE>& getHolderCardIDSet()const;
};

#endif
