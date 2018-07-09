#include "TitleLogo.h"
#include "Main\Main.h"

void TitleLogoDraw()
{
	//ƒ^ƒCƒgƒ‹ƒƒS•`‰æ
	CUSTOMVERTEX TitleLogo[]
	{
		{ 270.f,  -15.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 970.f,  -15.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 970.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 270.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_LOGO_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleLogo, sizeof(CUSTOMVERTEX));

	//ƒ`[ƒ€ƒƒS•`‰æ
	CUSTOMVERTEX TeamLogo[]
	{
		{ 320.f, 150.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 920.f, 150.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 920.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 320.f, 330.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_TEAMLOGO_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TeamLogo, sizeof(CUSTOMVERTEX));

}