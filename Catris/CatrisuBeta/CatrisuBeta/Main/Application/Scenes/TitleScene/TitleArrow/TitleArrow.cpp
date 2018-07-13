#include "TitleArrow.h"
#include "Main\Main.h"
#include <dinput.h>
#include "Library\DirectInput\DirectInput.h"
#include "Main\Application\Scenes\SceneManager.h"

//�ړ���
float g_MovePower = 0;

void TitleArrowDraw()
{
	CUSTOMVERTEX TitleArrow[]
	{
		{ 220.f, 360.f + g_MovePower, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 350.f, 360.f + g_MovePower, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 350.f, 430.f + g_MovePower, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 220.f, 430.f + g_MovePower, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_ARROW_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleArrow, sizeof(CUSTOMVERTEX));
}

void TitleArrowUpdate()
{
	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_RETURN], DIK_RETURN);
	KeyCheckDinput(&key[DIK_W], DIK_W);
	KeyCheckDinput(&key[DIK_S], DIK_S);

	if (g_MovePower != 0)
	{
		if (key[DIK_W] == PUSH)
		{
			g_MovePower -= 120.f;
		}
	}
	
	if (g_MovePower != 240)
	{
		if (key[DIK_S] == PUSH)
		{
			g_MovePower += 120.f;
		}
	}

	if (key[DIK_RETURN] == PUSH)
	{
		//TODO �t�F�[�h�C���A�t�F�[�h�A�E�g������H���̐l�ɕ��� 
		//�Q�[���J�n
		if (g_MovePower == 0)
		{
			g_MovePower = 0;
			g_scenes = GAME_SCENE;
		}
		//�I��
		else if (g_MovePower == 120)
		{
			g_MovePower = 0;
			PostQuitMessage(0);
		}
		//�ݒ���
		else if(g_MovePower == 240)
		{
			g_scenes = RESULT_SCENE;
			g_MovePower = 0;
			//�{���͂���
			//g_scenes = CONFIG_SCENE;
		}
	}


}