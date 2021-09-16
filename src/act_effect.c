
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/act.h"
#include "../include/block.h"
#include "../include/dconv.h"
#include "../include/work.h"

#include "../include/act_main.h"

void ACTeffectDamage(ACT *actp);

static void ACTeffectType1(ACT *actp);
static void ACTeffectType2(ACT *actp);
static void ACTeffectType3(ACT *actp);
static void ACTeffectType4(ACT *actp);

void ACTeffectDamage(ACT *actp)
{
	ACT *eactp;
	SINT i;

	switch(actp->step){
		case CHR_INIT:
			ACTnextStep();
		case CHR_MAIN:
			switch(actp->type){
				case 0:
					if((eactp = ACTsetTop(ACTeffectType1, GROUP_06))){
						eactp->pos[X] = actp->pos[X];
						eactp->pos[Y] = actp->pos[Y];
						eactp->prog_adr(eactp);
						actp->cnt--;
					}
					break;
				case 1:
					if((eactp = ACTsetTop(ACTeffectType2, GROUP_06))){
						eactp->pos[X] = actp->pos[X];
						eactp->pos[Y] = actp->pos[Y];
						eactp->prog_adr(eactp);
						actp->cnt--;
					}
					break;
				case 2:
					if(!(work[WRK_FRAME] % 0x08) && (eactp = ACTsetTop(ACTeffectType3, GROUP_06))){
						eactp->pos[X] = actp->pos[X];
						eactp->pos[Y] = actp->pos[Y];
						eactp->prog_adr(eactp);
						actp->cnt--;
					}
					break;
				case 3:
					actp->ofs[X] =
					actp->ofs[Y] = DCNVrand(0x8000);
					if(!(work[WRK_FRAME] & 0x04)){
						for(i = 0; i < 8; i++){
							if((eactp = ACTsetTop(ACTeffectType4, GROUP_06))){
								eactp->pos[X] = actp->pos[X];
								eactp->pos[Y] = actp->pos[Y];
								eactp->ofs[X] = actp->ofs[X];
								eactp->ofs[Y] = actp->ofs[Y];
								eactp->prog_adr(eactp);
								actp->ofs[X] += 0x2000;
								actp->ofs[Y] += 0x2000;
							}
						}
						actp->cnt--;
					}
					break;
				default:
					break;
			}
			if(!actp->cnt)
				ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void ACTeffectType1(ACT *actp)
{
	SINT32 pos[XY];

	switch(actp->step){
		case CHR_INIT:
			actp->trg[X] = (DCNVrand(64) - 32) * WP + actp->pos[X];
			actp->trg[Y] = (DCNVrand(64) - 32) * WP + actp->pos[Y];
			actp->cnt = 30;
			ACTnextStep();
			break;
		case CHR_MAIN:
			actp->pos[X] += (actp->trg[X] - actp->pos[X]) / 15;
			actp->pos[Y] += (actp->trg[Y] - actp->pos[Y]) / 15;
			pos[X] = actp->pos[X] / WP;
			pos[Y] = actp->pos[Y] / WP;
			pceLCDPoint(3, pos[X], pos[Y]);
			actp->cnt--;
			if(!actp->cnt)
				ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void ACTeffectType2(ACT *actp)
{
	SINT32 pos[XY];

	switch(actp->step){
		case CHR_INIT:
			actp->trg[X] = (DCNVrand(64) - 32) * WP + actp->pos[X];
			actp->trg[Y] = (DCNVrand(64) - 32) * WP + actp->pos[Y];
			actp->size = 3;
			actp->cnt = 60;
			ACTnextStep();
			break;
		case CHR_MAIN:
			actp->size = (60 - actp->cnt) / 20 + 3;
			actp->pos[X] += (actp->trg[X] - actp->pos[X]) / 30;
			actp->pos[Y] += (actp->trg[Y] - actp->pos[Y]) / 30;
			pos[X] = actp->pos[X] / WP;
			pos[Y] = actp->pos[Y] / WP;
			if(!(actp->cnt & 0x01)){
				BLOCKdraw(3, pos[X], pos[Y], actp->size + 6, actp->size + 6);
				BLOCKdraw(2, pos[X], pos[Y], actp->size + 4, actp->size + 4);
				BLOCKdraw(1, pos[X], pos[Y], actp->size + 2, actp->size + 2);
				BLOCKdraw(0, pos[X], pos[Y], actp->size + 0, actp->size + 0);
			}
			actp->cnt--;
			if(!actp->cnt)
				ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void ACTeffectType3(ACT *actp)
{
	SINT32 pos[XY];

	switch(actp->step){
		case CHR_INIT:
			actp->trg[X] = 0x0000;
			actp->trg[Y] = 0x0000;
			actp->ofs[X] =
			actp->ofs[Y] = DCNVrand(0x8000);
			actp->size = 3;
			actp->cnt = 30;
			ACTnextStep();
			break;
		case CHR_MAIN:
			actp->trg[X] += 0x7700;
			actp->trg[Y] += 0x7700;
			actp->ofs[X] += 0x530;
			actp->ofs[Y] += 0x530;
			pos[X] = actp->pos[X] + ((MOTsin((ANGLE)actp->ofs[X])) * ((actp->trg[X]) >> 16));
			pos[Y] = actp->pos[Y] - ((MOTcos((ANGLE)actp->ofs[Y])) * ((actp->trg[Y]) >> 16));
			pos[X] /= WP;
			pos[Y] /= WP;
			actp->size = (30 - actp->cnt) / 10 + 3;
			BLOCKdraw(3, pos[X], pos[Y], actp->size + 6, actp->size + 6);
			BLOCKdraw(2, pos[X], pos[Y], actp->size + 4, actp->size + 4);
			BLOCKdraw(1, pos[X], pos[Y], actp->size + 2, actp->size + 2);
			BLOCKdraw(0, pos[X], pos[Y], actp->size + 0, actp->size + 0);
			actp->cnt--;
			if(!actp->cnt)
				ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void ACTeffectType4(ACT *actp)
{
	SINT32 pos[XY];

	switch(actp->step){
		case CHR_INIT:
			actp->trg[X] = 0 * WP;
			actp->trg[Y] = 0 * WP;
			actp->size = 3;
			actp->cnt = 30;
			ACTnextStep();
			break;
		case CHR_MAIN:
			actp->trg[X] += 0x9300;
			actp->trg[Y] += 0x9300;
			pos[X] = actp->pos[X] + ((MOTsin((ANGLE)actp->ofs[X])) * ((actp->trg[X]) >> 16));
			pos[Y] = actp->pos[Y] - ((MOTcos((ANGLE)actp->ofs[Y])) * ((actp->trg[Y]) >> 16));
			pos[X] /= WP;
			pos[Y] /= WP;
			actp->size = (30 - actp->cnt) / 10 + 3;
			if(!(actp->cnt & 0x01)){
				BLOCKdraw(3, pos[X], pos[Y], actp->size + 6, actp->size + 6);
				BLOCKdraw(2, pos[X], pos[Y], actp->size + 4, actp->size + 4);
				BLOCKdraw(1, pos[X], pos[Y], actp->size + 2, actp->size + 2);
				BLOCKdraw(0, pos[X], pos[Y], actp->size + 0, actp->size + 0);
			}
			actp->cnt--;
			if(!actp->cnt)
				ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}
