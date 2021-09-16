
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/util_act.h"
#include "../include/util_grp.h"
#include "../include/dconv.h"
#include "../include/work.h"
#include "../include/graphic.h"

#include "../include/act_main.h"

void actBgCtrl(ACT *actp);
void actFrame(ACT *actp);

void actBgCtrl(ACT *actp)
{
	switch(actp->step){
		case CHR_INIT:
			actp->pos[X] = 0 * WP;
			actp->pos[Y] = 0 * WP;
			actp->vel[Y] = WP / 2;
			ACTnextStep();
		case CHR_MAIN:
			actp->pos[X] -= work[WRK_SCRX];
			actp->pos[Y] += actp->vel[Y] - work[WRK_SCRY];
			actp->cen[X] = actp->pos[X] >> 16;
			actp->cen[Y] = actp->pos[Y] >> 16;
			{
//				long prvTickCount;
//				long nowTick = SDL_GetTicks();
				pceLCDLineClip(1, 0, actp->cen[Y] +  0, 128, actp->cen[Y] +  0);
				pceLCDLineClip(1, 0, actp->cen[Y] + 11, 128, actp->cen[Y] + 11);
				pceLCDLineClip(1, 0, actp->cen[Y] + 22, 128, actp->cen[Y] + 22);
				pceLCDLineClip(1, 0, actp->cen[Y] + 33, 128, actp->cen[Y] + 33);
				pceLCDLineClip(1, 0, actp->cen[Y] + 44, 128, actp->cen[Y] + 44);
				pceLCDLineClip(1, 0, actp->cen[Y] + 55, 128, actp->cen[Y] + 55);
				pceLCDLineClip(1, 0, actp->cen[Y] + 66, 128, actp->cen[Y] + 66);
				pceLCDLineClip(1, 0, actp->cen[Y] + 77, 128, actp->cen[Y] + 77);
				pceLCDLineClip(1, actp->cen[X] +   0, 0, actp->cen[X] +   0, 88);
				pceLCDLineClip(1, actp->cen[X] +  16, 0, actp->cen[X] +  16, 88);
				pceLCDLineClip(1, actp->cen[X] +  32, 0, actp->cen[X] +  32, 88);
				pceLCDLineClip(1, actp->cen[X] +  48, 0, actp->cen[X] +  48, 88);
				pceLCDLineClip(1, actp->cen[X] +  64, 0, actp->cen[X] +  64, 88);
				pceLCDLineClip(1, actp->cen[X] +  80, 0, actp->cen[X] +  80, 88);
				pceLCDLineClip(1, actp->cen[X] +  96, 0, actp->cen[X] +  96, 88);
				pceLCDLineClip(1, actp->cen[X] + 112, 0, actp->cen[X] + 112, 88);
//				prvTickCount = SDL_GetTicks();
//				pceFontSetPos(120, 8);
//				pceFontPrintf("%2d", prvTickCount - nowTick);
			}
			if(actp->pos[Y] >= 11 * WP) actp->pos[Y] -= 11 * WP;
			if(actp->pos[X] <   0 * WP) actp->pos[X] += 16 * WP;
			if(actp->pos[X] >= 16 * WP) actp->pos[X] -= 16 * WP;
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void actFrame(ACT *actp)
{
	UINT32 fill;

	switch(actp->step){
		case 0:
			actp->actid |= FLG_SYSTEM;
			ACTnextStep();
		case 1:
			fill = SDL_MapRGBA(primary->format, 0, 0, 0, 255);
			fillSDLsurface(GRP_PRIMARY, 0, 0, getGRPminx(), SCREEN_SY * WP, fill);
			fillSDLsurface(GRP_PRIMARY, getGRPmaxx(), 0, SCREEN_X * WP, SCREEN_SY * WP, fill);
			fillSDLsurface(GRP_PRIMARY, getGRPminx(), 0, getGRPmaxx(), getGRPminy(), fill);
			fillSDLsurface(GRP_PRIMARY, getGRPminx(), getGRPmaxy(), getGRPmaxx(), SCREEN_SY * WP, fill);
			break;
		default:
			ACTclear(actp);
			break;
	}
}
