/*!
 * \file	Classes\engine\FileController.cpp
 *
 * \brief	定义类 FileController
 */

#pragma execution_character_set("utf-8")

#include "engine/FileController.h"

#include <memory>
#include <cstring>

#include "cocos2d.h"

FileController* FileController::Instance()
{
	static FileController instance;
	return &instance;
}

FileController::~FileController()
{
}

char* FileController::getCharBufferFromFile(const std::string& fileName)
{
	int size;
	return getCharBufferFromFile(fileName, size);
}

char* FileController::getCharBufferFromFile(const std::string& fileName, int& bufferSize)
{
	cocos2d::log("[information] 正尝试打开文件：\"%s\" ...", fileName);
	ssize_t size;
	char* charBuffer = (char*)cocos2d::FileUtils::getInstance()->getFileData(fileName, "r", &size);
	// 确保字符缓冲以'\0'结尾，因此读入的文件必须以空行结尾，且行尾部结束符为LF
	charBuffer[size - 1] = '\0';
	if (charBuffer == NULL)
	{
		cocos2d::log("[error] 文件打开失败：\"%s\" ", fileName);
		// TODO 在此退出程序
		bufferSize = 0;
		return nullptr;
	}
	bufferSize = size;
	cocos2d::log("[information] 文件(size=%d)打开成功：\"%s\"", bufferSize, fileName);
	return charBuffer;
}

void FileController::test()
{
	getCharBufferFromFile("data/archives/map.json");
}