#include "fileio/FileCache.h"

FileCache* FileCache::Instance()
{
	static FileCache instance;
	return &instance;
}

FileCache::~FileCache()
{
	fclose(roleStaticData);
	roleStaticData = nullptr;
}

bool FileCache::loadRoleStaticDataFile(const char *path, const char *mode)
{
	roleStaticData = fopen(path, mode);
	if (roleStaticData != NULL)
	{
		// TODO 发送文件打开成功消息
		return true;
	}
	else
	{
		// TODO 发送文件打开失败消息
		return false;
	}
}

FILE** FileCache::getRoleStaticDataFile()
{
	return &roleStaticData;
}

bool FileCache::closeRoleStaticDataFile()
{
	if (fclose(roleStaticData) == 0)
	{
		// TODO 发送文件关闭成功消息
		return true;
	}
	else
	{
		// TODO 发送文件关闭失败消息
		return false;
	}
}