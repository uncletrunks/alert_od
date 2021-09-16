#ifndef	_UTIL_GRP_
#define	_UTIL_GRP_

extern void initGRParea(f32 x1, f32 y1, f32 x2, f32 y2);
extern void drawGRPline(f32 x1, f32 y1, f32 x2, f32 y2, Uint32 color);
extern void drawGRPlineAbs(f32 x1, f32 y1, f32 x2, f32 y2, Uint32 color);
extern void drawGRPpoint(f32 x1, f32 y1, Uint32 color);
extern void drawGRPpointAbs(f32 x1, f32 y1, Uint32 color);

extern f32 grp_min_x;
extern f32 grp_max_x;
extern f32 grp_min_y;
extern f32 grp_max_y;
extern f32 grp_size_x;
extern f32 grp_size_y;

#define getGRPminx() grp_min_x
#define getGRPmaxx() grp_max_x
#define getGRPminy() grp_min_y
#define getGRPmaxy() grp_max_y
#define getGRPsizex() grp_size_x
#define getGRPsizey() grp_size_y

#endif /* _UTIL_GRP_ */
