#pragma execution_character_set("utf-8")

#include "dataHandle/ParserMapMissionMain.h"

#include "cocos2d.h"
#include "json/reader.h"

#include "dataHandle/CharBufferArea.h"

std::vector<MissionMap> ParserMapMissionMain::mainMissionMapSetTemp;

namespace ForParserMapMissionMain
{
	struct ParserNode
	{
		enum State
		{
			State_Global = 0,
			State_Info = 1,
			State_MapArray = 2,
			State_Map = 3,
			State_MapNodeArray = 4,
			State_MapNode = 5
		};

		int state;

		ParserNode() :
			state(State_Global)
		{}

		ParserNode& operator++()
		{
			if (state + 1 <= State_MapNode)
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

	struct HandlerMapMissionMain : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
	{
	private:
		ParserNode pn;

		std::vector<int> mapArgs;

		std::vector<int> mapNodeArgs;

		std::vector<MapNode> mapNodeSetTemp;

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
			if (pn.state == ParserNode::State::State_Map)
				mapArgs.push_back(i);
			else if (pn.state == ParserNode::State::State_MapNode)
				mapNodeArgs.push_back(i);
			return true;
		}
		bool Uint(unsigned u)
		{
			if (pn.state == ParserNode::State::State_Map)
				mapArgs.push_back(u);
			else if (pn.state == ParserNode::State::State_MapNode)
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
			if (pn.state == ParserNode::State::State_MapNodeArray)
			{
				mapNodeSetTemp.push_back(
					MapNode(
					mapNodeArgs[0],
					mapNodeArgs[1],
					mapNodeArgs[2],
					(mapNodeArgs[3] == 0 ? true : false),
					MapNode::NodeType(mapNodeArgs[4]),
					mapNodeArgs[5]
					)
					);
				mapNodeArgs.clear();
			}
			else if (pn.state == ParserNode::State::State_Map)
			{
				//cocos2d::log("aaa %d", ParserMapMissionMain::mainMissionMapSetTemp->at(0).mapNodeSet->size());
				ParserMapMissionMain::mainMissionMapSetTemp.push_back(
					MissionMap(
					mapArgs[0],
					MissionMap::MapType_MainMission,
					mapArgs[1],
					mapArgs[2],
					mapNodeSetTemp
					)
					);
				mapNodeSetTemp.clear();
			}
			return true;
		}
	};
}

void ParserMapMissionMain::parse()
{
	// 检查是否载入地图存档
	if (CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_Static_MainMissionMap) == nullptr)
		return;
	// 解析所需特定流
	rapidjson::StringStream ss(CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_Static_MainMissionMap));
	// 解析器
	rapidjson::Reader reader;
	// 处理器
	ForParserMapMissionMain::HandlerMapMissionMain handlerMapMissionMain;
	// 解析
	reader.Parse(ss, handlerMapMissionMain);
	// 判断解析是否出错
	if (reader.HasParseError())
	{
		cocos2d::log("[error] 解析地图存档出错");
	}
	cocos2d::log("aaa %d", ParserMapMissionMain::mainMissionMapSetTemp.at(0).mapNodeSet.size());
}