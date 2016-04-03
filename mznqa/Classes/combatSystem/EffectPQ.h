#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <vector>

class EffectPQ
{
private:
	std::priority_queue<
		int,
		std::function<bool(const std::vector<int>&)>,
		std::less<int>
	> epq;
public:
	EffectPQ();
	~EffectPQ();
};

#endif
