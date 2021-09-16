/*==========================================================================
 *
 *  Copyright (C) 2002 Jumpei Isshiki. All Rights Reserved.
 *
 *  File	:sound.h
 *  Content	:サウンド制御関連定義
 *	Program	:J.Issiki
 *	Date	:2002/11/17
 *	UpDate	:2002/11/21
 *
 ==========================================================================*/

#ifndef	_SOUND_INCLUDED_
#define	_SOUND_INCLUDED_

/*----------------------------------------------------------------------*/
/*	定数の定義															*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	構造体の宣言														*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	外部参照変数の宣言													*/
/*----------------------------------------------------------------------*/
extern	char				*sound_buff[];
extern	const unsigned char	ALERT_BGM01[];
extern	const unsigned char	ALERT_SE_ALERT[];
extern	const unsigned char	ALERT_SE_CHIP[];
extern	const unsigned char	ALERT_SE_COLLECT[];
extern	const unsigned char	ALERT_SE_DMG[];
extern	const unsigned char	ALERT_SE_ENEBRK[];
extern	const unsigned char	ALERT_SE_ENEEXP[];
extern	const unsigned char	ALERT_SE_EXTEND[];
extern	const unsigned char	ALERT_SE_SEL[];
extern	const unsigned char	ALERT_SE_SHIPBRK[];
extern	const unsigned char	ALERT_SE_SHOT[];

/*----------------------------------------------------------------------*/
/*	外部参照関数の宣言													*/
/*----------------------------------------------------------------------*/
extern	void	soundStopBgm( void );
extern	void 	soundRequstBgm( const char *, int );
extern	void 	soundPlayBgm( void );
extern	void 	soundSetVolumeBgm( char,int );
extern	void	soundStopSe( void);
extern	void 	soundRequstSe( const char *, int );
extern	void 	soundPlaySe( void );
extern	int	 	soundCheckSe( int );

/*----------------------------------------------------------------------*/
#endif					/* end of sound.h	*/
/*----------------------------------------------------------------------*/
