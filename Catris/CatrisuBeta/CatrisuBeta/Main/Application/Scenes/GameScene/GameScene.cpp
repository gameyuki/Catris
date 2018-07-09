#include "GameScene.h"
#include "GameBackGround\GameBackGround.h"
#include "GameHold\GameHold.h"
#include "GameScore\GameScore.h"
#include "NextFrame\NextFrame.h"
//#include "FeverMode\"
#include "MainGameFrame\MainGameFrame.h"
//#include "GameBlock\"


void GameSceneDraw()
{
	GameBackGroundDraw();
	MainFrameDraw();
	NextFrameDraw();
	GameScoreDraw();
	GameHoldDraw();
}

void GameSceneRun()
{
	GameSceneDraw();
}