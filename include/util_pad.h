#ifndef _UTIL_PAD_
#define _UTIL_PAD_

extern int initPAD(void);
extern void closePAD(void);
extern int getPAD(void);

extern int pad_type;
extern int pads;
extern int trgs;
extern int reps;
extern SDL_Joystick *joys;
extern Uint8 *keys;

#endif /* _UTIL_PAD_ */
