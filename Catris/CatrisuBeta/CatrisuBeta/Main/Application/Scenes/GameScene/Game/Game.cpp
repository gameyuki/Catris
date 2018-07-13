#include "GameCommon\GameCommon.h"
#include "GameInitialize\GameInitialize.h"
#include "GameRender\GameRender.h"
#include "GameUpdate\GameUpdate.h"
#include "Main\Main.h"
#include "Main\Application\Scenes\SceneManager.h"

void GameRun()
{

	if (isGameover == true)
	{
		g_scenes = RESULT_SCENE;
	}

	Control();
	Render();
}