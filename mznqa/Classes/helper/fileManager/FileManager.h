/*!
 * \file	Classes\helper\fileManager\FileManager.h
 *
 * \brief	������ FileManager
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_FILEMANAGER_FILEMANAGER_H_
#define MZNQA_CLASSES_HELPER_FILEMANAGER_FILEMANAGER_H_

#include <string>

/*!
 * \class	FileManager
 *
 * \brief	[����]�ļ������������ڶ�ȡд���ļ����Լ������ļ���
 *
 */
class FileManager
{
private:

	/*!
	 * \fn	FileManager::FileManager()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	FileManager()
	{
	}

	/*!
	 * \fn	FileManager::FileManager(const FileManager &fileManager);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	FileManager(const FileManager &fileManager);

	/*!
	 * \fn	FileManager& FileManager::operator=(const FileManager &fileManager);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	FileManager& operator=(const FileManager &fileManager);
public:

	/*!
	 * \fn	FileManager::~FileManager()
	 *
	 * \brief	��������
	 *
	 */
	~FileManager()
	{
	}

	/*!
	 * \fn	static FileManager* FileManager::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static FileManager* Instance();

	/*!
	 * \fn	char *const FileManager::getDataFromFile(const std::string& fileName)const;
	 *
	 * \brief	��ָ���ļ�����������
	 *
	 * \param	fileName	ָ���ļ�·�����ļ���
	 *
	 * \return	�� char*const ��Ϊ�ļ����ݷ��أ����ǵ��� releaseData() �����ͷ�
	 */
	char *const getDataFromFile(const std::string& fileName)const;

	/*!
	 * \fn	static void FileManager::releaseData(char *data)
	 *
	 * \brief	�����ͷ��� FileManager ���������
	 *
	 * \param [in,out]	data	ָ���� FileManager �������Դ
	 */
	static void releaseData(char *data)
	{
		free(data);
		data = nullptr;
	}
};

#endif
