#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATA_STATICDATA_EFFECTSET_H_
#define MZNQA_CLASSES_DATA_STATICDATA_EFFECTSET_H_

#include <map>
#include <functional>

class EffectSet
{
private:
	std::map<int, std::function<bool(int*, int)>> effectMap;
public:
	EffectSet();
	~EffectSet();

	static std::function<bool(int*, int)> getFunByEffectID(int id);

	// ����Ч���� //////////////////////////////////////////////////////////////////////////
	// ����Ч�� - Ӱ��Ѫ��
	// ����������Ѫ���仯��
	static bool effectBase1(int *arr, int size);

	// ����Ч�� - Ӱ�커��
	// �������������ױ仯��
	static bool effectBase2(int *arr, int size);

	// ����Ч�� - Ӱ��������
	// �������������Ʊ仯��
	static bool effectBase3(int *arr, int size);

	// ����Ч�� - Ӱ��غϳ�����
	// �����������غϳ������仯��
	static bool effectBase4(int *arr, int size);

	// ����Ч�� - Ӱ��غϳ�����
	// �����������غϳ������仯��
	static bool effectBase5(int *arr, int size);
	//////////////////////////////////////////////////////////////////////////

	// ����Ч������ //////////////////////////////////////////////////////////////////////////
	// ����Ч�� - ������Ч
	static bool effectSpecial1(int *arr, int size);

	// ����Ч�� - ��Ѫ��Ч
	static bool effectSpecial2(int *arr, int size);

	// ����Ч�� - �ؼ���Ч
	static bool effectSpecial3(int *arr, int size);
	//////////////////////////////////////////////////////////////////////////

	// ����Ч���� //////////////////////////////////////////////////////////////////////////
	// ����Ч�� - ��ǰ��Ѫ���Ƿ���[A]~[B]
	// ��������Χ���ޣ���Χ����
	static bool effectCondition1(int *arr, int size);

	// ����Ч�� - ��ǰ��Ѫ���Ƿ�С�ڵ���[A] ==> 1~[A]
	// ��������Χ����
	static bool effectCondition2(int *arr, int size);

	// ����Ч�� - ��ǰ��Ѫ���Ƿ����[A]
	// ����������ֵ
	static bool effectCondition3(int *arr, int size);

	// ����Ч�� - ��ǰ��Ѫ���Ƿ���ڵ���[A] ==> [A]~(Ѫ������)
	// ��������Χ����
	static bool effectCondition4(int *arr, int size);

	// ����Ч�� - ��ǰ�Ļ����Ƿ���[A]~[B]
	// ��������Χ���ޣ���Χ����
	static bool effectCondition5(int *arr, int size);

	// ����Ч�� - ��ǰ�Ļ����Ƿ�С�ڵ���[A] ==> 1~[A]
	// ��������Χ����
	static bool effectCondition6(int *arr, int size);

	// ����Ч�� - ��ǰ�Ļ����Ƿ����[A]
	// ����������ֵ
	static bool effectCondition7(int *arr, int size);

	// ����Ч�� - ��ǰ�Ļ����Ƿ���ڵ���[A] ==> [A]~(��������)
	// ��������Χ����
	static bool effectCondition8(int *arr, int size);

	// ����Ч�� - ��ǰ���������Ƿ���[A]~[B]
	// ��������Χ���ޣ���Χ����
	static bool effectCondition9(int *arr, int size);

	// ����Ч�� - ��ǰ���������Ƿ�С�ڵ���[A] ==> 1~[A]
	// ��������Χ����
	static bool effectCondition10(int *arr, int size);

	// ����Ч�� - ��ǰ���������Ƿ����[A]
	// ����������ֵ
	static bool effectCondition11(int *arr, int size);

	// ����Ч�� - ��ǰ���������Ƿ���ڵ���[A] ==> [A]~(����������)
	// ��������Χ����
	static bool effectCondition12(int *arr, int size);

	// ����Ч�� - �������һ��Ѫ������1~[A]
	// ��������Χ����
	static bool effectCondition13(int *arr, int size);

	// ����Ч�� - ��ǰ�غ����ҷ�ʹ�ü׷�Ѫ������
	static bool effectCondition14(int *arr, int size);
	//////////////////////////////////////////////////////////////////////////
};

#endif
