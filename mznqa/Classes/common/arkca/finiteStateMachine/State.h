#pragma execution_character_set("utf-8")

namespace ArKCa
{
	/*!
	 * \class	State
	 *
	 * \brief	为 FiniteStateMachine 提供状态的状态基类
	 *
	 * \tparam	Entity	状态持有者的类型
	 */
	template<typename Entity>
	class State
	{
	public:

		/*!
		 * \fn	virtual State::~State()
		 *
		 * \brief	虚析构函数
		 *
		 */
		virtual ~State(){};

		/*!
		 * \fn	virtual bool State::enter(Entity *owner) = 0;
		 *
		 * \brief	进入状态时的操作
		 *
		 * \param [in,out]	owner	指定状态所有者
		 *
		 * \return	返回执行成功与否
		 *
		 */
		virtual bool enter(Entity *owner) = 0;

		/*!
		 * \fn	virtual bool State::update(Entity *owner, double intervalTime) = 0;
		 *
		 * \brief	执行状态
		 *
		 * \param [in,out]	owner	指定状态所有者
		 * \param	intervalTime 	指定自上次操作以来所经历的时间
		 *
		 * \return	返回执行成功与否
		 */
		virtual bool update(Entity *owner, double intervalTime) = 0;

		/*!
		 * \fn	virtual bool State::exit(Entity *owner) = 0;
		 *
		 * \brief	离开状态时的操作
		 *
		 * \param [in,out]	owner	指定状态的所有者
		 *
		 * \return	返回执行成功与否
		 */
		virtual bool exit(Entity *owner) = 0;
	};
}