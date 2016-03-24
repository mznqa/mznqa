#pragma execution_character_set("utf-8")

#include "fileio/FileCache.h"

#include "cocos2d.h"

FileCache* FileCache::Instance()
{
	static FileCache instance;
	return &instance;
}

FileCache::~FileCache()
{
	closeRoleStaticDataFile();
	closeCardSkillStaticDataFile();
}

bool FileCache::loadRoleStaticDataFile(const char *path, const char *mode)
{
	cocos2d::log("提示：开始载入角色静态数据...");
	roleStaticData = new std::string(cocos2d::CCFileUtils::sharedFileUtils()->getStringFromFile(path));

	if (roleStaticData != nullptr && roleStaticData->empty() == false)
	{
		// TODO 发送文件打开成功消息
		cocos2d::log("提示：成功缓冲角色静态数据");
		return true;
	}
	else
	{
		// TODO 发送文件打开失败消息
		cocos2d::log("错误：缓冲角色静态数据失败");
		return false;
	}
}

const std::string* FileCache::getRoleStaticDataFile()
{
	return roleStaticData;
}

void FileCache::closeRoleStaticDataFile()
{
	if (roleStaticData != nullptr)
	{
		delete roleStaticData;
		roleStaticData = nullptr;
		cocos2d::log("提示：成功释放角色静态文件缓冲");
	}
}

bool FileCache::loadCardSkillStaticDataFile(const char *path, const char *mode)
{
	cocos2d::log("提示：开始载入技能卡静态数据...");
	cardSkillStaticData = new std::string(cocos2d::CCFileUtils::sharedFileUtils()->getStringFromFile(path));

	if (cardSkillStaticData != nullptr && cardSkillStaticData->empty() == false)
	{
		// TODO 发送文件打开成功消息
		cocos2d::log("提示：成功缓冲技能卡静态数据");
		return true;
	}
	else
	{
		// TODO 发送文件打开失败消息
		cocos2d::log("错误：缓冲技能卡静态数据失败");
		return false;
	}
}

const std::string* FileCache::getCardSkillStaticDataFile()
{
	return cardSkillStaticData;
}

void FileCache::closeCardSkillStaticDataFile()
{
	if (cardSkillStaticData != nullptr)
	{
		delete cardSkillStaticData;
		cardSkillStaticData = nullptr;
		cocos2d::log("提示：成功释放技能卡静态文件缓冲");
	}
}

bool FileCache::loadMapArchivesDataFile(const char *path, const char *mode)
{
	cocos2d::log("提示：开始载入地图存档数据...");
	mapArchivesData = new std::string(cocos2d::CCFileUtils::sharedFileUtils()->getStringFromFile(path));

	if (mapArchivesData != nullptr && mapArchivesData->empty() == false)
	{
		// TODO 发送文件打开成功消息
		cocos2d::log("提示：成功缓冲地图存档数据");
		return true;
	}
	else
	{
		// TODO 发送文件打开失败消息
		cocos2d::log("错误：缓冲地图存档数据失败");
		return false;
	}
}

const std::string* FileCache::getMapArchivesDataFile()
{
	return mapArchivesData;
}

void FileCache::closeMapArchivesDataFile()
{
	if (mapArchivesData != nullptr)
	{
		delete mapArchivesData;
		mapArchivesData = nullptr;
		cocos2d::log("提示：成功释放地图存档文件缓冲");
	}
}