/*!
 * \file	Classes\helper\bridge\Bridge.h
 *
 * \brief	������ Bridge
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE_H_
#define MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE_H_

#include "common/arkca/message/Message.h"
#include "helper/messageInterpreter/MessageInterpreter.h"
#include "interactive/manager/TargetInfo.h"

/*!
 * \class	Bridge
 *
 * \brief	[����]�����߼���ͽ�����֮��Ľ���
 *
 */
class Bridge
{
private:

	/*!
	 * \fn	Bridge::Bridge();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	Bridge();

	/*!
	 * \fn	Bridge::Bridge(const Bridge &bridge);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	Bridge(const Bridge &bridge);

	/*!
	 * \fn	Bridge& Bridge::operator=(const Bridge &bridge);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	Bridge& operator=(const Bridge &bridge);

public:

	/*!
	 * \fn	Bridge::~Bridge();
	 *
	 * \brief	��������
	 *
	 */
	~Bridge();

	/*!
	 * \fn	static Bridge* Bridge::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static Bridge* Instance();

	/*!
	* \enum	Language
	*
	* \brief	ö����Ϸ�е�����
	*/
	enum Language
	{
		Language_Zh,	///< ����
		Language_En		///< Ӣ��
	};

	/*!
	 * \fn	bool Bridge::update(double intervalTime);
	 *
	 * \brief	���������߼���
	 *
	 * \param	intervalTime	���ϴε���������������ʱ��
	 *
	 * \return	����ִ�гɹ����
	 */
	bool update(double intervalTime);

	/*!
	 * \fn	void Bridge::pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID);
	 *
	 * \brief	������Ϣ���߼���
	 *
	 * \param	messageID	ָ��һ����������ϢID
	 */
	void pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID);

	/*!
	 * \fn	template <typename ExtrasType> void Bridge::pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	������Ϣ���߼���
	 *
	 * \param	messageID	ָ��һ����������ϢID
	 * \param	extras   	ָ��һ������ֵ
	 */
	template <typename ExtrasType>
	void pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	{
		LogicMessagePQ::Instance()->pushMessage(MessageInterpreter::interpret(messageID, extras));
	}

	/*!
	 * \fn	void Bridge::pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID);
	 *
	 * \brief	������Ϣ��������
	 *
	 * \param	messageID	ָ��һ���߼�����ϢID
	 */
	void pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID);

	/*!
	 * \fn	template <typename ExtrasType> void Bridge::pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	������Ϣ��������
	 *
	 * \param	messageID	ָ��һ���߼�����ϢID
	 * \param	extras	  	ָ��һ������ֵ
	 */
	template <typename ExtrasType>
	void pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	{
		InteractiveMessagePQ::Instance()->pushMessage(MessageInterpreter::interpret(messageID, extras));
	}

	/*!
	 * \fn	Language Bridge::getLanguage()
	 *
	 * \brief	��ȡ��Ϸ��ʹ�õ�����
	 *
	 */
	Language getLanguage()
	{
		if (TargetInfo::Instance()->getLanguage() == TargetInfo::Language_Zh)
			return Language_Zh;
		else if (TargetInfo::Instance()->getLanguage() == TargetInfo::Language_En)
			return Language_En;
		else
			return Language_Zh;
	}
};

#endif
