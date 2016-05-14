/*!
 * \file	Classes\helper\dataLoader\ParseMissionMapMain.cpp
 *
 * \brief	定义类 ParseMissionMapMain
 */
#pragma execution_character_set("utf-8")

#include "helper/dataLoader/ParseMissionMapMain.h"

#include "json/reader.h"

#include "logic/data/info/NumDefine.h"
#include "logic/gameObject/map/MapNode.h"

ArKCa::Size<int> ParseMissionMapMain::bufferMapSize(0, 0);
std::vector<std::vector<MapNode>> ParseMissionMapMain::bufferMapNodeSet;

namespace ForParseMissionMapMain
{
	/*!
	* \struct	ParseState
	*
	* \brief	ForParseMissionMapMain::Handler 特需的用于记录解析节点状态的结构体
	*
	*/
	struct ParseState
	{
		enum State
		{
			State_Global = 0,
			State_MapArgs = 1,
			State_MapNodeSet = 2,
			State_MapNode = 3,
			State_AdjArgs = 4
		};

		int state;

		ParseState() :
			state(State_Global)
		{}

		ParseState& operator++()
		{
			if (state + 1 <= State_AdjArgs)
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
	* \brief	ParseMissionMapMain 特需的用于处理解析过程的结构体
	*
	*/
	struct Handler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
	{
	private:
		ParseState ps;

		std::vector<int> mapArgs;
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
			if (ps.state == ParseState::State_MapArgs)
			{
				mapArgs.push_back(i);
				if (mapArgs.size() >= 2)
				{
					ParseMissionMapMain::bufferMapSize.set(mapArgs[0], mapArgs[1]);
					for (int y = 0; y < ParseMissionMapMain::bufferMapSize.height; ++y)
						ParseMissionMapMain::bufferMapNodeSet.push_back(std::vector<MapNode>(
						ParseMissionMapMain::bufferMapSize.width,
						MapNode()
						));
				}
			}
			else if (ps.state == ParseState::State_MapNode || ps.state == ParseState::State_AdjArgs)
				mapNodeArgs.push_back(i);
			return true;
		}
		bool Uint(unsigned u)
		{
			if (ps.state == ParseState::State_MapArgs)
			{
				mapArgs.push_back(u);
				if (mapArgs.size() >= 2)
				{
					ParseMissionMapMain::bufferMapSize.set(mapArgs[0], mapArgs[1]);
					for (int y = 0; y < ParseMissionMapMain::bufferMapSize.height; ++y)
						ParseMissionMapMain::bufferMapNodeSet.push_back(std::vector<MapNode>(
						ParseMissionMapMain::bufferMapSize.width,
						MapNode()
						));
				}
			}
			else if (ps.state == ParseState::State_MapNode || ps.state == ParseState::State_AdjArgs)
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
			if (ps.state == ParseState::State_MapNode)
			{
				ParseMissionMapMain::bufferMapNodeSet[mapNodeArgs[1]][mapNodeArgs[0]] = MapNode(
					ArKCa::Vector2<int>(mapNodeArgs[0], mapNodeArgs[1]),
					(MapNode::NodeType)(mapNodeArgs[2]),
					(MapNode::ExtraType)(mapNodeArgs[3]),
					(mapNodeArgs[4] == 0) ? (false) : (true),
					(mapNodeArgs[5] == 0) ? (false) : (true),
					(mapNodeArgs[6] == 0) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(mapNodeArgs[0], mapNodeArgs[1] - 1)),
					(mapNodeArgs[7] == 0) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(mapNodeArgs[0] + 1, mapNodeArgs[1])),
					(mapNodeArgs[8] == 0) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(mapNodeArgs[0], mapNodeArgs[1] + 1)),
					(mapNodeArgs[9] == 0) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(mapNodeArgs[0] - 1, mapNodeArgs[1]))
					);
				mapNodeArgs.clear();
			}
			--ps;
			return true;
		}
	};
}

bool ParseMissionMapMain::parse(const char *const data)
{
	// 解析所需特定流
	rapidjson::StringStream ss(data);
	// 解析器
	rapidjson::Reader reader;
	// 处理器
	ForParseMissionMapMain::Handler handler;
	// 解析
	reader.Parse(ss, handler);
	// 判断解析是否出错
	if (reader.HasParseError())
	{
		bufferMapNodeSet.clear();
		return false;
	}
	else
		return true;
}