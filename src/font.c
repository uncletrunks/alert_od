
#include "../include/general.h"
#include "../include/custom.h"

static UINT8 font_sp[] = {
								9,
								20,
								0,
								0,
							};

static UINT8 font_a[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								 4, 8, 8, 4,
								12, 0, 4,20,
								 4,12, 4, 8,
								6,
								 0, 0,
								15, 0,
								 0,19,
								 7,19,
								12,19,
								15,19,
							};

static UINT8 font_b[] = {
								18,
								20,
								7,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								12, 4, 4, 4,
								 4, 8, 8, 4,
								12,12, 4, 4,
								 4,16, 8, 4,
								 4,12, 4, 4,
								8,
								 0, 0,
								11, 0,
								15, 4,
								15, 7,
								15,12,
								15,15,
								 0,19,
								11,19,
							};

static UINT8 font_c[] = {
								18,
								20,
								4,
								 0, 0, 4,20,
								 4, 0,12, 4,
								 4,16,12, 4,
								 4,12, 4, 4,
								7,
								 0, 0,
								15, 0,
								15, 3,
								 0,19,
								15,16,
								15,19,
								 7,12,
							};

static UINT8 font_d[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								 4,16, 8, 4,
								12, 4, 4,12,
								 4,12, 4, 4,
								7,
								 0, 0,
								11, 0,
								15, 4,
								15,15,
								 0,19,
								11,19,
								 7,12,
							};

static UINT8 font_e[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0,12, 4,
								 4, 8, 8, 4,
								 4,16,12, 4,
								 4,12, 4, 4,
								8,
								 0, 0,
								15, 0,
								15, 3,
								11, 8,
								11,11,
								 0,19,
								15,16,
								15,19,
							};

static UINT8 font_f[] = {
								18,
								20,
								4,
								 0, 0, 4,20,
								 4, 0,12, 4,
								 4, 8, 8, 4,
								 4,12, 4, 8,
								7,
								 0, 0,
								15, 0,
								15, 3,
								11, 8,
								11,11,
								 0,19,
								 7,19,
							};

static UINT8 font_g[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0,12, 4,
								 4,16,12, 4,
								12, 8, 4,12,
								 4,12, 4, 4,
								8,
								 0, 0,
								15, 0,
								15, 3,
								 0,19,
								15,19,
								12, 8,
								15, 8,
								 7,12,
							};

static UINT8 font_h[] = {
								18,
								20,
								4,
								 0, 0, 4,20,
								 4, 8, 8, 4,
								12, 0, 4,20,
								 4,12, 4, 8,
								8,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0,19,
								 7,19,
								12,19,
								15,19,
							};

static UINT8 font_i[] = {
								6,
								20,
								1,
								 0, 0, 4,20,
								4,
								 0, 0,
								 3, 0,
								 0,19,
								 3,19,
							};

static UINT8 font_j[] = {
								18,
								20,
								4,
								12, 0, 4,20,
								 0, 8, 4, 8,
								 0,16,16, 4,
								 4,12, 4, 4,
								7,
								12, 0,
								15, 0,
								 0, 8,
								 3, 8,
								 0,19,
								15,19,
								 7,12,
							};

static UINT8 font_k[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								12, 0, 4, 8,
								 4, 8, 8, 4,
								12,12, 4, 8,
								 4,12, 4, 8,
								10,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								15, 7,
								15,12,
								 0,19,
								 7,19,
								12,19,
								15,19,
							};

static UINT8 font_l[] = {
								18,
								20,
								3,
								 0, 0, 4,20,
								 4,16,12, 4,
								 4,12, 4, 4,
								6,
								 0, 0,
								 3, 0,
								 0,19,
								15,16,
								15,19,
								 7,12,
							};

static UINT8 font_m[] = {
								18,
								20,
								4,
								 0, 0, 4,20,
								 4, 4, 8, 8,
								12, 0, 4,20,
								 4,12, 4, 8,
								11,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0,19,
								 7,19,
								12,19,
								15,19,
								 7, 4,
								 8, 4,
								 8,11,
							};

static UINT8 font_n[] = {
								18,
								20,
								4,
								 0, 0, 4,20,
								 4, 4, 4,16,
								 8, 8, 4, 8,
								12, 0, 4,20,
								9,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0,19,
								 7,19,
								12,19,
								15,19,
								 7, 4,
							};

static UINT8 font_o[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								 4,16, 8, 4,
								12, 0, 4,20,
								 4,12, 4, 4,
								5,
								 0, 0,
								15, 0,
								 0,19,
								15,19,
								 7,12,
							};

static UINT8 font_p[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								 4, 8, 8, 4,
								12, 0, 4,12,
								 4,12, 4, 8,
								5,
								 0, 0,
								15, 0,
								15,11,
								 0,19,
								 7,19,
							};

static UINT8 font_q[] = {
								18,
								20,
								5,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								12, 0, 4,16,
								 4,16, 8, 4,
								 4,12, 4, 4,
								6,
								 0, 0,
								15, 0,
								 0,19,
								11,19,
								15,15,
								 7,12,
							};

static UINT8 font_r[] = {
								18,
								20,
								6,
								 0, 0, 4,20,
								 4, 0, 8, 4,
								 4, 8, 8, 4,
								12, 4, 4, 4,
								12,12, 4, 8,
								 4,12, 4, 8,
								9,
								 0, 0,
								11, 0,
								15, 4,
								15, 7,
								15,12,
								 0,19,
								 7,19,
								12,19,
								15,19,
							};

static UINT8 font_s[] = {
								18,
								20,
								6,
								 0, 0,16, 4,
								 0, 4, 4, 4,
								 0, 8,16, 4,
								12,12, 4, 4,
								 0,16,16, 4,
								 4, 4, 4, 4,
								8,
								 0, 0,
								15, 0,
								15, 3,
								15, 8,
								 0,11,
								 0,15,
								 0,19,
								15,19,
							};

static UINT8 font_t[] = {
								14,
								20,
								2,
								 0, 0,12, 4,
								 4, 4, 4,16,
								6,
								 0, 0,
								11, 0,
								 0, 3,
								11, 3,
								 4,19,
								 7,19,
							};

static UINT8 font_u[] = {
								18,
								20,
								4,
								 0, 0, 4,20,
								 4,16, 8, 4,
								12, 0, 4,20,
								 4,12, 4, 4,
								7,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0,19,
								15,19,
								 7,12,
							};

static UINT8 font_v[] = {
								18,
								20,
								4,
								 0, 0, 4,16,
								12, 0, 4,16,
								 4,16, 8, 4,
								 4,12, 4, 4,
								9,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0,15,
								15,15,
								 4,19,
								11,19,
								 7,12,
							};

static UINT8 font_w[] = {
								18,
								20,
								4,
								 0, 0, 4,16,
								 4, 8, 4,12,
								 8, 0, 4,20,
								12, 0, 4,16,
								12,
								 0, 0,
								 3, 0,
								 8, 0,
								11, 0,
								12, 0,
								15, 0,
								 0,15,
								15,15,
								 4,19,
								 7,19,
								 8,19,
								11,19,
							};

static UINT8 font_x[] = {
								18,
								20,
								5,
								 0, 0, 4, 8,
								12, 0, 4, 8,
								 4, 8, 8, 4,
								 0,12, 8, 8,
								12,12, 4, 8,
								12,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0, 7,
								15, 7,
								 0,12,
								15,12,
								 0,19,
								 7,19,
								12,19,
								15,19,
							};

static UINT8 font_y[] = {
								18,
								20,
								4,
								 0, 0, 4, 8,
								12, 0, 4, 8,
								 4, 8, 8,12,
								 4, 4, 4, 4,
								9,
								 0, 0,
								 3, 0,
								12, 0,
								15, 0,
								 0,11,
								15,11,
								 4,19,
								11,19,
								 7, 4,
							};

static UINT8 font_z[] = {
								18,
								20,
								5,
								 0, 0,16, 4,
								12, 4, 4, 4,
								 4, 8, 8, 4,
								 0,12, 8, 4,
								 0,16,16, 4,
								10,
								 0, 0,
								15, 0,
								 0, 3,
								15, 7,
								 4, 8,
								11,11,
								 0,12,
								 0,19,
								15,16,
								15,19,
							};

static UINT8 *font_list[] = {
									font_sp,
									font_a,
									font_b,
									font_c,
									font_d,
									font_e,
									font_f,
									font_g,
									font_h,
									font_i,
									font_j,
									font_k,
									font_l,
									font_m,
									font_n,
									font_o,
									font_p,
									font_q,
									font_r,
									font_s,
									font_t,
									font_u,
									font_v,
									font_w,
									font_x,
									font_y,
									font_z,
								};

static UINT8 font_dic[] = { " ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

void fontDispStr(SINT posx, SINT posy, UINT8 *str, SINT pal, SINT edge, BOOL flags);
int fontGetStrSize(UINT8 *str);

void fontDispStr(SINT posx, SINT posy, UINT8 *str, SINT pal, SINT edge, BOOL flags)
{
	SINT lp1;
	SINT max;
	UINT8 *font;
	UINT8 size_x;
	UINT8 size_y;
	SINT bpal;
	SINT len;

	if(flags == TRUE){
		bpal = pal;
		edge = pal;
		pal = 0;
	}else{
		bpal = 0;
	}

	len = strlen((char *)font_dic);

	for(; *str != '\0'; str++){
		for(lp1 = 0; lp1 < len; lp1++){
			if(*str == font_dic[lp1]){
				break;
			}
		}
		if(lp1 == len){
			return;
		}
		font = font_list[lp1];
		size_x = font[0];
		size_y = font[1];
		font += 2;
		if(bpal){
			pceLCDPaint(bpal, posx-1, posy-1, size_x, size_y+2);
		}
		max = font[0];
		font++;
		for(lp1 = 0; lp1 < max; lp1++){
			pceLCDPaint(pal, posx+font[0], posy+font[1], font[2], font[3]);
			font += 4;
		}
		max = font[0];
		font++;
		for(lp1 = 0; lp1 < max; lp1++){
			pceLCDPaint(edge, posx+font[0], posy+font[1], 1, 1);
			font += 2;
		}
		posx += size_x;
	}
}

int fontGetStrSize(UINT8 *str)
{
	SINT lp1;
	SINT max;
	SINT size = 0;
	UINT8 *font;
	SINT len;

	len = strlen((char *)font_dic);

	for(; *str != '\0'; str++){
		for(lp1 = 0; lp1 < len; lp1++){
			if(*str == font_dic[lp1]){
				break;
			}
		}
		if(lp1 == len){
			return	0;
		}
		font = font_list[lp1];
		size += font[0];
		font += 2;
		max = font[0];
		font++;
		for(lp1 = 0; lp1 < max; lp1++){
			font += 4;
		}
		max = font[0];
		font++;
		for(lp1 = 0; lp1 < max; lp1++){
			font += 2;
		}
	}

	return size;
}
