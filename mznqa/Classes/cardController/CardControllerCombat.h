/*!
 * \file	Classes\cardController\CardControllerCombat.h
 *
 * \brief	������ CardControllerCombat
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLERCOMBAT_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLERCOMBAT_H_

#include <list>

#include "cardController/CardBox.h"
#include "card/CardSkill.h"

/*!
 * \class	CardControllerCombat
 *
 * \brief	����ս�������µĿ��ƿ����������������ء����ƺͻ���վ��
 *
 */
class CardControllerCombat
{
private:
	/*! \brief	���� */
	CardBox<CardSkill> *cardPool = new CardBox<CardSkill>();
	/*! \brief	���� */
	CardBox<CardSkill> *handCard = new CardBox<CardSkill>(5);
	/*! \brief	����վ */
	CardBox<CardSkill> *recycleCard = new CardBox<CardSkill>();

public:

	/*!
	 * \fn	CardControllerCombat::CardControllerCombat()
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 */

	CardControllerCombat()
	{}

	/*!
	 * \fn	CardControllerCombat::~CardControllerCombat()
	 *
	 * \brief	��������
	 *
	 */
	~CardControllerCombat()
	{
		delete cardPool;
		cardPool = nullptr;

		delete handCard;
		handCard = nullptr;

		delete recycleCard;
		recycleCard = nullptr;
	}

	/*!
	 * \fn	int CardControllerCombat::getCardCountCardPool()const
	 *
	 * \brief	��ȡ�����еĿ�����
	 *
	 * \return	���ؿ����еĿ�����
	 */
	int getCardCountCardPool()const
	{
		return cardPool->getCardCount();
	}

	/*!
	 * \fn	int CardControllerCombat::getCardCountHandCard()const
	 *
	 * \brief	��ȡ�����еĿ�����
	 *
	 * \return	���������еĿ�����
	 */
	int getCardCountHandCard()const
	{
		return handCard->getCardCount();
	}

	/*!
	 * \fn	int CardControllerCombat::getCardCountRecycleCard()const
	 *
	 * \brief	��ȡ����վ�еĿ�����
	 *
	 * \return	���ػ���վ�еĿ�����
	 */
	int getCardCountRecycleCard()const
	{
		return recycleCard->getCardCount();
	}

	/*!
	 * \fn	bool CardControllerCombat::isFullHandCard()const
	 *
	 * \brief	�жϵ�ǰ�����Ƿ�����
	 *
	 * \return	���ص�ǰ�����Ƿ�����
	 */
	bool isFullHandCard()const
	{
		return handCard->isFull();
	}

	/*!
	 * \fn	int CardControllerCombat::addCardToCardPool(int id)
	 *
	 * \brief	��������id�򿨳������һ�ſ������ܿ���
	 *
	 * \param	id	ָ������id��ս�������µĽ����ռ��ܿ�
	 *
	 * \return	�ɹ�������ӵ����صĿ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int addCardToCardPool(int id)
	{
		cocos2d::log("[information] ������ս�������Ŀ����м���һ��idΪ%d�Ŀ�...", id);
		int result = cardPool->addCardByID(id);
		if (result != CardBase::invalidID)
			cocos2d::log("[information] �ɹ���ս�������Ŀ����м���һ��idΪ%d�Ŀ�", id);
		else
			cocos2d::log("[information] ��ս�������Ŀ����м���һ��idΪ%d�Ŀ�ʧ��");
		return result;
	}

	/*!
	 * \fn	int CardControllerCombat::drawACard()
	 *
	 * \brief	�ӿ����г�һ�ſ���������
	 *
	 * \return	���س鵽�Ŀ��Ƶ�id
	 */
	int drawACard();

	/*!
	 * \fn	int CardControllerCombat::playCardByID(int id)
	 *
	 * \brief	���������Ƴ�����id�Ŀ�������վ�����ƣ�
	 *
	 * \param	id	ָ��id���Ƴ��������ƣ�
	 *
	 * \return	���ر��Ƴ��Ŀ���id
	 */
	int playCardByID(int id)
	{
		cocos2d::log("[information] ���ڴ�ս��������������ʹ��һ��idΪ%d�Ŀ�...", id);
		// ���������Ƴ���
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] �ɹ���ս��������������ʹ��һ��idΪ%d��", id);
		else
			cocos2d::log("[warning] ��ս��������������ʹ��һ��idΪ%d��ʧ��", id);
		// �����վ����Ӹÿ�
		recycleCard->addCardByID(result);
		return result;
	}

	/*!
	 * \fn	int CardControllerCombat::playCardByIndex(int index)
	 *
	 * \brief	���������Ƴ����������Ŀ�������վ�����ƣ�
	 *
	 * \param	index	ָ�������п��Ƶ�����
	 *
	 * \return	���ر��Ƴ��Ŀ��Ƶ�id
	 */
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] ���ڴ�ս��������������ʹ��һ������Ϊ%d�Ŀ�...", index);
		// ���������Ƴ���
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] �ɹ���ս��������������ʹ��һ������Ϊ%d,idΪ%d�Ŀ�", index, id);
		else
			cocos2d::log("[warning] ��ս��������������ʹ��һ������Ϊ%d��ʧ��", index);
		// �����վ����Ӹÿ�
		recycleCard->addCardByID(id);
		return id;
	}

	/*!
	 * \fn	void CardControllerCombat::shuffle()
	 *
	 * \brief	ϴ��
	 *
	 */
	void shuffle();

	/*!
	 * \fn	void CardControllerCombat::clear()
	 *
	 * \brief	��տ��ƿ������е����п�
	 *
	 */
	void clear()
	{
		cardPool->clear();
		handCard->clear();
		recycleCard->clear();
	}

	/*!
	 * \fn	const std::list<int>& CardControllerCombat::getCardPool()const
	 *
	 * \brief	��ȡ���������п���id
	 *
	 * \return	���ؿ��������п���id
	 */
	const std::list<int>& getCardPool()const
	{
		return cardPool->getCardSet();
	}

	/*!
	 * \fn	const std::list<int>& CardControllerCombat::getHandCard()const
	 *
	 * \brief	��ȡ���������п���id
	 *
	 * \return	�������������п���id
	 */
	const std::list<int>& getHandCard()const
	{
		return handCard->getCardSet();
	}

	/*!
	 * \fn	const std::list<int>& CardControllerCombat::getRecycleCard()const
	 *
	 * \brief	��ȡ���н������յĿ���id
	 *
	 * \return	�������н������յĿ���id
	 */
	const std::list<int>& getRecycleCard()const
	{
		return recycleCard->getCardSet();
	}
};

#endif
