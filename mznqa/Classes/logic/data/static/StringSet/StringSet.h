/*!
 * \file	Classes\logic\data\static\StringSet\StringSet.h
 *
 * \brief	������ StringSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_STRINGTABLE_STRINGSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_STRINGTABLE_STRINGSET_H_

#include <string>

#include "common/arkca/stringTable/StringTable.h"

/*!
 * \class	StringSet
 *
 * \brief	��̬���ݣ��ַ�������
 *
 */
class StringSet
{
public:

	/*!
	 * \fn	StringSet::~StringSet()
	 *
	 * \brief	��������
	 *
	 */
	~StringSet()
	{
	}

	/*!
	 * \fn	static StringSet* StringSet::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static StringSet* Instance();

	/*!
	 * \enum	StringID
	 *
	 * \brief	ö��ָ��ָ���ַ�����ID
	 */
	enum StringID
	{
		StringID_Null = 0,		///< ���ַ���
		StringID_GameName = 1	///< ��Ϸ����
	};

	/*!
	 * \fn	void StringSet::init(const std::map<int, std::string> &stringSet);
	 *
	 * \brief	��ʼ���ַ���
	 *
	 * \param	stringSet	ָ���ⲿ�ַ���������
	 */
	void init(const std::map<int, std::string> &stringSet);

	/*!
	 * \fn	void StringSet::clear();
	 *
	 * \brief	����ַ�������
	 *
	 */
	void clear();

	/*!
	 * \fn	const std::string *const StringSet::getString(StringID stringID);
	 *
	 * \brief	��ȡָ��ID��Ӧ���ַ���
	 *
	 * \param	stringID	ָ���ַ���ID
	 *
	 */
	const std::string *const getString(StringID stringID);

private:

	/*!
	 * \fn	StringSet::StringSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	StringSet()
	{
	}

	/*!
	 * \fn	StringSet::StringSet(const StringSet &stringSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	StringSet(const StringSet &stringSet);

	/*!
	 * \fn	StringSet& StringSet::operator=(const StringSet &stringSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	StringSet& operator=(const StringSet &stringSet);

	/*! \brief	�ڽ��ַ����� */
	ArKCa::StringTable stringTable;
};

#endif
