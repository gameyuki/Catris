#include "NomalScore.h"
#include "Main\Main.h"

float g_NomalScore = 0;

void NomalScoreDraw()
{
	CUSTOMVERTEX NomalScoreFrame[] =
	{
		{ 670.f, 430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 940.f, 430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[GAME_HIGHTSCOREFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, NomalScoreFrame, sizeof(CUSTOMVERTEX));

	//TODO �g�̒��̃X�R�A�̐����̕\��
	// Font���g������
	// �����ϐ���ێ����Ă��Ă���𕶎���ɕς������Font�ŕ\������

}

void NomalScoreupdate()
{

}