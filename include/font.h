/*==========================================================================
 *
 *  Copyright (C) 2001 Jumpei Isshiki. All Rights Reserved.
 *
 *  File	:font.c
 *  Content	:オリジナルフォント関数関連定義
 *	Program	:J.Issiki
 *	Date	:2002/1/21
 *	UpDate	:2002/11/11
 *
 ==========================================================================*/

#ifndef	_FONT_INCLUDED_
#define	_FONT_INCLUDED_

/*----------------------------------------------------------------------*/
/*	定数の定義															*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	構造体の宣言														*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	外部参照変数の宣言													*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	外部参照関数の宣言													*/
/*----------------------------------------------------------------------*/
extern	void	fontDispStr( SINT posx,SINT posy,UINT8 *str,SINT pal,SINT edge,BOOL	flags );
extern	int		fontGetStrSize( UINT8 *str );

/*----------------------------------------------------------------------*/
#endif					/* end of font.h	*/
/*----------------------------------------------------------------------*/
