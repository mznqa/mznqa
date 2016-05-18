/*!
 * \file	Classes\logic\gameObject\cardController\CardControllerExplore.h
 *
 * \brief	定义类 CardControllerExplore
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
 * \brief	探索场景下的卡牌控制器
 *
 */
class CardControllerExplore
{
private:
	/*! \brief	内建卡池 */
	CardBox3<CardRoad, CardTreasure, CardMonster> pool;
	/*! \brief	内建回收站 */
	CardBox3<CardRoad, CardTreasure, CardMonster> recycleBin;
	/*! \brief	内建手牌容器 */
	CardArray3<CardRoad, CardTreasure, CardMonster, EXPLORE_CARDHOLDERSIZE> holder;
public:

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore();
	 *
	 * \brief	构造函数
	 *
	 */
	CardControllerExplore();

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	 *
	 * \brief	构造函数
	 *
	 * \param	poolCardIDSet	   	指定卡池中的卡牌ID集合
	 * \param	recycleBinCardIDSet	指定弃牌区的卡牌ID集合
	 * \param	holderCardIDSet	   	指定手牌区的卡牌ID集合
	 */
	CardControllerExplore(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	 * \fn	CardControllerExplore::CardControllerExplore(const CardControllerExplore &cardControllerExplore);
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardControllerExplore(const CardControllerExplore &cardControllerExplore);

	/*!
	 * \fn	CardControllerExplore& CardControllerExplore::operator=(const CardControllerExplore &cardControllerExplore);
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardControllerExplore& operator=(const CardControllerExplore &cardControllerExplore);

	/*!
	 * \fn	CardControllerExplore::~CardControllerExplore();
	 *
	 * \brief	析构函数
	 *
	 */
	~CardControllerExplore();

	/*!
	 * \fn	void CardControllerExplore::reset();
	 *
	 * \brief	重置卡牌控制器，所有卡牌将被集中在卡池中
	 *
	 */
	void reset();

	/*!
	 * \fn	void CardControllerExplore::reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	 *
	 * \brief	根据给定的卡牌ID集合重置卡牌控制器
	 *
	 * \param	poolCardIDSet	   	指定卡池区的卡牌ID集合
	 * \param	recycleBinCardIDSet	指定弃牌区的卡牌ID集合
	 * \param	holderCardIDSet	   	指定手牌区的卡牌ID集合
	 */
	void reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	 * \fn	void CardControllerExplore::addCardToPool(int cardID);
	 *
	 * \brief	向卡池中添加卡牌
	 *
	 * \param	cardID	指定待添加的卡牌ID
	 */
	void addCardToPool(int cardID);

	/*!
	 * \fn	int CardControllerExplore::drawCard();
	 *
	 * \brief	从卡池中随机抽出一张卡牌到手牌区
	 *
	 * \return	返回抽到的卡牌的ID
	 */
	int drawCard();

	/*!
	 * \fn	int CardControllerExplore::discard(int index);
	 *
	 * \brief	从手牌中丢弃指定索引位置上的卡牌到弃牌区
	 *
	 * \param	index	指定待丢弃的卡牌的索引
	 *
	 * \return	返回被丢弃的卡牌的ID
	 */
	int discard(int index);

	/*!
	 * \fn	void CardControllerExplore::shuffle();
	 *
	 * \brief	洗牌，将当前弃牌区的所有卡牌移到手牌区
	 *
	 */
	void shuffle();

	/*!
	 * \fn	void CardControllerExplore::clear();
	 *
	 * \brief	清空手牌控制器
	 *
	 */
	void clear();

	/*!
	 * \fn	bool CardControllerExplore::isEmptyPool()const;
	 *
	 * \brief	判断卡池是否为空
	 *
	 */
	bool isEmptyPool()const;

	/*!
	 * \fn	bool CardControllerExplore::isEmptyRecycleBin()const;
	 *
	 * \brief	判断弃牌区是否为空
	 *
	 */
	bool isEmptyRecycleBin()const;

	/*!
	 * \fn	bool CardControllerExplore::isEmptyHolder()const;
	 *
	 * \brief	判断手牌区是否为空
	 *
	 */
	bool isEmptyHolder()const;

	/*!
	 * \fn	bool CardControllerExplore::isFullHolder()const;
	 *
	 * \brief	判断手牌区是否已满
	 *
	 */
	bool isFullHolder()const;

	/*!
	 * \fn	const std::list<int>& CardControllerExplore::getPoolCardIDSet()const;
	 *
	 * \brief	获取卡池中的所有卡牌的ID
	 *
	 */
	const std::list<int>& getPoolCardIDSet()const;

	/*!
	 * \fn	const std::list<int>& CardControllerExplore::getRecycleBinCardIDSet()const;
	 *
	 * \brief	获取弃牌区中的所有卡牌的ID
	 *
	 */
	const std::list<int>& getRecycleBinCardIDSet()const;

	/*!
	 * \fn	const std::array<int, EXPLORE_CARDHOLDERSIZE>& CardControllerExplore::getHolderCardIDSet()const;
	 *
	 * \brief	获取手牌中所有卡牌的ID
	 *
	 */
	const std::array<int, EXPLORE_CARDHOLDERSIZE>& getHolderCardIDSet()const;
};

#endif
