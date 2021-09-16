
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/act.h"
#include "../include/main.h"
#include "../include/dconv.h"
#include "../include/work.h"
#include "../include/font.h"
#include "../include/util_snd.h"

#include "../include/act_main.h"

void actLogo(ACT *actp);
void actTitle(ACT *actp);

static void actStarCtrl(ACT *actp);
static void actStarMain(ACT *actp);

void actLogo(ACT *actp)
{
	switch(actp->step){
		case CHR_INIT:
			actp->cnt = 120;
			ACTnextStep();
			break;
		case 1:
			pceFontSetPos(2, 40);
			pceFontPutStr("HELLO WORLD PROJECT 2002 - 2008");
			if(pad_trg & (TRG_B)) actp->cnt = 1;
			actp->cnt--;
			if(!actp->cnt){
				ACTnextStep();
			}
			break;
		default:
			work[WRK_MODE] = MODE_QUIT;
			ACTclear(actp);
			break;
	}
}

void actTitle(ACT *actp)
{
	switch(actp->step){
		case CHR_INIT:
			actp->pos[X] = fontGetStrSize((UINT8 *)"ALERT") - 2;
			actp->pos[Y] = 0;
			ACTsetBtm(actStarCtrl, GROUP_00);
			work[WRK_CNT] = 10 * 60;
			ACTnextStep();
			break;
		case 1:
			if((pad_trg & TRG_DN)){
				soundPlaySe(SE_SEL);
				actp->pos[Y]++;
			}
			if((pad_trg & TRG_UP)){
				soundPlaySe(SE_SEL);
				actp->pos[Y]--;
			}
			actp->pos[Y] = (actp->pos[Y] < 0 ? 3 : actp->pos[Y] % 4);
			fontDispStr((MAX_X - actp->pos[X]) / 2 + 1, 12 + 1, (UINT8 *)"ALERT" ,1, 0, FALSE);
			fontDispStr((MAX_X - actp->pos[X]) / 2 + 0, 12 + 0, (UINT8 *)"ALERT" ,3, 1, FALSE);
			pceFontSetPos(44, 38 + 7 * 0);
			pceFontPutStr("EASY GAME");
			pceFontSetPos(44, 38 + 7 * 1);
			pceFontPutStr("HARD GAME");
			pceFontSetPos(44, 38 + 7 * 2);
			pceFontPutStr("ENDLESS");
			pceFontSetPos(44, 38 + 7 * 3);
			pceFontPutStr("EXIT");
			pceFontSetPos(38, 38 + (actp->pos[Y] * 7));
			pceFontPutStr(">");
			pceFontSetPos(34, 38 + (actp->pos[Y] * 7));
			pceFontPutStr(">");
			if(actp->pos[Y] != 3){
				pceFontSetPos(24, 68);
				pceFontPrintf("HIGH SCORE %09d", work[WRK_EASYSCORE + actp->pos[Y]]);
			}
			pceFontSetPos(2, 80);
			pceFontPutStr("HELLO WORLD PROJECT 2002 - 2008");
			if(pad_trg & (TRG_B)){
				soundPlaySe(SE_COLLECT);
				if(actp->pos[Y] == 0){
					work[WRK_GAME] = GAME_EASY;
					work[WRK_MODE] = MODE_GAME;
				}
				if(actp->pos[Y] == 1){
					work[WRK_GAME] = GAME_HARD;
					work[WRK_MODE] = MODE_GAME;
				}
				if(actp->pos[Y] == 2){
					work[WRK_GAME] = GAME_ENDLESS;
					work[WRK_MODE] = MODE_GAME;
				}
				if(actp->pos[Y] == 3){
					work[WRK_MODE] = MODE_EXIT;
				}
				ACTexitStep();
			}
			work[WRK_CNT]--;
			if(!work[WRK_CNT]){
				work[WRK_GAME] = GAME_ENDLESS;
				work[WRK_MODE] = MODE_DEMO;
			}
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void actStarCtrl(ACT *actp)
{
	ACT *eactp;
	SINT i;

	switch(actp->step){
		case CHR_INIT:
			for(i = 0; i < 224; i++){
				if((eactp = ACTsetTop(actStarMain,GROUP_01))){
					eactp->pos[X] = DCNVrand(MAX_X) * WP;
					eactp->pos[Y] = DCNVrand(MAX_Y) * WP;
				}
			}
			ACTnextStep();
			break;
		case 1:
			work[WRK_SCRX] = DCNVrand(0xE000) * 2 - 0x7000;
			work[WRK_SCRY] = DCNVrand(0xE000) * 2 - 0x7000;
			actp->wait = 240;
			ACTnextStep();
			break;
		case 2:
			actp->wait--;
			if(!actp->wait){
				actp->wait = 30;
				ACTnextStep();
			}
			break;
		case 3:
			actp->wait--;
			if(!actp->wait){
				ACTsetStep(1);
			}
			break;
		default:
			break;
	}
}

void actStarMain(ACT *actp)
{
	SINT pos[XY];

	switch(actp->step){
		case CHR_INIT:
			ACTnextStep();
			break;
		case 1:
			actp->color = 0;
			actp->wait = 240;
			actp->cnt = 40;
			ACTnextStep();
			break;
		case 2:
			if(actp->cnt){
				actp->cnt--;
			}
			if(actp->pos[X] > 128 * WP){
				actp->pos[X] -= 128 * WP;
			}else if(actp->pos[X] < 0 * WP){
				actp->pos[X] += 128 * WP;
			}else if(actp->pos[Y] > 88 * WP){
				actp->pos[Y] -= 88 * WP;
			}else if(actp->pos[Y] < 0 * WP){
				actp->pos[Y] += 88 * WP;
			}
			actp->pos[X] += work[WRK_SCRX];
			actp->pos[Y] += work[WRK_SCRY];
			pos[X] = actp->pos[X] / WP;
			pos[Y] = actp->pos[Y] / WP;
			if(!(work[WRK_FRAME] & 0x01)){
				pceLCDPoint((3 - (actp->cnt / 10)),pos[X],pos[Y]);
			}
			actp->wait--;
			if(!actp->wait){
				actp->wait = 30;
				actp->cnt = 40;
				ACTnextStep();
			}
			break;
		case 3:
			if(actp->cnt){
				actp->cnt--;
			}
			if(actp->pos[X] > 128 * WP){
				actp->pos[X] -= 128 * WP;
			}else if(actp->pos[X] < 0 * WP){
				actp->pos[X] += 128 * WP;
			}else if(actp->pos[Y] > 88 * WP){
				actp->pos[Y] -= 88 * WP;
			}else if(actp->pos[Y] < 0 * WP){
				actp->pos[Y] += 88 * WP;
			}
			actp->pos[X] += work[WRK_SCRX];
			actp->pos[Y] += work[WRK_SCRY];
			pos[X] = actp->pos[X] / WP;
			pos[Y] = actp->pos[Y] / WP;
			if(!(work[WRK_FRAME] & 0x01)){
				pceLCDPoint((actp->cnt / 10),pos[X],pos[Y]);
			}
			actp->wait--;
			if(!actp->wait){
				actp->wait = 30;
				actp->cnt = 40;
				ACTsetStep(1);
			}
			break;
		default:
			break;
	}
}
