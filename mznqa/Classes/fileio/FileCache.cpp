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
		// TODO �����ļ��򿪳ɹ���Ϣ
		return true;
	}
	else
	{
		// TODO �����ļ���ʧ����Ϣ
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
		// TODO �����ļ��رճɹ���Ϣ
		return true;
	}
	else
	{
		// TODO �����ļ��ر�ʧ����Ϣ
		return false;
	}
}