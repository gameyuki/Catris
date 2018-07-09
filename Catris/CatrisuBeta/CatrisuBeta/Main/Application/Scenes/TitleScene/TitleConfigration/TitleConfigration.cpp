#include "TitleConfigration.h"
#include "Main\Main.h"

void TitleConfigDraw()
{
	CUSTOMVERTEX TitleConfig[]
	{
		{ 332.f, 610.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 922.f, 610.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 922.f, 700.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 332.f, 700.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_CONFIGRATION_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleConfig, sizeof(CUSTOMVERTEX));
}