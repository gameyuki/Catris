#include "ResultScene.h"
#include "Main\Main.h"
#include "ResultBackGround\ResultBackGround.h"
#include "ResultLogo\ResultLogo.h"
#include "ResultReturnTitle\ResultReturnTitle.h"
#include "ResultScore\ResultScore.h"
#include "ResultContinue\ResultContinue.h"
#include "ResultArrow\ResultArrow.h"

void ResultDraw()
{
	/* 背景 */
	ResultBackGroundDraw();
	/* ロゴ */
	ResultLogoDraw();
	/* スコア */
	ResultScoreRun();
	/* コンテニュー */
	ResultContinueRun();
	/* タイトル画面へ戻る */
	ResultReturnTitleDraw();
	/* 矢印 */
	ResultArrowRun();
}

void ResultUpdate()
{
	
}


void ResultSceneRun()
{
	ResultUpdate();
	ResultDraw();
}