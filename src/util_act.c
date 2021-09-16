
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/util_act.h"
#include <memory.h>

void ACTinit(void);
ACT *ACTsetTop(FUNC exec_adr, UINT8 group);
ACT *ACTsetBtm(FUNC exec_adr, UINT8 group);
void ACTexec(void);
void ACTclearAll(ACT *actp);
void ACTclear(ACT *actp);

ACT ActIndex[ACT_GROUP_MAX][2];
ACT ActBuf[ACT_MAX];
UINT ActEntCnt;

static ACT *ActEmptyptr;

void ACTinit(void)
{
	int i;

	for(i = 0; i < ACT_MAX - 1; i++){
		ActBuf[i].emptr = &(ActBuf[i + 1]);
	}

	ActEmptyptr = ActBuf;
	ActBuf[ACT_MAX - 1].emptr = NULL;

	for(i = 0; i < ACT_GROUP_MAX; i++){
		ActIndex[i][ACT_TOP].prev_act = NULL;
		ActIndex[i][ACT_TOP].next_act = &(ActIndex[i][ACT_BOTTOM]);
		ActIndex[i][ACT_BOTTOM].prev_act = &(ActIndex[i][ACT_TOP]);
		ActIndex[i][ACT_BOTTOM].next_act = NULL;
	}
}

ACT *ACTsetTop(FUNC exec_adr, UINT8 group)
{
	ACT		*actp;

	if(ActEmptyptr){
		actp = ActEmptyptr;
		ActEmptyptr = actp->emptr;
		memset(actp,0,sizeof(ACT));
		actp->prog_adr = exec_adr;
		actp->group_no = group;
		actp->prev_act = &(ActIndex[group][ACT_TOP]);
		actp->next_act = ActIndex[group][ACT_TOP].next_act;
		actp->prev_act->next_act = actp;
		actp->next_act->prev_act = actp;
		actp->chr_flag = f_none;
		return actp;
	}

	return NULL;
}

ACT *ACTsetBtm(FUNC exec_adr, UINT8 group)
{
	ACT *actp;

	if(ActEmptyptr){
		actp = ActEmptyptr;
		ActEmptyptr = actp->emptr;
		memset(actp,0,sizeof(ACT));
		actp->prog_adr = exec_adr;
		actp->group_no = group;
		actp->prev_act = ActIndex[group][ACT_BOTTOM].prev_act;
		actp->next_act = &(ActIndex[group][ACT_BOTTOM]);
		actp->prev_act->next_act = actp;
		actp->next_act->prev_act = actp;
		actp->chr_flag = f_none;
		return actp;
	}

	return NULL;
}

void ACTexec(void)
{
	ACT *actp;
	int i, j;

	for(i = 0, j = 0; i < ACT_GROUP_MAX; i++){
		for(actp = ActIndex[i][ACT_TOP].next_act;
			actp != &(ActIndex[i][ACT_BOTTOM]);
			actp = actp->next_act){
			j++;
			if(actp->actid & FLG_PAUSE){
				continue;
			}
			actp->prog_adr(actp);
		}
	}

	ActEntCnt = j;
}

void ACTclearAll(ACT *actp)
{
	ACT *eactp;
	int i;

	for(i = 0; i < ACT_GROUP_MAX; i++){
		for(eactp = ActIndex[i][ACT_TOP].next_act;
			eactp != &(ActIndex[i][ACT_BOTTOM]);
			eactp = eactp->next_act){
			if(actp != eactp && !(eactp->actid & FLG_SYSTEM)){
				ACTclear(eactp);
			}
		}
	}
}

void ACTclear(ACT *actp)
{
	ACT *prev;
	ACT *next;

	prev = actp->next_act->prev_act = actp->prev_act;
	next = actp->prev_act->next_act = actp->next_act;
	memset(actp,0,sizeof(ACT));
	actp->emptr = ActEmptyptr;
	ActEmptyptr = actp;
	actp->prev_act = prev;
	actp->next_act = next;
}
