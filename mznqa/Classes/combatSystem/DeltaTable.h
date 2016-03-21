#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_


enum EffectObject { Role, Monster };

struct DeltaTable
{

	//技能接收者
	EffectObject recver;

	//技能释放者
	EffectObject releaser;
	
	//释放该技能所在的回合
	int round;

	//技能ID
	int effectId;

	//技能影响的基础效果
	int effectTable[5][2] = { 0 };

};

struct TableRound 
{
	//所在回合
	int round;

	//单回合内的效果变化表
	int deltaTableRound[5][2];
};


#endif
