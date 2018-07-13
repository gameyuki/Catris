#include <Windows.h>
#include <d3dx9.h>
#include <Xinput.h>
#include <stdio.h>
#include <dinput.h>
#include <stdlib.h>
#include "Main.h"
#include "Application\Application.h"
#include "Application\Scenes\SceneManager.h"
#include "Render\Render.h"
#include "Library\DirectInput\DirectInput.h"
#include "Library\DirectFont\DirectFont.h"
#include "Library\DirectSound\DirectSound.h"

#define TITLE TEXT ("Catris")
#define WIDTH	1280
#define	HEIGHT	 720

#define D3DFVF_CUSTOMVERTEX ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")

LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為の配列											//ダイレクトグラフィックスとして
IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
D3DDISPLAYMODE		  g_D3DdisplayMode;
IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス
LPD3DXFONT g_pFont[g_fontMax];
IDirectSound8 *pDS8;

void FreeDx()
{
	for (int i = 0; i <= TEXMAX; i++)
	{
		SAFE_RELEASE(g_pTexture[i]);
	}

	ReleaseKey();
	ReleaseDiput();

	for (int coordinateX = 0; coordinateX < g_fontMax; coordinateX++)
	{
		SAFE_RELEASE(g_pFont[coordinateX]);
	}

	SAFE_RELEASE(g_pD3Device);
	SAFE_RELEASE(g_pDirect3D);
}

/*ウィンドウプロシージャ*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		switch (wp)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInsta, LPSTR szStr, INT iCmdShow)
{
	WNDCLASS Wndclass;	//構造体タグ名を宣言
	HWND hWnd;
	MSG msg;

	//ウィンドウの設定
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TITLE;

	RegisterClass(&Wndclass);	//ウィンドウ情報の登録

								//ウィンドウの作成
	hWnd = CreateWindow(
		TITLE,
		TITLE,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WIDTH,
		HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)return 0;


	//DirectXオブジェクトの生成
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	//ディスプレイモードの設定
	g_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &g_D3DdisplayMode);

	ZeroMemory(&g_D3dPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
	g_D3dPresentParameters.BackBufferWidth =  1280;
	g_D3dPresentParameters.BackBufferHeight =  720;
	g_D3dPresentParameters.BackBufferFormat = g_D3DdisplayMode.Format;
	g_D3dPresentParameters.BackBufferCount = 1;
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_D3dPresentParameters.Windowed = TRUE;

	// フルスクリーンは出来ていないのでやれる時にやる
	//フルスクリーン用
	//ZeroMemory(&g_D3dPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
	//g_D3dPresentParameters.BackBufferWidth = 2256;
	//g_D3dPresentParameters.BackBufferHeight = 1504;
	//g_D3dPresentParameters.BackBufferFormat = D3DFMT_X8R8G8B8;
	//g_D3dPresentParameters.BackBufferCount = 1;
	//g_D3dPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	//g_D3dPresentParameters.MultiSampleQuality = 0;
	//g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	//g_D3dPresentParameters.hDeviceWindow = hWnd;
	//g_D3dPresentParameters.Windowed = FALSE;
	//g_D3dPresentParameters.EnableAutoDepthStencil = FALSE;
	//g_D3dPresentParameters.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	//g_D3dPresentParameters.Flags = 0;
	//g_D3dPresentParameters.FullScreen_RefreshRateInHz = 0;
	//g_D3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//デバイスの作成
	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3Device);

	//クライアント領域
	RECT rect;
	int ww, wh;
	int cw, ch;

	GetWindowRect(hWnd, &rect);
	ww = rect.right - rect.left;
	wh = rect.bottom - rect.top;

	GetClientRect(hWnd, &rect);
	cw = rect.right - rect.left;
	ch = rect.bottom - rect.top;

	ww = ww - cw;
	wh = wh - ch;

	ww = WIDTH + ww;
	wh = HEIGHT + wh;

	SetWindowPos(hWnd, HWND_TOP, 0, 0, ww, wh, SWP_NOMOVE);

	//DirectInputの初期化
	InitDinput();
	InitDinputKey(hWnd);

	if (FAILED(InitDfont(hWnd)))
	{
		return 0;
	}

	InitDSound(hWnd, &pDS8);

	//画像の読み込み・設定
	SetTexture();
	LoadTexture();

	//最初のシーンはタイトルにする
	g_scenes = TITLE_SCENE;

	/*ここで接続確認をする*/
	DWORD SyncOld = timeGetTime();		//	システム時間を取得
	DWORD SyncNow = timeGetTime();

	timeBeginPeriod(1);					//時間を細かく指定している　(1)=1000/1 
	ZeroMemory(&msg, sizeof(msg));		//&msgの初期化
	while (msg.message != WM_QUIT)		//WM_QUIT(終了)メッセージが来るまで継続
	{
		Sleep(1);						//高速で回らないように1ms(0.001秒)処理を遅らせている
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//PeekMessageでメッセージが来ていないか確認して来ていたら入る
		{
			TranslateMessage(&msg);		//メッセージをProcが読めるように翻訳する
			DispatchMessage(&msg);		//メッセージをProcに送信している
		}
		else
		{
			SyncNow = timeGetTime();

			if (SyncNow - SyncOld >= 1000 / 60) //	1秒間に60回この中に入るはず
			{
				//画面の消去
				g_pD3Device->Clear(0, NULL,
					D3DCLEAR_TARGET,
					D3DCOLOR_XRGB(0x00, 0x00, 0x00),
					1.0, 0);

				//描画の開始
				g_pD3Device->BeginScene();

				/* ゲーム処理 */
				ApplicationRun();

				//描画の終了
				g_pD3Device->EndScene();
				//表示
				g_pD3Device->Present(NULL, NULL, NULL, NULL);

				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	FreeDx();

	return (int)msg.wParam;
}