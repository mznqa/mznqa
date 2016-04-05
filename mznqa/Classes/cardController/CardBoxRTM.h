/*!
 * \file	Classes\cardController\CardBoxRTM.h
 *
 * \brief	定义类 CardBoxRTM
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
 * \brief	可同时包含地形卡、宝物卡和怪物卡的卡牌容器
 *
 */
class CardBoxRTM
{
private:
	/*! \brief	子容器，用于存放地形牌 */
	CardBox<CardRoad> cardBoxRoad;
	/*! \brief	子容器，用于存放宝物卡 */
	CardBox<CardTreasure> cardBoxTreasure;
	/*! \brief	子容器，用于存放怪物卡 */
	CardBox<CardMonster> cardBoxMonster;

	/*! \brief	总容器的卡牌索引表，索引三个自容器的卡牌id */
	std::map<int, int> index2ID;

	/*! \brief	容器大小 */
	int size;

	/*! \brief	标志无效的容器大小值 */
	static const int invalidSizeValue = -1;

	/*!
	 * \fn	int CardBoxRTM::insertIndexByID(int id)
	 *
	 * \brief	根据给定id向容器中添加索引
	 *
	 * \param	id 指定id
	 *
	 * \return	成功返回索引，失败返回-1
	 */
	int insertIndexByID(int id)
	{
		// 如果给定的id不合法
		if (id == CardBase::invalidID)
			return -1;

		// 插入索引
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, id));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));

		return index2ID.rbegin()->first;
	}

	/*!
	 * \fn	void CardBoxRTM::removeIndexByID(int id)
	 *
	 * \brief	根据给定id移除总容器的对应索引（注意移除的总是索引对应的id与给定的id相同的情况下，索引小的值）
	 *
	 * \param	id	指定id
	 * \return	成功返回索引，失败返回-1
	 */
	int removeIndexByID(int id);
public:

	/*!
	 * \fn	CardBoxRTM::CardBoxRTM()
	 *
	 * \brief	默认构造函数，将构造一个不限大小的用于同时存放地形卡、宝物卡和怪物卡的容器
	 */
	CardBoxRTM() :
		size(invalidSizeValue)
	{}

	/*!
	 * \fn	CardBoxRTM::CardBoxRTM(int size)
	 *
	 * \brief	构造指定大小的，用于同时存放地形卡、宝物卡和怪物卡的容器
	 *
	 * \param	size	指定待创建的容器的大小，值应大于0否则将构造一个不限大小的容器
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
	 * \brief	析构函数
	 *
	 */
	~CardBoxRTM()
	{}

	/*!
	 * \fn	int CardBoxRTM::getCardCount()const
	 *
	 * \brief	获取当前的卡牌数
	 *
	 * \return	返回当前的卡牌数
	 */
	int getCardCount()const
	{
		return cardBoxRoad.getCardCount() + cardBoxTreasure.getCardCount() + cardBoxMonster.getCardCount();
	}

	/*!
	 * \fn	int CardBoxRTM::getCardRoadCount()const
	 *
	 * \brief	获取容器中地形卡的卡牌数
	 *
	 * \return	返回容器中地形卡的卡牌数
	 */
	int getCardRoadCount()const
	{
		return cardBoxRoad.getCardCount();
	}

	/*!
	 * \fn	int CardBoxRTM::getCardTreasureCount()const
	 *
	 * \brief	获取容器中宝物卡的卡牌数
	 *
	 * \return	返回容器中宝物卡的卡牌数
	 */
	int getCardTreasureCount()const
	{
		return cardBoxTreasure.getCardCount();
	}

	/*!
	 * \fn	int CardBoxRTM::getCardMonsterCount()const
	 *
	 * \brief	获取容器中怪物卡的卡牌数
	 *
	 * \return	返回容器中怪物卡的卡牌数
	 */
	int getCardMonsterCount()const
	{
		return cardBoxMonster.getCardCount();
	}

	/*!
	 * \fn	void CardBoxRTM::addCardByCard(const CardRoad& card)
	 *
	 * \brief	给定一个地形卡实例以添加
	 *
	 * \param	card	指定地形卡实例
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */
	int addCardByCard(const CardRoad& card);

	/*!
	 * \fn	int CardBoxRTM::addCardByCard(const CardTreasure& card)
	 *
	 * \brief	给定一个宝物卡实例以添加
	 *
	 * \param	card	指定宝物卡实例
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */

	int addCardByCard(const CardTreasure& card);

	/*!
	 * \fn	int CardBoxRTM::addCardByCard(const CardMonster& card)
	 *
	 * \brief	给定一个怪物卡实例以添加
	 *
	 * \param	card	指定怪物卡实例
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */
	int addCardByCard(const CardMonster& card);

	/*!
	 * \fn	int CardBoxRTM::addCardByID(int id)
	 *
	 * \brief	给定卡牌id以添加
	 *
	 * \param	id	指定id
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */
	int addCardByID(int id);

	/*!
	 * \fn	int CardBoxRTM::removeCardByID(int id)
	 *
	 * \brief	更具给定id移除容器中的卡牌，（注意移除的总是索引对应的id与给定的id相同的情况下，索引小的值，线性时间）
	 *
	 * \param	id 指定待移除的卡的id
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */
	int removeCardByID(int id);

	/*!
	 * \fn	int CardBoxRTM::removeCardByIndex(int index)
	 *
	 * \brief	根据给定的索引删除卡牌（线性时间）
	 *
	 * \param	index	给定索引
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */
	int removeCardByIndex(int index);

	/*!
	 * \fn	int CardBoxRTM::removeCardByRandom()
	 *
	 * \brief	随机地从容器中移除一张卡
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
	 */
	int removeCardByRandom()
	{
		if (index2ID.size() <= 0)
			return CardBase::invalidID;

		// TODO 暂放
		srand(unsigned(time(NULL)));

		int index = rand() % (index2ID.size());

		return removeCardByIndex(index);
	}

	/*!
	 * \fn	int CardBoxRTM::removeCardRoadByRandom()
	 *
	 * \brief	随机地从容器中移除一张地形卡
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
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
	 * \brief	随机地从容器中移除一张宝物卡
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
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
	 * \brief	随机从容器中移除一张怪物卡
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invalidID
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
	 * \brief	清空容器
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
	 * \brief	判断容器是否已满
	 *
	 * \return	返回容器是否已满，当构造容器时未指定容器大小将永远返回false
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
	 * \brief	获取容器中所有卡牌的id
	 *
	 * \return	返回容器中所有卡牌的id
	 */
	const std::map<int, int>& getCardSet()const
	{
		return index2ID;
	}
};

#endif
