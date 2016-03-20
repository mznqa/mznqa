#pragma execution_character_set("utf-8")

#include <cstdlib>
#include <ctime>

#include <iterator>

#include "cocos2d.h"

#include "baseClass/CombatCardPool.h"

CombatCardPool::CombatCardPool()
{
}

CombatCardPool::~CombatCardPool()
{
}

void CombatCardPool::AddACard(const Card&card)
{
	if (card.getID() < 0 || card.getCardType() != Card::CardType_Skill)
	{
		cocos2d::log("警告：尝试向战斗场景中的卡池加入一张卡（id=%d, type=%d）失败", card.getID(), card.getCardType());
		return;
	}

	cardSkillSet.push_back(card);
	cocos2d::log("提示：已向战斗场景中的卡池加入一张卡（id=%d, type=%d）", card.getID(), card.getCardType());
}

Card CombatCardPool::DrawACard()
{
	if (getCardCount() <= 0)
	{
		cocos2d::log("警告：尝试在战斗场景中抽卡失败，当前卡池还剩%d张卡", getCardCount());
		return Card(-1, Card::CardType_None);
	}

	srand(unsigned(time(NULL)));

	int index = rand() % getCardCount();
	auto it = cardSkillSet.begin();
	advance(it, index);
	Card card(*it);
	cardSkillSet.erase(it);

	cocos2d::log("提示：已从战斗场景中的卡池中抽出一张卡（id=%d, type=%d）", card.getID(), card.getCardType());

	return card;
}

void CombatCardPool::clear()
{
	cardSkillSet.clear();

	cocos2d::log("提示：已清空战斗场景中的卡池");
}

void CombatCardPool::shuffle()
{
	while (recycleBin.empty() == false)
	{
		AddACard(recycleBin.back());
		recycleBin.pop_back();
	}

	cocos2d::log("提示：已完成战斗场景下的洗牌");
}

void CombatCardPool::pushRecycleBin(const Card &card)
{
	if (card.getID() < 0 || card.getCardType() != Card::CardType_Skill)
	{
		cocos2d::log("警告：尝试向战斗场景中的弃牌区加入一张卡（id=%d, type=%d）失败", card.getID(), card.getCardType());
		return;
	}

	recycleBin.push_back(card);
	cocos2d::log("提示：已向战斗场景中的弃牌区加入一张卡（id=%d, type=%d）", card.getID(), card.getCardType());
}

void CombatCardPool::clearRecycleBin()
{
	recycleBin.clear();
	cocos2d::log("提示：已清空战斗场景中的弃牌区");
}

int CombatCardPool::getRecycleBinCardCount()
{
	return recycleBin.size();
}

int CombatCardPool::getCardCount()
{
	return cardSkillSet.size();
}

void CombatCardPool::test()
{
	for (int i = 0; i < 10; ++i)
		AddACard(CardSkill(i));

	Card card(-1, Card::CardType_None);
	for (int i = 0; i < 13; ++i)
	{
		card = DrawACard();
		pushRecycleBin(card);
		cocos2d::log("card-id:%d, card-type:%d", card.getID(), card.getCardType());
		cocos2d::log("\tcard-count:%d", getCardCount());
	}

	shuffle();

	return;
}