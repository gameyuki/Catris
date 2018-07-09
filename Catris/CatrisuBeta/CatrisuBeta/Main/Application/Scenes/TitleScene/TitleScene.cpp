#include "TitleScene.h"
#include "Main\Main.h"
#include "TitleBackGround\TitleBackGround.h"
#include "TitleLogo\TitleLogo.h"
#include "TitleNext\TitleNext.h"
#include "TitleEnd\TitleEnd.h"
#include "TitleConfigration\TitleConfigration.h"
#include "TitleArrow\TitleArrow.h"

static Scenes g_NextSceneID = GAME_SCENE;

void TitleSceneDraw()
{
	/* �w�i */
	TitleBackGroundDraw();
	/* ���S */
	/* �`�[�����S */
	TitleLogoDraw();
	/* Start */
	TitleNextDraw();
	/* End */
	TitleEndDraw();
	/* �ݒ� */
	TitleConfigDraw();
	/* ��� */
	TitleArrowDraw();
}

void TitleSceneUpdate()
{
	TitleArrowUpdate();
}

void TitleSceneRun()
{
	TitleSceneDraw();
	TitleSceneUpdate();
}