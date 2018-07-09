#include "HightScore.h"
#include "Main\Main.h"

float g_HightScore = 0;

void HightScoreDraw()
{
	CUSTOMVERTEX HightScoreFrame[] = 
	{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 935.f,   670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 675.f,   670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[GAME_HIGHTSCOREFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, HightScoreFrame, sizeof(CUSTOMVERTEX));

	//TODO 終わった時のスコアをファイルに書き出し一番最初に読み込むそしてそれを表示

}