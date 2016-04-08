/*!
 * \file	Classes\dataHandle\StaticDataLoader.h
 *
 * \brief	������ StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_STATICDATALOADER_H_
#define MZNQA_CLASSES_DATAHANDLE_STATICDATALOADER_H_

/*!
 * \class	StaticDataLoader
 *
 * \brief	�������뾲̬�ļ�����
 *
 */
class StaticDataLoader
{
private:

	/*!
	 * \fn	StaticDataLoader::StaticDataLoader()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	StaticDataLoader(){}
public:

	/*!
	 * \fn	StaticDataLoader::~StaticDataLoader()
	 *
	 * \brief	��������
	 *
	 */
	~StaticDataLoader(){}

	/*!
	 * \fn	static void StaticDataLoader::loadStaticDataCardRoadSet();
	 *
	 * \brief	���뾲̬���ݣ����ο�����
	 *
	 */
	static void loadStaticDataCardRoadSet();

	/*!
	 * \fn	static void StaticDataLoader::loadStaticDataCardSkillSet();
	 *
	 * \brief	���뾲̬���ݣ����ܿ�����
	 *
	 */
	static void loadStaticDataCardSkillSet();
};

#endif