#include "ResultArrow.h"
#include "Main\Main.h"
#include "Library\DirectInput\DirectInput.h"
#include "Main\Application\Scenes\SceneManager.h"
#include <dinput.h>

static int g_MovePower = 0;

void ResultArrowDraw()
{
	CUSTOMVERTEX ResultArrow[]
	{
		{ -10.f + g_MovePower, 560.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  90.f + g_MovePower, 560.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  90.f + g_MovePower, 640.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -10.f + g_MovePower, 640.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_ARROW_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ResultArrow, sizeof(CUSTOMVERTEX));
}

void ResultArrowUpdate()
{
	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_RETURN], DIK_RETURN);
	KeyCheckDinput(&key[DIK_W], DIK_W);
	KeyCheckDinput(&key[DIK_S], DIK_S);

	if (key[DIK_W] == PUSH)
	{
		g_MovePower -= 870.f;
	}

	if (key[DIK_S] == PUSH)
	{
		g_MovePower += 870.f;
	}

	if (key[DIK_RETURN] == PUSH)
	{

	}
}

void ResultArrowRun()
{
	ResultArrowUpdate();
	ResultArrowDraw();
}