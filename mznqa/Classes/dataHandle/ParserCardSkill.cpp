#pragma execution_character_set("utf-8")

#include "dataHandle/ParserCardSkill.h"

#include <vector>

#include <cstring>

#include "json/reader.h"

#include "card/CardSkill.h"
#include "effect/Effect.h"
#include "dataHandle/CharBufferArea.h"

ParserCardSkill::ParserCardSkill()
{
}

ParserCardSkill::~ParserCardSkill()
{
}

// 解析过程中使用，用于记录json节点状态
struct ParserNode
{
	enum State
	{
		State_Global = 0,
		State_CardSkillArray = 1,
		State_CardSkill = 2,
		State_EffectArray = 3,
		State_Effect = 4,
		State_Args = 5
	};

	int state;

	ParserNode() :
		state(State_Global)
	{}

	ParserNode& operator++()
	{
		if (state + 1 <= State_Args)
			++state;
		return *this;
	}
	ParserNode& operator--()
	{
		if (state - 1 >= State_Global)
			--state;
		return *this;
	}
};

// 解析处理器：技能卡json数据处理器
struct HandlerCardSkill : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
{
private:
	ParserNode pn;

	std::vector<int> iCardSkillArgs;
	std::vector<std::string> sCardSkillArgs;

	std::vector<int> iEffectArgs;
	std::vector<std::string> sEffectArgs;

	std::vector<int> iArgsArgs;

	std::vector<int> argsTemp;
	std::vector<Effect> effectSetTemp;

public:
	bool Null()
	{
		return true;
	}
	bool Bool(bool b)
	{
		return true;
	}
	bool Int(int i)
	{
		switch (pn.state)
		{
		case ParserNode::State::State_CardSkill:
			iCardSkillArgs.push_back(i);
			break;
		case ParserNode::State::State_Effect:
			iEffectArgs.push_back(i);
			break;
		case ParserNode::State::State_Args:
			iArgsArgs.push_back(i);
			break;
		default:
			break;
		}
		return true;
	}
	bool Uint(unsigned u)
	{
		switch (pn.state)
		{
		case ParserNode::State::State_CardSkill:
			iCardSkillArgs.push_back(u);
			break;
		case ParserNode::State::State_Effect:
			iEffectArgs.push_back(u);
			break;
		case ParserNode::State::State_Args:
			iArgsArgs.push_back(u);
			break;
		default:
			break;
		}
		return true;
	}
	bool Int64(int64_t i)
	{
		return true;
	}
	bool Uint64(uint64_t u)
	{
		return true;
	}
	bool Double(double d)
	{
		return true;
	}
	bool String(const char* str, rapidjson::SizeType length, bool copy)
	{
		switch (pn.state)
		{
		case ParserNode::State::State_CardSkill:
			sCardSkillArgs.push_back(std::string(str));
			break;
		case ParserNode::State::State_Effect:
			sEffectArgs.push_back(std::string(str));
			break;
		default:
			break;
		}
		return true;
	}
	bool StartObject()
	{
		++pn;
		return true;
	}
	bool Key(const char* str, rapidjson::SizeType length, bool copy)
	{
		return true;
	}
	bool EndObject(rapidjson::SizeType memberCount)
	{
		--pn;
		switch (pn.state)
		{
		case ParserNode::State::State_EffectArray:
			effectSetTemp.push_back(Effect(sEffectArgs[0], (Effect::Receiver)iEffectArgs[0], iEffectArgs[1], argsTemp));
			iEffectArgs.clear();
			sEffectArgs.clear();
			break;
		case ParserNode::State::State_CardSkillArray:
			iCardSkillArgs.clear();
			sCardSkillArgs.clear();
			break;
		default:
			break;
		}
		return true;
	}
	bool StartArray()
	{
		++pn;
		return true;
	}
	bool EndArray(rapidjson::SizeType elementCount)
	{
		--pn;
		switch (pn.state)
		{
		case ParserNode::State::State_Effect:
			argsTemp = iArgsArgs;
			iArgsArgs.clear();
			break;
		case ParserNode::State::State_CardSkill:
			// 在这里获取逐一解析出来的技能卡数据，参考一下进行数据记录
			//cardSkillSet.push_back(CardSkill(iCardSkillArgs[0], sCardSkillArgs[0], sCardSkillArgs[1], (CardSkill::BelongTo)iCardSkillArgs[2], effectSetTemp));
			effectSetTemp.clear();
			break;
		default:
			break;
		}
		return true;
	}
};

void ParserCardSkill::parse()
{
	// 以下模拟解析：

	// 检查技能卡数据文件是否已经缓存
	if (CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_CardSkill) == nullptr)
		return;
	// 解析器所需的流格式
	rapidjson::StringStream ss(CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_CardSkill));
	// 解析器
	rapidjson::Reader reader;
	// 处理器
	HandlerCardSkill handlerCardSkill;
	// 解析
	reader.Parse(ss, handlerCardSkill);
	// 判断解析是否出错
	if (reader.HasParseError())
	{
		cocos2d::log("[error] 解析技能卡出错");
	}
	// 释放技能卡数据缓存
	CharBufferArea::Instance()->releaseBufferByIndex(CharBufferArea::Instance()->BufferIndex_CardSkill);
}