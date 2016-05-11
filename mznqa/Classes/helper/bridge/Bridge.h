/*!
 * \file	Classes\helper\bridge\Bridge.h
 *
 * \brief	������ Bridge
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE__H_
#define MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE__H_

#include "common/arkca/message/Message.h"
#include "logic/message/LogicMessagePQ.h"
#include "interactive/message/InteractiveMessagePQ.h"
#include "interactive/manager/TargetInfo.h"
#include "logic/core/CoreController.h"

/*!
 * \class	Bridge
 *
 * \brief	�����߼���ͽ�����֮��Ľ���
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

	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	LogicMessagePQ �������� */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	InteractiveMessagePQ �������� */
	InteractiveMessagePQ *const InteractiveMessagePQInstance = InteractiveMessagePQ::Instance();
	/*! \brief	TargetInfo �������� */
	TargetInfo *const TargetInfoInstance = TargetInfo::Instance();
	/*! \brief	Controller �������� */
	CoreController *const CoreControllerInstance = CoreController::Instance();
	//////////////////////////////////////////////////////////////////////////

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
	 * \fn	void Bridge::pushMessage2Logic(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);
	 *
	 * \brief	������Ϣ���߼���
	 *
	 * \param	message	ָ��һ�����������Ϣ
	 */
	void pushMessage2Logic(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);

	/*!
	 * \fn	void Bridge::pushMessage2Interactive(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
	 *
	 * \brief	������Ϣ��������
	 *
	 * \param	message	ָ��һ���߼�����Ϣ
	 */
	void pushMessage2Interactive(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);

	/*!
	 * \fn	Language Bridge::getLanguage()
	 *
	 * \brief	��ȡ��Ϸ��ʹ�õ�����
	 *
	 */
	Language getLanguage()
	{
		if (TargetInfoInstance->getLanguage() == TargetInfo::Language_Zh)
			return Language_Zh;
		else if (TargetInfoInstance->getLanguage() == TargetInfo::Language_En)
			return Language_En;
		else
			return Language_Zh;
	}
};

#endif
