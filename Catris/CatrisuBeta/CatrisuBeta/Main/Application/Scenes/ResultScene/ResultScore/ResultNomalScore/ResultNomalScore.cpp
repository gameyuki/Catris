#include "ResultNomalScore.h"
#include "Main\Main.h"
#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"
#include "Library\DirectFont\DirectFont.h"

//現在スコア座標
ImageState g_CurrentScoreStrState2 = { 1320.f,430.f,200.f, 225.f };

RECT rectCurrentScoreStr
{
	(LONG)(g_CurrentScoreStrState2.x - g_CurrentScoreStrState2.xScale),(LONG)(g_CurrentScoreStrState2.y - g_CurrentScoreStrState2.yScale),(LONG)(g_CurrentScoreStrState2.x + g_CurrentScoreStrState2.xScale),(LONG)(g_CurrentScoreStrState2.y + g_CurrentScoreStrState2.yScale)
};


void ResultNomalScoreDraw()
{
	//1番目
	CUSTOMVERTEX ResultNomalScoreFrame[]
	{
		{  700.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1250.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1250.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  700.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_NOMALSCOREFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultNomalScoreFrame, sizeof(CUSTOMVERTEX));

	g_pFont[g_currentscoreFont]->DrawText(NULL, g_scoreArray, -1, &rectCurrentScoreStr, NULL, NORMAL_COLOR);
}

void ResultNomalScoreUpdate()
{

}

void ResultNomalScoreRun()
{
	ResultNomalScoreUpdate();
	ResultNomalScoreDraw();
}