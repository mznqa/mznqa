/*!
 * \file	Classes\logic\gameObject\card\CardBase.h
 *
 * \brief	定义类 CardBase
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDBASE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDBASE_H_

#include <string>

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
	 * \fn	virtual CardBase::~CardBase();
	 *
	 * \brief	虚析构函数
	 *
	 */
	virtual ~CardBase()
	{
	}

	/*! \brief	无效的卡牌ID */
	static const int invalidCardID = -1;

	/*!
	* \enum	BelongTo
	*
	* \brief	枚举卡牌的所属方
	*/
	enum BelongTo
	{
		BelongTo_None = 0,		///< 不属于任何一方
		BelongTo_Character = 1,	///< 仅属于角色
		BelongTo_Monster = 2,	///< 仅属于怪物
		BelongTo_Both = 3		///< 既属于角色又属于怪物
	};

	/*!
	 * \enum	CardType
	 *
	 * \brief	枚举卡牌的类型
	 */
	enum CardType
	{
		CardType_Road = 0,		///< 道路卡
		CardType_Treasure = 1,	///< 宝物卡
		CardType_Monster = 2,	///< 怪物卡
		CardType_Skill = 3		///< 技能卡
	};

	/*!
	 * \fn	CardBase::CardBase(int id, int sidName, int sidDescribe, BelongTo belongTo)
	 *
	 * \brief	构造函数
	 *
	 * \param	id		   	指定卡牌的ID
	 * \param	sidName	   	指定卡牌的名称ID
	 * \param	sidDescribe	指定卡牌的描述ID
	 * \param	belongTo   	指定卡牌的所属方
	 */
	CardBase(int id, int sidName, int sidDescribe, BelongTo belongTo) :
		id(id),
		sidName(sidName),
		sidDescribe(sidDescribe),
		belongTo(belongTo)
	{
	}

	/*!
	 * \fn	CardBase::CardBase(const CardBase &cardBase);
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardBase(const CardBase &cardBase) :
		id(cardBase.id),
		sidName(cardBase.sidName),
		sidDescribe(cardBase.sidDescribe),
		belongTo(cardBase.belongTo)
	{
	}

	/*!
	 * \fn	CardBase& CardBase::operator=(const CardBase &cardBase);
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardBase& operator=(const CardBase &cardBase)
	{
		this->id = cardBase.id;
		this->sidName = cardBase.sidName;
		this->sidDescribe = cardBase.sidDescribe;
		this->belongTo = cardBase.belongTo;
	}

	/*!
	 * \fn	virtual int CardBase::getID()const
	 *
	 * \brief	获取卡牌的ID
	 *
	 */
	virtual int getID()const
	{
		return id;
	}

	virtual const int getSIDName()const
	{
		return sidName;
	}

	/*!
	 * \fn	virtual const std::string *const CardBase::getName()const;
	 *
	 * \brief	获取卡牌的名称
	 *
	 */
	virtual const std::string *const getName()const;

	virtual const int getSIDDescribe()const
	{
		return sidDescribe;
	}

	/*!
	 * \fn	virtual const std::string *const CardBase::getDescribe()const;
	 *
	 * \brief	获取卡牌的描述
	 *
	 */
	virtual const std::string *const getDescribe()const;

	/*!
	 * \fn	virtual BelongTo CardBase::getBelongTo()const
	 *
	 * \brief	获取卡牌的所属方
	 *
	 */
	virtual BelongTo getBelongTo()const
	{
		return belongTo;
	}

	/*!
	 * \fn	virtual CardType CardBase::getCardType()const = 0;
	 *
	 * \brief	获取卡牌类型
	 *
	 */
	virtual CardType getCardType()const = 0;

private:

	/*! \brief	卡牌的ID */
	int id;
	/*! \brief	卡牌名称SID */
	int sidName;
	/*! \brief	卡牌描述SID */
	int sidDescribe;
	/*! \brief	卡牌所属方 */
	BelongTo belongTo;
};

#endif