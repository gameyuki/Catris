#include "ResultHightScore.h"
#include "Main\Main.h"
#include "Library\DirectFont\DirectFont.h"
#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"

ImageState g_CurrentHighScoreStrState2 = { 1280.f,680.f,200.f, 225.f };

RECT rectCurrentHighScoreStr2
{
	(LONG)(g_CurrentHighScoreStrState2.x - g_CurrentHighScoreStrState2.xScale),(LONG)(g_CurrentHighScoreStrState2.y - g_CurrentHighScoreStrState2.yScale),(LONG)(g_CurrentHighScoreStrState2.x + g_CurrentHighScoreStrState2.xScale),(LONG)(g_CurrentHighScoreStrState2.y + g_CurrentHighScoreStrState2.yScale)
};

void ResultHightScoreDraw()
{
	//2番目
	CUSTOMVERTEX ResultHightScoreFrame[]
	{
		{  700.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1270.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1270.f, 530.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  700.f, 530.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_HIGHTSCOREFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultHightScoreFrame, sizeof(CUSTOMVERTEX));

	//現在ハイスコア
	g_pFont[g_currenthighscoreFont]->DrawText(NULL, HIGHSCORESHOW, -1, &rectCurrentHighScoreStr2, NULL, HIGHSCORE_COLOR);
}

void ResultHightScoreUpdate()
{

}

void ResultHightScoreRun()
{
	ResultHightScoreUpdate();
	ResultHightScoreDraw();
}