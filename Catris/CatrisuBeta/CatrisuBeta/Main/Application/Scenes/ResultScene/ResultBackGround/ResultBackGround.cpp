#include "ResultBackGround.h"
#include "Main\Main.h"

void ResultBackGroundDraw()
{
	CUSTOMVERTEX ResultBackGround[]
	{
		{ 0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//TODO ƒ‰ƒ“ƒ_ƒ€H
	g_pD3Device->SetTexture(0, g_pTexture[RESULT_BACKGROUND_TEX1]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultBackGround, sizeof(CUSTOMVERTEX));

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_BACKGROUND_TEX2]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultBackGround, sizeof(CUSTOMVERTEX));

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_BACKGROUND_TEX3]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultBackGround, sizeof(CUSTOMVERTEX));

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_BACKGROUND_TEX4]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultBackGround, sizeof(CUSTOMVERTEX));
}