#ifndef	_ACT_MAIN_
#define	_ACT_MAIN_

enum{
	MODE_INIT = 0,
	MODE_QUIT,
	MODE_GAME,
	MODE_OVER,
	MODE_CLEAR,
	MODE_DEMO,
	MODE_EXIT = -1,
};

enum{
	CHR_INIT = 0,
	CHR_MAIN,
	CHR_DAMAGE = 250,
	CHR_EXPLODE,
	CHR_DESTROY,
	CHR_EXIT = -1,
};

enum{
	GAME_EASY = 0,
	GAME_HARD,
	GAME_ENDLESS,
};

extern void actMain(ACT *actp);

#endif /* _ACT_MAIN_ */
