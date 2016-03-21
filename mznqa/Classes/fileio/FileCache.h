#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_FILEIO_FILECACHE_H_
#define MZNQA_CLASSES_FILEIO_FILECACHE_H_

#include <string>

// 用于缓存文件
class FileCache
{
private:
	FileCache(){}
	FileCache(const FileCache &fileCache);
	FileCache& operator=(const FileCache &FileCache);

	// 存放角色静态数据缓存
	std::string *roleStaticData;

	// 存放技能卡静态数据缓存
	std::string *cardSkillStaticData;
public:
	static FileCache* Instance();
	~FileCache();

	// 载入角色静态数据文件
	bool loadRoleStaticDataFile(const char *path, const char *mode);
	// 获取角色静态数据文件减缓
	const std::string* getRoleStaticDataFile();
	// 释放角色静态数据文件
	void closeRoleStaticDataFile();

	// 载入技能卡静态数据文件
	bool loadCardSkillStaticDataFile(const char *path, const char *mode);
	// 获取技能卡静态数据文件减缓
	const std::string* getCardSkillStaticDataFile();
	// 释放技能卡静态数据文件
	void closeCardSkillStaticDataFile();
};

#endif	// MZNQA_CLASSES_FILEIO_FILECACHE_H_