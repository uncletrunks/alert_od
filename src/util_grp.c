
#include <stdio.h>
#include <math.h>
#include "../include/general.h"
#include "../include/util_sdl.h"
#include "../include/graphic.h"

void initGRParea(f32 x1, f32 y1, f32 x2, f32 y2);
void drawGRPline(f32 x1, f32 y1, f32 x2, f32 y2, Uint32 color);
void drawGRPlineAbs(f32 x1, f32 y1, f32 x2, f32 y2, Uint32 color);
void drawGRPpoint(f32 x1, f32 y1, Uint32 color);
void drawGRPpointAbs(f32 x1, f32 y1, Uint32 color);

f32 grp_min_x = 0;
f32 grp_max_x = SCREEN_X;
f32 grp_min_y = 0;
f32 grp_max_y = SCREEN_Y;
f32 grp_size_x = SCREEN_X;
f32 grp_size_y = SCREEN_Y;

void initGRParea(f32 x1, f32 y1, f32 x2, f32 y2)
{
	grp_min_x = x1;
	grp_max_x = x2;
	grp_min_y = y1;
	grp_max_y = y2;
	grp_size_x = grp_max_x - grp_min_x;
	grp_size_y = grp_max_y - grp_min_y;
}

void drawGRPline(f32 x1, f32 y1, f32 x2, f32 y2, Uint32 color)
{
	f32 x, y, dx, dy, s, step;
	int i, j;

	dx = abs((x2 >> 16) - (x1 >> 16)) * WP;
	dy = abs((y2 >> 16) - (y1 >> 16)) * WP;

	x = x1;
	y = y1;
	if(x >= grp_max_x) x -= grp_size_x;
	if(x <  grp_min_x) x += grp_size_x;
	if(y >= grp_max_y) y -= grp_size_y;
	if(y <  grp_min_y) y += grp_size_y;

	if(dx > dy){
		if(x1 > x2){
			step = (y1 > y2) ? +1 * WP : -1 * WP;
			s = x1;
			x1 = x2;
			x2 = s;
			y1 = y2;
		}else{
			step = (y1 < y2) ? +1 * WP : -1 * WP;
		}
		pointSDLsurface(GRP_PRIMARY, x, y, color);
		s = dx / 2 * WP;
		i = x1 >> 16;
		j = x2 >> 16;
		while(++i <= j){
			x1 += 1 * WP;
			if(x1 >= grp_max_x) x1 -= grp_size_x;
			if(x1 <  grp_min_x) x1 += grp_size_x;
			s -= dy;
			if(s < 0){
				s += dx;
				y1 += step;
			}
			if(y1 >= grp_max_y) y1 -= grp_size_y;
			if(y1 <  grp_min_y) y1 += grp_size_y;
			pointSDLsurface(GRP_PRIMARY, x1, y1, color);
		}
	}else{
		if(y1 > y2){
			step = (x1 > x2) ? +1 * WP : -1 * WP;
			s = y1;
			y1 = y2;
			y2 = s;
			x1 = x2;
		}else{
			step = (x1 < x2)? +1 * WP : -1 * WP;
		}
		pointSDLsurface(GRP_PRIMARY, x, y, color);
		s = dy / 2 * WP;
		i = y1 >> 16;
		j = y2 >> 16;
		while(++i <= j){
			y1 += 1 * WP;
			if(y1 >= grp_max_y) y1 -= grp_size_y;
			if(y1 <  grp_min_y) y1 += grp_size_y;
			s -= dx;
			if(s < 0){
				s += dy;
				x1 += step;
			}
			if(x1 >= grp_max_x) x1 -= grp_size_x;
			if(x1 <  grp_min_x) x1 += grp_size_x;
			pointSDLsurface(GRP_PRIMARY, x1, y1, color);
		}
	}
}

void drawGRPlineAbs(f32 x1, f32 y1, f32 x2, f32 y2, Uint32 color)
{
	f32 x, y, dx, dy, s, step;
	int i, j;

	dx = abs((x2 >> 16) - (x1 >> 16)) * WP;
	dy = abs((y2 >> 16) - (y1 >> 16)) * WP;

	x = x1;
	y = y1;

	if(dx > dy){
		if(x1 > x2){
			step = (y1 > y2) ? +1 * WP : -1 * WP;
			s = x1;
			x1 = x2;
			x2 = s;
			y1 = y2;
		}else{
			step = (y1 < y2) ? +1 * WP : -1 * WP;
		}
		pointSDLsurfaceAbs(GRP_PRIMARY, x, y, color);
		s = dx / 2 * WP;
		i = x1 >> 16;
		j = x2 >> 16;
		while(++i <= j){
			x1 += 1 * WP;
			s -= dy;
			if(s < 0){
				s += dx;
				y1 += step;
			}
			pointSDLsurfaceAbs(GRP_PRIMARY, x1, y1, color);
		}
	}else{
		if(y1 > y2){
			step = (x1 > x2) ? +1 * WP : -1 * WP;
			s = y1;
			y1 = y2;
			y2 = s;
			x1 = x2;
		}else{
			step = (x1 < x2)? +1 * WP : -1 * WP;
		}
		pointSDLsurfaceAbs(GRP_PRIMARY, x, y, color);
		s = dy / 2 * WP;
		i = y1 >> 16;
		j = y2 >> 16;
		while(++i <= j){
			y1 += 1 * WP;
			s -= dx;
			if(s < 0){
				s += dy;
				x1 += step;
			}
			pointSDLsurfaceAbs(GRP_PRIMARY, x1, y1, color);
		}
	}
}

void drawGRPpoint(f32 x1, f32 y1, Uint32 color)
{
	pointSDLsurface(GRP_PRIMARY, x1, y1, color);
}

void drawGRPpointAbs(f32 x1, f32 y1, Uint32 color)
{
	pointSDLsurfaceAbs(GRP_PRIMARY, x1, y1, color);
}

