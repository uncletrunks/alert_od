
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/util_sdl.h"
#include "../include/util_grp.h"
#include "../include/graphic.h"

SDL_Surface *primary;
SDL_Surface *offscreen[SURFACE_MAX];

static int width = SCREEN_X;
static int height = SCREEN_Y;

int scr_width;
int scr_height;

static Uint32 fill_color;

#if	FILL_BLIT
static SDL_Rect clr_src;
static SDL_Rect clr_dst;
#endif

int initSDL(void);
void closeSDL(void);
void readSDLtexture(char *fname, int bank);
int createSDLsurface(int bank, int width, int height);
f32 getSDLtextureW(int bank);
f32 getSDLtextureH(int bank);
void dispSDLtexture(int bank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
void dispSDLtextureScale(int bank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey, f32 s);
void dispSDLtextureSurface(SDL_Surface *surf, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
void blitSDLtexture(int sbank, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
void blitSDLtextureScale(int sbank, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey, f32 s);
void blitSDLtextureSurface(SDL_Surface *surf, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey);
void clearSDL(void);
void flipSDL(void);
void setSDLcolorkey(int bank, Uint32 color);
void setSDLalpha(int bank, Uint8 alpha);
Uint32 getSDLpixel(SDL_Surface *surface, int x, int y);

int initSDL(void)
{
	int	i;
	Uint32 videoFlags;

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0){
		return	0;
    }

	videoFlags = SDL_SWSURFACE;
	primary = SDL_SetVideoMode(320,240,16,SDL_HWSURFACE|SDL_TRIPLEBUF);
	if(primary == NULL){
		return	0;
    }

	for(i = 0; i < SURFACE_MAX; i++){
		offscreen[i] = NULL;
	}

#ifndef GP2X
	offscreen[GRP_PRIMARY] = primary;
#else
	offscreen[GRP_PRIMARY] = primary;
	//createSDLsurface(GRP_PRIMARY, width, height);
#endif
	SDL_ShowCursor(SDL_DISABLE);
#ifndef GP2X
	SDL_WM_SetCaption("ALERT for SDL", NULL);
#else
	SDL_WM_SetCaption("ALERT for GP2X", NULL);
#endif

	scr_width  = SCREEN_SX;
	scr_height = SCREEN_SY;
	fill_color = SDL_MapRGBA(primary->format, 0, 0, 0, 255);
#if	FILL_BLIT
	if(createSDLsurface(GRP_FILL,scr_width,scr_height) != -1){
		fillSDLsurface(GRP_FILL, 0, 0, scr_width, scr_height, fill_color);
		clr_src.x = 0;
		clr_src.y = 0;
		clr_src.w = scr_width;
		clr_src.h = scr_height;
		clr_dst.x = 0;
		clr_dst.y = 0;
		clr_dst.w = scr_width;
		clr_dst.h = scr_height;
	}
#endif

	return	1;
}

void closeSDL(void)
{
	int	i;

#ifdef GP2X
	clearSDL();
	flipSDL();
	clearSDL();
	flipSDL();
#endif

	for(i = 1; i < SURFACE_MAX; i++){
		if(offscreen[i] && offscreen[i] != primary){
			SDL_FreeSurface(offscreen[i]);
			printf("free off-screen surface %d.\n", i);
		}
	}

#ifndef GP2X
	SDL_ShowCursor(SDL_ENABLE);
	SDL_Quit();
#endif
}

void readSDLtexture(char *fname, int bank)
{
	SDL_Surface* tmp;

	tmp = SDL_LoadBMP(fname);
	if(tmp){
		SDL_SetColorKey(tmp, SDL_SRCCOLORKEY, SDL_MapRGBA(primary->format,0,0,0,0));
		offscreen[bank] = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
	}
}

int createSDLsurface(int bank, int width, int height)
{
	Uint32 videoFlags;
    Uint32 rmask, gmask, bmask, amask;
	SDL_Surface *tmp;

	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
	videoFlags = 0;

	tmp = SDL_CreateRGBSurface(videoFlags, width, height, primary->format->BitsPerPixel, rmask, gmask, bmask, amask);

	if(tmp){
		offscreen[bank] = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
		return 0;
	}

	return -1;
}

f32 getSDLtextureW(int bank)
{
	return	offscreen[bank]->w;
}

f32 getSDLtextureH(int bank)
{
	return	offscreen[bank]->h;
}

void dispSDLtexture(int bank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey)
{
	SDL_Rect src;
	SDL_Rect dst;

	px >>= 16;
	py >>= 16;
	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	src.x = sx;
	src.y = sy;
	src.w = ex - sx;
	src.h = ey - sy;
	dst.x = px;
	dst.y = py;
	dst.w = src.w;
	dst.h = src.h;

	SDL_BlitSurface(offscreen[bank], &src, primary, &dst);
}

void dispSDLtextureScale(int bank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey, f32 s)
{
	SDL_Rect src;
	SDL_Rect dst;

	px >>= 16;
	py >>= 16;
	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	src.x = sx;
	src.y = sy;
	src.w = ex - sx;
	src.h = ey - sy;
	dst.x = px;
	dst.y = py;
	dst.w = src.w * s;
	dst.h = src.h * s;

	SDL_BlitSurface(offscreen[bank], &src, primary, &dst);
}

void dispSDLtextureSurface(SDL_Surface *surf, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey)
{
	SDL_Rect src;
	SDL_Rect dst;

	px >>= 16;
	py >>= 16;
	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	src.x = sx;
	src.y = sy;
	src.w = ex - sx;
	src.h = ey - sy;
	dst.x = px;
	dst.y = py;
	dst.w = src.w;
	dst.h = src.h;

	SDL_BlitSurface(surf, &src, primary, &dst);
}

void blitSDLtexture(int sbank, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey)
{
	SDL_Rect src;
	SDL_Rect dst;

	px >>= 16;
	py >>= 16;
	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	src.x = sx;
	src.y = sy;
	src.w = ex - sx;
	src.h = ey - sy;
	dst.x = px;
	dst.y = py;
	dst.w = src.w;
	dst.h = src.h;

	SDL_BlitSurface(offscreen[sbank], &src, offscreen[dbank], &dst);
}

void blitSDLtextureScale(int sbank, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey, f32 s)
{
	SDL_Rect src;
	SDL_Rect dst;

	px >>= 16;
	py >>= 16;
	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	src.x = sx;
	src.y = sy;
	src.w = ex - sx;
	src.h = ey - sy;
	dst.x = px;
	dst.y = py;
	dst.w = src.w * s;
	dst.h = src.h * s;

	SDL_BlitSurface(offscreen[sbank], &src, offscreen[dbank], &dst);
}

void blitSDLtextureSurface(SDL_Surface *surf, int dbank, f32 px, f32 py, f32 sx, f32 sy, f32 ex, f32 ey)
{
	SDL_Rect src;
	SDL_Rect dst;

	px >>= 16;
	py >>= 16;
	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	src.x = sx;
	src.y = sy;
	src.w = ex - sx;
	src.h = ey - sy;
	dst.x = px;
	dst.y = py;
	dst.w = src.w;
	dst.h = src.h;

	SDL_BlitSurface(surf, &src, offscreen[dbank], &dst);
}

void clearSDL(void)
{
#if	FILL_BLIT
	SDL_BlitSurface(offscreen[GRP_FILL], &clr_src, primary, &clr_dst);
#else
	SDL_FillRect(primary, NULL, fill_color);
#endif
}

void flipSDL(void)
{
	SDL_Flip(primary);
}

void setSDLcolorkey(int bank, Uint32 color)
{
	SDL_SetColorKey(offscreen[bank], SDL_SRCCOLORKEY, color);
}

void setSDLalpha(int bank, Uint8 alpha)
{
	SDL_SetAlpha(offscreen[bank], SDL_SRCALPHA, alpha);
}

Uint32 getSDLpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + (y >> 16) * surface->pitch + (x >> 16) * bpp;

    switch(bpp) {
	    case 1:
	        return *p;
	    case 2:
	        return *(Uint16 *)p;
	    case 3:
	        if(SDL_BYTEORDER == SDL_BIG_ENDIAN){
	            return p[0] << 16 | p[1] << 8 | p[2];
	        }else{
	            return p[0] | p[1] << 8 | p[2] << 16;
	            }
	    case 4:
	        return *(Uint32 *)p;
	    default:
	        return 0;
    }
}

inline void fillSDLsurface(int bank, f32 sx, f32 sy, f32 ex, f32 ey, Uint32 color)
{
	SDL_Rect rect;

	sx >>= 16;
	sy >>= 16;
	ex >>= 16;
	ey >>= 16;

	rect.x = sx;
	rect.y = sy;
	rect.w = ex - sx;
	rect.h = ey - sy;
	SDL_FillRect(offscreen[bank], &rect, color);
}

inline void putSDLpixel(SDL_Surface *surface, f32 x, f32 y, Uint32 pixel)
{
	register int bpp = surface->format->BytesPerPixel;
	register Uint8 *pixels = (Uint8 *)surface->pixels;
	register Uint16 pitch = surface->pitch;
	register Uint8 *p1 = pixels + ((y + 0 * WP) >> 16) * pitch + ((x + 0 * WP) >> 16) * bpp;
	register Uint8 *p2 = pixels + ((y + 1 * WP) >> 16) * pitch + ((x + 0 * WP) >> 16) * bpp;
	register Uint8 *p3 = pixels + ((y + 0 * WP) >> 16) * pitch + ((x + 1 * WP) >> 16) * bpp;
	register Uint8 *p4 = pixels + ((y + 1 * WP) >> 16) * pitch + ((x + 1 * WP) >> 16) * bpp;

    switch(bpp){
	    case 1:
	        *p1 = pixel;
	        *p2 = pixel;
	        *p3 = pixel;
	        *p4 = pixel;
	        break;
	    case 2:
	        *(Uint16 *)p1 = pixel;
	        *(Uint16 *)p2 = pixel;
	        *(Uint16 *)p3 = pixel;
	        *(Uint16 *)p4 = pixel;
	        break;
	    case 3:
	        if(SDL_BYTEORDER == SDL_BIG_ENDIAN){
	            p1[0] = (pixel >> 16) & 0xff;
	            p1[1] = (pixel >> 8) & 0xff;
	            p1[2] = pixel & 0xff;
	            p2[0] = (pixel >> 16) & 0xff;
	            p2[1] = (pixel >> 8) & 0xff;
	            p2[2] = pixel & 0xff;
	            p3[0] = (pixel >> 16) & 0xff;
	            p3[1] = (pixel >> 8) & 0xff;
	            p3[2] = pixel & 0xff;
	            p4[0] = (pixel >> 16) & 0xff;
	            p4[1] = (pixel >> 8) & 0xff;
	            p4[2] = pixel & 0xff;
	        }else{
	            p1[0] = pixel & 0xff;
	            p1[1] = (pixel >> 8) & 0xff;
	            p1[2] = (pixel >> 16) & 0xff;
	            p2[0] = pixel & 0xff;
	            p2[1] = (pixel >> 8) & 0xff;
	            p2[2] = (pixel >> 16) & 0xff;
	            p3[0] = pixel & 0xff;
	            p3[1] = (pixel >> 8) & 0xff;
	            p3[2] = (pixel >> 16) & 0xff;
	            p4[0] = pixel & 0xff;
	            p4[1] = (pixel >> 8) & 0xff;
	            p4[2] = (pixel >> 16) & 0xff;
	        }
	        break;
	    case 4:
	        *(Uint32 *)p1 = pixel;
	        *(Uint32 *)p2 = pixel;
	        *(Uint32 *)p3 = pixel;
	        *(Uint32 *)p4 = pixel;
	        break;
    }
}
