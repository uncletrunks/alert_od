#ifndef	_CUSTOM_
#define _CUSTOM_

#define CYGWIN

#define toFIXED(a) ((SINT32)(65536 * (a)))
#define DEGtoANG(d) ((ANGLE)((65536 * (d)) / 360))
#define WP 65536
#define WWP (WP*2)

#define MAX_X 128
#define MAX_Y 88
#define WIN_X 320
#define WIN_Y 240
#define VRAM_SIZE (MAX_X * MAX_Y)
#define CLIP_X MAX_X
#define CLIP_Y MAX_Y
#define SCR_M 2
#define SCR_X ((WIN_X - (MAX_X * SCR_M)) / 2)
#define SCR_Y ((WIN_X - (MAX_X * SCR_M)) / 2)

enum{
	GROUP_00 = 0,
	GROUP_01,
	GROUP_02,
	GROUP_03,
	GROUP_04,
	GROUP_05,
	GROUP_06,
	GROUP_07,
	GROUP_MAX
};

#define ACT_GROUP_MAX GROUP_MAX
#define ACT_MAX 1500

#define FLG_NONE 0x0000
#define FLG_SYSTEM 0x1000
#define FLG_PAUSE 0x8000

#define PAD_DN PAD_DOWN
#define PAD_LF PAD_LEFT
#define PAD_RI PAD_RIGHT
#define PAD_UP PAD_UP
#define PAD_A  PAD_BUTTON1
#define PAD_B  PAD_BUTTON2
#define PAD_C  PAD_BUTTON3
#define PAD_D  PAD_BUTTON4
#define TRG_DN PAD_DOWN
#define TRG_LF PAD_LEFT
#define TRG_RI PAD_RIGHT
#define TRG_UP PAD_UP
#define TRG_A  PAD_BUTTON1
#define TRG_B  PAD_BUTTON2
#define TRG_C  PAD_BUTTON3
#define TRG_D  PAD_BUTTON4

#define DIR_UP    0x0001
#define DIR_DOWN  0x0002
#define DIR_LEFT  0x0003
#define DIR_RIGHT 0x0004

#define PAD_DIR (PAD_RI+PAD_LF+PAD_DN+PAD_UP)

#define f_none 0x00
#define f_ship 0x01
#define f_sshot 0x02
#define f_enemy 0x03
#define f_eshot 0x04
#define f_chip 0x05
#define f_mship 0x06
#define f_nodmg 0x10
#define f_damage 0x80

#define get_cflag(act_p) ((act_p->chr_flag & 0x0F))
#define get_cstat(act_p, flag) ((act_p->chr_flag & 0xF0) == flag)

typedef struct tagCOLLISION COLLISION;
struct tagCOLLISION{
	SINT8	ofs[XY];
	SINT8	col[XY];
};

typedef struct tagACT ACT;
typedef void (*FUNC)(ACT *);

struct tagACT{
	UINT16 actid;
	UINT8 group_no;
	UINT8 chr_flag;
	ACT *prev_act;
	ACT *next_act;
	ACT *emptr;
	FUNC prog_adr;
	ACT *act_parent;
	ACT *act_ext;
	SINT32 pos[XY];
	SINT32 ofs[XY];
	SINT32 vel[XY];
	SINT32 trg[XY];
	SINT32 cen[XY];
	COLLISION *col;
	void *buff;
	int energy;
	int step;
	int wait;
	int cnt;
	int size;
	int num;
	int type;
	int color;
	int back;
	int bnum;
};

typedef struct tagGENV GENV;
struct tagGENV{
	SINT32	volume;
	SINT32	color;
	SINT32	blur;
	SINT32	stg_max;
};

extern GENV game_env;
extern GENV *genv_p;

#endif /* _CUSTOM_ */
