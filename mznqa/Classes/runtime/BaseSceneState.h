#ifndef MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_
#define MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_

// ����״̬�Ļ���
// �����������Ӧ��д��enter()��update()��exit()��������
template <typename SceneType>
class BaseSceneState
{
public:
	BaseSceneState(){}
	virtual ~BaseSceneState(){}
	// ����״̬ǰ�Ĳ���
	virtual bool enter(SceneType *scene) = 0;
	// ״ִ̬��ʱ�Ĳ���
	virtual bool update(SceneType *scene, double intervalTime) = 0;
	// �뿪״̬ǰ�Ĳ���
	virtual bool exit(SceneType *Scene) = 0;
};

#endif