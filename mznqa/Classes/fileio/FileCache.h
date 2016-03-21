#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_FILEIO_FILECACHE_H_
#define MZNQA_CLASSES_FILEIO_FILECACHE_H_

#include <string>

// ���ڻ����ļ�
class FileCache
{
private:
	FileCache(){}
	FileCache(const FileCache &fileCache);
	FileCache& operator=(const FileCache &FileCache);

	// ��Ž�ɫ��̬���ݻ���
	std::string *roleStaticData;

	// ��ż��ܿ���̬���ݻ���
	std::string *cardSkillStaticData;
public:
	static FileCache* Instance();
	~FileCache();

	// �����ɫ��̬�����ļ�
	bool loadRoleStaticDataFile(const char *path, const char *mode);
	// ��ȡ��ɫ��̬�����ļ�����
	const std::string* getRoleStaticDataFile();
	// �ͷŽ�ɫ��̬�����ļ�
	void closeRoleStaticDataFile();

	// ���뼼�ܿ���̬�����ļ�
	bool loadCardSkillStaticDataFile(const char *path, const char *mode);
	// ��ȡ���ܿ���̬�����ļ�����
	const std::string* getCardSkillStaticDataFile();
	// �ͷż��ܿ���̬�����ļ�
	void closeCardSkillStaticDataFile();
};

#endif	// MZNQA_CLASSES_FILEIO_FILECACHE_H_