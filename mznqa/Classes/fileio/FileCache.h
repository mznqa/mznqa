#ifndef MZNQA_CLASSES_FILEIO_FILECACHE_H_
#define MZNQA_CLASSES_FILEIO_FILECACHE_H_

#include <cstdio>

// ���ڻ����ļ�
class FileCache
{
private:
	FileCache(){}
	FileCache(const FileCache &fileCache);
	FileCache& operator=(const FileCache &FileCache);

	// ��Ž�ɫ��̬���ݻ���
	FILE *roleStaticData;
public:
	static FileCache* Instance();
	~FileCache();

	// �����ɫ��̬�����ļ�
	bool loadRoleStaticDataFile(const char *path, const char *mode);
	// ��ȡ��ɫ��̬�����ļ�����
	FILE** getRoleStaticDataFile();
	// �ͷŽ�ɫ��̬�����ļ�
	bool closeRoleStaticDataFile();
};

#endif	// MZNQA_CLASSES_FILEIO_FILECACHE_H_