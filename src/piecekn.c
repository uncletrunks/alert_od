
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/util_sdl.h"
#include "../include/util_grp.h"
#include "../include/util_ascii.h"
#include "../include/graphic.h"

void pceLCDLineClip(long pal, long x1, long y1, long x2, long y2);
void pceLCDPoint(int pal, int x, int y);
void pceLCDPaint(int pal, int x, int y, int sx, int sy);
UINT32 pceLCDGetPal(int pal);
void pceLCDSetColorKey(void);
void pceFontSetPos(int x, int y);
void pceFontGetPos(int *x, int *y);
void pceFontSetTxColor(int color);
void pceFontSetBkColor(int color);
int pceFontGetTxColor(void);
int pceFontGetBkColor(void);
void pceFontPutStr(char *str);
void pceFontPrintf(char *fmt, int val);
void pceFontPrintf2(char *fmt, int val1, int val2);
void pceFontPrintf3(char *fmt, int val1, int val2, int val3);

static int pceprint_x = 0;
static int pceprint_y = 0;
static int pceprint_color = 3;
static int pceprint_bkcolor = 0;

void pceLCDLineClip(long pal, long x1, long y1, long x2, long y2)
{
	drawGRPlineAbs(WP * (x1 * SCR_M + SCR_X), WP * (y1 * SCR_M + SCR_Y),
				   WP * (x2 * SCR_M + SCR_X), WP * (y2 * SCR_M + SCR_Y),
				   pceLCDGetPal(pal));
}

void pceLCDPoint(int pal, int x, int y)
{
	drawGRPpointAbs(WP * (x * SCR_M + SCR_X), WP * (y * SCR_M + SCR_Y), pceLCDGetPal(pal));
}

void pceLCDPaint(int pal, int x, int y, int sx, int sy)
{
	fillSDLsurface(GRP_PRIMARY,
				   WP * (x * SCR_M + SCR_X),        WP * (y * SCR_M + SCR_Y),
				   WP * ((x + sx) * SCR_M + SCR_X), WP * ((y + sy) * SCR_M + SCR_Y),
				   pceLCDGetPal(pal));
}

UINT32 pceLCDGetPal(int pal)
{
	switch(pal){
		case 0:
			return SDL_MapRGBA(primary->format, 255, 255, 255, 255);
		case 1:
			return SDL_MapRGBA(primary->format, 170, 170, 170, 255);
		case 2:
			return SDL_MapRGBA(primary->format, 85, 85, 85, 255);
		case 3:
			return SDL_MapRGBA(primary->format, 0, 0, 0, 255);
		default:
			break;
	}

	return SDL_MapRGBA(primary->format, 255, 255, 255, 255);
}

void pceLCDSetColorKey(void)
{
}

void pceFontSetPos(int x, int y)
{
	pceprint_x = (x * SCR_M) + SCR_X;
	pceprint_y = (y * SCR_M) + SCR_Y;
}

void pceFontGetPos(int *x, int *y)
{
	*x = pceprint_x;
	*y = pceprint_y;
}

void pceFontSetTxColor(int color)
{
	pceprint_color = color;
}

void pceFontSetBkColor(int color)
{
	pceprint_bkcolor = color;
}

int pceFontGetTxColor(void)
{
	return pceprint_color;
}

int pceFontGetBkColor(void)
{
	return pceprint_bkcolor;
}

void pceFontPutStr(char *str)
{
	drawASCII(str, WP * pceprint_x, WP * pceprint_y, 1 * WP, pceprint_color);
}

void pceFontPrintf(char *fmt, int val)
{
	char str[256];

	sprintf(str, fmt, val);
	drawASCII(str, WP * pceprint_x, WP * pceprint_y, 1 * WP, pceprint_color);
}

void pceFontPrintf2(char *fmt, int val1, int val2)
{
	char str[256];

	sprintf(str, fmt, val1, val2);
	drawASCII(str, WP * pceprint_x, WP * pceprint_y, 1 * WP, pceprint_color);
}

void pceFontPrintf3(char *fmt, int val1, int val2, int val3)
{
	char str[256];

	sprintf(str, fmt, val1, val2, val3);
	drawASCII(str, WP * pceprint_x, WP * pceprint_y, 1 * WP, pceprint_color);
}
