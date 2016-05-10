/*!
 * \file	Classes\helper\fileManager\FileManager.cpp
 *
 * \brief	������ FileManager
 */

#pragma execution_character_set("utf-8")

#include "helper/fileManager/FileManager.h"

#include "cocos2d.h"

FileManager* FileManager::Instance()
{
	static FileManager instance;
	return &instance;
}

char *const FileManager::getDataFromFile(const std::string& fileName)const
{
	ssize_t size;
	char* charBuffer = (char*)(cocos2d::FileUtils::getInstance()->getFileData(fileName, "r", &size));
	if (charBuffer == NULL || size == 0)
	{
		// �˴����޷�Ԥ֪�����ķ��ļ�����������Բ��ٴ���������
		return nullptr;
	}
	// ȷ���ַ�������'\0'��β����˶�����ļ������Կ��н�β������β��������ΪLF
	charBuffer[size - 1] = '\0';
	return charBuffer;
}