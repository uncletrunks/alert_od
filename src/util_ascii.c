
#include "../include/general.h"
#include "../include/util_sdl.h"
#include "../include/graphic.h"

void initASCII(void);
void drawASCII(char *str, f32 px, f32 py, f32 s, int pal);
int serchASCIIdict(char word);
f32 getWidthASCII(char *str, f32 s);

const int	ASC_CNTX = 16;
const int	ASC_CNTY = 16;
const f32	ASC_SIZEX = (8.0f);
const f32	ASC_SIZEY = (16.0f);

static char ascii_dict[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ      0123456789      !?#$%&{}=@*+-/¥_,.[]:;          \"'`<>\\^{|}~";
static int dict_max;
static int ascii_pal[4];

void initASCII(void)
{
	dict_max = strlen(ascii_dict);

	ascii_pal[0] = GRP_FONT01;
	ascii_pal[1] = GRP_FONT02;
	ascii_pal[2] = GRP_FONT03;
	ascii_pal[3] = GRP_FONT04;
}

void drawASCII(char *str, f32 px, f32 py, f32 s, int pal)
{
	int i;
	int word;
	int max;
	f32 nx, ny;
	SDL_Rect rect;
	int rgb, col;

	nx = px >> 16;
	ny = py >> 16;
	s >>= 16;

	max = strlen(str);
	col = pceFontGetBkColor();
	rgb = pceLCDGetPal(col);

	for(i = 0; i < max; i++){
		if((word = serchASCIIdict(str[i])) >= 0){
			if(col != -1){
				rect.x = nx;
				rect.y = ny;
				rect.w = rect.x + ASC_SIZEX * s;
				rect.h = rect.y + ASC_SIZEY * s;
				fillSDLsurface(GRP_PRIMARY, rect.x * WP, rect.y * WP, rect.w * WP, rect.h * WP, rgb);
			}
			rect.x = (word % ASC_CNTX) * ASC_SIZEX;
			rect.y = (word / ASC_CNTY) * ASC_SIZEY;
			rect.w = rect.x + ASC_SIZEX * s;
			rect.h = rect.y + ASC_SIZEY * s;
			dispSDLtexture(ascii_pal[pal], nx * WP, ny * WP, rect.x * WP, rect.y * WP, rect.w * WP, rect.h * WP);
			nx += ASC_SIZEX * s;
		}
	}
}

int serchASCIIdict(char word)
{
	int i;

	for(i = 0; i < dict_max; i++){
		if(ascii_dict[i] == word){
			return i;
		}
		if(islower(word) && ascii_dict[i] == toupper(word)){
			return i;
		}
	}

	return -1;
}

f32 getWidthASCII(char *str, f32 s)
{
	int i;
	int max;
	int word;
	f32 wx = 0.0f;

	max = strlen(str);

	for(i = 0; i < max; i++){
		if((word = serchASCIIdict(str[i])) >= 0) wx += ASC_SIZEX * s;
	}

	return wx * WP;
}
