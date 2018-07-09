#include "ConfigBackGround.h"
#include "Main\Main.h"

void ConfigBackGroundDraw()
{
	CUSTOMVERTEX ConfigBackGround[]
	{
		{ 0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ConfigBackGround, sizeof(CUSTOMVERTEX));
}

void ConfigBackGroundUpdate()
{

}