/*!
 * \file	Classes\card\CardBase.h
 *
 * \brief	定义类 CardBox
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDBASE_H_
#define MZNQA_CLASSES_CARD_CARDBASE_H_

#include <string>

#include "cocos2d.h"

/*!
 * \class	CardBase
 *
 * \brief	所有卡牌的基类
 *
 */
class CardBase
{
public:
	/*!
	 * 用以区分卡的类型\n
	 * idBaseNum*0 ~ idBaseNum*1-1 ==> CardRoad\n
	 * idBaseNum*1 ~ idBaseNum*2-1 ==> CardTreasure\n
	 * idBaseNum*2 ~ idBaseNum*3-1 ==> CardMonster\n
	 * idBaseNum*3 ~ idBaseNum*4-1 ==> CardSkill
	 */
	static const int idBaseNum = 10000;
public:
	/*! \brief	标识无效id值，当id为该值时，卡牌无效*/
	static const int invalidID = -1;

	/*!
	 * \enum	CardType
	 *
	 * \brief	枚举卡牌类型
	 */
	enum CardType
	{
		CardType_Invalid = -1,				///< 标识无效卡牌
		CardType_Road = idBaseNum * 0,		///< 地形卡
		CardType_Treasure = idBaseNum * 1,	///< 宝物卡
		CardType_Monster = idBaseNum * 2,	///< 怪物卡
		CardType_Skill = idBaseNum * 3		///< 技能卡
	};

	/*!
	 * \enum	BelongTo
	 *
	 * \brief	枚举卡牌所属对象
	 */
	enum BelongTo
	{
		BelongTo_MonsterOnly = -1,		///< 标识该卡牌仅仅属于怪物
		BelongTo_RoleMonsterBoth = 0,	///< 标识该卡牌属于角色也属于怪物
		BelongTo_RoleOnly = 1			///< 标识该卡牌仅仅属于角色
	};

	/*!
	 * \fn	static CardType CardBase::judgeCardTypeByID(int id)
	 *
	 * \brief	根据给定id判断卡牌类型
	 *
	 * \param	id	指定id值，非负数
	 *
	 * \return	卡牌类型枚举
	 */
	static CardType judgeCardTypeByID(int id)
	{
		// 此处id越界判定与 idBaseNum 和 CardType 相关

		// 如果下越界
		if (id <= -1)
			return CardType_Invalid;
		// 如果上越界
		else if (id >= idBaseNum * 4)
			return CardType_Invalid;
		// 如果未越界
		else
			return CardType(id / idBaseNum * idBaseNum);
	}

	/*!
	 * \fn	static bool CardBase::checkCardType(CardType cardType)
	 *
	 * \brief	判断卡牌类型是否合法
	 *
	 * \param	cardType	给定卡牌类型
	 *
	 */
	static bool checkCardType(CardType cardType)
	{
		// 此处卡牌类型判定与 idBaseNum 和 CardType 相关

		if (
			cardType == CardType_Road ||
			cardType == CardType_Treasure ||
			cardType == CardType_Monster ||
			cardType == CardType_Skill
			)
			return true;
		else
			return false;
	}

	/*!
	 * \fn	CardBase::CardBase( int id, CardType type, const std::string &name, const std::string &describe, BelongTo belongTo )
	 *
	 * \brief	给定构造一张卡牌的基本信息以构建一张卡，一般被用于派生类中
	 *
	 * \param	id			指定卡牌的id
	 * \param	type		指定卡牌的类型
	 * \param	name		指定卡牌的名称
	 * \param	describe	指定卡牌的描述
	 * \param	belongTo	指定卡牌所属方
	 */
	CardBase(
		int id,
		CardType type,
		const std::string &name,
		const std::string &describe,
		BelongTo belongTo
		);

	/*!
	 * \fn	virtual CardBase::~CardBase()
	 *
	 * \brief	析构函数
	 *
	 */

	virtual ~CardBase()
	{
	}

	/*!
	 * \fn	virtual int CardBase::getID() const
	 *
	 * \brief	获取卡牌id
	 *
	 * \return	卡牌id
	 */
	virtual int getID() const
	{
		return id;
	}

	/*!
	 * \fn	virtual CardType CardBase::getType() const
	 *
	 * \brief	获取卡牌类型
	 *
	 * \return	卡牌类型
	 */
	virtual CardType getType() const
	{
		return type;
	}

	/*!
	 * \fn	virtual const std::string& CardBase::getName() const
	 *
	 * \brief	获取卡牌名称
	 *
	 * \return	卡牌名称的const引用
	 */
	virtual const std::string& getName() const
	{
		return name;
	}

	/*!
	 * \fn	virtual const std::string& CardBase::getDescribe() const
	 *
	 * \brief	获取卡牌描述
	 *
	 * \return	卡牌描述的const引用
	 */
	virtual const std::string& getDescribe() const
	{
		return describe;
	}

	/*!
	 * \fn	virtual const BelongTo CardBase::getBelongTo() const
	 *
	 * \brief	获取卡牌的所属方
	 *
	 * \return	卡牌的所属方
	 */
	virtual const BelongTo getBelongTo() const
	{
		return belongTo;
	}

protected:
	/*! \brief	卡牌id */
	int id;
	/*! \brief	卡牌类型 */
	CardType type;
	/*! \brief	卡牌名称 */
	std::string name;
	/*! \brief	卡牌描述 */
	std::string describe;
	/*! \brief	卡牌所属方 */
	BelongTo belongTo;
};

#endif
