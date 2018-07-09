#include "NextFrame.h"
#include "Main\Main.h"

void NextFrameDraw()
{
	CUSTOMVERTEX NextFrame[] = 
	{
		{ 670.f,  10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 900.f,  10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 900.f, 450.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 670.f, 450.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[GAME_NEXTFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, NextFrame, sizeof(CUSTOMVERTEX));


}