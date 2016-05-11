/*!
 * \file	Classes\helper\fileManager\FileManager.h
 *
 * \brief	定义类 FileManager
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_FILEMANAGER_FILEMANAGER_H_
#define MZNQA_CLASSES_HELPER_FILEMANAGER_FILEMANAGER_H_

#include <string>

/*!
 * \class	FileManager
 *
 * \brief	[单例]文件管理器，由于读取写入文件，以及处理文件夹
 *
 */
class FileManager
{
private:

	/*!
	 * \fn	FileManager::FileManager()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	FileManager()
	{
	}

	/*!
	 * \fn	FileManager::FileManager(const FileManager &fileManager);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	FileManager(const FileManager &fileManager);

	/*!
	 * \fn	FileManager& FileManager::operator=(const FileManager &fileManager);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	FileManager& operator=(const FileManager &fileManager);
public:

	/*!
	 * \fn	FileManager::~FileManager()
	 *
	 * \brief	析构函数
	 *
	 */
	~FileManager()
	{
	}

	/*!
	 * \fn	static FileManager* FileManager::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static FileManager* Instance();

	/*!
	 * \fn	char *const FileManager::getDataFromFile(const std::string& fileName)const;
	 *
	 * \brief	从指定文件中载入数据
	 *
	 * \param	fileName	指定文件路径及文件名
	 *
	 * \return	以 char*const 作为文件数据返回，并记得用 free() 进行释放
	 */
	char *const getDataFromFile(const std::string& fileName)const;
};

#endif
