/*!
 * \file	Classes\staticData\CardSet.h
 *
 * \brief	������ CardSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_STATICDATA_CARDSET_H_
#define MZNQA_CLASSES_STATICDATA_CARDSET_H_

#include <map>

#include "cocos2d.h"

#include "card/CardRoad.h"
#include "card/CardTreasure.h"
#include "card/CardMonster.h"
#include "card/CardSkill.h"

/*!
 * \class	CardSet
 *
 * \brief	�������������п��Ƶļ���
 *
 */
class CardSet
{
private:

	/*!
	 * \fn	CardSet::CardSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CardSet(){}

	/*!
	 * \fn	CardSet::CardSet(const CardSet &cardSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	cardSet	CardSet ʵ��
	 */
	CardSet(const CardSet &cardSet);

	/*!
	 * \fn	CardSet& CardSet::operator=(const CardSet &cardSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	cardSet	CardSet ʵ��
	 *
	 * \return	CardSet ʵ��
	 */
	CardSet& operator=(const CardSet &cardSet);

	/*! \brief	���ο��Ӽ� */
	std::map<int, CardRoad> cardRoadSet;
	/*! \brief	���￨�Ӽ� */
	std::map<int, CardTreasure> cardTreasureSet;
	/*! \brief	���￨�Ӽ� */
	std::map<int, CardMonster> cardMonsterSet;
	/*! \brief	���ܿ��Ӽ� */
	std::map<int, CardSkill> cardSkillSet;

public:

	/*!
	 * \fn	static CardSet* CardSet::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static CardSet* Instance();

	/*!
	 * \fn	CardSet::~CardSet();
	 *
	 * \brief	��������
	 *
	 */
	~CardSet();

	/*!
	 * \fn	void CardSet::loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
	 *
	 * \brief	������ο����ϣ����ڳ�ʼ��
	 *
	 * \param [in,out]	cardRoadSet	���ο�����
	 */
	void loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
	{
		this->cardRoadSet.swap(cardRoadSet);
	}

	/*!
	 * \fn	void CardSet::loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
	 *
	 * \brief	���뱦�￨���ϣ����ڳ�ʼ��
	 *
	 * \param [in,out]	cardTreasureSet	���￨����
	 */
	void loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
	{
		this->cardTreasureSet.swap(cardTreasureSet);
	}

	/*!
	 * \fn	void CardSet::loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
	 *
	 * \brief	������￨���ϣ����ڳ�ʼ��
	 *
	 * \param [in,out]	cardMonsterSet	���￨����
	 */

	void loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
	{
		this->cardMonsterSet.swap(cardMonsterSet);
	}

	/*!
	 * \fn	void CardSet::loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
	 *
	 * \brief	���뼼�ܿ����ϣ����ڳ�ʼ��
	 *
	 * \param [in,out]	cardSkillSet	���ܿ�����
	 */
	void loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
	{
		this->cardSkillSet.swap(cardSkillSet);
	}

	/*!
	 * \fn	const CardRoad* CardSet::getCardRoadByID(int id)
	 *
	 * \brief	���ݸ��� id ��ȡ���ο�
	 *
	 * \param	id	ָ�����ο� id
	 *
	 * \return	�ɹ�����ָ��Ŀ����ο���ָ�룬ʧ�ܷ��� nullptr
	 */
	const CardRoad* getCardRoadByID(int id)
	{
		auto it = cardRoadSet.find(id);
		if (it == cardRoadSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�ĵ��ο�");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}

	/*!
	 * \fn	const CardTreasure* CardSet::getCardTreasureByID(int id)
	 *
	 * \brief	���ݸ��� id ��ȡ���￨
	 *
	 * \param	id	ָ�����￨ id
	 *
	 * \return	�ɹ�����ָ��Ŀ�걦�￨��ָ�룬ʧ�ܷ��� nullptr
	 */
	const CardTreasure* getCardTreasureByID(int id)
	{
		auto it = cardTreasureSet.find(id);
		if (it == cardTreasureSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�ı��￨");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}

	/*!
	 * \fn	const CardMonster* CardSet::getCardMonsterByID(int id)
	 *
	 * \brief	���ݸ��� id ��ȡ���￨
	 *
	 * \param	id	ָ�����￨ id
	 *
	 * \return	�ɹ�����ָ��Ŀ����￨��ָ�룬ʧ�ܷ��� nullptr
	 */
	const CardMonster* getCardMonsterByID(int id)
	{
		auto it = cardMonsterSet.find(id);
		if (it == cardMonsterSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�Ĺ��￨");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}

	/*!
	 * \fn	const CardSkill* CardSet::getCardSkillByID(int id)
	 *
	 * \brief	���ݸ��� id ��ȡ���ܿ�
	 *
	 * \param	id	ָ�����ܿ� id
	 *
	 * \return	�ɹ�����ָ��Ŀ�꼼�ܿ���ָ�룬ʧ�ܷ��� nullptr
	 */
	const CardSkill* getCardSkillByID(int id)
	{
		auto it = cardSkillSet.find(id);
		if (it == cardSkillSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�ļ��ܿ�");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}

	void test();
};

#endif
