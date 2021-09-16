#ifndef	_UTIL_SDL_
#define	_UTIL_SDL_

#include <SDL.h>
#include "../include/util_grp.h"

enum{
	SCREEN_X = 320,
	SCREEN_Y = 240,
	SCREEN_SX = SCREEN_X,
	SCREEN_SY = SCREEN_Y,

	SURFACE_MAX = 100,
};

#ifndef PI
#define PI 3.1415926535897932
#endif

#define FILL_BLIT 0

extern int initSDL(void);
extern void closeSDL(void);
extern void readSDLtexture(char *fname, int bank);
extern int createSDLsurface(int bank, int width, int height);
extern f32 getSDLtextureW(int bank);
extern f32 getSDLtextureH(int bank);
extern void dispSDLtexture(int bank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
extern void dispSDLtextureScale(int bank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey, f32 s);
extern void dispSDLtextureSurface(SDL_Surface *surf, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
extern void blitSDLtexture(int sbank, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
extern void blitSDLtextureScale(int sbank, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey, f32 s);
extern void blitSDLtextureSurface(SDL_Surface *surf, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
extern void clearSDL(void);
extern void flipSDL(void);
extern void setSDLcolorkey(int bank, Uint32 color);
extern void setSDLalpha(int bank, Uint8 alpha);
extern Uint32 getSDLpixel(SDL_Surface *surface, int x, int y);

extern inline void fillSDLsurface(int bank, f32 sx, f32 sy, f32 ex, f32 ey, Uint32 color);
extern inline void putSDLpixel(SDL_Surface *surface, f32 x, f32 y, Uint32 pixel);

#define pointSDLsurface(bank, px, py, color)\
{\
	if(px >= getGRPminx() && px < getGRPmaxx() && py >= getGRPminy() && py < getGRPmaxy()){\
		putSDLpixel(offscreen[bank], px, py, color);\
	}\
}

#define pointSDLsurfaceAbs(bank, px, py, color)\
{\
	if(px >= getGRPminx() && px < getGRPmaxx() && py >= getGRPminy() && py < getGRPmaxy()){\
		putSDLpixel(offscreen[bank], px, py, color);\
	}\
}

extern SDL_Surface *primary;
extern SDL_Surface *offscreen[SURFACE_MAX];

#endif /* _UTIL_SDL_ */
