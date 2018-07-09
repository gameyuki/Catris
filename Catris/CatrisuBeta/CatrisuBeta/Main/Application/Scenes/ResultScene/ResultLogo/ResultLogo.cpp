#include "ResultLogo.h"
#include "Main\Main.h"

void ResultLogoDraw()
{
	CUSTOMVERTEX ResultLogo[]
	{
		{   0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 570.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 570.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{   0.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_LOGO_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultLogo, sizeof(CUSTOMVERTEX));

}