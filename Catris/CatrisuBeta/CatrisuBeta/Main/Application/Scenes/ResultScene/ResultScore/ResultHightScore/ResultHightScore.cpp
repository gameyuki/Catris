#include "ResultHightScore.h"
#include "Main\Main.h"

void ResultHightScoreDraw()
{
	//2�Ԗ�
	CUSTOMVERTEX ResultHightScoreFrame[]
	{
		{  700.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1270.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1270.f, 530.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  700.f, 530.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_HIGHTSCOREFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultHightScoreFrame, sizeof(CUSTOMVERTEX));

	//TODO �n�C�X�R�A�̓��e
}

void ResultHightScoreUpdate()
{

}

void ResultHightScoreRun()
{
	ResultHightScoreUpdate();
	ResultHightScoreDraw();
}