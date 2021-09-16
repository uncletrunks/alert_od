
#include "../include/general.h"
#include "../include/custom.h"
#include "../include/act.h"
#include "../include/block.h"
#include "../include/dconv.h"
#include "../include/work.h"
#include "../include/font.h"
#include "../include/util_snd.h"

#include "../include/act_main.h"
#include "../include/act_enemy.h"
#include "../include/act_effect.h"

static ENEMY Boss01[] = {
								{ { +0, +0},{20,20} },
							};
static ENEMY Boss02[] = {
								{ { -6, -6},{ 8, 8} },
								{ { +6, -6},{ 8, 8} },
								{ { -6, +6},{ 8, 8} },
								{ { +6, +6},{ 8, 8} },
								{ { +0, +0},{12,12} },
							};
static ENEMY Boss03[] = {
								{ { +0, +0},{20,12} },
								{ { +0, +0},{12,20} },
							};
static ENEMY Boss04[] = {
								{ { +0, +0},{20,12} },
								{ { -4, +0},{ 4,20} },
								{ { +4, +0},{ 4,20} },
							};
static ENEMY Boss05[] = {
								{ { +0, -6},{20, 8} },
								{ { +0, +0},{12, 4} },
								{ { +0, +6},{20, 8} },
							};

static ENEMY *BossTbl[] = {
								&Boss01[0],
								&Boss02[0],
								&Boss03[0],
								&Boss04[0],
								&Boss05[0],
							};

static SINT8 BossSize[] = {
								(sizeof(Boss01) / sizeof(ENEMY)),
								(sizeof(Boss02) / sizeof(ENEMY)),
								(sizeof(Boss03) / sizeof(ENEMY)),
								(sizeof(Boss04) / sizeof(ENEMY)),
								(sizeof(Boss05) / sizeof(ENEMY)),
							};

static COLLISION BossColl01[] = {
								{ { +0, +0},{+11,+11} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION BossColl02[] = {
								{ { -6, -6},{ +5, +5} },
								{ { +6, -6},{ +5, +5} },
								{ { -6, +6},{ +5, +5} },
								{ { +6, +6},{ +5, +5} },
								{ { +0, +0},{ +7, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION BossColl03[] = {
								{ { +0, +0},{+11, +7} },
								{ { +0, +0},{ +7,+11} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION BossColl04[] = {
								{ { +0, +0},{+11, +7} },
								{ { -4, +0},{ +3,+11} },
								{ { +4, +0},{ +3,+11} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION BossColl05[] = {
								{ { +0, -6},{+11, +5} },
								{ { +0, +0},{ +7, +3} },
								{ { +0, +6},{+11, +5} },
								{ { -1, -1},{ -1, -1} },
							};

static COLLISION *BossCollision[] = {
								&BossColl01[0],
								&BossColl02[0],
								&BossColl03[0],
								&BossColl04[0],
								&BossColl05[0],
							};

static ENEMY Option01[] = {
								{ { +2, +0},{ 8, 4} },
								{ { -4, +0},{ 4,12} },
							};
static ENEMY Option02[] = {
								{ { +4, -4},{ 4, 4} },
								{ { -2, +0},{ 8,12} },
							};
static ENEMY Option03[] = {
								{ { +2, -4},{ 8, 4} },
								{ { -4, +0},{ 4,12} },
							};
static ENEMY Option04[] = {
								{ { +2, -4},{ 8, 4} },
								{ { -4, +0},{ 4,12} },
								{ { +2, +4},{ 8, 4} },
							};
static ENEMY Option05[] = {
								{ { +0, -4},{12, 4} },
								{ { +2, +0},{ 8, 4} },
								{ { +4, +4},{ 4, 4} },
							};
static ENEMY Option06[] = {
								{ { +0, -4},{12, 4} },
								{ { +0, +2},{ 4, 8} },
							};
static ENEMY Option07[] = {
								{ { -4, +0},{ 4,12} },
								{ { +0, +0},{ 4, 4} },
								{ { +4, +0},{ 4,12} },
							};
static ENEMY Option08[] = {
								{ { +0, -4},{12, 4} },
								{ { -4, +2},{ 4, 8} },
								{ { +4, +2},{ 4, 8} },
							};
static ENEMY Option09[] = {
								{ { +0, -2},{12, 8} },
								{ { +0, +4},{ 4, 4} },
							};
static ENEMY Option10[] = {
								{ { +0, -2},{12, 8} },
								{ { -4, +4},{ 4, 4} },
								{ { +4, +4},{ 4, 4} },
							};
static ENEMY Option11[] = {
								{ { -2, +0},{ 8, 4} },
								{ { +4, +0},{ 4,12} },
							};
static ENEMY Option12[] = {
								{ { -4, -4},{ 4, 4} },
								{ { +2, +0},{ 8,12} },
							};
static ENEMY Option13[] = {
								{ { -2, -4},{ 8, 4} },
								{ { +4, +0},{ 4,12} },
							};
static ENEMY Option14[] = {
								{ { -2, -4},{ 8, 4} },
								{ { +4, +0},{ 4,12} },
								{ { -2, +4},{ 8, 4} },
							};
static ENEMY Option15[] = {
								{ { +0, -4},{12, 4} },
								{ { -2, +0},{ 8, 4} },
								{ { -4, +4},{ 4, 4} },
							};
static ENEMY Option16[] = {
								{ { +0, -4},{12, 4} },
								{ { +0, +2},{ 4, 8} },
							};
static ENEMY Option17[] = {
								{ { +4, +0},{ 4,12} },
								{ { +0, +0},{ 4, 4} },
								{ { -4, +0},{ 4,12} },
							};
static ENEMY Option18[] = {
								{ { +0, -4},{12, 4} },
								{ { +4, +2},{ 4, 8} },
								{ { -4, +2},{ 4, 8} },
							};
static ENEMY Option19[] = {
								{ { +0, -2},{12, 8} },
								{ { +0, +4},{ 4, 4} },
							};
static ENEMY Option20[] = {
								{ { +0, -2},{12, 8} },
								{ { +4, +4},{ 4, 4} },
								{ { -4, +4},{ 4, 4} },
							};

static ENEMY *OptionTbl[] = {
								/* left */
								&Option01[0],
								&Option02[0],
								&Option03[0],
								&Option04[0],
								&Option05[0],
								&Option06[0],
								&Option07[0],
								&Option08[0],
								&Option09[0],
								&Option10[0],
								/* right */
								&Option11[0],
								&Option12[0],
								&Option13[0],
								&Option14[0],
								&Option15[0],
								&Option16[0],
								&Option17[0],
								&Option18[0],
								&Option19[0],
								&Option20[0],
							};

static SINT8 OptionSize[] = {
								/* left */
								(sizeof(Option01) / sizeof(ENEMY)),
								(sizeof(Option02) / sizeof(ENEMY)),
								(sizeof(Option03) / sizeof(ENEMY)),
								(sizeof(Option04) / sizeof(ENEMY)),
								(sizeof(Option05) / sizeof(ENEMY)),
								(sizeof(Option06) / sizeof(ENEMY)),
								(sizeof(Option07) / sizeof(ENEMY)),
								(sizeof(Option08) / sizeof(ENEMY)),
								(sizeof(Option09) / sizeof(ENEMY)),
								(sizeof(Option10) / sizeof(ENEMY)),
								/* right */
								(sizeof(Option11) / sizeof(ENEMY)),
								(sizeof(Option12) / sizeof(ENEMY)),
								(sizeof(Option13) / sizeof(ENEMY)),
								(sizeof(Option14) / sizeof(ENEMY)),
								(sizeof(Option15) / sizeof(ENEMY)),
								(sizeof(Option16) / sizeof(ENEMY)),
								(sizeof(Option17) / sizeof(ENEMY)),
								(sizeof(Option18) / sizeof(ENEMY)),
								(sizeof(Option19) / sizeof(ENEMY)),
								(sizeof(Option20) / sizeof(ENEMY)),
							};

static COLLISION OptionColl01[] = {
								{ { +2, +0},{ +5, +3} },
								{ { -4, +0},{ +3, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl02[] = {
								{ { +4, -4},{ +3, +3} },
								{ { -2, +0},{ +5, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl03[] = {
								{ { +2, -4},{ +5, +3} },
								{ { -4, +0},{ +3, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl04[] = {
								{ { +2, -4},{ +5, +3} },
								{ { -4, +0},{ +3, +7} },
								{ { +2, +4},{ +5, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl05[] = {
								{ { +0, -4},{ +7, +3} },
								{ { +2, +0},{ +5, +3} },
								{ { +4, +4},{ +3, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl06[] = {
								{ { +0, -4},{ +7, +3} },
								{ { +2, +0},{ +5, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl07[] = {
								{ { -4, +0},{ +3, +7} },
								{ { +0, +0},{ +3, +3} },
								{ { +4, +0},{ +3, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl08[] = {
								{ { +0, -4},{ +7, +3} },
								{ { -4, +2},{ +3, +5} },
								{ { +4, +2},{ +3, +5} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl09[] = {
								{ { +0, -2},{ +7, +5} },
								{ { +0, +4},{ +3, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl10[] = {
								{ { +0, -2},{ +7, +5} },
								{ { -4, +4},{ +3, +3} },
								{ { -4, +4},{ +3, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl11[] = {
								{ { -2, +0},{ +5, +3} },
								{ { +4, +0},{ +3, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl12[] = {
								{ { -4, -4},{ +3, +3} },
								{ { +2, +0},{ +5, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl13[] = {
								{ { -2, -4},{ +5, +3} },
								{ { +4, +0},{ +3, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl14[] = {
								{ { -2, -4},{ +5, +3} },
								{ { +4, +0},{ +3, +7} },
								{ { -2, +4},{ +5, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl15[] = {
								{ { +0, -4},{ +7, +3} },
								{ { -2, +0},{ +5, +3} },
								{ { -4, +4},{ +3, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl16[] = {
								{ { +0, -4},{ +7, +3} },
								{ { -2, +0},{ +5, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl17[] = {
								{ { -4, +0},{ +3, +7} },
								{ { +0, +0},{ +3, +3} },
								{ { +4, +0},{ +3, +7} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl18[] = {
								{ { +0, -4},{ +7, +3} },
								{ { +4, +2},{ +3, +5} },
								{ { -4, +2},{ +3, +5} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl19[] = {
								{ { +0, -2},{ +7, +5} },
								{ { +0, +4},{ +3, +3} },
								{ { -1, -1},{ -1, -1} },
							};
static COLLISION OptionColl20[] = {
								{ { +0, -2},{ +7, +5} },
								{ { +4, +4},{ +3, +3} },
								{ { +4, +4},{ +3, +3} },
								{ { -1, -1},{ -1, -1} },
							};

static COLLISION *OptionCollision[] = {
								/* left */
								&OptionColl01[0],
								&OptionColl02[0],
								&OptionColl03[0],
								&OptionColl04[0],
								&OptionColl05[0],
								&OptionColl06[0],
								&OptionColl07[0],
								&OptionColl08[0],
								&OptionColl09[0],
								&OptionColl10[0],
								/* right */
								&OptionColl11[0],
								&OptionColl12[0],
								&OptionColl13[0],
								&OptionColl14[0],
								&OptionColl15[0],
								&OptionColl16[0],
								&OptionColl17[0],
								&OptionColl18[0],
								&OptionColl19[0],
								&OptionColl20[0],
							};

static BULOFS OptBul01[] = {
								{ { -4*WP, +4*WP} },
							};
static BULOFS OptBul02[] = {
								{ { -2*WP, +0*WP} },
							};
static BULOFS OptBul03[] = {
								{ { -4*WP, +4*WP} },
							};
static BULOFS OptBul04[] = {
								{ { -4*WP, -4*WP} },
								{ { -4*WP, +4*WP} },
							};
static BULOFS OptBul05[] = {
								{ { -4*WP, -4*WP} },
								{ { +0*WP, +0*WP} },
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul06[] = {
								{ { +0*WP, +4*WP} },
							};
static BULOFS OptBul07[] = {
								{ { +0*WP, +0*WP} },
							};
static BULOFS OptBul08[] = {
								{ { -4*WP, +4*WP} },
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul09[] = {
								{ { +0*WP, +4*WP} },
							};
static BULOFS OptBul10[] = {
								{ { -4*WP, +4*WP} },
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul11[] = {
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul12[] = {
								{ { +2*WP, +0*WP} },
							};
static BULOFS OptBul13[] = {
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul14[] = {
								{ { +4*WP, -4*WP} },
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul15[] = {
								{ { +4*WP, -4*WP} },
								{ { +0*WP, +0*WP} },
								{ { -4*WP, +4*WP} },
							};
static BULOFS OptBul16[] = {
								{ { +0*WP, +4*WP} },
							};
static BULOFS OptBul17[] = {
								{ { +0*WP, +0*WP} },
							};
static BULOFS OptBul18[] = {
								{ { -4*WP, +4*WP} },
								{ { +4*WP, +4*WP} },
							};
static BULOFS OptBul19[] = {
								{ { +0*WP, +4*WP} },
							};
static BULOFS OptBul20[] = {
								{ { -4*WP, +4*WP} },
								{ { +4*WP, +4*WP} },
							};

static BULOFS *OptBulTbl[] = {
								/* left */
								&OptBul01[0],
								&OptBul02[0],
								&OptBul03[0],
								&OptBul04[0],
								&OptBul05[0],
								&OptBul06[0],
								&OptBul07[0],
								&OptBul08[0],
								&OptBul09[0],
								&OptBul10[0],
								/* right */
								&OptBul11[0],
								&OptBul12[0],
								&OptBul13[0],
								&OptBul14[0],
								&OptBul15[0],
								&OptBul16[0],
								&OptBul17[0],
								&OptBul18[0],
								&OptBul19[0],
								&OptBul20[0],
							};

static SINT8 OptBulSize[] = {
								/* left */
								(sizeof(OptBul01) / sizeof(BULOFS)),
								(sizeof(OptBul02) / sizeof(BULOFS)),
								(sizeof(OptBul03) / sizeof(BULOFS)),
								(sizeof(OptBul04) / sizeof(BULOFS)),
								(sizeof(OptBul05) / sizeof(BULOFS)),
								(sizeof(OptBul06) / sizeof(BULOFS)),
								(sizeof(OptBul07) / sizeof(BULOFS)),
								(sizeof(OptBul08) / sizeof(BULOFS)),
								(sizeof(OptBul09) / sizeof(BULOFS)),
								(sizeof(OptBul10) / sizeof(BULOFS)),
								/* right */
								(sizeof(OptBul11) / sizeof(BULOFS)),
								(sizeof(OptBul12) / sizeof(BULOFS)),
								(sizeof(OptBul13) / sizeof(BULOFS)),
								(sizeof(OptBul14) / sizeof(BULOFS)),
								(sizeof(OptBul15) / sizeof(BULOFS)),
								(sizeof(OptBul16) / sizeof(BULOFS)),
								(sizeof(OptBul17) / sizeof(BULOFS)),
								(sizeof(OptBul18) / sizeof(BULOFS)),
								(sizeof(OptBul19) / sizeof(BULOFS)),
								(sizeof(OptBul20) / sizeof(BULOFS)),
							};

static UINT8 BulletTable[][16] = {
								/* EASY */
								{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3},
								{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3},
								{ 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 4},
								{ 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 4},
								{ 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5},
								{ 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5},
								/* HARD */                                    
								{ 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4},
								{ 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4},
								{ 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4},
								{ 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4},
								{ 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4},
								{ 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4},
								{ 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5},
								{ 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5},
								{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5},
								{ 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6},
								{ 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6},
								{ 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6},
							};

static UINT16	BulletCtrl[16];

static COLLISION ChipColl[] = {
								{ { +0, +0},{ +4, +4} },
								{ { -1, -1},{ -1, -1} },
							};

static SINT EnemyLevel;
static SINT EnemyOptCnt;
static SINT EnemyTable[12];
static SINT EnemyShotMax;
static SINT EnemyShotNow;
static SINT EnemyShotBoss;
static SINT32 opt_ofsL[] = {
								-16 * WP, -4 * WP,
								-16 * WP,-16 * WP,
								-16 * WP, +8 * WP,
								-28 * WP, -4 * WP,
								-28 * WP,-16 * WP,
								-28 * WP, +8 * WP,
								-40 * WP, -4 * WP,
								-40 * WP,-16 * WP,
								-40 * WP, +8 * WP,
								-52 * WP, -4 * WP,
								-52 * WP,-16 * WP,
								-52 * WP, +8 * WP,
							};
static SINT32 opt_ofsR[] = {
								+16 * WP, -4 * WP,
								+16 * WP,-16 * WP,
								+16 * WP, +8 * WP,
								+28 * WP, -4 * WP,
								+28 * WP,-16 * WP,
								+28 * WP, +8 * WP,
								+40 * WP, -4 * WP,
								+40 * WP,-16 * WP,
								+40 * WP, +8 * WP,
								+52 * WP, -4 * WP,
								+52 * WP,-16 * WP,
								+52 * WP, +8 * WP,
							};
static COLLISION col_bullet[] = {
									{ {  +0, +0 },{  +2,  +2 } },
									{ {  -1, -1 },{  -1,  -1 } },
								};
static SINT8 shot_cnt[] = {
								16,
								18,
								20,
								22,
								24,
								26,
								28,
								30,
								32,

								36,
								40,
								44,
								48,
								52,
								56,
								60,
								64,
								68,

								72,
								76,
								80,
								84,
								88,
								90,
								92,
								96,
								98,

								100,
								102,
								104,
								108,
								110,
								112,
								114,
								116,
								118,

								120,
								121,
								122,
								123,
								124,
								125,
								126,
								127,
								128,
							};

void actEnemy(ACT *actp);

static void actBossMain(ACT *actp);
static void actOptionMain(ACT *actp);
static void actBulletCtrl(ACT *actp);
static void actBulletMain(ACT *actp);

static void scoretExtendChk(SINT score);
static void actBossMove(ACT *actp);

void actEnemy(ACT *actp)
{
	SINT i;
	SINT max;
	ACT *eactp;
	ACT *cactp;
	UINT8 *bulp;

	switch(actp->step){
		case CHR_INIT:
			if(work[WRK_MODE] != MODE_DEMO){
				EnemyLevel = 1;
			}else{
				EnemyLevel = DCNVrand(12) + 1;
			}
			EnemyShotNow = 0;
			work[WRK_OPTIONS] = 0;
			ACTnextStep();
			break;

		case CHR_MAIN:
			EnemyOptCnt = EnemyLevel;
			if((work[WRK_GAME] == GAME_EASY && EnemyOptCnt == 7) ||
				(work[WRK_GAME] == GAME_HARD && EnemyOptCnt == 13)){
				actp->pos[X] =  +0 * WP;
				actp->cen[X] = -68 * WP;
				actp->trg[X] = -(fontGetStrSize((UINT8 *)"COMPLETE ")) * WP;
				actp->vel[X] = -(WP / 1);
				actp->cnt = 0;
				work[WRK_WAIT] = 5 * 60;
				ACTsetStep(CHR_MAIN+5);
				break;
			}
			EnemyOptCnt = (EnemyOptCnt < (sizeof(EnemyTable) / sizeof(EnemyTable[0])) ? EnemyOptCnt : (sizeof(EnemyTable) / sizeof(EnemyTable[0])));
			bulp = BulletTable[EnemyOptCnt - 1 + (12 * (work[WRK_GAME] == GAME_EASY ? 0 : 1))];
			for(i = 0; i < 16; i++){
				BulletCtrl[i] = (UINT16)bulp[i];
			}
			DCNVshuffleMain(16,BulletCtrl);
			actp->cnt = 150;
			actp->pos[X] =  +0 * WP;
			actp->cen[X] = -64 * WP;
			actp->trg[X] = -(fontGetStrSize((UINT8 *)"ALERT ")) * WP;
			actp->vel[X] = -(WP / 1);
			ACTnextStep();
			break;
		case CHR_MAIN+1:
			actp->pos[X] += actp->vel[X];
			actp->cen[X] -= actp->vel[X];
			if(!soundIsPlaySe(SE_ALERT)){
				soundPlaySe(SE_ALERT);
			}
			if(actp->pos[X] < actp->trg[X]){
				actp->pos[X] += (0 * WP - actp->trg[X]);
			}
			if(actp->cen[X] > (0 * WP)){
				actp->cen[X] += (-64 * WP - 0 * WP);
			}
			if(actp->cnt & 0x1F){
				fontDispStr((actp->pos[X] / WP), 32, (UINT8 *)"ALERT ALERT ALERT", (actp->cnt & 0x1F) / 8, 1, TRUE);
				pceFontSetBkColor((actp->cnt & 0x1F) / 8);
				pceFontSetTxColor(0x00);
				pceFontSetPos((actp->cen[X] / WP), 24);
				pceFontPrintf3("ENEMY LEVEL %02d  ENEMY LEVEL %02d  ENEMY LEVEL %02d  ", EnemyOptCnt, EnemyOptCnt, EnemyOptCnt);
				pceFontSetPos((actp->cen[X] / WP), 53);
				pceFontPrintf3("ENEMY LEVEL %02d  ENEMY LEVEL %02d  ENEMY LEVEL %02d  ", EnemyOptCnt, EnemyOptCnt, EnemyOptCnt);
				pceFontSetBkColor(FC_SPRITE);
				pceFontSetTxColor(0x03);
			}
			actp->cnt--;
			if(!actp->cnt){
				ACTnextStep();
			}
			break;
		case CHR_MAIN+2:
			max = EnemyLevel - 1;
			max = (max < (sizeof(shot_cnt) / sizeof(SINT8)) ? max : (sizeof(shot_cnt) / sizeof(SINT8)) - 1);
			EnemyShotMax = shot_cnt[max];
			EnemyShotBoss = 0;
			if(work[WRK_GAME] == GAME_EASY){
				EnemyShotMax /= 2;
			}else{
				EnemyShotMax = EnemyShotMax * 2;
			}
			for(i = 0; i < EnemyOptCnt; i++){
				EnemyTable[i] = DCNVrand(sizeof(OptionTbl) / sizeof(ENEMY *) / 2);
			}
			eactp = ACTsetTop(actBossMain,GROUP_02);
			eactp->num = DCNVrand(sizeof(BossTbl) / sizeof(ENEMY *));
			for(i = 0; i < EnemyOptCnt; i++){
				/* left */
				cactp = ACTsetTop(actOptionMain,GROUP_02);
				cactp->act_parent = eactp;
				cactp->num = EnemyTable[i];
				cactp->ofs[X] = opt_ofsL[i * 2 + 0];
				cactp->ofs[Y] = opt_ofsL[i * 2 + 1];
				work[WRK_OPTIONS]++;
				/* right */
				cactp = ACTsetTop(actOptionMain,GROUP_02);
				cactp->act_parent = eactp;
				cactp->num = EnemyTable[i] + (sizeof(OptionTbl) / sizeof(ENEMY *) / 2);
				cactp->ofs[X] = opt_ofsR[i * 2 + 0];
				cactp->ofs[Y] = opt_ofsR[i * 2 + 1];
				work[WRK_OPTIONS]++;
			}
			work[WRK_BULLET]     = 0;
			work[WRK_BOSSMAX]    =
			work[WRK_BOSSENEMY]  = 500 + (EnemyOptCnt * 15);
			work[WRK_BOSSBROKEN] = 0;
			work[WRK_LIMIT]      = work[WRK_BOSSENEMY] * 2;
			ACTnextStep();
			break;
		case CHR_MAIN+3:
			if(work[WRK_BOSSBROKEN]){
				actp->wait = 120;
				ACTnextStep();
			}
			break;
		case CHR_MAIN+4:
			actp->wait--;
			if(!actp->wait){
				EnemyLevel += 1;
				ACTsetStep(CHR_MAIN);
			}
			break;
		case CHR_MAIN+5:
			if(actp->cnt < 24){
				actp->cnt++;
			}
			actp->pos[X] += actp->vel[X];
			actp->cen[X] -= actp->vel[X];
			if(actp->pos[X] < actp->trg[X]){
				actp->pos[X] += (0 * WP - actp->trg[X]);
			}
			if(actp->cen[X] > (0 * WP)){
				actp->cen[X] += (-68 * WP - 0 * WP);
			}
			if((actp->cnt / 8)){
				fontDispStr((actp->pos[X] / WP), 32, (UINT8 *)"COMPLETE COMPLETE ", (actp->cnt / 8), 1, TRUE);
				pceFontSetBkColor((actp->cnt / 8));
				pceFontSetTxColor(0x00);
				pceFontSetPos((actp->cen[X] / WP), 24);
				pceFontPutStr("CONGRATULATIONS! CONGRATULATIONS! CONGRATULATIONS! ");
				pceFontSetPos((actp->cen[X] / WP), 53);
				pceFontPutStr("CONGRATULATIONS! CONGRATULATIONS! CONGRATULATIONS! ");
				pceFontSetBkColor(FC_SPRITE);
				pceFontSetTxColor(0x03);
			}
			work[WRK_WAIT]--;
			if(!work[WRK_WAIT]){
				work[WRK_MODE] = MODE_CLEAR;
				work[WRK_WAIT] = 60;
				ACTnextStep();
			}
			break;
		case CHR_MAIN+6:
			if(actp->cnt){
				actp->cnt--;
			}
			actp->pos[X] += actp->vel[X];
			actp->cen[X] -= actp->vel[X];
			if(actp->pos[X] < actp->trg[X]){
				actp->pos[X] += (0 * WP - actp->trg[X]);
			}
			if(actp->cen[X] > (0 * WP)){
				actp->cen[X] += (-68 * WP - 0 * WP);
			}
			if((actp->cnt / 8)){
				fontDispStr((actp->pos[X] / WP), 32, (UINT8 *)"COMPLETE COMPLETE ", (actp->cnt / 8), 1, TRUE);
				pceFontSetBkColor((actp->cnt / 8));
				pceFontSetTxColor(0x00);
				pceFontSetPos((actp->cen[X] / WP), 25);
				pceFontPutStr("CONGRATULATIONS! CONGRATULATIONS! CONGRATULATIONS! ");
				pceFontSetPos((actp->cen[X] / WP), 53);
				pceFontPutStr("CONGRATULATIONS! CONGRATULATIONS! CONGRATULATIONS! ");
				pceFontSetBkColor(FC_SPRITE);
				pceFontSetTxColor(0x03);
			}
			work[WRK_WAIT]--;
			if(!work[WRK_WAIT]){
				ACTexitStep();
			}
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void actBossMain(ACT *actp)
{
	SINT i;
	SINT wait;
	ACT *eactp;
	ENEMY *enep;

	switch(actp->step){
		case CHR_INIT:
			actp->chr_flag = f_enemy;
			actp->pos[X] = (MAX_X / 2) * WP;
			actp->pos[Y] = -64 * WP;
			actp->trg[X] = (MAX_X / 2) * WP;
			actp->trg[Y] = +32 * WP;
			actp->buff = (void *)BossTbl[actp->num];
			actp->size = BossSize[actp->num];
			actp->col = BossCollision[actp->num];
			actp->cnt = 60;
			actp->back = 255;
			actp->color = 3;
			work[WRK_BOSSMODE] = 0;
			work[WRK_BOSSMOVE] = 0;
			ACTnextStep();
			break;
		case CHR_MAIN:
			actp->pos[X] += (actp->trg[X] - actp->pos[X]) / 15;
			actp->pos[Y] += (actp->trg[Y] - actp->pos[Y]) / 15;
			actp->cnt--;
			enep = (ENEMY *)actp->buff;
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			for(i = 0; i < actp->size; i++){
				BLOCKdraw(3,actp->cen[X]+enep[i].ofs[X],actp->cen[Y]+enep[i].ofs[Y],enep[i].size[X],enep[i].size[Y]);
			}
			actp->color = 3;
			if(!actp->cnt){
				actp->pos[X] = actp->trg[X];
				actp->pos[Y] = actp->trg[Y];
				ACTnextStep();
			}
			break;
		case CHR_MAIN+1:
			if(!work[WRK_BOSSENEMY]){
				work[WRK_OPTBROKEN] += 2;
				actp->chr_flag = f_none;
				actp->wait = 60;
				ACTsetStep(CHR_EXPLODE);
				break;
			}

			if(!work[WRK_OPTIONS]){
				actBossMove(actp);
			}
			enep = (ENEMY *)actp->buff;
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			for(i = 0; i < actp->size; i++){
				BLOCKdraw(actp->color,actp->cen[X]+enep[i].ofs[X],actp->cen[Y]+enep[i].ofs[Y],enep[i].size[X],enep[i].size[Y]);
			}
			if(actp->color != 3){
				actp->color = 3;
			}
			if(actp->wait){
				actp->wait--;
			}else{
				if(actp->cnt){
					if(EnemyShotNow < EnemyShotMax){
						eactp = ACTsetTop(actBulletCtrl,GROUP_01);
						if(eactp){
							eactp->pos[X] = actp->pos[X];
							eactp->pos[Y] = actp->pos[Y];
							eactp->type = actp->type;
							switch(actp->type){
								case 0:
									EnemyShotNow += 1;
									actp->wait = 15;
									eactp->num = 0;
									eactp->cnt = 1;
									break;
								case 1:
									EnemyShotNow += 1;
									actp->wait = 10;
									eactp->num = 0;
									eactp->cnt = 1;
									break;
								case 2:
									EnemyShotNow += 1;
									actp->wait = 10;
									eactp->num = 0;
									eactp->cnt = 1;
									break;
								case 3:
									EnemyShotNow += 1;
									actp->wait = 3;
									eactp->num = 0;
									eactp->cnt = 1;
									break;
								case 4:
									EnemyShotNow += 5;
									actp->wait = 20;
									eactp->num = -2;
									eactp->cnt = 5;
									break;
								case 5:
									EnemyShotNow += 4;
									actp->wait = 15;
									eactp->num = 0;
									eactp->cnt = 4;
									break;
								case 6:
									EnemyShotNow += 1;
									actp->wait = 5;
									eactp->num = actp->bnum;
									eactp->cnt = 1;
									actp->bnum++;
									break;
							}
							eactp->prog_adr(eactp);
							actp->cnt--;
						}
					}
				}else{
					actp->type = BulletCtrl[work[WRK_BULLET]];
					work[WRK_BULLET] %= 16;
					switch(actp->type){
						case 0:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) >  6 ?  6 : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(180) + 60;
							break;
						case 1:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) >  8 ?  8 : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(120) + 60;
							break;
						case 2:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > 12 ? 12 : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(120) + 60;
							break;
						case 3:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > 16 ? 16 : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(90) + 60;
							break;
						case 4:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > 10 ?  2 : (EnemyShotMax - EnemyShotNow) / 5);
							wait = DCNVrand(60) + 60;
							break;
						case 5:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) >  8 ?  2 : (EnemyShotMax - EnemyShotNow) / 4);
							wait = DCNVrand(60) + 60;
							break;
						case 6:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > 16 ? 16 : EnemyShotMax - EnemyShotNow);
							actp->bnum = -8;
							wait = DCNVrand(60) + 60;
								break;
						default:
							wait = 0;
							break;
					}
					actp->wait = (actp->wait * 100) / (EnemyOptCnt - (work[WRK_OPTIONS] / 2) + 1) / 100;
					if(!work[WRK_OPTIONS]){
						wait = 0;
					}
					if(actp->back == actp->type){
						actp->wait = wait;
						actp->back = 255;
						break;
					}
					if(actp->cnt){
						actp->back = actp->type;
						work[WRK_BULLET]++;
						actp->wait = wait;
					}
				}
			}
			break;
		case CHR_DAMAGE:
			actp->color = 1;
			if(work[WRK_BOSSENEMY]){
				soundPlaySe(SE_DMG);
				scoretExtendChk(10);
				work[WRK_BOSSENEMY]--;
				if((eactp = ACTsetTop(ACTeffectDamage,GROUP_05))){
					eactp->cnt = 2;
					eactp->type = 0;
					eactp->pos[X] = actp->act_ext->pos[X];
					eactp->pos[Y] = actp->act_ext->pos[Y];
					eactp->prog_adr(eactp);
				}
			}
			break;
		case CHR_EXPLODE:
			soundPlaySe(SE_ENEEXP);
			if(!(actp->wait % 10)){
				if((eactp = ACTsetTop(ACTeffectDamage,GROUP_05))){
					eactp->cnt = 8;
					eactp->type = 0;
					eactp->pos[X] = actp->pos[X];
					eactp->pos[Y] = actp->pos[Y];
					eactp->prog_adr(eactp);
				}
				if((eactp = ACTsetTop(ACTeffectDamage,GROUP_01))){
					switch(DCNVrand(3)){
						case 0:
							eactp->cnt = 6;
							eactp->type = 1;
							break;
						case 1:
							eactp->cnt = 8;
							eactp->type = 2;
							break;
						case 2:
							eactp->cnt = 4;
							eactp->type = 3;
							break;
					}
					eactp->pos[X] = actp->pos[X];
					eactp->pos[Y] = actp->pos[Y];
					eactp->prog_adr(eactp);
				}
			}
			actp->wait--;
			if(actp->wait){
				break;
			}
			ACTsetStep(CHR_DESTROY);
		case CHR_DESTROY:
			scoretExtendChk(5000 * EnemyOptCnt);
			work[WRK_BOSSBROKEN] = 1;
			ACTsetStep(-1);
			break;
		default:
			ACTclear(actp);
			break;
	}

	if(work[WRK_OPTBROKEN]){
		work[WRK_OPTBROKEN]--;
	}
}

void actOptionMain(ACT *actp)
{
	SINT i;
	SINT shot;
	SINT wait;
	ACT *eactp;
	ENEMY *enep;
	BULOFS *bulp;

	switch(actp->step){
		case CHR_INIT:
			actp->chr_flag = f_enemy;
			actp->buff = (void *)OptionTbl[actp->num];
			actp->size = OptionSize[actp->num];
			actp->col = OptionCollision[actp->num];
			actp->color = 3;
			actp->cnt = 0;
			actp->wait = 0;
			actp->back = 255;
			actp->energy = 100;
			ACTnextStep();
			break;
		case CHR_MAIN:
			enep = (ENEMY *)actp->buff;
			actp->pos[X] = actp->act_parent->pos[X] + actp->ofs[X];
			actp->pos[Y] = actp->act_parent->pos[Y] + actp->ofs[Y];
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			for(i = 0; i < actp->size; i++){
				BLOCKdraw(actp->color,actp->cen[X]+enep[i].ofs[X],actp->cen[Y]+enep[i].ofs[Y],enep[i].size[X],enep[i].size[Y]);
			}
			if(actp->act_parent->step == (CHR_MAIN + 1)){
				ACTnextStep();
			}
			actp->color = 3;
			break;
		case CHR_MAIN+1:
			if(!work[WRK_BOSSENEMY]){
				actp->chr_flag = 0;
				actp->wait = 60;
				ACTsetStep(CHR_EXPLODE);
				break;
			}
			enep = (ENEMY *)actp->buff;
			actp->pos[X] = actp->act_parent->pos[X] + actp->ofs[X];
			actp->pos[Y] = actp->act_parent->pos[Y] + actp->ofs[Y];
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			for(i = 0; i < actp->size; i++){
				BLOCKdraw(actp->color,actp->cen[X]+enep[i].ofs[X],actp->cen[Y]+enep[i].ofs[Y],enep[i].size[X],enep[i].size[Y]);
			}
			if(actp->energy > 25){
				actp->color = 3;
			}else{
				actp->color = (work[WRK_FRAME] / 9) % 0x03;
			}
			if(actp->wait){
				actp->wait--;
			}else{
				if(actp->cnt){
					if(EnemyShotNow < EnemyShotMax){
						bulp = OptBulTbl[actp->num];
						shot = 0;
						for(i = 0; i < OptBulSize[actp->num]; i++){
							eactp = ACTsetTop(actBulletCtrl,GROUP_01);
							if(eactp){
								eactp->pos[X] = actp->pos[X] + bulp[i].ofs[X];
								eactp->pos[Y] = actp->pos[Y] + bulp[i].ofs[Y];
								eactp->type = actp->type;
								switch(actp->type){
									case 0:
										EnemyShotNow += 1;
										actp->wait = 20;
										eactp->num = 0;
										eactp->cnt = 1;
										break;
									case 1:
										EnemyShotNow += 1;
										actp->wait = 15;
										eactp->num = 0;
										eactp->cnt = 1;
										break;
									case 2:
										EnemyShotNow += 1;
										actp->wait = 15;
										eactp->num = 0;
										eactp->cnt = 1;
										break;
									case 3:
										EnemyShotNow += 1;
										actp->wait = 5;
										eactp->num = 0;
										eactp->cnt = 1;
										break;
									case 4:
										EnemyShotNow += 5;
										actp->wait = 20;
										eactp->num = -2;
										eactp->cnt = 5;
										break;
									case 5:
										EnemyShotNow += 4;
										actp->wait = 20;
										eactp->num = 0;
										eactp->cnt = 4;
										break;
									case 6:
										EnemyShotNow += 1;
										actp->wait = 5;
										eactp->num = actp->bnum;
										eactp->cnt = 1;
										actp->bnum++;
										break;
								}
								eactp->prog_adr(eactp);
								actp->cnt--;
							}
						}
					}
				}else{
					actp->type = BulletCtrl[work[WRK_BULLET]];
					shot = OptBulSize[actp->num];
					switch(actp->type){
						case 0:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 3) ? (shot * 3) : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(180) + 60;
							break;
						case 1:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 4) ? (shot * 4) : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(120) + 60;
							break;
						case 2:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 6) ? (shot * 6) : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(120) + 60;
							break;
						case 3:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 8) ? (shot * 8) : EnemyShotMax - EnemyShotNow);
							wait = DCNVrand(90) + 60;
							break;
						case 4:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 5) ? shot : (EnemyShotMax - EnemyShotNow) / 5);
							wait = DCNVrand(60) + 60;
							break;
						case 5:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 4) ? shot : (EnemyShotMax - EnemyShotNow) / 4);
							wait = DCNVrand(60) + 60;
							break;
						case 6:
							actp->cnt = ((EnemyShotMax - EnemyShotNow) > (shot * 12) ? (shot * 12) : EnemyShotMax - EnemyShotNow);
							actp->bnum = -6;
							wait = DCNVrand(60) + 60;
							break;
						default:
							wait = 0;
							break;
					}
					if(actp->back == actp->type){
						actp->wait = wait;
						actp->back = 255;
						break;
					}
					if(actp->cnt){
						actp->back = actp->type;
						work[WRK_BULLET]++;
						work[WRK_BULLET] %= 16;
						actp->wait = wait;
					}
				}
			}
			break;
		case CHR_DAMAGE:
			actp->color = 1;
			if(actp->energy){
				soundPlaySe(SE_DMG);
				scoretExtendChk(10);
				actp->energy--;
				if((eactp = ACTsetTop(ACTeffectDamage,GROUP_01))){
					eactp->cnt = 2;
					eactp->type = 0;
					eactp->pos[X] = actp->act_ext->pos[X];
					eactp->pos[Y] = actp->act_ext->pos[Y];
					eactp->prog_adr(eactp);
				}
			}else{
				actp->chr_flag = f_none;
				scoretExtendChk(1000);
				work[WRK_OPTBROKEN] += 2;
				actp->wait = 30;
				if((eactp = ACTsetTop(ACTeffectDamage,GROUP_01))){
					switch(DCNVrand(3)){
						case 0:
							eactp->cnt = 6;
							eactp->type = 1;
							break;
						case 1:
							eactp->cnt = 8;
							eactp->type = 2;
							break;
						case 2:
							eactp->cnt = 4;
							eactp->type = 3;
							break;
					}
					eactp->pos[X] = actp->pos[X];
					eactp->pos[Y] = actp->pos[Y];
					eactp->prog_adr(eactp);
				}
				ACTsetStep(CHR_EXPLODE);
			}
			break;
		case CHR_EXPLODE:
			soundPlaySe(SE_ENEBRK);
			actp->wait--;
			if(actp->wait){
				break;
			}
			ACTsetStep(CHR_DESTROY);
		case CHR_DESTROY:
			work[WRK_OPTIONS]--;
			EnemyShotMax += 4;
			EnemyShotMax  = (EnemyShotMax >= 180 ? 180 : EnemyShotMax);
			ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void actBulletCtrl(ACT *actp)
{
	ACT *eactp;
	SINT i;

	switch(actp->step){
		case CHR_INIT:
			ACTnextStep();
		case CHR_MAIN:
			for(i = 0; i < actp->cnt; i++){
				eactp = ACTsetTop(actBulletMain,GROUP_06);
				if(eactp){
					eactp->pos[X] = actp->pos[X];
					eactp->pos[Y] = actp->pos[Y];
					eactp->type = actp->type;
					switch(actp->type){
						case 4:
						case 5:
						case 6:
							eactp->num = actp->num;
							actp->num++;
							break;
					}
					eactp->prog_adr(eactp);
				}
			}
			ACTexitStep();
			break;
		default:
			ACTclear(actp);
			break;
	}
}

void actBulletMain(ACT *actp)
{
	ACT *eactp = (ACT *)work[WRK_ACTSHIP];
	SINT32 pos[XY];
	ANGLE ang[XY];

	switch(actp->step){
		case CHR_INIT:
			actp->chr_flag = f_eshot;
			actp->cnt = 0;
			actp->wait = 0;
			actp->col = col_bullet;
			switch(actp->type){
				case 0:
					actp->vel[X] = 0;
					actp->vel[Y] = WP / 2;
					break;
				case 1:
					pos[X] = eactp->pos[X] - actp->pos[X];
					pos[Y] = actp->pos[Y] - eactp->pos[Y];
					ang[X] =
					ang[Y] = MOTatan(pos[X],pos[Y]);
					actp->vel[X] = MOTsin(ang[X]) / 2;
					actp->vel[Y] = MOTcos(ang[Y]) / 2;
					break;
				case 2:
					pos[X] = eactp->pos[X] - actp->pos[X];
					pos[Y] = actp->pos[Y] - eactp->pos[Y];
					ang[X] =
					ang[Y] = MOTatan(pos[X],pos[Y]);
					ang[X] += DCNVrand(0x2000) - 0x1000;
					ang[Y] += DCNVrand(0x2000) - 0x1000;
					actp->vel[X] = MOTsin(ang[X]) / 2;
					actp->vel[Y] = MOTcos(ang[Y]) / 2;
					break;
				case 3:
					pos[X] = (DCNVrand(32) - 16) * WP;
					pos[Y] = (DCNVrand(32) - 16) * WP;
					actp->vel[X] = pos[X] / 30;
					actp->vel[Y] = pos[Y] / 30;
					actp->wait = 30;
					break;
				case 4:
				case 6:
					pos[X] = eactp->pos[X] - actp->pos[X];
					pos[Y] = actp->pos[Y] - eactp->pos[Y];
					ang[X] =
					ang[Y] = MOTatan(pos[X],pos[Y]);
					ang[X] += actp->num * 0x1000;
					ang[Y] += actp->num * 0x1000;
					actp->vel[X] = MOTsin(ang[X]) / 2;
					actp->vel[Y] = MOTcos(ang[Y]) / 2;
					break;
				case 5:
					pos[X] = eactp->pos[X] - actp->pos[X];
					pos[Y] = actp->pos[Y] - eactp->pos[Y];
					ang[X] =
					ang[Y] = MOTatan(pos[X],pos[Y]);
					actp->trg[X] = MOTsin(ang[X]) / 2;
					actp->trg[Y] = MOTcos(ang[Y]) / 2;
					actp->vel[X] = actp->trg[X] * (actp->num + 1);
					actp->vel[Y] = actp->trg[Y] * (actp->num + 1);
					actp->wait = 60;
					break;
				default:
					pos[X] = eactp->pos[X] - actp->pos[X];
					pos[Y] = actp->pos[Y] - eactp->pos[Y];
					ang[X] =
					ang[Y] = MOTatan(pos[X],pos[Y]);
					actp->vel[X] = MOTsin(ang[X]) / 2;
					actp->vel[Y] = MOTcos(ang[Y]) / 2;
					break;
			}
			if(work[WRK_GAME] != GAME_EASY){
				actp->vel[X] = (actp->vel[X] * ((EnemyLevel - 1) * 100 + 1200)) / 1200;
				actp->vel[Y] = (actp->vel[Y] * ((EnemyLevel - 1) * 100 + 1200)) / 1200;
			}
			if(work[WRK_OPTBROKEN]){
				actp->chr_flag = f_chip;
				actp->col = ChipColl;
				actp->wait = 20;
				ACTsetStep(CHR_MAIN + 1);
			}else{
				ACTnextStep();
			}
			break;
		case CHR_MAIN+0:
			if(work[WRK_OPTBROKEN]){
				actp->chr_flag = f_chip;
				actp->col = ChipColl;
				actp->wait = 20;
				ACTnextStep();
				break;
			}
			switch(actp->type){
				case 0:
				case 1:
				case 2:
				case 4:
				case 6:
					if(!actp->wait){
						actp->pos[X] += actp->vel[X];
						actp->pos[Y] += actp->vel[Y];
					}else{
						actp->wait--;
					}
					break;
				case 3:
					actp->pos[X] += actp->vel[X];
					actp->pos[Y] += actp->vel[Y];
					actp->wait--;
					if(!actp->wait){
						pos[X] = eactp->pos[X] - actp->pos[X];
						pos[Y] = actp->pos[Y] - eactp->pos[Y];
						ang[X] =
						ang[Y] = MOTatan(pos[X],pos[Y]);
						actp->vel[X] = MOTsin(ang[X]);
						actp->vel[Y] = MOTcos(ang[Y]);
						actp->wait = 10;
						actp->type = 0;
					}
					break;
				case 5:
					actp->pos[X] += actp->vel[X];
					actp->pos[Y] += actp->vel[Y];
					if(actp->wait){
						actp->vel[X] += (actp->trg[X] - actp->vel[X]) / 15;
						actp->vel[Y] += (actp->trg[Y] - actp->vel[Y]) / 15;
						actp->wait--;
					}
					break;
			}
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			actp->cnt++;
			if(actp->cnt % 0x03){
				pceLCDPaint(3,actp->cen[X]+2,actp->cen[Y]+0,2,2);
				pceLCDPaint(3,actp->cen[X]-2,actp->cen[Y]+0,2,2);
				pceLCDPaint(3,actp->cen[X]+0,actp->cen[Y]+2,2,2);
				pceLCDPaint(3,actp->cen[X]+0,actp->cen[Y]-2,2,2);
			}else{
				pceLCDPaint(3,actp->cen[X]+2,actp->cen[Y]-2,2,2);
				pceLCDPaint(3,actp->cen[X]+2,actp->cen[Y]+2,2,2);
				pceLCDPaint(3,actp->cen[X]-2,actp->cen[Y]-2,2,2);
				pceLCDPaint(3,actp->cen[X]-2,actp->cen[Y]+2,2,2);
			}
			pceLCDPaint(1,actp->cen[X]-1,actp->cen[Y]-1,4,4);
			pceLCDPaint(3,actp->cen[X]+0,actp->cen[Y]+0,2,2);
			if(actp->cen[X] < -4 || actp->cen[X] > (MAX_X + 4) || actp->cen[Y] < -4 || actp->cen[Y] > (MAX_Y + 4)){
				ACTexitStep();
			}
			break;
		case CHR_MAIN+1:
			if(!actp->wait){
				actp->pos[X] += (eactp->pos[X] - actp->pos[X]) / 10;
				actp->pos[Y] += (eactp->pos[Y] - actp->pos[Y]) / 10;
			}else{
				actp->wait--;
			}
			actp->cen[X] = actp->pos[X] / WP;
			actp->cen[Y] = actp->pos[Y] / WP;
			if(work[WRK_FRAME] & 0x08){
				pceLCDPaint(3,actp->cen[X]-3,actp->cen[Y]-1,6,2);
				pceLCDPaint(3,actp->cen[X]-1,actp->cen[Y]-3,2,6);
				pceLCDPaint(1,actp->cen[X]-2,actp->cen[Y]-2,4,4);
			}else{
				pceLCDPaint(3,actp->cen[X]-3,actp->cen[Y]-3,6,6);
				pceLCDPaint(1,actp->cen[X]-2,actp->cen[Y]-2,4,4);
			}
			break;
		case CHR_DAMAGE:
		case CHR_EXPLODE:
		case CHR_DESTROY:
			if(actp->chr_flag == f_chip){
				soundPlaySe(SE_CHIP);
				actp->chr_flag = f_none;
				work[WRK_BFLAG]  = 1;
				work[WRK_BONUS] += 100;
				scoretExtendChk(work[WRK_BONUS]);
			}
			ACTexitStep();
			break;
		default:
			EnemyShotNow--;
			ACTclear(actp);
			break;
	}
}

void scoretExtendChk(SINT score)
{
	work[WRK_SCORE] += score;
	work[WRK_SCORE]  = (work[WRK_SCORE] < 1000000000 ? work[WRK_SCORE] : 999999999);

	if(work[WRK_SCORE] >= 50000 && work[WRK_EXTEND] == 0){
		soundPlaySe(SE_EXTEND);
		work[WRK_LEFT]++;
		work[WRK_EXTEND]++;
	}else if(work[WRK_SCORE] >= 200000 && work[WRK_EXTEND] == 1){
		soundPlaySe(SE_EXTEND);
		work[WRK_LEFT]++;
		work[WRK_EXTEND]++;
	}else if(work[WRK_SCORE] >= 600000 && work[WRK_EXTEND] == 2){
		soundPlaySe(SE_EXTEND);
		work[WRK_LEFT]++;
		work[WRK_EXTEND]++;
	}else if(work[WRK_SCORE] >= 1000000 && work[WRK_EXTEND] == 3){
		soundPlaySe(SE_EXTEND);
		work[WRK_LEFT]++;
		work[WRK_EXTEND]++;
	}else if(work[WRK_EXTEND] >= 4 && work[WRK_SCORE] >= ((work[WRK_EXTEND] - 2) * 1000000)){
		if(work[WRK_GAME] == GAME_EASY || work[WRK_LEFT] < 4){
			soundPlaySe(SE_EXTEND);
			work[WRK_LEFT]++;
		}
		work[WRK_EXTEND]++;
	}

	return;
}

void actBossMove(ACT *actp)
{
	switch(work[WRK_BOSSMODE]){
		case 0:
			work[WRK_BOSSCNT] = 4;
			work[WRK_BOSSMODE]++;
		case 1:
			actp->trg[X] = ((DCNVrand(20) - 10) + 64) * WP;
			actp->trg[Y] = ((DCNVrand(32) - 16) + 32) * WP;
			work[WRK_BOSSMODE]++;
			work[WRK_BOSSMOVE] = 120;
			break;
		case 2:
			if(!work[WRK_BOSSCNT]){
				work[WRK_BOSSCNT] = 60;
				work[WRK_BOSSMODE]++;
				break;
			}
			actp->pos[X] += (actp->trg[X] - actp->pos[X]) / 10;
			actp->pos[Y] += (actp->trg[Y] - actp->pos[Y]) / 10;
			work[WRK_BOSSMOVE]--;
			if(!work[WRK_BOSSMOVE]){
				work[WRK_BOSSCNT]--;
				work[WRK_BOSSMODE] = 1;
			}
			break;
		case 3:
			work[WRK_BOSSCNT]--;
			if(!work[WRK_BOSSCNT]){
				work[WRK_BOSSCNT] = 8;
				work[WRK_BOSSMODE]++;
			}
			break;
		case 4:
			actp->trg[X] = ((DCNVrand(80) - 40) + 64) * WP;
			actp->trg[Y] = ((DCNVrand(32) - 16) + 32) * WP;
			work[WRK_BOSSMODE]++;
			work[WRK_BOSSMOVE] = 20;
			break;
		case 5:
			actp->pos[X] += (actp->trg[X] - actp->pos[X]) / 10;
			actp->pos[Y] += (actp->trg[Y] - actp->pos[Y]) / 10;
			work[WRK_BOSSMOVE]--;
			if(!work[WRK_BOSSCNT]){
				work[WRK_BOSSMODE] = 0;
				break;
			}
			if(!work[WRK_BOSSMOVE]){
				work[WRK_BOSSCNT]--;
				work[WRK_BOSSMODE] = 4;
			}
			break;
	}
}
