
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/act.h"
#include "../include/main.h"
#include "../include/block.h"
#include "../include/dconv.h"
#include "../include/work.h"
#include "../include/util_snd.h"

#include "../include/act_main.h"

#define	PAD_DIR	(PAD_RI+PAD_LF+PAD_DN+PAD_UP)
#define	DIR_X	((SINT32)((1.0f / 0.7f) * WP * 1.0f))
#define	DIR_Y	((SINT32)((1.0f / 0.7f) * WP * 1.0f))
#define	DIR_XY	((SINT32)(1.0f * WP))

#define	actShotSet(eactp,x,y)\
				eactp->act_parent = actp;\
				eactp->pos[X] = actp->pos[X] + (x * WP);\
				eactp->pos[Y] = actp->pos[Y] + (y * WP);\
				shot_now++

static UINT8 shot_max;
static UINT8 shot_now;
static UINT8 shot_pow;
static UINT8 shot_blank;
static UINT8 shot_level;
static UINT8 shot_single;

static UINT8 demo_step = 0;
static UINT8 demo_mode = 0;
static UINT8 demo_cnt = 0;
static UINT8 demo_wait = 0;
static UINT8 demo_shot = 0;

static SINT32	mov_tbl[][2] = {
				{      +0,     +0 },	/* none							*/
				{      +0, +DIR_Y },	/* PAD_DN						*/
				{  -DIR_X,     +0 },	/* PAD_LF						*/
				{ -DIR_XY,+DIR_XY },	/* PAD_DN+PAD_LF				*/
				{  +DIR_X,     +0 },	/* PAD_RI						*/
				{ +DIR_XY,+DIR_XY },	/* PAD_DN+PAD_RI				*/
				{      +0,     +0 },	/* PAD_RI+PAD_LF				*/
				{      +0,     +0 },	/* PAD_DN+PAD_RI+PAD_LF			*/
				{      +0, -DIR_Y },	/* PAD_UP						*/
				{      +0,     +0 },	/* PAD_UP+PAD_DN				*/
				{ -DIR_XY,-DIR_XY },	/* PAD_UP+PAD_LF				*/
				{      +0,     +0 },	/* PAD_UP+PAD_DN+PAD_LF			*/
				{ +DIR_XY,-DIR_XY },	/* PAD_UP+PAD_RI				*/
				{      +0,     +0 },	/* PAD_UP+PAD_DN+PAD_RI			*/
				{      +0,     +0 },	/* PAD_UP+PAD_RI+PAD_LF			*/
				{      +0,     +0 },	/* PAD_UP+PAD_DN+PAD_RI+PAD_LF	*/
};

static COLLISION col_ship[] = {
									{ {  +0, +0 },{  +1,  +1 } },
									{ {  -1, -1 },{  -1,  -1 } },
								};

static COLLISION col_sshot[] = {
									{ {  +0, +0 },{  +1,  +6 } },
									{ {  -1, -1 },{  -1,  -1 } },
								};

void actShip(ACT *actp);

static void actShipShot(ACT *actp);
static void actShipDemoInit(void);
static UINT32 actShipDemoCtrl(void);

void actShip(ACT *actp)
{
	ACT *eactp;

	switch(actp->step){
		case CHR_INIT:
			actp->chr_flag = f_mship;
			actp->col = col_ship;
			shot_max = 12;
			shot_now = 0;
			shot_pow = 1;
			shot_blank = 0;
			shot_level = 0;
			shot_single = 3;
			actp->wait = 1;
			actShipDemoInit();
			ACTnextStep();
			break;
		case CHR_MAIN+0:
			if(work[WRK_LEFT] < 0){
				work[WRK_MODE] = MODE_OVER;
				ACTexitStep();
				break;
			}
			actp->wait--;
			if(!actp->wait){
				actp->pos[X] = 64 * WP;
				actp->pos[Y] = 72 * WP;
				actp->wait = 120;
				ACTnextStep();
				
			}
			break;
		case CHR_MAIN+1:
			if(work[WRK_MODE] != MODE_DEMO){
				actp->wait--;
				if(!actp->wait){
					actp->chr_flag = f_ship;
					ACTnextStep();
				}
			}else{
				pad_dat = actShipDemoCtrl();
				actp->wait--;
			}
		case CHR_MAIN+2:
			if(work[WRK_MODE] == MODE_CLEAR){
				actp->trg[X] = (MAX_X / 2) * WP;
				actp->trg[Y] = -16 * WP;
				if(actp->pos[X] > actp->trg[X]){
					actp->vel[X] = -1 * WP;
				}else{
					actp->vel[X] = +1 * WP;
				}
				actp->vel[Y] = +1 * WP;
				actp->ofs[X] = 0x0c00;
				actp->ofs[Y] = 0x0c00;
				ACTsetStep(CHR_MAIN+3);
				break;
			}
			if(shot_single){
				actp->pos[X] += mov_tbl[(pad_dat & PAD_DIR)][X];
				actp->pos[Y] += mov_tbl[(pad_dat & PAD_DIR)][Y];
			}else{
				actp->pos[X] += mov_tbl[(pad_dat & PAD_DIR)][X] / 2;
				actp->pos[Y] += mov_tbl[(pad_dat & PAD_DIR)][Y] / 2;
			}
			if(actp->pos[X] < (7 * WP)){
				actp->pos[X] = 7 * WP;
			}
			if(actp->pos[X] > ((MAX_X - 7) * WP)){
				actp->pos[X] = (MAX_X - 7) * WP;
			}
			if(actp->pos[Y] < (7 * WP)){
				actp->pos[Y] = (7 * WP);
			}
			if(actp->pos[Y] > ((MAX_Y - 7) * WP)){
				actp->pos[Y] = (MAX_Y - 7) * WP;
			}
			if(!(pad_dat & PAD_A)){
				shot_single = 3;
			}
			if((pad_dat & PAD_A) && shot_now < shot_max && !shot_blank){
				soundPlaySe(SE_SHOT);
				if(shot_single){
					if((eactp = ACTsetTop(actShipShot,GROUP_03))){
						actShotSet(eactp,-5,-4);
						eactp->vel[X] = WP / 2 * (-1);
						eactp->vel[Y] = -3 * WP;
						eactp->type = 0;
						eactp->prog_adr(eactp);
					}
					if((eactp = ACTsetTop(actShipShot,GROUP_03))){
						actShotSet(eactp,-1,-4);
						eactp->vel[X] = +0 * WP;
						eactp->vel[Y] = -3 * WP;
						eactp->type = 0;
						eactp->prog_adr(eactp);
					}
					if((eactp = ACTsetTop(actShipShot,GROUP_03))){
						actShotSet(eactp,+3,-4);
						eactp->vel[X] = WP / 2 * (+1);
						eactp->vel[Y] = -3 * WP;
						eactp->type = 0;
						eactp->prog_adr(eactp);
					}
					shot_blank = 6;
					shot_single--;
				}else{
					if((eactp = ACTsetTop(actShipShot,GROUP_03))){
						actShotSet(eactp,-1,-4);
						eactp->vel[X] = +0 * WP;
						eactp->vel[Y] = -3 * WP;
						eactp->type = 2;
						eactp->prog_adr(eactp);
					}
					if((eactp = ACTsetTop(actShipShot,GROUP_03))){
						actShotSet(eactp, -3, -2);
						eactp->vel[X] = +0 * WP;
						eactp->vel[Y] = -3 * WP;
						eactp->type = 1;
						eactp->prog_adr(eactp);
					}
					if((eactp = ACTsetTop(actShipShot,GROUP_03))){
						actShotSet(eactp, +1, -2);
						eactp->vel[X] = +0 * WP;
						eactp->vel[Y] = -3 * WP;
						eactp->type = 1;
						eactp->prog_adr(eactp);
					}
					shot_blank = 3;
				}
			}
			if(shot_blank){
				shot_blank--;
			}
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			work[WRK_SCRX] = (actp->cen[X] - 64) * 0x400;
			work[WRK_SCRY] = (actp->cen[Y] - MAX_Y) * 0x200;
			if(!(actp->wait & 0x01)){
				BLOCKdraw(3, actp->cen[X] + 0, actp->cen[Y] + 2,  8,  6);
				BLOCKdraw(3, actp->cen[X] + 0, actp->cen[Y] + 4, 12,  4);
				BLOCKdraw(3, actp->cen[X] + 0, actp->cen[Y] + 0,  4, 14);
				pceLCDPaint(1, actp->cen[X] - 1, actp->cen[Y] - 1, 2, 2);
			}
			break;
		case CHR_MAIN+3:
			actp->pos[X] += actp->vel[X];
			actp->pos[Y] += actp->vel[Y];
			actp->vel[X] += (actp->pos[X] < actp->trg[X] ? actp->ofs[X] : -(actp->ofs[X]));
			actp->vel[Y] += (actp->pos[Y] < actp->trg[Y] ? actp->ofs[Y] : -(actp->ofs[Y]));
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			work[WRK_SCRX] = (actp->cen[X] - 64) * 0x400;
			work[WRK_SCRY] = (actp->cen[Y] - MAX_Y) * 0x200;
			if(!(actp->wait & 0x01)){
				BLOCKdraw(3, actp->cen[X] + 0, actp->cen[Y] + 2,  8,  6);
				BLOCKdraw(3, actp->cen[X] + 0, actp->cen[Y] + 4, 12,  4);
				BLOCKdraw(3, actp->cen[X] + 0, actp->cen[Y] + 0,  4, 14);
			}
			if(actp->pos[Y] < (-16 * WP)){
				ACTexitStep();
			}
			break;
		case CHR_DAMAGE:
			soundPlaySe(SE_SHIPBRK);
			actp->chr_flag = f_mship;
			actp->wait = 60;
			ACTsetStep(CHR_MAIN + 0);
			work[WRK_LEFT]--;
			break;
		case -1:
			ACTclear(actp);
			break;
	}

	return;
}

void actShipShot(ACT *actp)
{
	switch(actp->step){
		case CHR_INIT:
			actp->chr_flag = f_none;
			actp->col = col_sshot;
			ACTnextStep();
			break;
		case 1:
			actp->chr_flag = f_sshot;
			actp->pos[X] += actp->vel[X];
			actp->pos[Y] += actp->vel[Y];
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			if(actp->pos[Y] < (-6 * WP)){
				ACTexitStep();
				break;
			}
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			BLOCKdraw(3,actp->cen[X],actp->cen[Y], 3, 12);
			if(actp->type){
				if(actp->type == 1){
					pceLCDPaint(0,actp->cen[X]+0,actp->cen[Y]-5,1,10);
				}else{
					pceLCDPaint(0,actp->cen[X]-1,actp->cen[Y]-5,3,10);
				}
			}
			break;
		case CHR_DAMAGE:
			actp->chr_flag = f_none;
			ACTexitStep();
			break;
		case CHR_DESTROY:
		case CHR_EXIT:
		default:
			actp->chr_flag = f_none;
			shot_now--;
			ACTclear(actp);
			break;
	}
}

void actShipDemoInit(void)
{
	demo_step = 0;
	demo_mode = 0;
	demo_cnt = 0;
	demo_wait = 0;
	demo_shot = 0;
}

UINT32 actShipDemoCtrl(void)
{
	ACT *actp = (ACT *)work[WRK_ACTSHIP];
	UINT32 pad_dat = 0;
	UINT16 branch;

	if(!actp){
		return 0;
	}

	switch(demo_step){
		case 0:
			do{
				branch = DCNVrand(100);
				if(branch < 60){
					demo_mode = 0;
				}
			}while(demo_mode);
			if(branch < 20){
				if(actp->cen[X] > 64){
					demo_step = 2;
					demo_cnt = DCNVrand(30) + 10;
				}else{
					demo_step = 3;
					demo_cnt = DCNVrand(30) + 10;
				}
			}else if(branch < 40){
				if(actp->cen[X] > 64){
					if(actp->cen[Y] > 73){
						demo_step = 4;
						demo_cnt = DCNVrand(30) + 10;
					}else{
						demo_step = 5;
						demo_cnt = DCNVrand(30) + 10;
					}
				}else{
					if(actp->cen[Y] > 73){
						demo_step = 6;
						demo_cnt = DCNVrand(10) + 5;
					}else{
						demo_step = 7;
						demo_cnt = DCNVrand(10) + 5;
					}
				}
			}else if(branch < 60){
				if(actp->cen[Y] > 73){
					demo_step = 8;
					demo_cnt = DCNVrand(15) + 10;
				}else{
					demo_step = 9;
					demo_cnt = DCNVrand(15) + 10;
				}
			}else{
				demo_step = 1;
				demo_mode = 1;
				demo_cnt = DCNVrand(30) + 30;
			}
			break;
		case 1:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			break;
		case 2:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_LF;
			break;
		case 3:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_RI;
			break;
		case 4:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_LF + PAD_UP;
			break;
		case 5:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_LF + PAD_DN;
			break;
		case 6:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_RI + PAD_UP;
			break;
		case 7:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_RI + PAD_DN;
			break;
		case 8:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_UP;
			break;
		case 9:
			demo_cnt--;
			if(!demo_cnt){
				demo_step = 0;
			}
			pad_dat |= PAD_DN;
			break;
	}

	if(!demo_shot && DCNVrand(100) > 98){
		demo_shot = DCNVrand(60) + 60;
	}

	if(demo_shot){
		demo_shot--;
		if((demo_shot & 0x01)){
			pad_dat |= PAD_A;
		}
	}else{
		pad_dat |= PAD_A;
	}

	return pad_dat;
}
