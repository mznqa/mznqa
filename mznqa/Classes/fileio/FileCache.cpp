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
	cocos2d::log("��ʾ����ʼ�����ɫ��̬����...");
	roleStaticData = new std::string(cocos2d::CCFileUtils::sharedFileUtils()->getStringFromFile(path));

	if (roleStaticData != nullptr && roleStaticData->empty() == false)
	{
		// TODO �����ļ��򿪳ɹ���Ϣ
		cocos2d::log("��ʾ���ɹ������ɫ��̬����");
		return true;
	}
	else
	{
		// TODO �����ļ���ʧ����Ϣ
		cocos2d::log("���󣺻����ɫ��̬����ʧ��");
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
		cocos2d::log("��ʾ���ɹ��ͷŽ�ɫ��̬�ļ�����");
	}
}