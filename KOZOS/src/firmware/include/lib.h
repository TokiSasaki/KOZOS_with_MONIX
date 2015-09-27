/*****************************************************************************
	オーダー	: 共通ライブラリ関数群 ヘッダファイル
	CPU			: H8 3069F
	コンパイラ	: h8300-elf-gcc version 3.4.6
	ファイル名	: lib.h
	接頭辞		: 無し
	作成日時	: 2013-09-03
*****************************************************************************/
/*
	改訂履歴
*/

#ifndef _LIB_H_
#define _LIB_H_

/*****************************************************************************
	インクルード
*****************************************************************************/
#include "defines.h"

/*****************************************************************************
	定義
*****************************************************************************/

/*****************************************************************************
	型定義、構造体定義
*****************************************************************************/

/*****************************************************************************
	プロトタイプ宣言
*****************************************************************************/
int16		putc(uint08	ucChar);					/* 1文字送信 */
int16		puts(char	*pucStr);					/* 文字列送信 */
uint08		getc(void);								/* 1文字受信 */
int16		gets(uint08	*pucStr);					/* 文字列受信 */
/* 16進数文字列表示 */
KOS_STS		printhex(uint32 ulVal, int16 iColumn, int16 i0xflg);

void		*memset(void *pvBuf, int16 iSet, uint32 lLen);
void		*memcpy(void *pvDst, const void *pvSrc, uint32 lLen);
KOS_BOOL	memcmp(const void *pvBuf1, const void *pvBuf2, uint32 lLen);
int16		strlen(const char *pcStr);
char		*strcpy(char *pcDst, const char *pcSrc);
KOS_BOOL	strcmp(const char *pcStr1, const char *pcStr2);
KOS_BOOL	strncmp(const char *pcStr1, const char *pcStr2, int16 iLen);
uint32		asc2hex(const char* pHexAsc, uint16 usStrNum);
int			isdigit(char cChar);

void		waitms(int ms);
void		waitus(int us);

/*****************************************************************************
	外部変数 
*****************************************************************************/

#endif /* _LIB_H_ */


/***** End Of File *****/


