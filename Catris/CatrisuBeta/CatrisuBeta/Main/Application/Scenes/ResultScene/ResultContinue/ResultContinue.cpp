#include "ResultContinue.h"
#include "Main\Main.h"


void ResultContinueDraw()
{
	CUSTOMVERTEX ResultContinue[]
	{
		{  950.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1270.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1270.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  950.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_CONTINUE_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultContinue, sizeof(CUSTOMVERTEX));
}

void ResultContinueUpdate()
{

}

void ResultContinueRun()
{
	ResultContinueUpdate();
	ResultContinueDraw();
}