#include <Windows.h>
#include <d3dx9.h>
#include "Render.h"
#include "Main\Main.h"
#include "Main\Application\Scenes\GameScene\Game\GameInitialize\GameInitialize.h"

void SetTexture()
{
	/*������O��I�ɕ׋����鎖*/
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

bool CreateTexture(const char* filename, TEXTURE texture_ID)
{
	if (FAILED(D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT(filename),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[texture_ID])))
	{
		return false;
	}

	return true;
}

void LoadTexture()
{
	g_pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	
	//�S�̔w�i
	CreateTexture("Resourse/�w�i/BackGround.png", BACKGROUND_TEX);
	CreateTexture("Resourse/�w�i/BackGround2.png", BACKGROUND_TEX2);
	//�^�C�g�����
	CreateTexture("Resourse/���/arrow.png", TITLE_ARROW_TEX);
	CreateTexture("Resourse/�^�C�g����ʑf��/TitleLogo.png", TITLE_LOGO_TEX);
	CreateTexture("Resourse/�^�C�g����ʑf��/TeamLogo.png", TITLE_TEAMLOGO_TEX);
	CreateTexture("Resourse/�^�C�g����ʑf��/TitleStart.png", TITLE_NEXT_TEX);
	CreateTexture("Resourse/�^�C�g����ʑf��/TitleEnd.png", TITLE_END_TEX);
	//�Q�[�����
	CreateTexture("Resourse/�w�i�t�B�[�o�[�i���e�C�N�j/seisaku_bg_fever4.png", GAME_FEVERBACKGROUND_TEX1);
	CreateTexture("Resourse/�w�i�t�B�[�o�[�i���e�C�N�j/seisaku_bg_fever5.png", GAME_FEVERBACKGROUND_TEX2);
	CreateTexture("Resourse/���C���Q�[��/fieldFrame.png", GAME_MAINFRAME_TEX);
	CreateTexture("Resourse/���C���Q�[��/gaugeframe.png", GAME_FEVERFRAME_TEX);
	CreateTexture("Resourse/���C���Q�[��/hold_frame.png", GAME_HOLDFRAME_TEX);
	CreateTexture("Resourse/���C���Q�[��/next_frame.png", GAME_NEXTFRAME_TEX);
	CreateTexture("Resourse/���C���Q�[��/score_frame.png", GAME_NOMALSCOREFRAME_TEX);
	CreateTexture("Resourse/���C���Q�[��/highscore_frame.png", GAME_HIGHTSCOREFRAME_TEX);
	//�ݒ���

	//���U���g���
	CreateTexture("Resourse/�w�i���U���g/result_1.png", RESULT_BACKGROUND_TEX1);
	CreateTexture("Resourse/�w�i���U���g/result_2.png", RESULT_BACKGROUND_TEX2);
	CreateTexture("Resourse/�w�i���U���g/result_3.png", RESULT_BACKGROUND_TEX3);
	CreateTexture("Resourse/�w�i���U���g/result_4.png", RESULT_BACKGROUND_TEX4);
	CreateTexture("Resourse/���U���g�t���[��/result.png", RESULT_LOGO_TEX);
	CreateTexture("Resourse/���U���g�t���[��/continue.png", RESULT_CONTINUE_TEX);
	CreateTexture("Resourse/���U���g�t���[��/title_return.png", RESULT_RETURNTITLE_TEX);
	CreateTexture("Resourse/���U���g�t���[��/score_frame_2.png", RESULT_NOMALSCOREFRAME_TEX);
	CreateTexture("Resourse/���U���g�t���[��/highscore_frame_2.png", RESULT_HIGHTSCOREFRAME_TEX);

	CreateTextureFromFile();
}