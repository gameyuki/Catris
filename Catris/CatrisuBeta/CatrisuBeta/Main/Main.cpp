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

LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	�摜�̏������Ă����ׂ̔z��											//�_�C���N�g�O���t�B�b�N�X�Ƃ���
IDirect3DDevice9*	  g_pD3Device;		//	Direct3D�̃f�o�C�X
D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	�p�����[�^
D3DDISPLAYMODE		  g_D3DdisplayMode;
IDirect3D9*			  g_pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X
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

/*�E�B���h�E�v���V�[�W��*/
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
	WNDCLASS Wndclass;	//�\���̃^�O����錾
	HWND hWnd;
	MSG msg;

	//�E�B���h�E�̐ݒ�
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

	RegisterClass(&Wndclass);	//�E�B���h�E���̓o�^

								//�E�B���h�E�̍쐬
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


	//DirectX�I�u�W�F�N�g�̐���
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	//�f�B�X�v���C���[�h�̐ݒ�
	g_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &g_D3DdisplayMode);

	ZeroMemory(&g_D3dPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
	g_D3dPresentParameters.BackBufferWidth =  1280;
	g_D3dPresentParameters.BackBufferHeight =  720;
	g_D3dPresentParameters.BackBufferFormat = g_D3DdisplayMode.Format;
	g_D3dPresentParameters.BackBufferCount = 1;
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_D3dPresentParameters.Windowed = TRUE;

	// �t���X�N���[���͏o���Ă��Ȃ��̂ł��鎞�ɂ��
	//�t���X�N���[���p
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

	//�f�o�C�X�̍쐬
	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3Device);

	//�N���C�A���g�̈�
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

	//DirectInput�̏�����
	InitDinput();
	InitDinputKey(hWnd);

	if (FAILED(InitDfont(hWnd)))
	{
		return 0;
	}

	InitDSound(hWnd, &pDS8);

	//�摜�̓ǂݍ��݁E�ݒ�
	SetTexture();
	LoadTexture();

	//�ŏ��̃V�[���̓^�C�g���ɂ���
	g_scenes = TITLE_SCENE;

	/*�����Őڑ��m�F������*/
	DWORD SyncOld = timeGetTime();		//	�V�X�e�����Ԃ��擾
	DWORD SyncNow = timeGetTime();

	timeBeginPeriod(1);					//���Ԃ��ׂ����w�肵�Ă���@(1)=1000/1 
	ZeroMemory(&msg, sizeof(msg));		//&msg�̏�����
	while (msg.message != WM_QUIT)		//WM_QUIT(�I��)���b�Z�[�W������܂Ōp��
	{
		Sleep(1);						//�����ŉ��Ȃ��悤��1ms(0.001�b)������x�点�Ă���
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//PeekMessage�Ń��b�Z�[�W�����Ă��Ȃ����m�F���ė��Ă��������
		{
			TranslateMessage(&msg);		//���b�Z�[�W��Proc���ǂ߂�悤�ɖ|�󂷂�
			DispatchMessage(&msg);		//���b�Z�[�W��Proc�ɑ��M���Ă���
		}
		else
		{
			SyncNow = timeGetTime();

			if (SyncNow - SyncOld >= 1000 / 60) //	1�b�Ԃ�60�񂱂̒��ɓ���͂�
			{
				//��ʂ̏���
				g_pD3Device->Clear(0, NULL,
					D3DCLEAR_TARGET,
					D3DCOLOR_XRGB(0x00, 0x00, 0x00),
					1.0, 0);

				//�`��̊J�n
				g_pD3Device->BeginScene();

				/* �Q�[������ */
				ApplicationRun();

				//�`��̏I��
				g_pD3Device->EndScene();
				//�\��
				g_pD3Device->Present(NULL, NULL, NULL, NULL);

				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	FreeDx();

	return (int)msg.wParam;
}