#include "GameInitialize.h"
#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"
#include "Main\Main.h"

//�e�N�X�`�������֐�
VOID CreateTextureFromFile(VOID)
{
	//�ʏ�w�i
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal1.png",
		&g_pTexture[g_backgroundTex]);

	//�g
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal1_frame.png",
		&g_pTexture[g_frameTex]);

	//�t�B�[�o�[�w�i
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever1.png",
		&g_pTexture[g_feverbackgroundTex]);

	//�t�B�[�o�[�g
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever1_frame.png",
		&g_pTexture[g_feverframeTex]);


	//�ʏ�w�i2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal2.png",
		&g_pTexture[g_backgroundTex2]);

	//�g2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal2_frame.png",
		&g_pTexture[g_frameTex2]);

	//�t�B�[�o�[�w�i2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever2.png",
		&g_pTexture[g_feverbackgroundTex2]);

	//�t�B�[�o�[�g2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever2_frame.png",
		&g_pTexture[g_feverframeTex2]);

	//�t�B�[�o�[�w�i3
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever3.png",
		&g_pTexture[g_feverbackgroundTex3]);

	//�t�B�[�o�[�g3
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever3_frame.png",
		&g_pTexture[g_feverframeTex3]);

	//�t�B�[�o�[�w�i4
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever4.png",
		&g_pTexture[g_feverbackgroundTex4]);

	//�t�B�[�o�[�g4
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever4_frame.png",
		&g_pTexture[g_feverframeTex4]);

	//�t�B�[�o�[�w�i5
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever5.png",
		&g_pTexture[g_feverbackgroundTex5]);

	//�t�B�[�o�[�g5
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever5_frame.png",
		&g_pTexture[g_feverframeTex5]);

	//�z�[���h�g
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/hold_frame.png",
		&g_pTexture[g_holdFrameTex]);

	//�t�B�[�o�[�Q�[�W
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/gaugeframe.png",
		&g_pTexture[g_gaugeTex]);

	//�t�B�[�o�[�Q�[�W�t�B�[�o�[��
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/gaugeframe_fever.png",
		&g_pTexture[g_gaugeFiverTex]);

	//�X�R�A�g
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/score_frame.png",
		&g_pTexture[g_scoreFrameTex]);

	//�n�C�X�R�A�g
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/highscore_frame.png",
		&g_pTexture[g_highScoreFrameTex]);

	//�t�B�[�o�[�Q�[�W�u���b�N
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/gauge.png",
		&g_pTexture[g_feverBlockTex]);

	//�l�N�X�g�g
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/next_frame.png",
		&g_pTexture[g_nextFrameTex]);

	//�t�B�[�o�[����
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/main_fever.png",
		&g_pTexture[g_feverStr]);

	//�Q�[���I�[�o�[����
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/main_gameover.png",
		&g_pTexture[g_gameoverStrTex]);

	//�l�N�X�g�e�g���~�m
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/next_tetmino.png",
		&g_pTexture[g_nexttetminoTex]);

	//�e�g���~�m
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/tetmino.png",
		&g_pTexture[g_tetminoTex]);

	return;
}
