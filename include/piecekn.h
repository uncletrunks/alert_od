#ifndef	_PIECEKN_
#define	_PIECEKN_

extern void pceLCDLineClip(long pal, long x1, long y1, long x2, long y2);
extern void pceLCDPoint(int pal, int x, int y);
extern void pceLCDPaint(int pal, int x, int y, int sx, int sy);
extern UINT32 pceLCDGetPal(int pal);
extern void pceLCDSetColorKey(void);
extern void pceFontSetPos(int x, int y);
extern void pceFontGetPos(int *x, int *y);
extern void pceFontSetTxColor(int color);
extern void pceFontSetBkColor(int color);
extern int pceFontGetTxColor(void);
extern int pceFontGetBkColor(void);
extern void pceFontPutStr(char *str);
extern void pceFontPrintf(char *fmt, int val);
extern void pceFontPrintf2(char *fmt, int val1, int val2);
extern void pceFontPrintf3(char *fmt, int val1, int val2, int val3);

#define FC_SPRITE (-1)

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_endian.h>

#endif /* _PIECEKN_ */
