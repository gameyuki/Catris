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
	/* îwåi */
	TitleBackGroundDraw();
	/* ÉçÉS */
	/* É`Å[ÉÄÉçÉS */
	TitleLogoDraw();
	/* Start */
	TitleNextDraw();
	/* End */
	TitleEndDraw();
	/* ê›íË */
	TitleConfigDraw();
	/* ñÓàÛ */
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