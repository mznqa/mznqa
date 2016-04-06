/*!
 * \file	Classes\dataHandle\ParserCardSkill.h
 *
 * \brief	定义类 ParserCardSkill
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_PARSERCARDSKILL_H_
#define MZNQA_CLASSES_DATAHANDLE_PARSERCARDSKILL_H_

/*!
 * \class	ParserCardSkill
 *
 * \brief	用于解析技能卡数据文件
 *
 */
class ParserCardSkill
{
private:

public:

	/*!
	 * \fn	ParserCardSkill::ParserCardSkill();
	 *
	 * \brief	构造函数
	 *
	 */
	ParserCardSkill();

	/*!
	 * \fn	ParserCardSkill::~ParserCardSkill();
	 *
	 * \brief	析构函数
	 *
	 */

	~ParserCardSkill();

	/*!
	 * \fn	void ParserCardSkill::parse();
	 *
	 * \brief	解析
	 *
	 */
	void parse();
};

#endif
