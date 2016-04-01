/*!
 * \file	Classes\card\CardBase.h
 *
 * \brief	������ CardBox
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDBASE_H_
#define MZNQA_CLASSES_CARD_CARDBASE_H_

#include <string>

#include "cocos2d.h"

/*!
 * \class	CardBase
 *
 * \brief	���п��ƵĻ���
 *
 */
class CardBase
{
public:
	/*!
	 * �������ֿ�������\n
	 * idBaseNum*0 ~ idBaseNum*1-1 ==> CardRoad\n
	 * idBaseNum*1 ~ idBaseNum*2-1 ==> CardTreasure\n
	 * idBaseNum*2 ~ idBaseNum*3-1 ==> CardMonster\n
	 * idBaseNum*3 ~ idBaseNum*4-1 ==> CardSkill
	 */
	static const int idBaseNum = 10000;
public:
	/*! \brief	��ʶ��Чidֵ����idΪ��ֵʱ��������Ч*/
	static const int invalidID = -1;

	/*!
	 * \enum	CardType
	 *
	 * \brief	ö�ٿ�������
	 */
	enum CardType
	{
		CardType_Invalid = -1,				///< ��ʶ��Ч����
		CardType_Road = idBaseNum * 0,		///< ���ο�
		CardType_Treasure = idBaseNum * 1,	///< ���￨
		CardType_Monster = idBaseNum * 2,	///< ���￨
		CardType_Skill = idBaseNum * 3		///< ���ܿ�
	};

	/*!
	 * \enum	BelongTo
	 *
	 * \brief	ö�ٿ�����������
	 */
	enum BelongTo
	{
		BelongTo_MonsterOnly = -1,		///< ��ʶ�ÿ��ƽ������ڹ���
		BelongTo_RoleMonsterBoth = 0,	///< ��ʶ�ÿ������ڽ�ɫҲ���ڹ���
		BelongTo_RoleOnly = 1			///< ��ʶ�ÿ��ƽ������ڽ�ɫ
	};

	/*!
	 * \fn	static CardType CardBase::judgeCardTypeByID(int id)
	 *
	 * \brief	���ݸ���id�жϿ�������
	 *
	 * \param	id	ָ��idֵ���Ǹ���
	 *
	 * \return	��������ö��
	 */
	static CardType judgeCardTypeByID(int id)
	{
		// �˴�idԽ���ж��� idBaseNum �� CardType ���

		// �����Խ��
		if (id <= -1)
			return CardType_Invalid;
		// �����Խ��
		else if (id >= idBaseNum * 4)
			return CardType_Invalid;
		// ���δԽ��
		else
			return CardType(id / idBaseNum * idBaseNum);
	}

	/*!
	 * \fn	static bool CardBase::checkCardType(CardType cardType)
	 *
	 * \brief	�жϿ��������Ƿ�Ϸ�
	 *
	 * \param	cardType	������������
	 *
	 */
	static bool checkCardType(CardType cardType)
	{
		// �˴����������ж��� idBaseNum �� CardType ���

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
	 * \brief	��������һ�ſ��ƵĻ�����Ϣ�Թ���һ�ſ���һ�㱻������������
	 *
	 * \param	id			ָ�����Ƶ�id
	 * \param	type		ָ�����Ƶ�����
	 * \param	name		ָ�����Ƶ�����
	 * \param	describe	ָ�����Ƶ�����
	 * \param	belongTo	ָ������������
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
	 * \brief	��������
	 *
	 */

	virtual ~CardBase()
	{
	}

	/*!
	 * \fn	virtual int CardBase::getID() const
	 *
	 * \brief	��ȡ����id
	 *
	 * \return	����id
	 */
	virtual int getID() const
	{
		return id;
	}

	/*!
	 * \fn	virtual CardType CardBase::getType() const
	 *
	 * \brief	��ȡ��������
	 *
	 * \return	��������
	 */
	virtual CardType getType() const
	{
		return type;
	}

	/*!
	 * \fn	virtual const std::string& CardBase::getName() const
	 *
	 * \brief	��ȡ��������
	 *
	 * \return	�������Ƶ�const����
	 */
	virtual const std::string& getName() const
	{
		return name;
	}

	/*!
	 * \fn	virtual const std::string& CardBase::getDescribe() const
	 *
	 * \brief	��ȡ��������
	 *
	 * \return	����������const����
	 */
	virtual const std::string& getDescribe() const
	{
		return describe;
	}

	/*!
	 * \fn	virtual const BelongTo CardBase::getBelongTo() const
	 *
	 * \brief	��ȡ���Ƶ�������
	 *
	 * \return	���Ƶ�������
	 */
	virtual const BelongTo getBelongTo() const
	{
		return belongTo;
	}

protected:
	/*! \brief	����id */
	int id;
	/*! \brief	�������� */
	CardType type;
	/*! \brief	�������� */
	std::string name;
	/*! \brief	�������� */
	std::string describe;
	/*! \brief	���������� */
	BelongTo belongTo;
};

#endif
