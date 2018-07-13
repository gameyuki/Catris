#include "TitleConfigration.h"
#include "Main\Main.h"

void TitleConfigDraw()
{
	CUSTOMVERTEX TitleConfig[]
	{
		{ 340.f, 590.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 930.f, 590.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 930.f, 680.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 340.f, 680.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_CONFIGRATION_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleConfig, sizeof(CUSTOMVERTEX));
}