#include "GameInitialize.h"
#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"
#include "Main\Main.h"

//テクスチャを作る関数
VOID CreateTextureFromFile(VOID)
{
	//通常背景
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal1.png",
		&g_pTexture[g_backgroundTex]);

	//枠
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal1_frame.png",
		&g_pTexture[g_frameTex]);

	//フィーバー背景
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever1.png",
		&g_pTexture[g_feverbackgroundTex]);

	//フィーバー枠
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever1_frame.png",
		&g_pTexture[g_feverframeTex]);


	//通常背景2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal2.png",
		&g_pTexture[g_backgroundTex2]);

	//枠2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_normal2_frame.png",
		&g_pTexture[g_frameTex2]);

	//フィーバー背景2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever2.png",
		&g_pTexture[g_feverbackgroundTex2]);

	//フィーバー枠2
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever2_frame.png",
		&g_pTexture[g_feverframeTex2]);

	//フィーバー背景3
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever3.png",
		&g_pTexture[g_feverbackgroundTex3]);

	//フィーバー枠3
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever3_frame.png",
		&g_pTexture[g_feverframeTex3]);

	//フィーバー背景4
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever4.png",
		&g_pTexture[g_feverbackgroundTex4]);

	//フィーバー枠4
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever4_frame.png",
		&g_pTexture[g_feverframeTex4]);

	//フィーバー背景5
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever5.png",
		&g_pTexture[g_feverbackgroundTex5]);

	//フィーバー枠5
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/bg_fever5_frame.png",
		&g_pTexture[g_feverframeTex5]);

	//ホールド枠
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/hold_frame.png",
		&g_pTexture[g_holdFrameTex]);

	//フィーバーゲージ
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/gaugeframe.png",
		&g_pTexture[g_gaugeTex]);

	//フィーバーゲージフィーバー中
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/gaugeframe_fever.png",
		&g_pTexture[g_gaugeFiverTex]);

	//スコア枠
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/score_frame.png",
		&g_pTexture[g_scoreFrameTex]);

	//ハイスコア枠
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/highscore_frame.png",
		&g_pTexture[g_highScoreFrameTex]);

	//フィーバーゲージブロック
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/gauge.png",
		&g_pTexture[g_feverBlockTex]);

	//ネクスト枠
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/next_frame.png",
		&g_pTexture[g_nextFrameTex]);

	//フィーバー文字
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/main_fever.png",
		&g_pTexture[g_feverStr]);

	//ゲームオーバー文字
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/main_gameover.png",
		&g_pTexture[g_gameoverStrTex]);

	//ネクストテトリミノ
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/next_tetmino.png",
		&g_pTexture[g_nexttetminoTex]);

	//テトリミノ
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Resourse/Game/tetmino.png",
		&g_pTexture[g_tetminoTex]);

	return;
}
