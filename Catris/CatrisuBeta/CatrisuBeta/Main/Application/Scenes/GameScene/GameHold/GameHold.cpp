#include "GameHold.h"
#include "Main\Main.h"


void GameHoldDraw()
{
	CUSTOMVERTEX HoldFrame[] = 
	{
		{  30.f,  10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 205.f,  10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[GAME_HOLDFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, HoldFrame, sizeof(CUSTOMVERTEX));
}