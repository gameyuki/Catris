#ifndef MAIN_H
#define	MAIN_H

#include <Windows.h>
#include <d3dx9.h>
#include <dsound.h>


#define SAFE_RELEASE(p){if(p){(p)->Release();(p)=NULL;}}

/* 頂点構造体 */
typedef struct _CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CUSTOMVERTEX;

/* 画像情報 */
enum TEXTURE
{
	BACKGROUND_TEX,					//<<全体の背景1
	BACKGROUND_TEX2,				//<<全体の背景2
	TITLE_LOGO_TEX,					//<<タイトルのロゴ
	TITLE_TEAMLOGO_TEX,				//<<チームのロゴ
	TITLE_ARROW_TEX,				//<<タイトル画面の矢印
	TITLE_CONFIGRATION_TEX,			//<<タイトルの設定画面遷移用
	TITLE_NEXT_TEX,					//<<タイトルのゲーム開始
	TITLE_END_TEX,					//<<タイトルの終了
	GAME_FEVERBACKGROUND_TEX1,		//<<ゲーム画面のフィーバーモードの背景1
	GAME_FEVERBACKGROUND_TEX2,		//<<ゲーム画面のフィーバーモードの背景2
	GAME_MAINFRAME_TEX,				//<<ゲーム画面のメインフレーム
	GAME_HOLDFRAME_TEX,				//<<ゲーム画面のホールド用のフレーム
	GAME_NEXTFRAME_TEX,				//<<ゲーム画面の次のブロック用のフレーム
	GAME_NOMALSCOREFRAME_TEX,		//<<ゲーム画面のスコア用フレーム
	GAME_HIGHTSCOREFRAME_TEX,		//<<ゲーム画面のハイスコア用のフレーム
	GAME_FEVERFRAME_TEX,			//<<ゲーム画面のフィーバーゲージ用のフレーム
	CONFIG_BACKGROUND_TEX,			//<<設定画面用の背景
	RESULT_BACKGROUND_TEX1,			//<<リザルト画面の背景1
	RESULT_BACKGROUND_TEX2,			//<<リザルト画面の背景2
	RESULT_BACKGROUND_TEX3,			//<<リザルト画面の背景3
	RESULT_BACKGROUND_TEX4,			//<<リザルト画面の背景4
	RESULT_LOGO_TEX,				//<<リザルト画面のロゴ
	RESULT_CONTINUE_TEX,			//<<リザルト画面のコンテニュー
	RESULT_NOMALSCOREFRAME_TEX,		//<<リザルト画面のノーマルスコア用フレーム
	RESULT_HIGHTSCOREFRAME_TEX,		//<<リザルト画面のハイスコア用フレーム
	RESULT_RETURNTITLE_TEX,			//<<リザルト画面のタイトル画面へ戻る用

	g_backgroundTex,
	g_frameTex,
	g_feverbackgroundTex,
	g_feverframeTex,

	g_backgroundTex2,
	g_frameTex2,
	g_feverbackgroundTex2,
	g_feverframeTex2,

	g_feverbackgroundTex3,
	g_feverframeTex3,

	g_feverbackgroundTex4,
	g_feverframeTex4,

	g_feverbackgroundTex5,
	g_feverframeTex5,

	g_holdFrameTex,
	g_gaugeTex,
	g_gaugeFiverTex,
	g_scoreFrameTex,
	g_highScoreFrameTex,

	g_nextFrameTex,

	g_feverStr,
	g_gameoverStrTex,

	g_tetminoTex,

	g_nexttetminoTex,

	g_feverBlockTex,

	TEXMAX
};

/* シーン種類 */
enum Scenes
{
	EMPTY_SCENE,
	TITLE_SCENE,
	GAME_SCENE,
	RESULT_SCENE,
	CONFIG_SCENE,
	SCENE_MAX
};

enum FONT
{
	g_gameoverFont,
	g_currentscoreFont,
	g_currenthighscoreFont,
	g_nextFont,
	g_countFont,
	g_countshowFont,
	g_normalFont,
	g_feverFont,
	g_fevertimerFont,
	g_fevertimeshowFont,
	g_fevergaugeshowFont,
	g_falllevelFont,
	g_falllevelshowFont,
	g_fontMax
};

//	ブロックの数を決める数字は定数化しておきます
#define BLOCK_HEIGHT	4
#define BLOCK_WIDTH		4

//フィールドの縦幅・横幅
#define FIELD_HEIGHT	20
#define FIELD_WIDTH		10


extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為の配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス
extern LPD3DXFONT g_pFont[g_fontMax];
extern IDirectSound8* pDS8;

#endif