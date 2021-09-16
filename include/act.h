/*==========================================================================
 *
 *  Copyright (C) 1998 Jumpei Isshiki. All Rights Reserved.
 *
 *  File	:Act.h
 *  Content	:�A�N�g����֘A��`
 *	Program	:T.Sato / J.Issiki
 *	Date	:1998/5/12
 *	UpDate	:2002/10/28
 *
 ==========================================================================*/

#ifndef	_ACT_INCLUDED_
#define	_ACT_INCLUDED_

/*----------------------------------------------------------------------*/
/*	�f�[�^�^�錾														*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	�萔��`															*/
/*----------------------------------------------------------------------*/
#define	ACT_TOP		0
#define	ACT_BOTTOM	1

#define	ACTnextStep()		actp->step++
#define	ACTbackStep()		actp->step--
#define	ACTsetStep(num)		actp->step = num
#define	ACTexitStep()		actp->step = CHR_EXIT

/*----------------------------------------------------------------------*/
/*	�\���̒�`															*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	�O���Q�Ɗ֐��̐錾													*/
/*----------------------------------------------------------------------*/
extern	void	ACTinit( void );
extern	ACT		*ACTsetTop( FUNC,UINT8 );
extern	ACT		*ACTsetBtm( FUNC,UINT8 );
extern	void	ACTexec( void );
extern	void	ACTclearAll( ACT * );
extern	void	ACTclear( ACT * );

/*----------------------------------------------------------------------*/
/*	�O���Q�ƕϐ��̐錾													*/
/*----------------------------------------------------------------------*/
extern	ACT		ActIndex[ACT_GROUP_MAX][2];
extern	ACT		ActBuf[ACT_MAX];
extern	UINT	ActEntCnt;

/*----------------------------------------------------------------------*/
#endif					/* end of Act.h	*/
/*----------------------------------------------------------------------*/