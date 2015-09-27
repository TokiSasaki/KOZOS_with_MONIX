/*****************************************************************************
	オーダー	: 割り込み
	CPU			: H8 3069F
	コンパイラ	: h8300-elf-gcc version 3.4.6
	ファイル名	: interrupt.c
	接頭辞		: sv
	作成日時	: 2013-11-16
*****************************************************************************/
/*
	改訂履歴
*/

/*****************************************************************************
	インクルード
*****************************************************************************/
#include	"defines.h"
#include	"intr.h"
#include	"interrupt.h"

/*****************************************************************************
	定義
*****************************************************************************/

/*****************************************************************************
	型定義、構造体定義
*****************************************************************************/

/*****************************************************************************
	外部変数
*****************************************************************************/

/*****************************************************************************
	内部変数
*****************************************************************************/

/*****************************************************************************
	プロトタイプ宣言
*****************************************************************************/

/*****************************************************************************
	DISCRIPTION	: ソフトウェア・割り込みベクタの初期化
	ARGUMENT	: -
	RETURN		: 0			= 正常終了
				  0以外		= 異常終了
	NOTE		: -
	UPDATED		: 2014-03-23
*****************************************************************************/
int16	svInit(void)
{
	int iType;
	
	/* 単純にすべての割り込みベクタにNULLを設定し、初期化*/
	for(iType = 0; iType < SV_TYPE_NUM; iType++){
		svSetHandler(iType, NULL);
	}
	return 0;
}

/*****************************************************************************
	DISCRIPTION	: ソフトウェア・割り込みベクタの設定
	ARGUMENT	: svType	= 割り込みの種類
				  svHandler	= 登録する割り込みハンドラ
	RETURN		: 0			= 正常終了
				  0以外		= 異常終了
	NOTE		: -
	UPDATED		: 2014-03-23
*****************************************************************************/
int16	svSetHandler(SV_T type, SV_HANDLER_T* pHandler)
{
	SOFTVECS[type] = pHandler;
	return 0;
}
	
/*****************************************************************************
	DISCRIPTION	: 共通割り込みハンドラ
	ARGUMENT	: svType	= 割り込みの種類
				  svHandler	= 登録する割り込みハンドラ
	RETURN		: 0			= 正常終了
				: 0以外		= 異常終了
	NOTE		: -
	UPDATED		: 2014-03-23
*****************************************************************************/
void	svInterrupt(SV_T type, uint32 ulSP)
{
	SV_HANDLER_T* pHandler = SOFTVECS[type];
	if(pHandler != NULL) {
		pHandler(type, ulSP);
	}
}

/***** End Of File *****/

