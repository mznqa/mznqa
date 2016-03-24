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

	// ��ŵ�ͼ��̬���ݻ���
	std::string *mapStaticData;

	// ��ŵ�ͼ�浵����
	std::string *mapArchivesData;
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

	// �����ͼ�浵�����ļ�
	bool loadMapArchivesDataFile(const char *path, const char *mode);
	// ��ȡ��ͼ�浵�����ļ�����
	const std::string* getMapArchivesDataFile();
	// �ͷŵ�ͼ�浵�����ļ�
	void closeMapArchivesDataFile();
};

#endif	// MZNQA_CLASSES_FILEIO_FILECACHE_H_