#ifndef MZNQA_CLASSES_FILEIO_FILECACHE_H_
#define MZNQA_CLASSES_FILEIO_FILECACHE_H_

#include <cstdio>

// 用于缓存文件
class FileCache
{
private:
	FileCache(){}
	FileCache(const FileCache &fileCache);
	FileCache& operator=(const FileCache &FileCache);

	// 存放角色静态数据缓存
	FILE *roleStaticData;
public:
	static FileCache* Instance();
	~FileCache();

	// 载入角色静态数据文件
	bool loadRoleStaticDataFile(const char *path, const char *mode);
	// 获取角色静态数据文件减缓
	FILE** getRoleStaticDataFile();
	// 释放角色静态数据文件
	bool closeRoleStaticDataFile();
};

#endif	// MZNQA_CLASSES_FILEIO_FILECACHE_H_