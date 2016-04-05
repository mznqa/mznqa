/*!
 * \file	Classes\engine\FileController.h
 *
 * \brief	������ FileController
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_
#define MZNQA_CLASSES_ENGINE_FILECONTROLLER_H_

#include <string>
#include <memory>

/*!
 * \class	FileController
 *
 * \brief	�����������ļ�����
 *
 */
class FileController
{
private:

	/*!
	 * \fn	FileController::FileController()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	FileController(){}

	/*!
	 * \fn	FileController::FileController(const FileController& fileController);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	fileController	FileController ʵ��
	 */
	FileController(const FileController& fileController);

	/*!
	 * \fn	FileController& FileController::operator=(const FileController& fileController);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	fileController	FileController ʵ��
	 *
	 * \return	FileController ʵ��
	 */
	FileController& operator=(const FileController& fileController);
public:

	/*!
	 * \fn	static FileController* FileController::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static FileController* Instance();

	/*!
	 * \fn	FileController::~FileController();
	 *
	 * \brief	��������
	 *
	 */
	~FileController();

	/*!
	 * \fn	char* FileController::getCharBufferFromFile(const std::string& fileName);
	 *
	 * \brief	���ļ��ж�ȡ�ַ����棨free()�ͷţ�ƽ̨����ԣ�
	 *
	 * \param	fileName	ָ���ļ���
	 *
	 * \return	�����ַ�����
	 */
	char* getCharBufferFromFile(const std::string& fileName);

	/*!
	 * \fn	char* FileController::getCharBufferFromFile(const std::string& fileName, int& bufferSize);
	 *
	 * \brief	���ļ��ض�ȡ�ַ����棨free()�ͷţ�ƽ̨����ԣ�
	 *
	 * \param	fileName		  	ָ���ļ���
	 * \param [in,out]	bufferSize	���ڻ�ȡ�ַ�����Ĵ�С
	 *
	 * \return	�����ַ�����
	 */
	char* getCharBufferFromFile(const std::string& fileName, int& bufferSize);

	void test();
};

#endif
