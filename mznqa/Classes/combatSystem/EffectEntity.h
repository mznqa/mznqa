#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTENTITY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTENTITY_H_

#include <functional>

struct EffectEntity
{
	// Ч���ּ�
	int level;

	// Ч������ָ��
	std::function<bool(int*, int)> fun;
	// ��������:
	int *arr;
	int size;

	EffectEntity(int level, std::function<bool(int*, int)> fun, int *arr, int size)
	{
		this->level = level;
		this->fun = fun;
		this->arr = arr;
		this->size = size;
	}

	bool operator<(const EffectEntity &rhs) const
	{
		return this->level < rhs.level;
	}

	bool operator>(const EffectEntity &rhs) const
	{
		return this->level > rhs.level;
	}
};

#endif
