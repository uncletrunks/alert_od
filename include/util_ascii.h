#ifndef	_UTIL_
#define	_UTIL_

extern void initASCII(void);
extern void drawASCII(char *str, f32 px, f32 py, f32 s, int pal);
extern int serchASCIIdict(char word);
extern f32 getWidthASCII(char *str, f32 s);

#endif	/* _UTIL_ */
