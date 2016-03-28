#pragma execution_character_set("utf-8")

#include "dataHandle/ParserMapArchives.h"

#include <vector>

#include "cocos2d.h"

#include "json/reader.h"

#include "map/MapNode.h"
#include "map/MapController.h"
#include "dataHandle/CharBufferArea.h"

ParserMapArchives::ParserMapArchives()
{
}

ParserMapArchives::~ParserMapArchives()
{
}

// 记录json节点状态
struct ParserNode
{
	enum State
	{
		State_Global = 0,
		State_MapArgs = 1,
		State_MapNodeArray = 2,
		State_MapNode = 3
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

// 技能卡json数据处理器
struct HandlerMapArchives : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
{
private:
	ParserNode pn;

	std::vector<int> mapNodeArgs;

	std::vector<MapNode> mapNodeSet;

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
		if (pn.state == ParserNode::State::State_MapNode)
			mapNodeArgs.push_back(i);
		return true;
	}
	bool Uint(unsigned u)
	{
		if (pn.state == ParserNode::State::State_MapNode)
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
			mapNodeSet.push_back(MapNode(
				mapNodeArgs[0],
				mapNodeArgs[1],
				mapNodeArgs[2],
				((mapNodeArgs[3] == 1) ? (true) : (false)),
				MapNode::RoadType(mapNodeArgs[4]),
				MapNode::NodeStyle(mapNodeArgs[5])
				));
			mapNodeArgs.clear();
		}
		return true;
	}
};

void ParserMapArchives::parse()
{
	if (CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_MapArchives) == nullptr)
		return;
	rapidjson::StringStream ss(CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_MapArchives));
	rapidjson::Reader reader;
	HandlerMapArchives handlerMapArchives;
	reader.Parse(ss, handlerMapArchives);
	CharBufferArea::Instance()->releaseBufferByIndex(CharBufferArea::Instance()->BufferIndex_MapArchives);
	while (true)
	{
		cocos2d::log(".");
	}
}