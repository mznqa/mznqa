/*!
 * \file	Classes\helper\dataLoader\ParseCardRoadSet.cpp
 *
 * \brief	定义类 ParseCardRoadSet
 */

#pragma execution_character_set("utf-8")

#include "helper/dataLoader/ParseCardRoadSet.h"

#include "logic/data/static/StringSet/StringSet.h"
#include "logic/data/info/DataFilePath.h"

#include "json/reader.h"

std::vector<CardRoad> ParseCardRoadSet::bufferCardRoadSet;

namespace ForParseCardRoadSet
{
	/*!
	* \struct	ParseState
	*
	* \brief	ForParseCardRoadSet::Handler 特需的用于记录解析节点状态的结构体
	*
	*/
	struct ParseState
	{
		enum State
		{
			State_Global = 0,
			State_CardRoadSet = 1,
			State_CardRoad = 2,
			State_RoadNode = 3,
		};

		int state;

		ParseState() :
			state(State_Global)
		{}

		ParseState& operator++()
		{
			if (state + 1 <= State_RoadNode)
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
	* \brief	ParseCardRoadSet 特需的用于处理解析过程的结构体
	*
	*/
	struct Handler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
	{
	private:
		ParseState ps;

		std::vector<int> intArgs;

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
			if (ps.state == ParseState::State_CardRoad || ps.state == ParseState::State_RoadNode)
				intArgs.push_back(i);
			return true;
		}
		bool Uint(unsigned u)
		{
			if (ps.state == ParseState::State_CardRoad || ps.state == ParseState::State_RoadNode)
				intArgs.push_back(u);
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
			if (ps.state == ParseState::State_CardRoad)
			{
				bool roadNode[MAPNODE_GROUPSIZE][MAPNODE_GROUPSIZE];
				int step = 1;
				for (int y = 0; y < MAPNODE_GROUPSIZE; ++y)
					for (int x = 0; x < MAPNODE_GROUPSIZE; ++x)
					{
						roadNode[y][x] = (intArgs[step] == 1) ? (true) : (false);
						++step;
					}

				ParseCardRoadSet::bufferCardRoadSet.push_back(CardRoad(
					intArgs[0],
					StringSet::StringID_Null,
					StringSet::StringID_Null,
					CardBase::BelongTo_Character,
					roadNode
					));

				intArgs.clear();
			}
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
			--ps;
			return true;
		}
	};
}

bool ParseCardRoadSet::parse(const char *const data)
{
	// 解析所需特定流
	rapidjson::StringStream ss(data);
	// 解析器
	rapidjson::Reader reader;
	// 处理器
	ForParseCardRoadSet::Handler handler;
	// 解析
	reader.Parse(ss, handler);

	// 判断解析是否出错
	if (reader.HasParseError())
	{
		bufferCardRoadSet.clear();
		return false;
	}
	else
		return true;
}