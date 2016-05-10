/*!
 * \file	Classes\helper\fileManager\FileManager.cpp
 *
 * \brief	定义类 FileManager
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
		// 此处因无法预知具体哪份文件载入出错，所以不再次做错误处理
		return nullptr;
	}
	// 确保字符缓冲以'\0'结尾，因此读入的文件必须以空行结尾，且行尾部结束符为LF
	charBuffer[size - 1] = '\0';
	return charBuffer;
}