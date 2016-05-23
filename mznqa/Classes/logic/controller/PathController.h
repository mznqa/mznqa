/*!
 * \file	Classes\logic\controller\PathController.h
 *
 * \brief	������ PathController
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CONTROLLER_PATHCONTROLLER_H_
#define MZNQA_CLASSES_LOGIC_CONTROLLER_PATHCONTROLLER_H_

#include <vector>
#include <list>

#include "common/arkca/Vector2.h"

/*!
 * \class	PathController
 *
 * \brief	[����]·��������
 *
 */
class PathController
{
public:

	/*!
	 * \enum	State
	 *
	 * \brief	״̬
	 */
	enum State
	{
		State_Idle,		///< ������
		State_Ready,	///< ��׼����
		State_Working,	///< ������
		State_Done		///< �����
	};

	/*! \brief	��Ч������ֵ */
	static const ArKCa::Vector2<int> invalidPosition;

	/*!
	 * \fn	PathController::~PathController()
	 *
	 * \brief	��������
	 *
	 */
	~PathController()
	{
	}

	/*!
	 * \fn	static PathController* PathController::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static PathController* Instance();

	/*!
	 * \fn	State PathController::getCurrentState()const
	 *
	 * \brief	��ȡ��ǰ״̬
	 *
	 */
	State getCurrentState()const
	{
		return state;
	}

	/*!
	 * \fn	void PathController::ready( const ArKCa::Vector2<int> &startPosition, const ArKCa::Vector2<int> &goalPosition );
	 *
	 * \brief	׼����ʼ�滮·��
	 *
	 * \param	startPosition	ָ����ʼ��
	 * \param	goalPosition 	ָ��Ŀ���
	 */
	void ready(
		const ArKCa::Vector2<int> &startPosition,
		const ArKCa::Vector2<int> &goalPosition
		);

	/*!
	 * \fn	const ArKCa::Vector2<int>& PathController::getStartPosition()const
	 *
	 * \brief	��ȡ���滮��·������ʼ��
	 *
	 */
	const ArKCa::Vector2<int>& getStartPosition()const
	{
		return originPosition;
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& PathController::getGoalPosition()const
	 *
	 * \brief	��ȡ���滮��·����Ŀ���
	 *
	 */
	const ArKCa::Vector2<int>& getGoalPosition()const
	{
		return targetPosition;
	}

	/*!
	 * \fn	void PathController::planning();
	 *
	 * \brief	�𲽹滮·��
	 *
	 */
	void planning();

	/*!
	 * \fn	ArKCa::Vector2<int> PathController::getNextStepByCurrentPosition(const ArKCa::Vector2<int> &currentPosition);
	 *
	 * \brief	ָ����ǰ�����Ի�ȡ��һ��������
	 *
	 * \param	currentPosition	ָ����ǰ����
	 *
	 * \return	������һ��������
	 */
	ArKCa::Vector2<int> getNextStepByCurrentPosition(const ArKCa::Vector2<int> &currentPosition);

private:

	/*!
	 * \fn	PathController::PathController()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	PathController() :
		state(State_Idle),
		checkTable(),
		openList(),
		closeList(),
		fScore(),
		gScore(),
		edgeForm(),
		path(),
		originPosition(invalidPosition),
		targetPosition(invalidPosition)
	{
	}

	/*!
	 * \fn	PathController::PathController(const PathController &pathController);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	PathController(const PathController &pathController);

	/*!
	 * \fn	PathController& PathController::operator=(const PathController &pathController);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	PathController& operator=(const PathController &pathController);

	/*! \brief	��ǰ״̬ */
	State state;

	/*! \brief	��Ŵ����ʵ����ŵ��б� */
	std::list<ArKCa::Vector2<int>> checkTable;
	/*! \brief	��ʶ�����ʵĵ� */
	std::vector<std::vector<bool>> openList;
	/*! \brief	��ʶ�Բ��ٷ��ʵĵ� */
	std::vector<std::vector<bool>> closeList;
	/*! \brief	��¼���е��f���� */
	std::vector<std::vector<int>> fScore;
	/*! \brief	��¼���е��g���� */
	std::vector<std::vector<int>> gScore;
	/*! \brief	��¼���е����Դ�� */
	std::vector<std::vector<ArKCa::Vector2<int>>> edgeForm;
	/*! \brief	��¼���ɵ�·�� */
	std::list<ArKCa::Vector2<int>> path;

	/*! \brief	���滮��·������� */
	ArKCa::Vector2<int> originPosition;
	/*! \brief	���滮��·������Ŀ��� */
	ArKCa::Vector2<int> targetPosition;

	/*!
	 * \fn	void PathController::reset();
	 *
	 * \brief	����·���滮
	 *
	 */
	void reset();

	/*!
	 * \fn	void PathController::insertCheckPoint(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	��Ӵ�����
	 *
	 */
	void insertCheckPoint(const ArKCa::Vector2<int> &position);

	/*!
	 * \fn	void PathController::updateCheckPoint(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	���¼���
	 *
	 */
	void updateCheckPoint(const ArKCa::Vector2<int> &position);

	/*!
	 * \fn	void PathController::generatePath();
	 *
	 * \brief	����·��
	 *
	 */
	void generatePath();

	/*!
	 * \fn	int PathController::getDist(const ArKCa::Vector2<int> &origin, const ArKCa::Vector2<int> &target)const
	 *
	 * \brief	��ȡ�����ľ���
	 *
	 */
	int getDist(const ArKCa::Vector2<int> &origin, const ArKCa::Vector2<int> &target)const
	{
		return (abs(target.x - origin.x) + abs(target.y - origin.y));
	}
};

#endif
