/*!
 * \file	Classes\cardController\CardControllerExplore.h
 *
 * \brief	������ CardControllerExplore
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <map>

#include "cardController/CardBoxRTM.h"

/*!
 * \class	CardControllerExplore
 *
 * \brief	������̽�������µĿ��ƿ����������������ء����ƺͻ���վ��
 *
 */
class CardControllerExplore
{
private:

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CardControllerExplore(){}

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore(const CardControllerExplore& cardControllerExplore);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	cardControllerExplore	CardControllerExploreʵ��
	 */
	CardControllerExplore(const CardControllerExplore& cardControllerExplore);

	/*!
	 * \fn	CardControllerExplore& CardControllerExplore::operator=(const CardControllerExplore& cardControllerExplore);
	 *
	 * \brief	���صĸ�ֵ�����
	 *
	 * \param	cardControllerExplore	CardControllerExploreʵ��
	 *
	 * \return	CardControllerExploreʵ��
	 */
	CardControllerExplore& operator=(const CardControllerExplore& cardControllerExplore);

	/*! \brief	���� */
	CardBoxRTM *cardPool = new CardBoxRTM();
	/*! \brief	���� */
	CardBoxRTM *handCard = new CardBoxRTM(5);
	/*! \brief	����վ */
	CardBoxRTM *recycleCard = new CardBoxRTM();

public:

	/*!
	 * \fn	static CardControllerExplore* CardControllerExplore::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static CardControllerExplore* Instance();

	/*!
	 * \fn	CardControllerExplore::~CardControllerExplore()
	 *
	 * \brief	��������
	 *
	 */
	~CardControllerExplore()
	{
		delete cardPool;
		cardPool = nullptr;

		delete handCard;
		handCard = nullptr;

		delete recycleCard;
		recycleCard = nullptr;
	}

	/*!
	 * \fn	int CardControllerExplore::getCardCountCardPool()const
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
	 * \fn	int CardControllerExplore::getCardCountHandCard()const
	 *
	 * \brief	��ȡ�����еĿ�����
	 *
	 * \return	��ȡ�����еĿ�����
	 */
	int getCardCountHandCard()const
	{
		return handCard->getCardCount();
	}

	/*!
	 * \fn	int CardControllerExplore::getCardCountRecycleCard()const
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
	 * \fn	bool CardControllerExplore::isFullHandCard()const
	 *
	 * \brief	�ж������Ƿ�����
	 *
	 * \return	���������Ƿ�����
	 */
	bool isFullHandCard()const
	{
		return handCard->isFull();
	}

	/*!
	 * \fn	int CardControllerExplore::addCardToCardPool(int id)
	 *
	 * \brief	����id���򿨳������һ�ſ������ο������￨�͹��￨��
	 *
	 * \param	id	������Ҫ���뵽���صĿ���id
	 *
	 * \return	���ؼ��뵽�����еĿ���id��ʧ���򷵻� CardBase::invalidID
	 */
	int addCardToCardPool(int id)
	{
		cocos2d::log("[information] ������̽�������Ŀ����м���һ��idΪ%d�Ŀ�...", id);
		// �򿨳�����ӿ�
		int result = cardPool->addCardByID(id);
		if (result != CardBase::invalidID)
			cocos2d::log("[information] �ɹ���̽�������Ŀ����м���һ��idΪ%d�Ŀ�", id);
		else
			cocos2d::log("[information] ��̽�������Ŀ����м���һ��idΪ%d�Ŀ�ʧ��", id);
		return result;
	}

	/*!
	 * \fn	int CardControllerExplore::drawACard()
	 *
	 * \brief	�ӿ����г�ȡһ�ſ���������
	 *
	 * \return	���س鵽�Ŀ���id��ʧ�ܷ��� CardBase::invalidID
	 */
	int drawACard();

	/*!
	 * \fn	int CardControllerExplore::playCardByID(int id)
	 *
	 * \brief	���������Ƴ�����id�Ŀ�������վ�����ƣ�
	 *
	 * \param	id	ָ�����Ƴ��Ŀ���id
	 *
	 * \return	���ر��Ƴ��Ŀ���id
	 */
	int playCardByID(int id)
	{
		cocos2d::log("[information] ���ڴ�̽��������������ʹ��һ��idΪ%d�Ŀ�...", id);
		// ���������Ƴ�һ�ſ�
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] �ɹ���̽��������������ʹ��һ��idΪ%d��", id);
		else
			cocos2d::log("[warning] ��̽��������������ʹ��һ��idΪ%d��ʧ��", id);
		// �������뵽������
		recycleCard->addCardByID(result);
		return result;
	}

	/*!
	 * \fn	int CardControllerExplore::playCardByIndex(int index)
	 *
	 * \brief	���������Ƴ����������Ŀ�������վ�����ƣ�
	 *
	 * \param	index	ָ�����Ƴ��Ŀ���id
	 *
	 * \return	���ر��Ƴ��Ŀ��Ƶ�id
	 */
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] ���ڴ�̽��������������ʹ��һ������Ϊ%d�Ŀ�...", index);
		// ���������Ƴ�һ�ſ�
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] �ɹ���̽��������������ʹ��һ������Ϊ%d,idΪ%d�Ŀ�", index, id);
		else
			cocos2d::log("[warning] ��̽��������������ʹ��һ������Ϊ%d��ʧ��", index);
		// ���ÿ��������վ
		recycleCard->addCardByID(id);
		return id;
	}

	/*!
	 * \fn	void CardControllerExplore::shuffle()
	 *
	 * \brief	ϴ��
	 *
	 */
	void shuffle();

	/*!
	 * \fn	void CardControllerExplore::clear()
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
	 * \fn	const std::map<int, int>& CardControllerExplore::getCardPool()const
	 *
	 * \brief	��ȡ�����е����п��Ƶ�id
	 *
	 * \return	���ؿ����е����п��Ƶ�id
	 */
	const std::map<int, int>& getCardPool()const
	{
		return cardPool->getCardSet();
	}

	/*!
	 * \fn	const std::map<int, int>& CardControllerExplore::getHandCard()const
	 *
	 * \brief	��ȡ���������п��Ƶ�id
	 *
	 * \return	�������������п��Ƶ�id
	 */
	const std::map<int, int>& getHandCard()const
	{
		return handCard->getCardSet();
	}

	/*!
	 * \fn	const std::map<int, int>& CardControllerExplore::getRecycleCard()const
	 *
	 * \brief	��ȡ����վ�е����п��Ƶ�id
	 *
	 * \return	���ػ���վ�е����п��Ƶ�id
	 */
	const std::map<int, int>& getRecycleCard()const
	{
		return recycleCard->getCardSet();
	}
};

#endif
