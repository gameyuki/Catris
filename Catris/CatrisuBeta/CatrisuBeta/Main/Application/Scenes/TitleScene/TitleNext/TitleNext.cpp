#include "TitleNext.h"
#include "Main\Main.h"

void TitleNextDraw()
{
	CUSTOMVERTEX TitleNext[]
	{
		{ 320.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 920.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 920.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 320.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_NEXT_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleNext, sizeof(CUSTOMVERTEX));
}