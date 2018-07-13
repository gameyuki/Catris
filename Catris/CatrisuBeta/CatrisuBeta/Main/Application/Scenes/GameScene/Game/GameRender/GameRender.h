#ifndef GAME_RENDER_H
#define	GAME_RENDER_H

#include <windows.h>
#include <d3dx9.h>

//描画に関する関数
VOID Render(VOID);

//総合的な視点の設定をする関数
VOID SetViewPointOverall(VOID);

//総合的な視野角の設定をする関数
VOID SetFocusOfViewOverall(VOID);

//画面を表示させる関数
VOID DisplayScreen(
	CustomVertex *cusV4Background, //通常背景1
	CustomVertex *cusV4Frame,      //枠1

	CustomVertex *cusV4Background2, //通常背景2
	CustomVertex *cusV4Frame2,      //枠2

	CustomVertex *cusV4FeverBackground, //フィーバー背景1
	CustomVertex *cusV4FeverFrame,      //フィーバー枠1

	CustomVertex *cusV4FeverBackground2, //フィーバー背景2
	CustomVertex *cusV4FeverFrame2,      //フィーバー枠2

	CustomVertex *cusV4FeverBackground3, //フィーバー背景3
	CustomVertex *cusV4FeverFrame3,      //フィーバー枠3

	CustomVertex *cusV4FeverBackground4, //フィーバー背景4
	CustomVertex *cusV4FeverFrame4,      //フィーバー枠4

	CustomVertex *cusV4FeverBackground5, //フィーバー背景5
	CustomVertex *cusV4FeverFrame5,      //フィーバー枠5

	CustomVertex *cusV4NextFrame,  //ネクスト枠

	CustomVertex *cusV4HoldFrame,  //ホールド枠
	CustomVertex *cusV4GaugeFrame, //フィーバーゲージ

	CustomVertex *cusV4GaugeFrame_Fiver,//フィーバーゲージフィーバー中

	CustomVertex *cusV4FeverStr,//フィーバー文字

	CustomVertex *cusV4GameoverStr,//ゲームオーバー文字

	CustomVertex *cusV4ScoreFrame, //スコア枠
	CustomVertex *cusV4HighScoreframe,//ハイスコア枠
	CustomVertex *cusV4GaugeBlock,    //フィーバーゲージブロック
	CustomVertex *cusV4Tetmino,       //テトリミノ

	CustomVertex *cusV4NextTetmino,       //ネクストテトリミノ

	RECT *rectCurrentScoreStr,        //現在スコア文字
	RECT *rectCurrentHighScoreStr,    //現在ハイスコア文字
	RECT *rectCountStr,                //ラインカウント文字
	RECT *rectCountShowStr,                //ラインカウント表示文字
	RECT *rectNormalStr,                //ノーマルモード文字
	RECT *rectFeverTimerStr,            //フィーバーモードタイマー
	RECT *rectFeverTimeShowStr,          //フィーバーモードタイム
	RECT *rectFevergaugeShowStr,         //フィーバーゲージ文字
	RECT *rectFallLevelStr,               //落下速度レベル文字
	RECT *rectFallLevelShowStr            //落下速度レベル表示文字

);

void SetCatAndMouseUV(CustomVertex vertex[], int kind, bool is_flg_convert = true);


#endif