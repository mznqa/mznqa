#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_
#define MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_

#include <string>
#include <memory>

// 用于读写文件，请勿在该类中保存任何文件缓存
class FileController
{
private:
	FileController(){}
	FileController(const FileController&);
	FileController& operator=(const FileController&);
public:
	static FileController* Instance();
	~FileController();

	// 从文件获取字符缓存
	char* getCharBufferFromFile(const std::string& fileName);
	// 从文件获取字符缓存，并指定一个量来记录缓存大小
	char* getCharBufferFromFile(const std::string& fileName, int& bufferSize);

	void test();
};

#endif
