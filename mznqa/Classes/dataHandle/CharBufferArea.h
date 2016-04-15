/*!
 * \file	Classes\dataHandle\CharBufferArea.h
 *
 * \brief	������ CharBufferArea
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_
#define MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_

#include <map>

/*!
 * \class	CharBufferArea
 *
 * \brief	���������ڴ���ַ�����
 *
 */
class CharBufferArea
{
private:

	/*!
	 * \fn	CharBufferArea::CharBufferArea()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CharBufferArea(){}

	/*!
	 * \fn	CharBufferArea::CharBufferArea(const CharBufferArea&);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	charBufferArea	CharBufferArea ʵ��
	 */
	CharBufferArea(const CharBufferArea& charBufferArea);

	/*!
	 * \fn	CharBufferArea& CharBufferArea::operator=(const CharBufferArea&);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	charBufferArea	CharBufferArea ʵ��
	 *
	 * \return	CharBufferArea ʵ��
	 */
	CharBufferArea& operator=(const CharBufferArea& charBufferArea);

	/*! \brief	����������ַ����� */
	std::map<int, char*> bufferSet;
public:

	/*!
	 * \enum	BufferIndex
	 *
	 * \brief	ö���ַ����������
	 */
	enum BufferIndex
	{
		// ��̬����-���� //////////////////////////////////////////////////////////////////////////
		BufferIndex_Static_CardSkillSet = 0,	///< ���ܿ��ַ�����
		BufferIndex_Static_CardTreasureSet = 1,	///< ���￨�ַ�����
		BufferIndex_Static_CardMonsterSet = 2,	///< ���ο��ַ�����
		//////////////////////////////////////////////////////////////////////////

		// ��̬����-��ͼ //////////////////////////////////////////////////////////////////////////
		BufferIndex_Static_MainMissionMap = 100,	///< ��̬���ݣ����������ͼ
		//////////////////////////////////////////////////////////////////////////

		// �浵-��ͼ //////////////////////////////////////////////////////////////////////////
		BufferIndex_Archives_GlobalMap = 200	///< ��ͼ�浵�ַ�����
		//////////////////////////////////////////////////////////////////////////
	};

	/*!
	 * \fn	static CharBufferArea* CharBufferArea::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static CharBufferArea* Instance();

	/*!
	 * \fn	CharBufferArea::~CharBufferArea();
	 *
	 * \brief	��������
	 *
	 */
	~CharBufferArea();

	/*!
	 * \fn	bool CharBufferArea::createBuffer(BufferIndex bufferIndex, char *buffer);
	 *
	 * \brief	������������ע�⣺����Ļ������ free() �����ͷţ�
	 *
	 * \param	bufferIndex   	ָ�����������
	 * \param [in,out]	buffer	�ַ�����
	 *
	 * \return	���ػ����Ƿ񴴽��ɹ�
	 */
	bool createBuffer(BufferIndex bufferIndex, char *buffer);

	/*!
	 * \fn	bool CharBufferArea::releaseBufferByIndex(BufferIndex bufferIndex);
	 *
	 * \brief	�ͷŻ�������ע�⣺ʹ�� free() �����ͷţ�
	 *
	 * \author	Yeshiyong
	 * \date	2016/4/5
	 *
	 * \param	bufferIndex	ָ�����������
	 *
	 * \return	���ػ����Ƿ��ͷųɹ�
	 */
	bool releaseBufferByIndex(BufferIndex bufferIndex);

	/*!
	 * \fn	void CharBufferArea::releaseAllBuffer();
	 *
	 * \brief	�ͷ����л���
	 *
	 */
	void releaseAllBuffer();

	/*!
	 * \fn	const char* CharBufferArea::getBufferByIndex(BufferIndex bufferIndex);
	 *
	 * \brief	��ȡָ��������Ӧ�Ļ�������ֻ�������ݶ��������ڸ����б���ֻ���ַ�����
	 *
	 * \param	bufferIndex	ָ�����������
	 *
	 * \return	���ػ���
	 */
	const char* getBufferByIndex(BufferIndex bufferIndex);

	// ��Ԫ����
	void test();
};

#endif
