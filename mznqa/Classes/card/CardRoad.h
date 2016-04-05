/*!
 * \file	Classes\card\CardRoad.h
 *
 * \brief	定义类 CardRoad
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDROAD_H_
#define MZNQA_CLASSES_CARD_CARDROAD_H_

#include "card/CardBase.h"

/*!
 * \class	CardRoad
 *
 * \brief	地形卡
 *
 */
class CardRoad : public CardBase
{
public:
	/*! \brief	卡类型 */
	static const  CardBase::CardType CARDTYPE = CardBase::CardType_Road;

	/*!
	 * \enum	RoadType
	 *
	 * \brief	枚举道路类型
	 */
	enum RoadType
	{
		RoadType_None = 0,		///< 无道路
		RoadType_URDL = 1234,	///< 四方向道路
		RoadType_RDL = 234,		///< 三方向道路
		RoadType_UDL = 134,		///< 三方向道路
		RoadType_URL = 124,		///< 三方向道路
		RoadType_URD = 123,		///< 三方向道路
		RoadType_DL = 34,		///< 双方向道路
		RoadType_UL = 14,		///< 双方向道路
		RoadType_UR = 12,		///< 双方向道路
		RoadType_RL = 24,		///< 双方向道路
		RoadType_UD = 13,		///< 双方向道路
		RoadType_RD = 23,		///< 双方向道路
		RoadType_U = 1,			///< 单方向道路
		RoadType_R = 2,			///< 单方向道路
		RoadType_D = 3,			///< 单方向道路
		RoadType_L = 4			///< 单方向道路
	};

	/*!
	 * \fn	CardRoad::CardRoad( int id, const std::string &name, const std::string describe, CardBase::BelongTo belongTo, RoadType roadType )
	 *
	 * \brief	默认构造函数
	 *
	 * \param	id			卡牌id
	 * \param	name		卡牌名称
	 * \param	describe	卡牌描述
	 * \param	belongTo	卡牌所属
	 * \param	roadType	道路类型
	 */
	CardRoad(
		int id,
		const std::string &name,
		const std::string describe,
		CardBase::BelongTo belongTo,
		RoadType roadType
		);

	/*!
	 * \fn	CardRoad::~CardRoad()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardRoad()
	{
	}

private:
	/*! \brief	道路类型 */
	RoadType roadType;
};

#endif
