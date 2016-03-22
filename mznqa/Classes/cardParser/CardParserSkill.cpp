#pragma execution_character_set("utf-8")

#include "cocos2d.h"
#include "json/document.h"

#include "cardParser/CardParserSkill.h"
#include "fileio/FileCache.h"
#include "fileio/JsonParser.h"
#include "filePath/DataPath.h"
#include "combatSystem/EffectEntity.h"
#include "data/staticData/EffectSet.h"

CardParserSkill::CardParserSkill()
{
}

CardParserSkill::~CardParserSkill()
{
}

int CardParserSkill::createCardSkillJsonBuffer()
{
	if (JsonParser::Instance()->getEmptyBufferCount() <= 0)
	{
		cocos2d::log("错误：当前无空余的json缓冲区可用");
		jsonBufferIndex = -1;
		return -1;
	}

	// 缓存文件:技能卡数据
	if (!FileCache::Instance()->loadCardSkillStaticDataFile(
		cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(STATIC_DATA_CARDSKILL).c_str(),
		"r"
		))
	{
		cocos2d::log("错误：缓冲技能卡数据文件出错");
		jsonBufferIndex = -1;
		return -1;
	}

	// 创建json缓冲区:技能卡数据
	jsonBufferIndex = JsonParser::Instance()->createBuffer(FileCache::Instance()->getCardSkillStaticDataFile());

	if (jsonBufferIndex == -1)
	{
		cocos2d::log("错误：缓冲区分配失败");
		return -1;
	}

	return jsonBufferIndex;
}

std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> CardParserSkill::parseEffect(int cardID)
{
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> result;
	if (cardID < 0)
	{
		cocos2d::log("警告：尝试解析错误的技能卡（id=%d）", cardID);
		return result;
	}

	if (jsonBufferIndex == -1)
	{
		cocos2d::log("警告：未指定可用的json缓冲区以用于解析");
		return result;
	}

	rapidjson::Document *doc = JsonParser::Instance()->getJsonDOMByBufferIndex(jsonBufferIndex);

	int effectCount = 0;
	rapidjson::Value card;

	if (doc->IsObject() && doc->HasMember("card_skill"))
	{
		card = (*doc)["card_skill"][cardID];
		effectCount = card["effect_count"].GetInt();
		cocos2d::log("提示：解析到id为%d的技能卡的效果数为%d", cardID, effectCount);
	}
	if (effectCount <= 0)
	{
		cocos2d::log("警告：id为%d的技能卡未解析到任何效果", cardID);
		return result;
	}

	EffectSet es;
	rapidjson::Value eff;
	for (int i = 0; i < effectCount; ++i)
	{
		int *arr;
		eff = card["effect"][i];
		int argCount = eff["effect_arg_count"].GetInt() + 2;
		arr = new int[argCount];
		arr[0] = eff["start_roung"].GetInt();
		arr[1] = eff["continued"].GetInt();
		for (int j = 2; j < argCount; ++j)
		{
			arr[j] = eff["effect_args"][j - 2].GetInt();
		}
		result.push(EffectEntity(
			-1,
			es.getFunByEffectID(eff["effect_id"].GetInt()),
			arr,
			argCount
			));
	}

	return result;
}

void CardParserSkill::test()
{
	int index = createCardSkillJsonBuffer();
	if (index == -1)
		return;

	EffectPQ epq;
	auto a = parseEffect(0);
	EffectEntity temp(-1, nullptr, nullptr, 0);
	int i = 0;
	int j = 0;
	int k = 0;
	while (a.empty() == false)
	{
		temp = a.top();
		if (temp.arr[0] == 0)
			temp.level = i++;
		else if (temp.arr[0] == 1)
			temp.level = (j++) + 100;
		else if (temp.arr[0] == 2)
			temp.level = (k++) + 200;
		epq.pushRoleEffect(temp);
		a.pop();
	}
	cocos2d::log("max = %d", epq.getRoleEPQLevelMaxByRound(0));
	cocos2d::log("max = %d", epq.getRoleEPQLevelMaxByRound(1));
	cocos2d::log("max = %d", epq.getRoleEPQLevelMaxByRound(2));
	while (epq.isRoleEffectPQEmpty() == false)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		(ee.fun)(ee.arr, ee.size);
	}
}