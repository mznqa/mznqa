/*!
 * \file	Classes\logic\gameObject\card\CardBase.h
 *
 * \brief	������ CardBase
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDBASE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDBASE_H_

#include <string>

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
	 * \fn	virtual CardBase::~CardBase();
	 *
	 * \brief	����������
	 *
	 */
	virtual ~CardBase()
	{
	}

	/*! \brief	��Ч�Ŀ���ID */
	static const int invalidCardID = -1;

	/*!
	* \enum	BelongTo
	*
	* \brief	ö�ٿ��Ƶ�������
	*/
	enum BelongTo
	{
		BelongTo_None = 0,		///< �������κ�һ��
		BelongTo_Character = 1,	///< �����ڽ�ɫ
		BelongTo_Monster = 2,	///< �����ڹ���
		BelongTo_Both = 3		///< �����ڽ�ɫ�����ڹ���
	};

	/*!
	 * \enum	CardType
	 *
	 * \brief	ö�ٿ��Ƶ�����
	 */
	enum CardType
	{
		CardType_Road = 0,		///< ��·��
		CardType_Treasure = 1,	///< ���￨
		CardType_Monster = 2,	///< ���￨
		CardType_Skill = 3		///< ���ܿ�
	};

	/*!
	 * \fn	CardBase::CardBase(int id, int sidName, int sidDescribe, BelongTo belongTo)
	 *
	 * \brief	���캯��
	 *
	 * \param	id		   	ָ�����Ƶ�ID
	 * \param	sidName	   	ָ�����Ƶ�����ID
	 * \param	sidDescribe	ָ�����Ƶ�����ID
	 * \param	belongTo   	ָ�����Ƶ�������
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
	 * \brief	�������캯��
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
	 * \brief	������ֵ�����
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
	 * \brief	��ȡ���Ƶ�ID
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
	 * \brief	��ȡ���Ƶ�����
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
	 * \brief	��ȡ���Ƶ�����
	 *
	 */
	virtual const std::string *const getDescribe()const;

	/*!
	 * \fn	virtual BelongTo CardBase::getBelongTo()const
	 *
	 * \brief	��ȡ���Ƶ�������
	 *
	 */
	virtual BelongTo getBelongTo()const
	{
		return belongTo;
	}

	/*!
	 * \fn	virtual CardType CardBase::getCardType()const = 0;
	 *
	 * \brief	��ȡ��������
	 *
	 */
	virtual CardType getCardType()const = 0;

private:

	/*! \brief	���Ƶ�ID */
	int id;
	/*! \brief	��������SID */
	int sidName;
	/*! \brief	��������SID */
	int sidDescribe;
	/*! \brief	���������� */
	BelongTo belongTo;
};

#endif