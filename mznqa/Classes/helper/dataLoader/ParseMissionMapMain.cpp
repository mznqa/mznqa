/*!
 * \file	Classes\helper\dataLoader\ParseMissionMapMain.cpp
 *
 * \brief	定义类 ParseMissionMapMain
 */
#pragma execution_character_set("utf-8")

#include "helper/dataLoader/ParseMissionMapMain.h"

#include "json\reader.h"

std::vector<MapNode> ParseMissionMapMain::bufferMapNodeSet;
std::vector<std::vector<int>> ParseMissionMapMain::bufferGraph;

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
	* \brief	ParseMissionMapMain 特需的用于处理解析过程的结构体
	*
	*/
	struct Handler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
	{
	private:
		ParseState ps;

		std::vector<int> mapNodeArgs;
		std::vector<int> edgeArgs;

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
			if (ps.state == ParseState::State_MapNode)
				mapNodeArgs.push_back(i);
			else if (ps.state == ParseState::State_EdgeSet)
				edgeArgs.push_back(i);
			return true;
		}
		bool Uint(unsigned u)
		{
			if (ps.state == ParseState::State_MapNode)
				mapNodeArgs.push_back(u);
			else if (ps.state == ParseState::State_EdgeSet)
				edgeArgs.push_back(u);
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
			if (ps.state == ParseState::State_MapNode)
			{
				ParseMissionMapMain::bufferMapNodeSet.push_back(MapNode(
					mapNodeArgs[0],
					mapNodeArgs[1],
					mapNodeArgs[2],
					(MapNode::NodeType)(mapNodeArgs[3]),
					(MapNode::ExtraType)(mapNodeArgs[4]),
					(mapNodeArgs[5] == 0) ? (false) : (true),
					(mapNodeArgs[6] == 0) ? (false) : (true)
					));
				mapNodeArgs.clear();
			}
			++ps;
			return true;
		}
		bool EndArray(rapidjson::SizeType elementCount)
		{
			if (ps.state == ParseState::State_EdgeSet)
			{
				auto itBegin = edgeArgs.cbegin();
				auto itEnd = edgeArgs.cend();
				auto it = edgeArgs.cbegin();
				if (ParseMissionMapMain::bufferGraph.size() <= *itBegin)
					ParseMissionMapMain::bufferGraph.push_back(std::vector<int>());
				++it;
				while (it != itEnd)
				{
					ParseMissionMapMain::bufferGraph[*itBegin].push_back(*it);
					++it;
				}
				edgeArgs.clear();
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
		bufferGraph.clear();
		return false;
	}
	else
		return true;
}