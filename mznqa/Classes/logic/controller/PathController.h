/*!
 * \file	Classes\logic\controller\PathController.h
 *
 * \brief	定义类 PathController
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
 * \brief	[单例]路径控制器
 *
 */
class PathController
{
public:

	/*!
	 * \enum	State
	 *
	 * \brief	状态
	 */
	enum State
	{
		State_Idle,		///< 空闲中
		State_Ready,	///< 已准备好
		State_Working,	///< 工作中
		State_Done		///< 已完成
	};

	/*! \brief	无效的坐标值 */
	static const ArKCa::Vector2<int> invalidPosition;

	/*!
	 * \fn	PathController::~PathController()
	 *
	 * \brief	析构函数
	 *
	 */
	~PathController()
	{
	}

	/*!
	 * \fn	static PathController* PathController::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static PathController* Instance();

	/*!
	 * \fn	State PathController::getCurrentState()const
	 *
	 * \brief	获取当前状态
	 *
	 */
	State getCurrentState()const
	{
		return state;
	}

	/*!
	 * \fn	void PathController::ready( const ArKCa::Vector2<int> &startPosition, const ArKCa::Vector2<int> &goalPosition );
	 *
	 * \brief	准备开始规划路径
	 *
	 * \param	startPosition	指定起始点
	 * \param	goalPosition 	指定目标点
	 */
	void ready(
		const ArKCa::Vector2<int> &startPosition,
		const ArKCa::Vector2<int> &goalPosition
		);

	/*!
	 * \fn	const ArKCa::Vector2<int>& PathController::getStartPosition()const
	 *
	 * \brief	获取待规划的路径的起始点
	 *
	 */
	const ArKCa::Vector2<int>& getStartPosition()const
	{
		return originPosition;
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& PathController::getGoalPosition()const
	 *
	 * \brief	获取待规划的路径的目标点
	 *
	 */
	const ArKCa::Vector2<int>& getGoalPosition()const
	{
		return targetPosition;
	}

	/*!
	 * \fn	void PathController::planning();
	 *
	 * \brief	逐步规划路径
	 *
	 */
	void planning();

	/*!
	 * \fn	ArKCa::Vector2<int> PathController::getNextStepByCurrentPosition(const ArKCa::Vector2<int> &currentPosition);
	 *
	 * \brief	指定当前坐标以获取下一步的坐标
	 *
	 * \param	currentPosition	指定当前坐标
	 *
	 * \return	返回下一步的坐标
	 */
	ArKCa::Vector2<int> getNextStepByCurrentPosition(const ArKCa::Vector2<int> &currentPosition);

private:

	/*!
	 * \fn	PathController::PathController()
	 *
	 * \brief	隐藏的构造函数
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
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	PathController(const PathController &pathController);

	/*!
	 * \fn	PathController& PathController::operator=(const PathController &pathController);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	PathController& operator=(const PathController &pathController);

	/*! \brief	当前状态 */
	State state;

	/*! \brief	存放待访问的最优点列表 */
	std::list<ArKCa::Vector2<int>> checkTable;
	/*! \brief	标识待访问的点 */
	std::vector<std::vector<bool>> openList;
	/*! \brief	标识以不再访问的店 */
	std::vector<std::vector<bool>> closeList;
	/*! \brief	记录所有点的f评估 */
	std::vector<std::vector<int>> fScore;
	/*! \brief	记录所有点的g评估 */
	std::vector<std::vector<int>> gScore;
	/*! \brief	记录所有点的来源点 */
	std::vector<std::vector<ArKCa::Vector2<int>>> edgeForm;
	/*! \brief	记录生成的路径 */
	std::list<ArKCa::Vector2<int>> path;

	/*! \brief	待规划的路径的起点 */
	ArKCa::Vector2<int> originPosition;
	/*! \brief	待规划的路径的中目标点 */
	ArKCa::Vector2<int> targetPosition;

	/*!
	 * \fn	void PathController::reset();
	 *
	 * \brief	重置路径规划
	 *
	 */
	void reset();

	/*!
	 * \fn	void PathController::insertCheckPoint(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	添加待检查点
	 *
	 */
	void insertCheckPoint(const ArKCa::Vector2<int> &position);

	/*!
	 * \fn	void PathController::updateCheckPoint(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	更新检查点
	 *
	 */
	void updateCheckPoint(const ArKCa::Vector2<int> &position);

	/*!
	 * \fn	void PathController::generatePath();
	 *
	 * \brief	生成路径
	 *
	 */
	void generatePath();

	/*!
	 * \fn	int PathController::getDist(const ArKCa::Vector2<int> &origin, const ArKCa::Vector2<int> &target)const
	 *
	 * \brief	获取两点间的距离
	 *
	 */
	int getDist(const ArKCa::Vector2<int> &origin, const ArKCa::Vector2<int> &target)const
	{
		return (abs(target.x - origin.x) + abs(target.y - origin.y));
	}
};

#endif
