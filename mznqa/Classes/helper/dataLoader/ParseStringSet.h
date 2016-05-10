/*!
 * \file	Classes\helper\dataLoader\ParseStringSet.h
 *
 * \brief	������ ParseStringSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_DATALOADER_PARSESTRINGSET_H_
#define MZNQA_CLASSES_HELPER_DATALOADER_PARSESTRINGSET_H_

#include <map>
#include <string>

/*!
 * \class	ParseStringSet
 *
 * \brief	���ڽ����ַ��������ļ�
 *
 */
class ParseStringSet
{
private:

	/*!
	 * \fn	ParseStringSet::ParseStringSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	ParseStringSet()
	{
	}

	/*!
	 * \fn	ParseStringSet::ParseStringSet(const ParseStringSet &parseStringSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	ParseStringSet(const ParseStringSet &parseStringSet);

	/*!
	 * \fn	ParseStringSet& ParseStringSet::operator=(const ParseStringSet &parseStringSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	ParseStringSet& operator=(const ParseStringSet &parseStringSet);
public:

	/*!
	 * \fn	ParseStringSet::~ParseStringSet()
	 *
	 * \brief	��������
	 *
	 */
	~ParseStringSet()
	{
	}

	/*!
	 * \fn	static bool ParseStringSet::parse(const char *const data);
	 *
	 * \brief	ִ�н���
	 *
	 * \param	data	ָ���ļ�����
	 *
	 * \return	�����Ƿ�����ɹ�
	 */
	static bool parse(const char *const data);

	/*! \brief	�������������� */
	static std::map<int, std::string> bufferStringSet;
};
#endif
