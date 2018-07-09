#include "TitleEnd.h"
#include "Main\Main.h"

void TitleEndDraw()
{
	CUSTOMVERTEX TitleEnd[]
	{
		{ 332.f, 460.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 922.f, 460.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 922.f, 590.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 332.f, 590.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_END_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleEnd, sizeof(CUSTOMVERTEX));
}