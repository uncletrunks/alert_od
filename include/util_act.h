#ifndef	_ACT_
#define _ACT_

#define ACT_TOP 0
#define ACT_BOTTOM 1

#define ACTnextStep() actp->step++
#define ACTbackStep() actp->step--
#define ACTsetStep(num) actp->step = num
#define ACTexitStep() actp->step = CHR_EXIT

extern void ACTinit(void);
extern ACT *ACTsetTop(FUNC exec_adr, UINT8 group);
extern ACT *ACTsetBtm(FUNC exec_adr, UINT8 group);
extern void ACTexec(void);
extern void ACTclearAll(ACT *actp);
extern void ACTclear(ACT *actp);

extern ACT ActIndex[ACT_GROUP_MAX][2];
extern ACT ActBuf[ACT_MAX];
extern UINT ActEntCnt;

#endif /* _ACT_ */
