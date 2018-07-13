#include <Windows.h>
#include <d3dx9.h>
#include "DirectFont.h"
#include "Main\Main.h"

VOID CreateFontEx(VOID)
{
	//���݂̃X�R�A
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currentscoreFont]);

	//���݂̃n�C�X�R�A
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currenthighscoreFont]);

	//���C���J�E���g����
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countFont]);

	//���C���J�E���g�\������
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countshowFont]);

	//�m�[�}�����[�h����
	D3DXCreateFont(g_pD3Device, 50, 30, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_normalFont]);

	//�t�B�[�o�[���[�h�^�C�}�[����
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimerFont]);

	//�t�B�[�o�[���[�h�^�C������
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimeshowFont]);

	//�t�B�[�o�[�Q�[�W����
	D3DXCreateFont(g_pD3Device, 20, 10, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevergaugeshowFont]);

	//�������x���x������
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelFont]);

	//�������x���x���\������
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelshowFont]);

	return;
}

HRESULT InitDfont(HWND hWnd)
{
	//�t�H���g�̐���
	CreateFontEx();

	return S_OK;
}