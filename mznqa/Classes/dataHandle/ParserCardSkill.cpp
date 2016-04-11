/*!
 * \file	Classes\dataHandle\ParserCardSkill.cpp
 *
 * \brief	������ ParserCardSkill���Լ�����Ľṹ�壺 ParserNode �� HandlerCardSkill
 */

#pragma execution_character_set("utf-8")

#include "dataHandle/ParserCardSkill.h"

#include <vector>

#include <cstring>

#include "json/reader.h"

#include "effect/Effect.h"
#include "dataHandle/CharBufferArea.h"

std::map<int, CardSkill> ParserCardSkill::cardSkillSetTemp;

ParserCardSkill::ParserCardSkill()
{
}

ParserCardSkill::~ParserCardSkill()
{
}

namespace ForParseCardSkill
{
	/*!
	 * \struct	ParserNode
	 *
	 * \brief	ParserCardSkill ��������ڼ�¼�����ڵ�״̬�Ľṹ��
	 *
	 */
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

	/*!
	 * \struct	HandlerCardSkill
	 *
	 * \brief	ParserCardSkill ��������ڴ���������̵Ľṹ��
	 *
	 */
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
				effectSetTemp.push_back(Effect(sEffectArgs[0], (Effect::Behavior)iEffectArgs[0], (Effect::Receiver)iEffectArgs[1], iEffectArgs[2], argsTemp));
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
				ParserCardSkill::cardSkillSetTemp.insert(
					std::pair<int, CardSkill>(
					iCardSkillArgs[0], CardSkill(iCardSkillArgs[0], sCardSkillArgs[0], sCardSkillArgs[1], (CardSkill::BelongTo)iCardSkillArgs[2], effectSetTemp)
					));
				effectSetTemp.clear();
				break;
			default:
				break;
			}
			return true;
		}
	};
}

void ParserCardSkill::parse()
{
	// ��鼼�ܿ������ļ��Ƿ��Ѿ�����
	if (CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_Static_CardSkillSet) == nullptr)
		return;
	// ���������������ʽ
	rapidjson::StringStream ss(CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_Static_CardSkillSet));
	// ������
	rapidjson::Reader reader;
	// ������
	ForParseCardSkill::HandlerCardSkill handlerCardSkill;
	// ����
	reader.Parse(ss, handlerCardSkill);
	// �жϽ����Ƿ����
	if (reader.HasParseError())
	{
		cocos2d::log("[error] �������ܿ�����");
	}
}