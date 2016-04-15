/*!
 * \file	Classes\dataHandle\CharBufferArea.h
 *
 * \brief	定义类 CharBufferArea
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_
#define MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_

#include <map>

/*!
 * \class	CharBufferArea
 *
 * \brief	单例。用于存放字符缓冲
 *
 */
class CharBufferArea
{
private:

	/*!
	 * \fn	CharBufferArea::CharBufferArea()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CharBufferArea(){}

	/*!
	 * \fn	CharBufferArea::CharBufferArea(const CharBufferArea&);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	charBufferArea	CharBufferArea 实例
	 */
	CharBufferArea(const CharBufferArea& charBufferArea);

	/*!
	 * \fn	CharBufferArea& CharBufferArea::operator=(const CharBufferArea&);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	charBufferArea	CharBufferArea 实例
	 *
	 * \return	CharBufferArea 实例
	 */
	CharBufferArea& operator=(const CharBufferArea& charBufferArea);

	/*! \brief	按索引存放字符缓存 */
	std::map<int, char*> bufferSet;
public:

	/*!
	 * \enum	BufferIndex
	 *
	 * \brief	枚举字符缓存的索引
	 */
	enum BufferIndex
	{
		// 静态数据-卡牌 //////////////////////////////////////////////////////////////////////////
		BufferIndex_Static_CardSkillSet = 0,	///< 技能卡字符缓存
		BufferIndex_Static_CardTreasureSet = 1,	///< 宝物卡字符缓存
		BufferIndex_Static_CardMonsterSet = 2,	///< 地形卡字符缓存
		//////////////////////////////////////////////////////////////////////////

		// 静态数据-地图 //////////////////////////////////////////////////////////////////////////
		BufferIndex_Static_MainMissionMap = 100,	///< 静态数据：主线任务地图
		//////////////////////////////////////////////////////////////////////////

		// 存档-地图 //////////////////////////////////////////////////////////////////////////
		BufferIndex_Archives_GlobalMap = 200	///< 地图存档字符缓存
		//////////////////////////////////////////////////////////////////////////
	};

	/*!
	 * \fn	static CharBufferArea* CharBufferArea::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static CharBufferArea* Instance();

	/*!
	 * \fn	CharBufferArea::~CharBufferArea();
	 *
	 * \brief	析构函数
	 *
	 */
	~CharBufferArea();

	/*!
	 * \fn	bool CharBufferArea::createBuffer(BufferIndex bufferIndex, char *buffer);
	 *
	 * \brief	创建缓冲区（注意：传入的缓存仅由 free() 进行释放）
	 *
	 * \param	bufferIndex   	指定缓存的索引
	 * \param [in,out]	buffer	字符缓存
	 *
	 * \return	返回缓存是否创建成功
	 */
	bool createBuffer(BufferIndex bufferIndex, char *buffer);

	/*!
	 * \fn	bool CharBufferArea::releaseBufferByIndex(BufferIndex bufferIndex);
	 *
	 * \brief	释放缓冲区（注意：使用 free() 进行释放）
	 *
	 * \author	Yeshiyong
	 * \date	2016/4/5
	 *
	 * \param	bufferIndex	指定缓存的索引
	 *
	 * \return	返回缓存是否释放成功
	 */
	bool releaseBufferByIndex(BufferIndex bufferIndex);

	/*!
	 * \fn	void CharBufferArea::releaseAllBuffer();
	 *
	 * \brief	释放所有缓存
	 *
	 */
	void releaseAllBuffer();

	/*!
	 * \fn	const char* CharBufferArea::getBufferByIndex(BufferIndex bufferIndex);
	 *
	 * \brief	获取指定索引对应的缓冲区（只读），暂定仅允许在该类中保存只读字符缓存
	 *
	 * \param	bufferIndex	指定缓存的索引
	 *
	 * \return	返回缓存
	 */
	const char* getBufferByIndex(BufferIndex bufferIndex);

	// 单元测试
	void test();
};

#endif
