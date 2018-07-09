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
	/* �w�i */
	ResultBackGroundDraw();
	/* ���S */
	ResultLogoDraw();
	/* �X�R�A */
	ResultScoreRun();
	/* �R���e�j���[ */
	ResultContinueRun();
	/* �^�C�g����ʂ֖߂� */
	ResultReturnTitleDraw();
	/* ��� */
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