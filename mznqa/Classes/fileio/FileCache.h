#ifndef MZNQA_CLASSES_FILEIO_FILECACHE_H_
#define MZNQA_CLASSES_FILEIO_FILECACHE_H_

// ���ڻ����ļ�
class FileCache
{
private:
	FileCache(){}
	FileCache(const FileCache &fileCache);
	FileCache& operator=(const FileCache &FileCache);

	// ��Ž�ɫ��̬���ݻ���
	char *roleStaticData;
public:
	static FileCache* Instance();
	~FileCache();

	// �����ɫ��̬�����ļ�
	bool loadRoleStaticDataFile(const char *path, const char *mode);
	// ��ȡ��ɫ��̬�����ļ�����
	char* getRoleStaticDataFile();
	// �ͷŽ�ɫ��̬�����ļ�
	void closeRoleStaticDataFile();
};

#endif	// MZNQA_CLASSES_FILEIO_FILECACHE_H_