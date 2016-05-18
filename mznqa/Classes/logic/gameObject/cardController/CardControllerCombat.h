/*!
* \file	Classes\logic\gameObject\cardController\CardControllerCombat.h
*
* \brief	定义类 CardControllerCombat
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
* \brief	战斗场景下的卡牌控制器
*
*/
class CardControllerCombat
{
private:
	/*! \brief	内建卡池 */
	CardBox<CardSkill> pool;
	/*! \brief	内建回收站 */
	CardBox<CardSkill> recycleBin;
	/*! \brief	内建手牌容器 */
	CardArray<CardSkill, EXPLORE_CARDHOLDERSIZE> holder;
public:

	/*!
	* \fn	CardControllerCombat::CardControllerCombat();
	*
	* \brief	构造函数
	*
	*/
	CardControllerCombat();

	/*!
	* \fn	CardControllerCombat::CardControllerCombat(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	*
	* \brief	构造函数
	*
	* \param	poolCardIDSet	   	指定卡池中的卡牌ID集合
	* \param	recycleBinCardIDSet	指定弃牌区的卡牌ID集合
	* \param	holderCardIDSet	   	指定手牌区的卡牌ID集合
	*/
	CardControllerCombat(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	* \fn	CardControllerCombat::CardControllerCombat(const CardControllerCombat &cardControllerCombat);
	*
	* \brief	拷贝构造函数
	*
	*/
	CardControllerCombat(const CardControllerCombat &cardControllerCombat);

	/*!
	* \fn	CardControllerCombat& CardControllerCombat::operator=(const CardControllerCombat &cardControllerCombat);
	*
	* \brief	拷贝赋值运算符
	*
	*/
	CardControllerCombat& operator=(const CardControllerCombat &cardControllerCombat);

	/*!
	* \fn	CardControllerCombat::~CardControllerCombat();
	*
	* \brief	析构函数
	*
	*/
	~CardControllerCombat();

	/*!
	* \fn	void CardControllerCombat::reset();
	*
	* \brief	重置卡牌控制器，所有卡牌将被集中在卡池中
	*
	*/
	void reset();

	/*!
	* \fn	void CardControllerCombat::reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);
	*
	* \brief	根据给定的卡牌ID集合重置卡牌控制器
	*
	* \param	poolCardIDSet	   	指定卡池区的卡牌ID集合
	* \param	recycleBinCardIDSet	指定弃牌区的卡牌ID集合
	* \param	holderCardIDSet	   	指定手牌区的卡牌ID集合
	*/
	void reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet);

	/*!
	* \fn	void CardControllerCombat::addCardToPool(int cardID);
	*
	* \brief	向卡池中添加卡牌
	*
	* \param	cardID	指定待添加的卡牌ID
	*/
	void addCardToPool(int cardID);

	/*!
	* \fn	int CardControllerCombat::drawCard();
	*
	* \brief	从卡池中随机抽出一张卡牌到手牌区
	*
	* \return	返回抽到的卡牌的ID
	*/
	int drawCard();

	/*!
	* \fn	int CardControllerCombat::discard(int index);
	*
	* \brief	从手牌中丢弃指定索引位置上的卡牌到弃牌区
	*
	* \param	index	指定待丢弃的卡牌的索引
	*
	* \return	返回被丢弃的卡牌的ID
	*/
	int discard(int index);

	/*!
	* \fn	void CardControllerCombat::shuffle();
	*
	* \brief	洗牌，将当前弃牌区的所有卡牌移到手牌区
	*
	*/
	void shuffle();

	/*!
	* \fn	void CardControllerCombat::clear();
	*
	* \brief	清空手牌控制器
	*
	*/
	void clear();

	/*!
	* \fn	bool CardControllerCombat::isEmptyPool()const;
	*
	* \brief	判断卡池是否为空
	*
	*/
	bool isEmptyPool()const;

	/*!
	* \fn	bool CardControllerCombat::isEmptyRecycleBin()const;
	*
	* \brief	判断弃牌区是否为空
	*
	*/
	bool isEmptyRecycleBin()const;

	/*!
	* \fn	bool CardControllerCombat::isEmptyHolder()const;
	*
	* \brief	判断手牌区是否为空
	*
	*/
	bool isEmptyHolder()const;

	/*!
	* \fn	bool CardControllerCombat::isFullHolder()const;
	*
	* \brief	判断手牌区是否已满
	*
	*/
	bool isFullHolder()const;

	/*!
	* \fn	const std::list<int>& CardControllerCombat::getPoolCardIDSet()const;
	*
	* \brief	获取卡池中的所有卡牌的ID
	*
	*/
	const std::list<int>& getPoolCardIDSet()const;

	/*!
	* \fn	const std::list<int>& CardControllerCombat::getRecycleBinCardIDSet()const;
	*
	* \brief	获取弃牌区中的所有卡牌的ID
	*
	*/
	const std::list<int>& getRecycleBinCardIDSet()const;

	/*!
	* \fn	const std::array<int, EXPLORE_CARDHOLDERSIZE>& CardControllerCombat::getHolderCardIDSet()const;
	*
	* \brief	获取手牌中所有卡牌的ID
	*
	*/
	const std::array<int, EXPLORE_CARDHOLDERSIZE>& getHolderCardIDSet()const;
};

#endif
