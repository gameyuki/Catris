#include "ResultNomalScore.h"
#include "Main\Main.h"

void ResultNomalScoreDraw()
{
	//1”Ô–Ú
	CUSTOMVERTEX ResultNomalScoreFrame[]
	{
		{  700.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1250.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1250.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  700.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_NOMALSCOREFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultNomalScoreFrame, sizeof(CUSTOMVERTEX));
}

void ResultNomalScoreUpdate()
{

}

void ResultNomalScoreRun()
{
	ResultNomalScoreUpdate();
	ResultNomalScoreDraw();
}