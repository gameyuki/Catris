#include "GameBackGround.h"
#include "Main\Main.h"
#include <Windows.h>
#include <d3dx9.h>

static int  g_FeverCount = 0;
static bool g_IsFever = false;

void GameBackGroundDraw()
{
	CUSTOMVERTEX GameBackGround[]
	{
		{ 0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	if (g_IsFever)
	{
		if (g_FeverCount % 2 == 0)
		{
			g_pD3Device->SetTexture(0, g_pTexture[GAME_FEVERBACKGROUND_TEX1]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBackGround, sizeof(CUSTOMVERTEX));
		}
		else
		{
			g_pD3Device->SetTexture(0, g_pTexture[GAME_FEVERBACKGROUND_TEX2]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBackGround, sizeof(CUSTOMVERTEX));
		}
	}
	else
	{
		if (g_FeverCount % 2 == 0)
		{
			g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBackGround, sizeof(CUSTOMVERTEX));
		}
		else
		{
			g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX2]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBackGround, sizeof(CUSTOMVERTEX));
		}
	}
}
	

void GameBackGroundUpdate()
{
	/* TODO フィーバーモードになったらカウントを足していくそれを割って画像を交互に描画していく
	*	g_IsFeverを操作
	**/

}