/*!
 * \file	Classes\cardController\CardControllerCombat.h
 *
 * \brief	定义类 CardControllerCombat
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
 * \brief	用于战斗场景下的卡牌控制器（包含：卡池、手牌和回收站）
 *
 */
class CardControllerCombat
{
private:
	/*! \brief	卡池 */
	CardBox<CardSkill> *cardPool = new CardBox<CardSkill>();
	/*! \brief	手牌 */
	CardBox<CardSkill> *handCard = new CardBox<CardSkill>(5);
	/*! \brief	回收站 */
	CardBox<CardSkill> *recycleCard = new CardBox<CardSkill>();

public:

	/*!
	 * \fn	CardControllerCombat::CardControllerCombat()
	 *
	 * \brief	默认构造函数
	 *
	 */

	CardControllerCombat()
	{}

	/*!
	 * \fn	CardControllerCombat::~CardControllerCombat()
	 *
	 * \brief	析构函数
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
	 * \brief	获取卡池中的卡牌数
	 *
	 * \return	返回卡池中的卡牌数
	 */
	int getCardCountCardPool()const
	{
		return cardPool->getCardCount();
	}

	/*!
	 * \fn	int CardControllerCombat::getCardCountHandCard()const
	 *
	 * \brief	获取手牌中的卡牌数
	 *
	 * \return	返回手牌中的卡牌数
	 */
	int getCardCountHandCard()const
	{
		return handCard->getCardCount();
	}

	/*!
	 * \fn	int CardControllerCombat::getCardCountRecycleCard()const
	 *
	 * \brief	获取回收站中的卡牌数
	 *
	 * \return	返回回收站中的卡牌数
	 */
	int getCardCountRecycleCard()const
	{
		return recycleCard->getCardCount();
	}

	/*!
	 * \fn	bool CardControllerCombat::isFullHandCard()const
	 *
	 * \brief	判断当前手牌是否已满
	 *
	 * \return	返回当前卡牌是否已满
	 */
	bool isFullHandCard()const
	{
		return handCard->isFull();
	}

	/*!
	 * \fn	int CardControllerCombat::addCardToCardPool(int id)
	 *
	 * \brief	给定卡牌id向卡池中添加一张卡（技能卡）
	 *
	 * \param	id	指定卡牌id，战斗场景下的仅接收技能卡
	 *
	 * \return	成功返回添加到卡池的卡的id，失败返回 CardBase::invalidID
	 */
	int addCardToCardPool(int id)
	{
		cocos2d::log("[information] 正在向战斗场景的卡池中加入一张id为%d的卡...", id);
		int result = cardPool->addCardByID(id);
		if (result != CardBase::invalidID)
			cocos2d::log("[information] 成功向战斗场景的卡池中加入一张id为%d的卡", id);
		else
			cocos2d::log("[information] 向战斗场景的卡池中加入一张id为%d的卡失败");
		return result;
	}

	/*!
	 * \fn	int CardControllerCombat::drawACard()
	 *
	 * \brief	从卡池中抽一张卡到手牌中
	 *
	 * \return	返回抽到的卡牌的id
	 */
	int drawACard();

	/*!
	 * \fn	int CardControllerCombat::playCardByID(int id)
	 *
	 * \brief	从手牌中移除给定id的卡到回收站（出牌）
	 *
	 * \param	id	指定id以移除卡（出牌）
	 *
	 * \return	返回被移除的卡的id
	 */
	int playCardByID(int id)
	{
		cocos2d::log("[information] 正在从战斗场景的手牌中使用一张id为%d的卡...", id);
		// 从手牌中移除卡
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] 成功从战斗场景的手牌中使用一张id为%d卡", id);
		else
			cocos2d::log("[warning] 从战斗场景的手牌中使用一张id为%d卡失败", id);
		// 向回收站中添加该卡
		recycleCard->addCardByID(result);
		return result;
	}

	/*!
	 * \fn	int CardControllerCombat::playCardByIndex(int index)
	 *
	 * \brief	从手牌中移除给定索引的卡到回收站（出牌）
	 *
	 * \param	index	指定手牌中卡牌的索引
	 *
	 * \return	返回被移除的卡牌的id
	 */
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] 正在从战斗场景的手牌中使用一张索引为%d的卡...", index);
		// 从手牌中移除卡
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] 成功从战斗场景的手牌中使用一张索引为%d,id为%d的卡", index, id);
		else
			cocos2d::log("[warning] 从战斗场景的手牌中使用一张索引为%d卡失败", index);
		// 向回收站中添加该卡
		recycleCard->addCardByID(id);
		return id;
	}

	/*!
	 * \fn	void CardControllerCombat::shuffle()
	 *
	 * \brief	洗牌
	 *
	 */
	void shuffle();

	/*!
	 * \fn	void CardControllerCombat::clear()
	 *
	 * \brief	清空卡牌控制器中的所有卡
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
	 * \brief	获取卡池中所有卡的id
	 *
	 * \return	返回卡池中所有卡的id
	 */
	const std::list<int>& getCardPool()const
	{
		return cardPool->getCardSet();
	}

	/*!
	 * \fn	const std::list<int>& CardControllerCombat::getHandCard()const
	 *
	 * \brief	获取手牌中所有卡的id
	 *
	 * \return	返回手牌中所有卡的id
	 */
	const std::list<int>& getHandCard()const
	{
		return handCard->getCardSet();
	}

	/*!
	 * \fn	const std::list<int>& CardControllerCombat::getRecycleCard()const
	 *
	 * \brief	获取所有将被回收的卡的id
	 *
	 * \return	返回所有将被回收的卡的id
	 */
	const std::list<int>& getRecycleCard()const
	{
		return recycleCard->getCardSet();
	}
};

#endif
