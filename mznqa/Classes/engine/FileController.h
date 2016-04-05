/*!
 * \file	Classes\engine\FileController.h
 *
 * \brief	定义类 FileController
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_
#define MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_

#include <string>
#include <memory>

/*!
 * \class	FileController
 *
 * \brief	单例。用于文件操作
 *
 */
class FileController
{
private:

	/*!
	 * \fn	FileController::FileController()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	FileController(){}

	/*!
	 * \fn	FileController::FileController(const FileController& fileController);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	fileController	FileController 实例
	 */
	FileController(const FileController& fileController);

	/*!
	 * \fn	FileController& FileController::operator=(const FileController& fileController);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	fileController	FileController 实例
	 *
	 * \return	FileController 实例
	 */
	FileController& operator=(const FileController& fileController);
public:

	/*!
	 * \fn	static FileController* FileController::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static FileController* Instance();

	/*!
	 * \fn	FileController::~FileController();
	 *
	 * \brief	析构函数
	 *
	 */
	~FileController();

	/*!
	 * \fn	char* FileController::getCharBufferFromFile(const std::string& fileName);
	 *
	 * \brief	从文件中读取字符缓存（free()释放，平台相关性）
	 *
	 * \param	fileName	指定文件名
	 *
	 * \return	返回字符缓存
	 */
	char* getCharBufferFromFile(const std::string& fileName);

	/*!
	 * \fn	char* FileController::getCharBufferFromFile(const std::string& fileName, int& bufferSize);
	 *
	 * \brief	从文件重读取字符缓存（free()释放，平台相关性）
	 *
	 * \param	fileName		  	指定文件名
	 * \param [in,out]	bufferSize	用于获取字符缓存的大小
	 *
	 * \return	返回字符缓存
	 */
	char* getCharBufferFromFile(const std::string& fileName, int& bufferSize);

	void test();
};

#endif
