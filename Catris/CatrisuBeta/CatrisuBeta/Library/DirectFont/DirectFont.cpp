#include <Windows.h>
#include <d3dx9.h>
#include "DirectFont.h"
#include "Main\Main.h"

VOID CreateFontEx(VOID)
{
	//現在のスコア
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currentscoreFont]);

	//現在のハイスコア
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currenthighscoreFont]);

	//ラインカウント文字
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countFont]);

	//ラインカウント表示文字
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countshowFont]);

	//ノーマルモード文字
	D3DXCreateFont(g_pD3Device, 50, 30, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_normalFont]);

	//フィーバーモードタイマー文字
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimerFont]);

	//フィーバーモードタイム文字
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimeshowFont]);

	//フィーバーゲージ文字
	D3DXCreateFont(g_pD3Device, 20, 10, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevergaugeshowFont]);

	//落下速度レベル文字
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelFont]);

	//落下速度レベル表示文字
	D3DXCreateFont(g_pD3Device, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelshowFont]);

	return;
}

HRESULT InitDfont(HWND hWnd)
{
	//フォントの生成
	CreateFontEx();

	return S_OK;
}