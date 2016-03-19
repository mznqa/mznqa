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