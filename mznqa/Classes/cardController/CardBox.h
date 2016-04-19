/*!
 * \file	Classes\cardController\CardBox.h
 *
 * \brief	定义类 CardBox
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
 * \brief	保存单一卡牌类型的卡牌容器
 *
 * \tparam	CardType	卡牌类型
 */
template <typename CardType>
class CardBox
{
private:
	/*! \brief	卡牌集合（仅为卡牌的id集合） */
	std::list<int> cardSet;

	/*! \brief	标识卡牌容器的大小，当其值为 invalidSizeValue 时卡牌容量无限定 */
	int size;

	/*! \brief	标志无效的容器大小值 */
	static const int invalidSizeValue = -1;
public:

	/*!
	 * \fn	CardBox::CardBox()
	 *
	 * \brief	默认构造函数，构造一个任意容量的卡牌容器
	 *
	 */
	CardBox() :
		size(invalidSizeValue)
	{}

	/*!
	 * \fn	CardBox::CardBox(int size)
	 *
	 * \brief	构造函数，构造一个指定大小的卡牌容器
	 *
	 * \param	size	指定的卡牌容器大小，应为一个大于零的整数，当给定的值不合法时将构造一个任意容量的卡牌容器
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
	 * \brief	析构函数
	 *
	 */
	~CardBox()
	{}

	/*!
	 * \fn	int CardBox::getCardCount()const
	 *
	 * \brief	获取当前卡牌张数
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
	 * \brief	给定一个卡牌实例以添加
	 *
	 * \param	card	卡牌实例
	 *
	 * \return	成功返回卡牌id，失败返回 CardBase::invlidID
	 */
	int addCardByCard(const CardType& card)
	{
		// 如果容器容量不足
		if (size != invalidSizeValue && (int)cardSet.size() >= size)
			return CardBase::invalidID;

		// 注意：不在此做卡牌合法性判定，而直接添加
		cardSet.push_back(card.getID());

		return card.getID();
	}

	/*!
	 * \fn	int CardBox::addCardByID(int id)
	 *
	 * \brief	给定一个卡牌id以添加，id指向的卡牌必须有效并在卡牌库（CardSet）中已经添加
	 *
	 * \param	id	The identifier.
	 *
	 * \return	添加成功将返回参数给定的id，失败将返回 CardBase::invalidID
	 */
	int addCardByID(int id)
	{
		// 判断容器容量不足
		if (size != invalidSizeValue && (int)cardSet.size() >= size)
			return CardBase::invalidID;

		// 如果是地形卡，而且在卡牌库中存在
		if (
			CardType::CARDTYPE == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// 如果是宝物卡，而且在卡牌库中存在
		else if (
			CardType::CARDTYPE == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// 如果是怪物卡，而且在卡牌库中存在
		else if (
			CardType::CARDTYPE == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// 如果是技能卡，而且在卡牌库中存在
		else if (
			CardType::CARDTYPE == CardBase::CardType_Skill &&
			CardSet::Instance()->getCardSkillByID(id) != nullptr
			)
		{
			cardSet.push_back(id);
			return id;
		}
		// 无效卡或未在卡牌库中的卡
		else
		{
			cocos2d::log("[warning] 向 CardBox 添加卡牌失败，给定的id=%d有误，或尚未加入到卡牌库，请检查", id);
			return CardBase::invalidID;
		}
	}

	/*!
	 * \fn	int CardBox::removeCardByID(int id)
	 *
	 * \brief	根据给定id移除容器内一张的卡牌（线性时间）
	 *
	 * \param	id 指定待移除卡的id
	 *
	 * \return	成功返回该id，失败返回 CardBase::invalidID
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
	 * \brief	根据索引移除指定卡牌
	 *
	 * \param	index	指定待删除的卡牌索引
	 *
	 * \return	成功返回被删除卡牌的id，失败返回 CardBase::invalidID
	 */
	int removeCardByIndex(int index)
	{
		// 获取当前卡牌数
		int sTemp = cardSet.size();
		// 如果索引越界
		if (!(0 <= index && index < sTemp))
			return CardBase::invalidID;

		// 否则...
		// 遍历容器找到指定卡牌并删除
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
	 * \brief	随机移除一张卡牌
	 *
	 * \return	成功将返回被删除的卡牌的id，失败则返回 CardBase::invalidID
	 */
	int removeCardByRandom()
	{
		if (cardSet.size() <= 0)
			return CardBase::invalidID;

		// TODO 暂放
		srand(unsigned(time(NULL)));

		int index = rand() % (cardSet.size());

		return removeCardByIndex(index);
	}

	/*!
	 * \fn	void CardBox::clear()
	 *
	 * \brief	清空容器
	 */
	void clear()
	{
		cardSet.clear();
	}

	/*!
	 * \fn	bool CardBox::isFull()
	 *
	 * \brief	判断容器是否已满
	 *
	 * \return	返回容器是否已满，注意当容器被构造的时候未指定大小的话这里将永远返回 false
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
	 * \brief	获取一个容器内的所有卡牌的id集合
	 *
	 * \return	获取一个 const std::list&，其包含容器类的所有卡牌的id集合
	 */
	const std::list<int>& getCardSet()const
	{
		return cardSet;
	}
};

#endif