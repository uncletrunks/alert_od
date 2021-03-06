/*==========================================================================
 *
 *  Copyright (C) 2001 Jumpei Isshiki. All Rights Reserved.
 *
 *  File	:act_enemy.h
 *  Content	:敵制御関連定義
 *	Program	:J.Issiki
 *	Date	:2002/10/29
 *	UpDate	:2002/11/5
 *
 ==========================================================================*/

#ifndef	_ACT_ENEMY_INCLUDED_
#define	_ACT_ENEMY_INCLUDED_

/*----------------------------------------------------------------------*/
/*	データ型宣言														*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	定数定義															*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	構造体定義															*/
/*----------------------------------------------------------------------*/

/* 敵構造体 */
typedef	struct	tagENEMY
{
	SINT8	ofs[XY];
	SINT8	size[XY];
} ENEMY;

/* 弾発射位置構造体 */
typedef	struct	tagBULOFS
{
	SINT32	ofs[XY];
} BULOFS;

/*----------------------------------------------------------------------*/
/*	外部参照関数の宣言													*/
/*----------------------------------------------------------------------*/
extern	void	actEnemy( ACT *actp );

/*----------------------------------------------------------------------*/
/*	外部参照変数の宣言													*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
#endif					/* end of act_enemy.h	*/
/*----------------------------------------------------------------------*/
