/*!
 * \file	Classes\engine\FileController.cpp
 *
 * \brief	������ FileController
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
	cocos2d::log("[information] �����Դ��ļ���\"%s\" ...", fileName);
	ssize_t size;
	char* charBuffer = (char*)cocos2d::FileUtils::getInstance()->getFileData(fileName, "r", &size);
	// ȷ���ַ�������'\0'��β����˶�����ļ������Կ��н�β������β��������ΪLF
	charBuffer[size - 1] = '\0';
	if (charBuffer == NULL)
	{
		cocos2d::log("[error] �ļ���ʧ�ܣ�\"%s\" ", fileName);
		// TODO �ڴ��˳�����
		bufferSize = 0;
		return nullptr;
	}
	bufferSize = size;
	cocos2d::log("[information] �ļ�(size=%d)�򿪳ɹ���\"%s\"", bufferSize, fileName);
	return charBuffer;
}

void FileController::test()
{
	getCharBufferFromFile("data/archives/map.json");
}