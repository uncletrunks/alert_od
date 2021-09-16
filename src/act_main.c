
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/act.h"
#include "../include/main.h"
#include "../include/block.h"
#include "../include/dconv.h"
#include "../include/work.h"
#include "../include/util_snd.h"

#include "../include/act_main.h"
#include "../include/act_bg.h"
#include "../include/act_ship.h"
#include "../include/act_enemy.h"
#include "../include/title.h"

#ifdef GP2X
#include <unistd.h>
#endif

#define PAD_VLDN (PAD_BUTTON7)
#define PAD_VLUP (PAD_BUTTON8)

typedef struct tagSAVEDATA
{
	SINT32 vol;
	SINT32 easy;
	SINT32 hard;
	SINT32 endless;
	
} SAVEDATA;

void actMain(ACT *actp);

static void actInfo(ACT *actp);
static void actVolume(ACT *actp);
static int write_savedata(void);

static SAVEDATA savedata;
static FILE *fd;

void actMain(ACT *actp)
{
	switch(actp->step){
		case 0:
			work[WRK_FRAME] = 0;
			work[WRK_PAUSE] = 0;
			work[WRK_EASYSCORE] = 10000;
			work[WRK_HARDSCORE] = 10000;
			work[WRK_ENDLSCORE] = 10000;
			fd = fopen("./alert.dat", "rb");
			if(fd != NULL){
				fread(&savedata, sizeof(SAVEDATA), 1, fd);
				fclose(fd);
				master_vol = savedata.vol;
				work[WRK_EASYSCORE] = savedata.easy;
				work[WRK_HARDSCORE] = savedata.hard;
				work[WRK_ENDLSCORE] = savedata.endless;
				soundSetVolumeMaster(master_vol);
			}else{
				int ret;
				ret = write_savedata();
				if(ret == -1){
					ACTsetStep(100);
					break;
				}else if(ret == -2){
					ACTsetStep(101);
					break;
				}
			}
			ACTsetBtm(actVolume, GROUP_06);
			ACTnextStep();
		case 1:
			work[WRK_MODE] = MODE_INIT;
			ACTsetBtm(actLogo, GROUP_00);
			ACTnextStep();
		case 2:
			if(work[WRK_MODE]){
				ACTnextStep();
			}
			break;
		case 3:
			work[WRK_MODE] = MODE_INIT;
			ACTsetBtm(actTitle, GROUP_01);
			ACTnextStep();
		case 4:
			switch(work[WRK_MODE]){
				case MODE_GAME:
					work[WRK_PAUSE] = 1;
					ACTsetStep(5);
					ACTclearAll(actp);
					break;
				case MODE_DEMO:
					work[WRK_PAUSE] = 0;
					work[WRK_CNT] = 30 * 60;
					ACTsetStep(5);
					ACTclearAll(actp);
					break;
				case MODE_EXIT:
					ACTexitStep();
					break;
				default:
					break;
			}
			break;
		case 5:
			work[WRK_SCORE]      = 0;
			work[WRK_BONUS]      = 0;
			work[WRK_BFLAG]      = 0;
			work[WRK_BOSSMAX]    = 0;
			work[WRK_BOSSENEMY]  = 0;
			work[WRK_BOSSBROKEN] = 0;
			work[WRK_OPTBROKEN]  = 0;
			work[WRK_LEFT]       = 3;
			work[WRK_EXTEND]     = 0;
			actp->wait = 30;
			ACTnextStep();
			break;
		case 6:
			if(work[WRK_MODE] == MODE_DEMO){
				work[WRK_CNT]--;
			}
			actp->wait--;
			if(!actp->wait){
				work[WRK_ACTSHIP] = (SINT32)ACTsetBtm(actShip, GROUP_05);
				work[WRK_ACTBG]   = (SINT32)ACTsetBtm(actBgCtrl, GROUP_00);
				ACTsetBtm(actInfo, GROUP_06);
				ACTsetBtm(actEnemy, GROUP_06);
				soundPlayBgm(BGM_GAME01);
				ACTnextStep();
			}
			break;
		case 7:
			if(work[WRK_MODE] == MODE_DEMO){
				work[WRK_CNT]--;
				if(!work[WRK_CNT] || (pad_trg & (TRG_A+TRG_B+TRG_C+TRG_D))){
					ACTsetStep(10);
					break;
				}
			}
			if((pad_dat & PAD_BUTTON9)){
				ACTsetStep(10);
				break;
			}
			switch(work[WRK_MODE]){
				case MODE_OVER:
				case MODE_CLEAR:
						actp->wait = 240;
						ACTnextStep();
						break;
			}
			break;
		case 8:
			actp->wait--;
			if(actp->wait < 180){
				if(!actp->wait || (pad_dat & (TRG_A+TRG_B+TRG_C))){
					ACTclearAll(actp);
					ACTnextStep();
				}
			}
			break;
		case 9:
			if(work[WRK_EASYSCORE+work[WRK_GAME]] < work[WRK_SCORE]){
				work[WRK_EASYSCORE+work[WRK_GAME]] = work[WRK_SCORE];
				write_savedata();
			}
			ACTnextStep();
			break;
		case 10:
			soundStopBgmPlaying();
			work[WRK_PAUSE] = 0;
			work[WRK_MODE] = MODE_INIT;
			ACTclearAll(actp);
			ACTsetStep(3);
			break;

		case 100:
			pceFontSetPos(1, 0);
			pceFontPutStr("FILE OPEN ERROR!! (ALERT.DAT)");
			break;
		case 101:
			pceFontSetPos(1, 0);
			pceFontPutStr("FILE WRITE ERROR!! (ALERT.DAT)");
			break;

		default:
			GameExec = FALSE;
			ACTclear(actp);
			break;
	}
	work[WRK_FRAME]++;
}

void actInfo(ACT *actp)
{
	SINT pal;

	switch(actp->step){
		case 0:
			actp->cnt = 0;
			ACTnextStep();
			break;
		case 1:
			if(work[WRK_MODE] != MODE_DEMO){
				if(work[WRK_BOSSENEMY]){
					actp->trg[X] = ((124 * 100) / ((work[WRK_BOSSMAX] * 100) / work[WRK_BOSSENEMY])) * WP;
				}else{
					actp->trg[X] = 0;
					actp->ofs[X] = 0;
				}
				actp->ofs[X] += (actp->trg[X] - actp->ofs[X]) / 15;
				if(work[WRK_FRAME] & 0x01){
					pceLCDPaint(2, 3, 8, (actp->ofs[X] / WP), 4);
				}
				pceFontSetPos(1, 0);
				pceFontPrintf("SCORE %08d", work[WRK_SCORE]);
				if(work[WRK_LEFT] >= 0){
					pceFontSetPos(1, 80);
					pceFontPrintf("LEFT %02d", work[WRK_LEFT]);
				}
			}else{
				pceFontSetPos(1, 80);
				pceFontPutStr("DEMO PLAY");
			}
			if(work[WRK_BFLAG]){
				work[WRK_BFLAG] = 0;
				actp->cnt = 60;
				actp->pos[X] = 128 * WP;
			}
			if(!actp->cnt){
				work[WRK_BONUS] = 0;
			}else{
				if(work[WRK_MODE] != MODE_DEMO){
					actp->pos[X] += ((104 * WP) - actp->pos[X]) / 5;
					pceFontSetBkColor(0x00);
					pceFontSetPos((actp->pos[X] / WP), 12);
					pceFontPrintf("%05d!", work[WRK_BONUS]);
					pceFontSetBkColor(FC_SPRITE);
				}
				actp->cnt--;
			}
			if(work[WRK_MODE] == MODE_OVER){
				pal = (work[WRK_FRAME] % 30) / 10;
				pceFontSetBkColor(pal);
				pceFontSetPos(46, 40);
				pceFontPutStr("GAME OVER");
				pceFontSetBkColor(FC_SPRITE);
			}
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void actVolume(ACT *actp)
{
	switch(actp->step){
		case 0:
			actp->actid |= FLG_SYSTEM;
			ACTnextStep();
			break;

		case 1:
			if(pad_rep & (PAD_VLDN+PAD_VLUP)){
				if(pad_rep & PAD_VLDN) master_vol--;
				if(pad_rep & PAD_VLUP) master_vol++;
				if(master_vol < 0) master_vol = 0;
				if(master_vol >= 127) master_vol = 127;
				savedata.vol = master_vol;
				soundSetVolumeMaster(master_vol);
				actp->cnt = 60;
				ACTnextStep();
			}
			break;
		case 2:
			if(pad_rep & (PAD_VLDN+PAD_VLUP)){
				if(pad_rep & PAD_VLDN) master_vol--;
				if(pad_rep & PAD_VLUP) master_vol++;
				if(master_vol < 0) master_vol = 0;
				if(master_vol >= 127) master_vol = 127;
				savedata.vol = master_vol;
				soundSetVolumeMaster(master_vol);
				actp->cnt = 60;
			}
			pceFontSetBkColor(1);
			pceFontSetPos(80, 80);
			pceFontPrintf(" VOLUME %3d ", master_vol);
			pceFontSetBkColor(FC_SPRITE);
			actp->cnt--;
			if(actp->cnt) break;
			write_savedata();
			ACTbackStep();
			break;

		default:
			ACTclear(actp);
			break;
	}
}

int write_savedata(void)
{
	int ret = 0;

	savedata.vol     = master_vol;
	savedata.easy    = work[WRK_EASYSCORE];
	savedata.hard    = work[WRK_HARDSCORE];
	savedata.endless = work[WRK_ENDLSCORE];

	fd = fopen("./alert.dat", "wb");
	if(fd == NULL){
		ret = -1;
	}else{
		int size;
		size = fwrite(&savedata, sizeof(SAVEDATA), 1, fd);
		fflush(fd);
		fclose(fd);
		if(size != 1){
			return -2;
		}
	}

#ifdef GP2X
	sync();
#endif

	return ret;
}
