#ifndef MZNQA_CLASSES_FILEIO_JSONPARSER_H_
#define MZNQA_CLASSES_FILEIO_JSONPARSER_H_

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

// ���ڻ����ⲿJson�ļ����ڴ棬���ṩ������json����api
class JsonParser
{
private:
	JsonParser(){}
	JsonParser(const JsonParser &jsonParser);
	JsonParser& operator=(const JsonParser &jsonParser);

	// ����������
	static const int bufferCount = 3;
	// ��¼ÿ����������״̬
	bool bufferCheck[bufferCount];

	// 3�����ݶ�3�������ڻ�������� //////////////////////////////////////////////////////////////////////////
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

	// ��ȡ���������ܸ���
	int getBufferCount();

	// ��ȡ���õĻ���������
	int getEmptyBufferCount();

	// ��ȡһ�����õĻ�������ţ�������-1ʱ��ʾ��ǰ�޿��õĻ�����
	int getNextBufferCount();

	// ��ȡָ����Ż������µ�JsonDOM
	rapidjson::Document* getJsonDOMByBufferIndex(int index);

	// ���ݸ���json�ļ��ͻ�������С�����ٻ��������ɹ������ػ��������
	int createBuffer(FILE *file, size_t bufferSize);

	// ����ָ����Ż�����
	void clearBuffer(int bufferIndex);

	void test();
};

#endif // MZNQA_CLASSES_FILEIO_JSONPARSER_H_
