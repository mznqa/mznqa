#pragma execution_character_set("utf-8")

namespace ArKCa
{
	/*!
	 * \class	State
	 *
	 * \brief	Ϊ FiniteStateMachine �ṩ״̬��״̬����
	 *
	 * \tparam	Entity	״̬�����ߵ�����
	 */
	template<typename Entity>
	class State
	{
	public:

		/*!
		 * \fn	virtual State::~State()
		 *
		 * \brief	����������
		 *
		 */
		virtual ~State(){};

		/*!
		 * \fn	virtual bool State::enter(Entity *owner) = 0;
		 *
		 * \brief	����״̬ʱ�Ĳ���
		 *
		 * \param [in,out]	owner	ָ��״̬������
		 *
		 * \return	����ִ�гɹ����
		 *
		 */
		virtual bool enter(Entity *owner) = 0;

		/*!
		 * \fn	virtual bool State::update(Entity *owner, double intervalTime) = 0;
		 *
		 * \brief	ִ��״̬
		 *
		 * \param [in,out]	owner	ָ��״̬������
		 * \param	intervalTime 	ָ�����ϴβ���������������ʱ��
		 *
		 * \return	����ִ�гɹ����
		 */
		virtual bool update(Entity *owner, double intervalTime) = 0;

		/*!
		 * \fn	virtual bool State::exit(Entity *owner) = 0;
		 *
		 * \brief	�뿪״̬ʱ�Ĳ���
		 *
		 * \param [in,out]	owner	ָ��״̬��������
		 *
		 * \return	����ִ�гɹ����
		 */
		virtual bool exit(Entity *owner) = 0;
	};
}