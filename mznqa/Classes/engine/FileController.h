#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_
#define MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_

#include <string>
#include <memory>

// ���ڶ�д�ļ��������ڸ����б����κ��ļ�����
class FileController
{
private:
	FileController(){}
	FileController(const FileController&);
	FileController& operator=(const FileController&);
public:
	static FileController* Instance();
	~FileController();

	// ���ļ���ȡ�ַ�����
	char* getCharBufferFromFile(const std::string& fileName);
	// ���ļ���ȡ�ַ����棬��ָ��һ��������¼�����С
	char* getCharBufferFromFile(const std::string& fileName, int& bufferSize);

	void test();
};

#endif
