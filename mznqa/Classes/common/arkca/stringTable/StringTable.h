/*!
 * \file	Classes\common\arkca\stringTable\StringTable.h
 *
 * \brief	������ ArKCa::StringTable
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_STRINGTABLE_STRINGTABLE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_STRINGTABLE_STRINGTABLE_H_

#include <map>
#include <string>

namespace ArKCa
{
	/*!
	 * \class	StringTable
	 *
	 * \brief	ID-�ַ�����ֵ�Ա�
	 *
	 */
	class StringTable
	{
	private:
		/*! \brief	�ڽ�ID-�ַ�����ֵ�� */
		std::map<int, std::string> strTable;
	public:

		/*!
		 * \fn	StringTable::StringTable()
		 *
		 * \brief	Ĭ�Ϲ��캯��
		 *
		 */
		StringTable()
		{
		}

		/*!
		 * \fn	StringTable::StringTable(const StringTable &stringTable);
		 *
		 * \brief	�������캯��
		 *
		 */
		StringTable(const StringTable &stringTable);

		/*!
		 * \fn	StringTable& StringTable::operator=(const StringTable &stringTable);
		 *
		 * \brief	������ֵ�����
		 *
		 */
		StringTable& operator=(const StringTable &stringTable);

		/*!
		 * \fn	StringTable::~StringTable()
		 *
		 * \brief	��������
		 *
		 */
		~StringTable()
		{
		}

		/*!
		 * \fn	void StringTable::swap(std::map<int, std::string> &stringTable)
		 *
		 * \brief	���ⲿת���ַ�����
		 *
		 * \param [in,out]	stringTable	���ID-�ַ�����ֵ�Ա�
		 */
		void swap(std::map<int, std::string> &stringTable)
		{
			this->clear();
			this->strTable.swap(stringTable);
		}

		/*!
		 * \fn	void StringTable::insert(int key, const std::string &value);
		 *
		 * \brief	�����ַ���ֵ��
		 *
		 * \param	key  	ָ����
		 * \param	value	ָ��ֵ
		 */
		void insert(int key, const std::string &value);

		/*!
		 * \fn	const std::string *const StringTable::get(int key)const;
		 *
		 * \brief	��ȡָ������Ӧ��ֵ
		 *
		 * \param	key	ָ����
		 *
		 * \return	���ض�Ӧ��ֵ
		 */
		const std::string *const get(int key)const;

		/*!
		 * \fn	void StringTable::clear();
		 *
		 * \brief	��ձ�
		 *
		 */
		void clear();

		/*!
		 * \fn	const std::map<int, std::string>::const_iterator StringTable::getIteratorBegin()const;
		 *
		 * \brief	��ȡ��ֵ�Ա����ʼ������
		 *
		 */
		const std::map<int, std::string>::const_iterator getIteratorBegin()const;

		/*!
		 * \fn	const std::map<std::string, std::string>::const_iterator StringTable::getIteratorEnd()const;
		 *
		 * \brief	��ȡ��ֵ�Ա����ֹ������
		 *
		 */
		const std::map<int, std::string>::const_iterator getIteratorEnd()const;

		/*!
		 * \fn	void StringTable::getIterator( std::map<int, std::string>::const_iterator &begin, std::map<int, std::string>::const_iterator &end )const;
		 *
		 * \brief	���ؼ�ֵ�Ա����ʼ����ֹ������
		 *
		 * \param	begin	ָ�����ڽ�����ʼ������
		 * \param	end  	ָ�����ڽ�����ֹ������
		 */
		void getIterator(
			std::map<int, std::string>::const_iterator &begin,
			std::map<int, std::string>::const_iterator &end
			)const;
	};
}

#endif