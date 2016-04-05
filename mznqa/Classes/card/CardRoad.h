/*!
 * \file	Classes\card\CardRoad.h
 *
 * \brief	������ CardRoad
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDROAD_H_
#define MZNQA_CLASSES_CARD_CARDROAD_H_

#include "card/CardBase.h"

/*!
 * \class	CardRoad
 *
 * \brief	���ο�
 *
 */
class CardRoad : public CardBase
{
public:
	/*! \brief	������ */
	static const  CardBase::CardType CARDTYPE = CardBase::CardType_Road;

	/*!
	 * \enum	RoadType
	 *
	 * \brief	ö�ٵ�·����
	 */
	enum RoadType
	{
		RoadType_None = 0,		///< �޵�·
		RoadType_URDL = 1234,	///< �ķ����·
		RoadType_RDL = 234,		///< �������·
		RoadType_UDL = 134,		///< �������·
		RoadType_URL = 124,		///< �������·
		RoadType_URD = 123,		///< �������·
		RoadType_DL = 34,		///< ˫�����·
		RoadType_UL = 14,		///< ˫�����·
		RoadType_UR = 12,		///< ˫�����·
		RoadType_RL = 24,		///< ˫�����·
		RoadType_UD = 13,		///< ˫�����·
		RoadType_RD = 23,		///< ˫�����·
		RoadType_U = 1,			///< �������·
		RoadType_R = 2,			///< �������·
		RoadType_D = 3,			///< �������·
		RoadType_L = 4			///< �������·
	};

	/*!
	 * \fn	CardRoad::CardRoad( int id, const std::string &name, const std::string describe, CardBase::BelongTo belongTo, RoadType roadType )
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 * \param	id			����id
	 * \param	name		��������
	 * \param	describe	��������
	 * \param	belongTo	��������
	 * \param	roadType	��·����
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
	 * \brief	��������
	 *
	 */
	~CardRoad()
	{
	}

private:
	/*! \brief	��·���� */
	RoadType roadType;
};

#endif
