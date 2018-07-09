#include "ResultReturnTitle.h"
#include "Main\main.h"

void ResultReturnTitleDraw()
{
	CUSTOMVERTEX ResultReturnTitle[]
	{
		{	80.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  600.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  600.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{	80.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_RETURNTITLE_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultReturnTitle, sizeof(CUSTOMVERTEX));

}

void ResultReturnTitleUpdate()
{

}