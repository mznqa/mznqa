#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

struct DeltaTable
{

	enum EffectObject { Role, Monster };

	//技能接收者
	EffectObject recver;

	//技能释放者
	EffectObject releaser;

	//技能影响的基础效果
	int effectTable[5][2] = { 0 };
	 
};

#endif