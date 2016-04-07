/*!
 * \file	Classes\dataHandle\ParserMapArchives.cpp
 *
 * \brief	定义类 ParserMapArchives，以及特需的结构体： ParserNode 和 HandlerMapArchives
 */

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

namespace ForParserMapArchives
{
	/*!
	 * \struct	ParserNode
	 *
	 * \brief	ParserMapArchives 特需的用于记录解析节点状态的结构体
	 *
	 */
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

	/*!
	* \struct	HandlerMapArchives
	*
	* \brief	ParserMapArchives 特需的用于处理解析过程的结构体
	*
	*/
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
}

void ParserMapArchives::parse()
{
	// 以下作为地图存档解析参考：

	// 检查是否载入地图存档
	if (CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_Archives_MapGlobal) == nullptr)
		return;
	// 解析所需特定流
	rapidjson::StringStream ss(CharBufferArea::Instance()->getBufferByIndex(CharBufferArea::Instance()->BufferIndex_Archives_MapGlobal));
	// 解析器
	rapidjson::Reader reader;
	// 处理器
	ForParserMapArchives::HandlerMapArchives handlerMapArchives;
	// 解析
	reader.Parse(ss, handlerMapArchives);
	// 判断解析是否出错
	if (reader.HasParseError())
	{
		cocos2d::log("[error] 解析地图存档出错");
	}
	// 释放地图存档数据缓存
	CharBufferArea::Instance()->releaseBufferByIndex(CharBufferArea::Instance()->BufferIndex_Archives_MapGlobal);
}