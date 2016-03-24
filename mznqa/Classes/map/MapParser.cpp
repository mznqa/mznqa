#pragma execution_character_set("utf-8")

#include <utility>
#include <vector>

#include "cocos2d.h"
#include "json/document.h"

#include "map/MapParser.h"
#include "fileio/FileCache.h"
#include "filePath/DataPath.h"
#include "fileio/JsonParser.h"

MapParser::MapParser()
{
}

MapParser::~MapParser()
{
}

std::map<int, MapNode> MapParser::parseMap(int x0, int y0, int x1, int y1)
{
	std::map<int, MapNode> result;
	if (x0 < 0 || y0 < 0)
		return result;
	if (x1 < x0 || y1 < y0)
		return result;

	std::vector<int> range;
	for (int x = x0; x <= x1; ++x)
		for (int y = y0; y <= y1; ++y)
			range.push_back(x + y * 640);

	int jsonBufferIndex = -1;
	if (!FileCache::Instance()->loadMapArchivesDataFile(
		cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(ARCHIVES_DATA_MAP).c_str(),
		"r"
		))
	{
		cocos2d::log("错误：缓冲地图存档数据文件出错");
		jsonBufferIndex = -1;
		return result;
	}

	// 创建json缓冲区:技能卡数据
	jsonBufferIndex = JsonParser::Instance()->createBuffer(FileCache::Instance()->getMapArchivesDataFile());

	if (jsonBufferIndex == -1)
	{
		cocos2d::log("错误：缓冲区分配失败");
		return result;
	}

	rapidjson::Document *doc = JsonParser::Instance()->getJsonDOMByBufferIndex(jsonBufferIndex);

	int mapNodeCount = 0;

	if (doc->IsObject() && doc->HasMember("map_node_count"))
	{
		mapNodeCount = (*doc)["map_node_count"].GetInt();
	}
	if (mapNodeCount <= 0)
	{
		return result;
	}

	rapidjson::Value mapSet;
	if (doc->IsObject() && doc->HasMember("map"))
		mapSet = (*doc)["map"];

	result.insert(std::pair<int, MapNode>(-1, MapNode()));
	rapidjson::Value temp;
	auto it = range.begin();
	auto itEnd = range.end();
	while (it != itEnd)
	{
		temp = mapSet[*it];
		MapNode node;
		node.index = temp[0].GetInt();
		node.x = temp[1].GetInt();
		node.y = temp[2].GetInt();
		node.type = MapNode::MapNodeType(temp[3].GetInt());
		node.roadSign = MapNode::RoadSign(temp[4].GetInt());
		node.up = temp[5].GetInt();
		node.right = temp[6].GetInt();
		node.down = temp[7].GetInt();
		node.left = temp[8].GetInt();
		result.insert(std::pair<int, MapNode>(node.index, node));
		++it;
	}
	JsonParser::Instance()->clearBuffer(jsonBufferIndex);
	return result;
}