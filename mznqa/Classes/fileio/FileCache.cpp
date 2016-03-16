#include "fileio/FileCache.h"

#include "cocos2d.h"

FileCache* FileCache::Instance()
{
	static FileCache instance;
	return &instance;
}

FileCache::~FileCache()
{
	delete roleStaticData;
	roleStaticData = nullptr;
}

bool FileCache::loadRoleStaticDataFile(const char *path, const char *mode)
{
	ssize_t size = 0;
	unsigned char * temp = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(path, mode, &size);
	roleStaticData = new char[size + 1];
	roleStaticData = (char*)temp;

	if (roleStaticData != NULL)
	{
		// TODO �����ļ��򿪳ɹ���Ϣ
		return true;
	}
	else
	{
		// TODO �����ļ���ʧ����Ϣ
		return false;
	}
}

char* FileCache::getRoleStaticDataFile()
{
	return roleStaticData;
}

void FileCache::closeRoleStaticDataFile()
{
	delete roleStaticData;
	roleStaticData = nullptr;
}