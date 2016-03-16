#ifndef MZNQA_CLASSES_FILEIO_JSONPARSER_H_
#define MZNQA_CLASSES_FILEIO_JSONPARSER_H_

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

// 用于缓存外部Json文件到内存，并提供基本的json解析api
class JsonParser
{
private:
	JsonParser(){}
	JsonParser(const JsonParser &jsonParser);
	JsonParser& operator=(const JsonParser &jsonParser);

	// 缓冲区总数
	static const int bufferCount = 3;
	// 记录每个缓冲区的状态
	bool bufferCheck[bufferCount];

	// 3个（暂定3个）用于缓冲的区域 //////////////////////////////////////////////////////////////////////////
	// index 0
	char *buffer0;
	rapidjson::FileReadStream *frs0;
	rapidjson::Document *jdom0;

	// index 1
	char *buffer1;
	rapidjson::FileReadStream *frs1;
	rapidjson::Document *jdom1;

	// index 2
	char *buffer2;
	rapidjson::FileReadStream *frs2;
	rapidjson::Document *jdom2;
	//////////////////////////////////////////////////////////////////////////
public:
	static JsonParser *Instance();
	~JsonParser();

	// 获取缓冲区的总个数
	int getBufferCount();

	// 获取可用的缓冲区个数
	int getEmptyBufferCount();

	// 获取一个可用的缓冲区编号，当返回-1时表示当前无可用的缓冲区
	int getNextBufferCount();

	// 获取指定编号缓冲区下的JsonDOM
	rapidjson::Document* getJsonDOMByBufferIndex(int index);

	// 根据给定json文件和缓冲区大小来开辟缓冲区，成功将返回缓冲区编号
	int createBuffer(FILE *file, size_t bufferSize);

	// 回收指定编号缓冲区
	void clearBuffer(int bufferIndex);

	void test();
};

#endif // MZNQA_CLASSES_FILEIO_JSONPARSER_H_
