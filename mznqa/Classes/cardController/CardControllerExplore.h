/*!
 * \file	Classes\cardController\CardControllerExplore.h
 *
 * \brief	定义类 CardControllerExplore
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <map>

#include "cardController/CardBoxRTM.h"

/*!
 * \class	CardControllerExplore
 *
 * \brief	单例。探索场景下的卡牌控制器（包含：卡池、手牌和回收站）
 *
 */
class CardControllerExplore
{
private:

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CardControllerExplore(){}

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore(const CardControllerExplore& cardControllerExplore);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	cardControllerExplore	CardControllerExplore实例
	 */
	CardControllerExplore(const CardControllerExplore& cardControllerExplore);

	/*!
	 * \fn	CardControllerExplore& CardControllerExplore::operator=(const CardControllerExplore& cardControllerExplore);
	 *
	 * \brief	隐藏的赋值运算符
	 *
	 * \param	cardControllerExplore	CardControllerExplore实例
	 *
	 * \return	CardControllerExplore实例
	 */
	CardControllerExplore& operator=(const CardControllerExplore& cardControllerExplore);

	/*! \brief	卡池 */
	CardBoxRTM *cardPool = new CardBoxRTM();
	/*! \brief	手牌 */
	CardBoxRTM *handCard = new CardBoxRTM(5);
	/*! \brief	回收站 */
	CardBoxRTM *recycleCard = new CardBoxRTM();

public:

	/*!
	 * \fn	static CardControllerExplore* CardControllerExplore::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static CardControllerExplore* Instance();

	/*!
	 * \fn	CardControllerExplore::~CardControllerExplore()
	 *
	 * \brief	析构函数
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
	 * \brief	获取卡池中的卡牌数
	 *
	 * \return	返回卡池中的卡牌数
	 */
	int getCardCountCardPool()const
	{
		return cardPool->getCardCount();
	}

	/*!
	 * \fn	int CardControllerExplore::getCardCountHandCard()const
	 *
	 * \brief	获取手牌中的卡牌数
	 *
	 * \return	获取手牌中的卡牌数
	 */
	int getCardCountHandCard()const
	{
		return handCard->getCardCount();
	}

	/*!
	 * \fn	int CardControllerExplore::getCardCountRecycleCard()const
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
	 * \fn	bool CardControllerExplore::isFullHandCard()const
	 *
	 * \brief	判断手牌是否已满
	 *
	 * \return	返回手牌是否已满
	 */
	bool isFullHandCard()const
	{
		return handCard->isFull();
	}

	/*!
	 * \fn	int CardControllerExplore::addCardToCardPool(int id)
	 *
	 * \brief	给定id以向卡池中添加一张卡（地形卡、宝物卡和怪物卡）
	 *
	 * \param	id	给定将要加入到卡池的卡的id
	 *
	 * \return	返回加入到卡池中的卡的id，失败则返回 CardBase::invalidID
	 */
	int addCardToCardPool(int id)
	{
		cocos2d::log("[information] 正在向探索场景的卡池中加入一张id为%d的卡...", id);
		// 向卡池中添加卡
		int result = cardPool->addCardByID(id);
		if (result != CardBase::invalidID)
			cocos2d::log("[information] 成功向探索场景的卡池中加入一张id为%d的卡", id);
		else
			cocos2d::log("[information] 向探索场景的卡池中加入一张id为%d的卡失败", id);
		return result;
	}

	/*!
	 * \fn	int CardControllerExplore::drawACard()
	 *
	 * \brief	从卡池中抽取一张卡到手牌中
	 *
	 * \return	返回抽到的卡的id，失败返回 CardBase::invalidID
	 */
	int drawACard();

	/*!
	 * \fn	int CardControllerExplore::playCardByID(int id)
	 *
	 * \brief	从手牌中移除给定id的卡到回收站（出牌）
	 *
	 * \param	id	指定待移除的卡的id
	 *
	 * \return	返回被移除的卡的id
	 */
	int playCardByID(int id)
	{
		cocos2d::log("[information] 正在从探索场景的手牌中使用一张id为%d的卡...", id);
		// 从手牌中移除一张卡
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] 成功从探索场景的手牌中使用一张id为%d卡", id);
		else
			cocos2d::log("[warning] 从探索场景的手牌中使用一张id为%d卡失败", id);
		// 将卡加入到弃牌区
		recycleCard->addCardByID(result);
		return result;
	}

	/*!
	 * \fn	int CardControllerExplore::playCardByIndex(int index)
	 *
	 * \brief	从手牌中移除给定索引的卡到回收站（出牌）
	 *
	 * \param	index	指定待移除的卡的id
	 *
	 * \return	返回被移除的卡牌的id
	 */
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] 正在从探索场景的手牌中使用一张索引为%d的卡...", index);
		// 从手牌中移除一张卡
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] 成功从探索场景的手牌中使用一张索引为%d,id为%d的卡", index, id);
		else
			cocos2d::log("[warning] 从探索场景的手牌中使用一张索引为%d卡失败", index);
		// 将该卡放入回收站
		recycleCard->addCardByID(id);
		return id;
	}

	/*!
	 * \fn	void CardControllerExplore::shuffle()
	 *
	 * \brief	洗牌
	 *
	 */
	void shuffle();

	/*!
	 * \fn	void CardControllerExplore::clear()
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
	 * \fn	const std::map<int, int>& CardControllerExplore::getCardPool()const
	 *
	 * \brief	获取卡池中的所有卡牌的id
	 *
	 * \return	返回卡池中的所有卡牌的id
	 */
	const std::map<int, int>& getCardPool()const
	{
		return cardPool->getCardSet();
	}

	/*!
	 * \fn	const std::map<int, int>& CardControllerExplore::getHandCard()const
	 *
	 * \brief	获取手牌中所有卡牌的id
	 *
	 * \return	返回手牌中所有卡牌的id
	 */
	const std::map<int, int>& getHandCard()const
	{
		return handCard->getCardSet();
	}

	/*!
	 * \fn	const std::map<int, int>& CardControllerExplore::getRecycleCard()const
	 *
	 * \brief	获取回收站中的所有卡牌的id
	 *
	 * \return	返回回收站中的所有卡牌的id
	 */
	const std::map<int, int>& getRecycleCard()const
	{
		return recycleCard->getCardSet();
	}
};

#endif
