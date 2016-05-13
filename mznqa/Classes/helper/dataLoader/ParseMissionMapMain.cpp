/*!
 * \file	Classes\helper\dataLoader\ParseMissionMapMain.cpp
 *
 * \brief	������ ParseMissionMapMain
 */
#pragma execution_character_set("utf-8")

#include "helper/dataLoader/ParseMissionMapMain.h"

#include <vector>

#include "json/reader.h"

#include "logic/data/info/NumDefine.h"
#include "logic/gameObject/map/MapNode.h"

std::map<int, MapNode> ParseMissionMapMain::bufferMapNodeSet;

namespace ForParseMissionMapMain
{
	/*!
	* \struct	ParseState
	*
	* \brief	ForParseMissionMapMain::Handler ��������ڼ�¼�����ڵ�״̬�Ľṹ��
	*
	*/
	struct ParseState
	{
		enum State
		{
			State_Global = 0,
			State_MapNodeSet = 1,
			State_MapNode = 2,
			State_EdgeSet = 3
		};

		int state;

		ParseState() :
			state(State_Global)
		{}

		ParseState& operator++()
		{
			if (state + 1 <= State_EdgeSet)
				++state;
			return *this;
		}
		ParseState& operator--()
		{
			if (state - 1 >= State_Global)
				--state;
			return *this;
		}
	};

	/*!
	* \struct	Handler
	*
	* \brief	ParseMissionMapMain ��������ڴ���������̵Ľṹ��
	*
	*/
	struct Handler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
	{
	private:
		ParseState ps;

		std::vector<int> mapNodeArgs;

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
			if (ps.state == ParseState::State_MapNode || ps.state == ParseState::State_EdgeSet)
				mapNodeArgs.push_back(i);
			return true;
		}
		bool Uint(unsigned u)
		{
			if (ps.state == ParseState::State_MapNode || ps.state == ParseState::State_EdgeSet)
				mapNodeArgs.push_back(u);
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
			return true;
		}
		bool StartObject()
		{
			++ps;
			return true;
		}
		bool Key(const char* str, rapidjson::SizeType length, bool copy)
		{
			return true;
		}
		bool EndObject(rapidjson::SizeType memberCount)
		{
			--ps;
			return true;
		}
		bool StartArray()
		{
			++ps;
			return true;
		}
		bool EndArray(rapidjson::SizeType elementCount)
		{
			if (ps.state == ParseState::State_EdgeSet)
			{
				ParseMissionMapMain::bufferMapNodeSet.insert(std::pair<int, MapNode>(mapNodeArgs[0], MapNode(
					mapNodeArgs[0],
					mapNodeArgs[1],
					mapNodeArgs[2],
					(MapNode::NodeType)(mapNodeArgs[3]),
					(MapNode::ExtraType)(mapNodeArgs[4]),
					(mapNodeArgs[5] == 0) ? (false) : (true),
					(mapNodeArgs[6] == 0) ? (false) : (true),
					mapNodeArgs[7],
					mapNodeArgs[8],
					mapNodeArgs[9],
					mapNodeArgs[10]
					)));
				mapNodeArgs.clear();
			}
			--ps;
			return true;
		}
	};
}

bool ParseMissionMapMain::parse(const char *const data)
{
	// ���������ض���
	rapidjson::StringStream ss(data);
	// ������
	rapidjson::Reader reader;
	// ������
	ForParseMissionMapMain::Handler handler;
	// ����
	reader.Parse(ss, handler);
	// �жϽ����Ƿ����
	if (reader.HasParseError())
	{
		bufferMapNodeSet.clear();
		return false;
	}
	else
		return true;
}