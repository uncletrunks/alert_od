
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/file.h"
#include "../include/work.h"
#include "../include/util_sdl.h"
#include "../include/util_pad.h"
#include "../include/util_snd.h"
#include "../include/util_act.h"
#include "../include/util_ascii.h"
#include "../include/util_grp.h"
#include "../include/act_main.h"
#include "../include/act_bg.h"
#include "../include/graphic.h"

#ifdef GP2X
#include <unistd.h>
#endif
#include <time.h>

//#define CAPTURE

#define UPDATE_DELAY 16
#define EXIT_KEY (PAD_BUTTON5+PAD_BUTTON6+PAD_BUTTONA)

int	main(int argc, char *argv[]);

static void ExitProgram(void);
static void CollisionCheck(void);
static void CollisionCheckSub(ACT *actp, UINT8 group);

int pad_dat;
int pad_trg;
int pad_rep;

BOOL GameExec;

static time_t times;

int	main(int argc, char *argv[])
{
	const int INTERVAL_BASE = 8;
	int interval = INTERVAL_BASE;
	long prvTickCount = 0;
	long nowTick;
	int frame;
	SDL_Event event;

	GameExec = FALSE;
	initSDL();
	initPAD();
	soundInitBuffer();
	initASCII();
	initGRParea(SCR_X * WP, SCR_Y * WP, (SCREEN_X - SCR_X) * WP, (SCREEN_Y - SCR_Y) * WP);
	ACTinit();
	WORKinit();
	ACTinit();

	GameExec = TRUE;

	readSDLtexture("font01.bmp", GRP_FONT01);
	readSDLtexture("font02.bmp", GRP_FONT02);
	readSDLtexture("font03.bmp", GRP_FONT03);
	readSDLtexture("font04.bmp", GRP_FONT04);
	setSDLcolorkey(GRP_FONT01, SDL_MapRGBA(primary->format,0,0,0,255));
	setSDLcolorkey(GRP_FONT02, SDL_MapRGBA(primary->format,255,255,255,255));
	setSDLcolorkey(GRP_FONT03, SDL_MapRGBA(primary->format,255,255,255,255));
	setSDLcolorkey(GRP_FONT04, SDL_MapRGBA(primary->format,255,255,255,255));

	soundLoadBuffer(BGM_GAME01 ,(UINT8 *)"alert_bgm01.ogg", -1);

	soundLoadBufferSE(SE_SEL,     (UINT8 *)"alert_se_sel.wav");
	soundLoadBufferSE(SE_COLLECT, (UINT8 *)"alert_se_collect.wav");
	soundLoadBufferSE(SE_SHOT,    (UINT8 *)"alert_se_shot.wav");
	soundLoadBufferSE(SE_SHIPBRK, (UINT8 *)"alert_se_shipbrk.wav");
	soundLoadBufferSE(SE_CHIP,    (UINT8 *)"alert_se_chip.wav");
	soundLoadBufferSE(SE_DMG,     (UINT8 *)"alert_se_dmg.wav");
	soundLoadBufferSE(SE_ENEEXP,  (UINT8 *)"alert_se_eneexp.wav");
	soundLoadBufferSE(SE_ENEBRK,  (UINT8 *)"alert_se_enebrk.wav");
	soundLoadBufferSE(SE_EXTEND,  (UINT8 *)"alert_se_extend.wav");
	soundLoadBufferSE(SE_ALERT,   (UINT8 *)"alert_se_alert.wav");

	ACTsetTop(actMain, GROUP_00);
	ACTsetBtm(actFrame, GROUP_07);

	time(&times);
	printf("rand seed %d\n", (int)times);
	srand(times);

	while(TRUE){
		SDL_PollEvent(&event);
		getPAD();
		pad_dat = pads;
		pad_trg = trgs;
		pad_rep = reps;
#ifndef GP2X
		if(keys[SDLK_ESCAPE] == SDL_PRESSED || event.type == SDL_QUIT){
#else
		if(((pad_dat & EXIT_KEY) == EXIT_KEY) || event.type == SDL_QUIT){
#endif
			GameExec = 0;
		}
		if(!GameExec){
			break;
		}
		ACTexec();
		soundPlayCtrl();
		CollisionCheck();
		nowTick = SDL_GetTicks();
		frame = (nowTick - prvTickCount) / interval;
		if(frame <= 0){
			/*pceFontSetPos(120, 0);
			pceFontPrintf("%2d", prvTickCount + interval - nowTick);*/
			SDL_Delay(prvTickCount + interval - nowTick);
			//wait(prvTickCount + interval - nowTick);
		}
		prvTickCount = SDL_GetTicks();
		flipSDL();
#ifdef CAPTURE
		if(pad_trg & PAD_BUTTON6){
			SDL_SaveBMP(primary, "capture.bmp");
#ifdef GP2X
			//sync();
#endif
		}
#endif
//		clearSDL();
		pceLCDPaint(0, 0, 0, MAX_X, MAX_Y);
	}

	ExitProgram();

	return	0;
}

void ExitProgram(void)
{
	ACTclearAll(NULL);

	soundStopBgm(0);
	soundStopSeAll();
	soundRelease();

	closePAD();
	closeSDL();

#ifdef GP2X
	chdir("/usr/gp2x");
	execl("gp2xmenu", "gp2xmenu", NULL);
#endif
}

void CollisionCheck(void)
{
	ACT *actp;
	SINT16 group = 0;

	for(group = 0; group < ACT_GROUP_MAX; group++){
		for(actp = ActIndex[group][ACT_TOP].next_act;
			 actp != &ActIndex[group][ACT_BOTTOM];
			 actp = actp->next_act){
			switch(get_cflag(actp)){
				case f_ship:
					CollisionCheckSub(actp,GROUP_02);
					CollisionCheckSub(actp,GROUP_06);
					break;
				case f_sshot:
					CollisionCheckSub(actp,GROUP_02);
					break;
				case f_enemy:
					CollisionCheckSub(actp,GROUP_05);
					break;
				case f_eshot:
					break;
				case f_chip:
					CollisionCheckSub(actp,GROUP_05);
					break;
				default:
					break;
			}
			continue;
		}
	}
}

void CollisionCheckSub(ACT *actp,UINT8 group)
{
	ACT *eactp;
	COLLISION *src_col;
	COLLISION *dst_col;
	SINT8 src_x;
	SINT8 src_y;
	SINT8 dst_x;
	SINT8 dst_y;
	UINT8 eflag;
	UINT8 step;
	UINT8 cnt1;
	UINT8 cnt2;

	cnt1 = 0;

	while(actp->col[cnt1].ofs[X] != -1){
		src_col = &actp->col[cnt1];
		src_x = src_col->col[X];
		src_y = src_col->col[Y];
		for(eactp = ActIndex[group][ACT_TOP].next_act;
			 eactp != &ActIndex[group][ACT_BOTTOM];
			 eactp = eactp->next_act){
			eflag = get_cflag(eactp);
			switch(get_cflag(actp)){
				case f_ship:
					if(eflag == f_eshot || eflag == f_enemy){
						cnt2 = 0;
						while(eactp->col[cnt2].ofs[X] != -1){
							if(ABS(eactp->cen[X] - actp->cen[X] + eactp->col[cnt2].ofs[X]) < src_x &&
								ABS(eactp->cen[Y] - actp->cen[Y] + eactp->col[cnt2].ofs[Y]) < src_y){
								step = actp->step;
								actp->act_ext = eactp;
								actp->step = CHR_DAMAGE;
								actp->prog_adr(actp);
								if(actp->step == CHR_DAMAGE){
									actp->step = step;
								}
								return;
							}
							cnt2++;
						}
					}
					break;
				case f_sshot:
					if(get_cflag(eactp) == f_enemy){
						cnt2 = 0;
						while(eactp->col[cnt2].ofs[X] != -1){
							dst_col = &eactp->col[cnt2];
							dst_x = dst_col->col[X];
							dst_y = dst_col->col[Y];
							if(ABS(eactp->cen[X] - actp->cen[X] + eactp->col[cnt2].ofs[X]) < dst_x &&
								ABS(eactp->cen[Y] - actp->cen[Y] + eactp->col[cnt2].ofs[Y]) < dst_y){
								if(!(eactp->chr_flag & f_damage)){
									step = actp->step;
									actp->act_ext = eactp;
									actp->step = CHR_DAMAGE;
									actp->prog_adr(actp);
									if(actp->step == CHR_DAMAGE){
										actp->step = step;
									}
									step = eactp->step;
									eactp->act_ext = actp;
									eactp->step = CHR_DAMAGE;
									eactp->prog_adr(eactp);
									if(eactp->step == CHR_DAMAGE){
										eactp->step = step;
									}
									return;
								}
							}
							cnt2++;
						}
					}
					break;
				case f_enemy:
					if(eflag == f_ship){
						if(ABS(eactp->cen[X] - actp->cen[X]) < src_x &&
							ABS(eactp->cen[Y] - actp->cen[Y]) < src_y){
							if(!(eactp->chr_flag & f_damage)){
								step = eactp->step;
								eactp->act_ext = actp;
								eactp->step = CHR_DAMAGE;
								eactp->prog_adr(eactp);
								if(eactp->step == CHR_DAMAGE){
									eactp->step = step;
								}
								return;
							}
						}
					}
					break;
				case f_chip:
					if(eflag == f_ship || eflag == f_mship){
						if(ABS(eactp->cen[X] - actp->cen[X]) < src_x &&
							ABS(eactp->cen[Y] - actp->cen[Y]) < src_y){
							step = actp->step;
							actp->act_ext = eactp;
							actp->step = CHR_DAMAGE;
							actp->prog_adr(actp);
							if(actp->step == CHR_DAMAGE){
								actp->step = step;
							}
							return;
						}
					}
					break;
				case f_eshot:
					return;
				default:
					break;
			}
			continue;
		}
		cnt1++;
	}
}
