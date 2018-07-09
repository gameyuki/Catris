#include "SceneManager.h"
#include "TitleScene\TitleScene.h"
#include "ResultScene\ResultScene.h"
#include "GameScene\GameScene.h"
#include "ConfigScene\ConfigScene.h"
#include "Main\Main.h"

Scenes g_scenes = EMPTY_SCENE;

void SceneRun()
{
	switch (g_scenes)
	{
	case EMPTY_SCENE:
		break;
	case TITLE_SCENE:
		TitleSceneRun();
		break;
	case GAME_SCENE:
		GameSceneRun();
		break;
	case RESULT_SCENE:
		ResultSceneRun();
		break;
	case CONFIG_SCENE:
		ConfigSceneRun();
		break;
	case SCENE_MAX:
		break;
	}
}