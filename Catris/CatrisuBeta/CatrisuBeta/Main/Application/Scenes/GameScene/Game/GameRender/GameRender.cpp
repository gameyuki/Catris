#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"
#include "Main\Application\Scenes\GameScene\Game\GameRender\GameRender.h"
#include "Main\Application\Scenes\GameScene\Game\GameInitialize\GameInitialize.h"
#include "Main\Main.h"
#include "Library\DirectFont\DirectFont.h"
#include "Library\DirectInput\DirectInput.h"

 
VOID Render(VOID)
{

	//視点位置の設定、最後に絶対座標への変換を行う
	SetViewPointOverall();


	//視野角の設定、最後に絶対座標への変換を行う
	SetFocusOfViewOverall();

	//カスタムバーテックスの生成

	//通常背景

	CustomVertex cusV4Background[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//枠

	CustomVertex cusV4Frame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景

	CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠

	CustomVertex cusV4FeverFrame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//通常背景2

	CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//枠2

	CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景2

	CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠2

	CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景3

	CustomVertex cusV4FeverBackground3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠3

	CustomVertex cusV4FeverFrame3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景4

	CustomVertex cusV4FeverBackground4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠4

	CustomVertex cusV4FeverFrame4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景5

	CustomVertex cusV4FeverBackground5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠5

	CustomVertex cusV4FeverFrame5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//ネクスト枠
	CustomVertex cusV4NextFrame[4]
	{
		{ 650.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 835.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 835.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 650.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//ホールド枠
	CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//フィーバーゲージ
	CustomVertex cusV4GaugeFrame[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージフィーバー中
	CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//ハイスコア枠
	CustomVertex cusV4HighScoreframe[4]{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//スコア枠
	CustomVertex cusV4ScoreFrame[4]{
		{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//フィーバーゲージブロック

	CustomVertex cusV4GaugeBlock[4]{
		{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//フィーバー文字
	CustomVertex cusV4FeverStr[4]
	{
		{ 920.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1259.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1259.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 920.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};
	//ゲームオーバー文字
	CustomVertex cusV4GameoverStr[4]
	{
		{ 150.f,   150.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1107,   150.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1107.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 150.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//ネクストテトリミノ
	CustomVertex cusV4NextTetmino[4]
	{
		{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};

	//テトリミノ

	CustomVertex cusV4Tetmino[4]
	{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};


	//現在スコア表示

	RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	//現在ハイスコア表示

	RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};

	//ラインカウント文字

	RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)

	};

	//ラインカウント表示文字

	RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//ノーマルモード文字

	RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)

	};

	//フィーバータイマー文字

	RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)

	};

	//フィーバータイム文字
	RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//フィーバーゲージ文字
	RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//落下速度レベル文字
	RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//落下速度レベル表示文字
	RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)
	};

	//画面表示関係の処理、カスタムバーテックスをg_tetlisBoardの配列番号を用いて、
	//書き換えテトリスを表示している
	DisplayScreen(
		cusV4Background, //通常背景
		cusV4Frame,      //枠
		cusV4FeverBackground, //フィーバー背景
		cusV4FeverFrame,      //フィーバー枠

		cusV4Background2, //通常背景2
		cusV4Frame2,      //枠2

		cusV4FeverBackground2, //フィーバー背景2
		cusV4FeverFrame2,      //フィーバー枠2

		cusV4FeverBackground3, //フィーバー背景3
		cusV4FeverFrame3,      //フィーバー枠3

		cusV4FeverBackground4, //フィーバー背景4
		cusV4FeverFrame4,      //フィーバー枠4

		cusV4FeverBackground5, //フィーバー背景5
		cusV4FeverFrame5,      //フィーバー枠5

		cusV4NextFrame,  //ネクスト枠

		cusV4HoldFrame,  //ホールド枠
		cusV4GaugeFrame, //フィーバーゲージ
		cusV4GaugeFrame_Fiver, //フィーバーゲージフィーバー中

		cusV4FeverStr,//フィーバー文字

		cusV4GameoverStr,//ゲームオーバー文字

		cusV4ScoreFrame, //スコア枠
		cusV4HighScoreframe,//ハイスコア枠
		cusV4GaugeBlock,    //フィーバーゲージブロック
		cusV4Tetmino,       //テトリミノ

		cusV4NextTetmino,       //ネクストテトリミノ

		&rectCurrentScoreStr,        //現在スコア文字
		&rectCurrentHighScoreStr,    //現在ハイスコア文字
		&rectCountStr,                //ラインカウント文字
		&rectCountShowStr,                //ラインカウント表示文字
		&rectNormalStr,                //ノーマルモード文字
		&rectFeverTimerStr,            //フィーバーモードタイマー
		&rectFeverTimeShowStr,         //フィーバーモードタイム
		&rectFevergaugeShowStr,        //フィーバーゲージ文字
		&rectFallLevelStr,              //落下速度レベル文字
		&rectFallLevelShowStr            //落下速度レベル表示文字
	);

	//画面表示が行われたことをバックバッファーに伝える
	g_pD3Device->Present(NULL, NULL, NULL, NULL);

	return;
}

//視点位置の設定
VOID SetViewPointOverall(VOID)
{
	D3DXVECTOR3 vecEyePt(0.0f, 1.0f, -3.0f);
	D3DXVECTOR3 vecLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vecUpVec(0.0f, 1.0f, 100.0f);
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vecEyePt, &vecLookatPt, &vecUpVec);
	g_pD3Device->SetTransform(D3DTS_VIEW, &matView);

	return;
}

//視野角の設定
VOID SetFocusOfViewOverall(VOID)
{
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pD3Device->SetTransform(D3DTS_VIEW, &matProj);

	return;
}

VOID CreateCustomVertex(VOID)
{
	//通常背景
	static CustomVertex cusV4Background[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//枠
	static CustomVertex cusV4Frame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景
	static CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠
	static CustomVertex cusV4FeverFrame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//通常背景2
	static CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//枠2
	static CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景2
	static CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠2
	static CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景3
	static CustomVertex cusV4FeverBackground3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠3
	static CustomVertex cusV4FeverFrame3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景4
	static CustomVertex cusV4FeverBackground4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠4
	static CustomVertex cusV4FeverFrame4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景5
	static CustomVertex cusV4FeverBackground5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠5
	static CustomVertex cusV4FeverFrame5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//ネクスト枠
	static CustomVertex cusV4NextFrame[4]
	{
		{ 650.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 835.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 835.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 650.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//ホールド枠
	static CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージ
	static CustomVertex cusV4GaugeFrame[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージフィーバー中
	static CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//スコア枠
	static CustomVertex cusV4ScoreFrame[4]{
		{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//ハイスコア枠
	static CustomVertex cusV4HighScoreframe[4]{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー文字
	static CustomVertex cusV4FeverStr[4]
	{
		{ 930.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1249.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1249.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 930.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};
	//ゲームオーバー文字
	static CustomVertex cusV4GameoverStr[4]
	{
		{ 150.f,   150.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1107,   150.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1107.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 150.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//フィーバーゲージブロック

	static CustomVertex cusV4GaugeBlock[4]
	{
		{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//ネクストテトリミノ
	static CustomVertex cusV4NextTetmino[4]
	{
		{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};

	//テトリミノ
	static CustomVertex cusV4Tetmino[4]
	{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};


	//現在スコア表示
	static RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	// 現在ハイスコア表示
	static RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};


	//ラインカウント文字
	static RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)
	};

	//ラインカウント表示文字

	static RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//ノーマルモード文字
	static RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)
	};


	//フィーバータイマー文字
	static RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)
	};

	//フィーバータイム文字
	static RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//フィーバーゲージ文字
	static RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//落下速度レベル文字
	static RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//落下速度レベル表示文字
	static RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)

	};
	return;
}


//描画
VOID DisplayScreen(
	CustomVertex *cusV4Background, //通常背景
	CustomVertex *cusV4Frame,      //枠
	CustomVertex *cusV4FeverBackground, //フィーバー背景
	CustomVertex *cusV4FeverFrame,      //フィーバー枠

	CustomVertex *cusV4Background2, //通常背景2
	CustomVertex *cusV4Frame2,      //枠2

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

	CustomVertex *cusV4GaugeFrame_Fiver, //フィーバーゲージフィーバー中

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
	RECT *rectFeverTimeShowStr,            //フィーバーモードタイム
	RECT *rectFevergaugeShowStr,         //フィーバーゲージ文字
	RECT *rectFallLevelStr,               //落下速度レベル文字
	RECT *rectFallLevelShowStr            //落下速度レベル表示文字
)
{
	g_pD3Device->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0,
		0
	);

	g_pD3Device->BeginScene();

	//ラインの数が10以上のときフィーバー背景 10以下なら通常背景
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 4 == 0)
		{
			//フィーバー背景4表示
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex4]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground4, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 5 == 0)
		{
			//フィーバー背景5表示
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex5]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground5, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 2 == 0)
		{
			//フィーバー背景2表示
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground2, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 3 == 0)
		{
			//フィーバー背景3表示
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex3]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground3, sizeof(CustomVertex));

		}

		else
		{
			//フィーバー背景1表示
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground, sizeof(CustomVertex));

		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//背景表示2
			g_pD3Device->SetTexture(0, g_pTexture[g_backgroundTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background2, sizeof(CustomVertex));

		}

		else
		{
			//背景表示1
			g_pD3Device->SetTexture(0, g_pTexture[g_backgroundTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background, sizeof(CustomVertex));

		}

	}



	//テトリミノ表示
	for (int column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (int row = 0; row < TETLIS_WIDTH; row++)
		{
			//if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
			//{
			//	cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
			//	cusV4Tetmino->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
			//	//一マスずれて描画
			//	(cusV4Tetmino + 1)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
			//	(cusV4Tetmino + 1)->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
			//	(cusV4Tetmino + 2)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
			//	(cusV4Tetmino + 2)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
			//	(cusV4Tetmino + 3)->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
			//	(cusV4Tetmino + 3)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
			//	g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
			//	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			//}

			if (/*(g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9)*/
				(tetBoard.tetlisBoard[column][row] != -1) && (tetBoard.tetlisBoard[column][row] != 9)
				)
			{
				int kind = tetBoard.tetlisBoard[column][row];

				for (INT block = 0; block < 4; block++)
				{
					//g_tetlisBoard[g_movMinoNumOfArBuf.YX[block][0]][g_movMinoNumOfArBuf.YX[block][1]] = currentTetmino;
					if (g_movMinoNumOfArBuf.YX[block][0] == column &&
						g_movMinoNumOfArBuf.YX[block][1] == row)
					{
						kind = g_movMinoNumOfArBuf.m_Kind[block];
						break;
					}
				}

				cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				//一マスずれて描画
				(cusV4Tetmino + 1)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

				SetCatAndMouseUV(cusV4Tetmino, kind, false);

				//switch (tetBoard.tetlisPattern[column][row])
				//{
				//case 0://ネズミブロック
				//	cusV4Tetmino->tu = 0.5f;
				//	cusV4Tetmino->tv = 1.0f;
				//	/*2
				//	/*(cusV4Tetmino + 2)->tu = 0.5f;
				//	(cusV4Tetmino + 2)->tv = 1.0f;
				//	(cusV4Tetmino + 3)->tu = 0.5f;
				//	(cusV4Tetmino + 3)->tv = 1.0f;*/
				//	break;
				//case 1://ネコブロック1
				//	cusV4Tetmino->tu = 1.0f;
				//	cusV4Tetmino->tv = 1.0f;
				//	break;
				//case 2://ネコブロック2
				//	break;
				//case 3://ネコブロック3
				//	break;
				//default:
				//	break;
				//}
				g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}
		}
	}


	//ラインの数が10以上のときフィーバー枠 10以下なら通常枠
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 4 == 0)
		{
			//フィーバー枠4
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex4]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame4, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 5 == 0)
		{
			//フィーバー枠5
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex5]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame5, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 2 == 0)
		{
			//フィーバー枠2
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame2, sizeof(CustomVertex));
		}

		else if (FallSpeedLevel % 3 == 0)
		{
			//フィーバー枠3
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex3]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame3, sizeof(CustomVertex));

		}

		else
		{
			//フィーバー枠1
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame, sizeof(CustomVertex));
		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//枠2
			g_pD3Device->SetTexture(0, g_pTexture[g_frameTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame2, sizeof(CustomVertex));

		}

		else
		{
			//枠
			g_pD3Device->SetTexture(0, g_pTexture[g_frameTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame, sizeof(CustomVertex));

		}

	}

	//ネクスト枠
	g_pD3Device->SetTexture(0, g_pTexture[g_nextFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4NextFrame, sizeof(CustomVertex));


	//ホールド枠
	g_pD3Device->SetTexture(0, g_pTexture[g_holdFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HoldFrame, sizeof(CustomVertex));

	//フィーバーゲージ
	g_pD3Device->SetTexture(0, g_pTexture[g_gaugeTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame, sizeof(CustomVertex));

	//ハイスコア枠
	g_pD3Device->SetTexture(0, g_pTexture[g_scoreFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4ScoreFrame, sizeof(CustomVertex));

	//スコア枠
	g_pD3Device->SetTexture(0, g_pTexture[g_highScoreFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HighScoreframe, sizeof(CustomVertex));


	//現在スコア
	g_pFont[g_currentscoreFont]->DrawText(NULL, g_scoreArray, -1, rectCurrentScoreStr, NULL, NORMAL_COLOR);

	//現在ハイスコア
	g_pFont[g_currenthighscoreFont]->DrawText(NULL, HIGHSCORESHOW, -1, rectCurrentHighScoreStr, NULL, HIGHSCORE_COLOR);

	//フィーバーゲージ文字
	g_pFont[g_fevergaugeshowFont]->DrawText(NULL, FEVERGAUGE, -1, rectFevergaugeShowStr, NULL, GAMEOVER_COLOR);

	//落下速度レベル文字
	g_pFont[g_falllevelFont]->DrawText(NULL, g_LevelArray, -1, rectFallLevelStr, NULL, FEVERTIMER_COLOR);

	//落下速度レベル表示文字
	g_pFont[g_falllevelshowFont]->DrawText(NULL, FALLLEVEL, -1, rectFallLevelShowStr, NULL, FEVERTIMER_COLOR);


	//ラインの数が10以上のとき赤文字 10以下なら黒文字 フィーバーモード文字表示
	if (g_lineTotalCount >= 10)
	{

		//フィーバータイマー文字
		g_pFont[g_fevertimerFont]->DrawText(NULL, g_feverTimerArray, -1, rectFeverTimerStr, NULL, FEVER_COLOR);

		//フィーバータイム文字
		g_pFont[g_fevertimeshowFont]->DrawText(NULL, FEVERTIME, -1, rectFeverTimeShowStr, NULL, FEVER_COLOR);

		//フィーバーモード文字
		g_pD3Device->SetTexture(0, g_pTexture[g_feverStr]);

		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverStr, sizeof(CustomVertex));

	}

	else
	{
		//ラインカウント文字
		g_pFont[g_countFont]->DrawText(NULL, g_countArray, -1, rectCountStr, NULL, NORMAL_COLOR);


		//ラインカウント表示文字
		g_pFont[g_countFont]->DrawText(NULL, LINECOUNT, -1, rectCountShowStr, NULL, NORMAL_COLOR);

		//ノーマルモード文字
		g_pFont[g_normalFont]->DrawText(NULL, NORMALMODE, -1, rectNormalStr, NULL, NORMALMODE_COLOR);

	}


	if (g_hold.m_Kind[0] > BLOCK_KIND::NON)
	{
		for (int i = 0; i < 4; i++)
		{
			int coordinateY = g_hold.YX[i][0];
			int coordinateX = g_hold.YX[i][1];
			int kind = g_hold.m_Kind[i];

			cusV4Tetmino[0].x = 65.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
			cusV4Tetmino[0].y = 80.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
			cusV4Tetmino[1].x = 65.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
			cusV4Tetmino[1].y = 80.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
			cusV4Tetmino[2].x = 65.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
			cusV4Tetmino[2].y = 80.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
			cusV4Tetmino[3].x = 65.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
			cusV4Tetmino[3].y = 80.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

			SetCatAndMouseUV(cusV4Tetmino, kind, false);


			g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
		}

	}

	if (g_next.m_Kind[0] > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			int coordinateY = g_next.YX[i][0];
			int coordinateX = g_next.YX[i][1];
			int kind = g_next.m_Kind[i];

			cusV4NextTetmino[0].x = 690.f + coordinateX * (g_nextTetminoState.xScale * 2) - g_nextTetminoState.xScale;
			cusV4NextTetmino[0].y = 90.f + coordinateY * (g_nextTetminoState.yScale * 2) - g_nextTetminoState.yScale;
			cusV4NextTetmino[1].x = 690.f + coordinateX * (g_nextTetminoState.xScale * 2) + g_nextTetminoState.xScale;
			cusV4NextTetmino[1].y = 90.f + coordinateY * (g_nextTetminoState.yScale * 2) - g_nextTetminoState.yScale;
			cusV4NextTetmino[2].x = 690.f + coordinateX * (g_nextTetminoState.xScale * 2) + g_nextTetminoState.xScale;
			cusV4NextTetmino[2].y = 90.f + coordinateY * (g_nextTetminoState.yScale * 2) + g_nextTetminoState.yScale;
			cusV4NextTetmino[3].x = 690.f + coordinateX * (g_nextTetminoState.xScale * 2) - g_nextTetminoState.xScale;
			cusV4NextTetmino[3].y = 90.f + coordinateY * (g_nextTetminoState.yScale * 2) + g_nextTetminoState.yScale;

			SetCatAndMouseUV(cusV4NextTetmino, kind, false);

			g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4NextTetmino, sizeof(CustomVertex));
		}
	}

	if (g_nextNext.m_Kind[0] > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			int coordinateY = g_nextNext.YX[i][0];
			int coordinateX = g_nextNext.YX[i][1];
			int kind = g_nextNext.m_Kind[i];

			cusV4NextTetmino[0].x = 720.f + coordinateX * (g_nextTetminoState.xScale * 2) - g_nextTetminoState.xScale;
			cusV4NextTetmino[0].y = 210.f + coordinateY * (g_nextTetminoState.yScale * 2) - g_nextTetminoState.yScale;
			cusV4NextTetmino[1].x = 720.f + coordinateX * (g_nextTetminoState.xScale * 2) + g_nextTetminoState.xScale;
			cusV4NextTetmino[1].y = 210.f + coordinateY * (g_nextTetminoState.yScale * 2) - g_nextTetminoState.yScale;
			cusV4NextTetmino[2].x = 720.f + coordinateX * (g_nextTetminoState.xScale * 2) + g_nextTetminoState.xScale;
			cusV4NextTetmino[2].y = 210.f + coordinateY * (g_nextTetminoState.yScale * 2) + g_nextTetminoState.yScale;
			cusV4NextTetmino[3].x = 720.f + coordinateX * (g_nextTetminoState.xScale * 2) - g_nextTetminoState.xScale;
			cusV4NextTetmino[3].y = 210.f + coordinateY * (g_nextTetminoState.yScale * 2) + g_nextTetminoState.yScale;

			SetCatAndMouseUV(cusV4NextTetmino, kind, false);


			g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4NextTetmino, sizeof(CustomVertex));
		}
	}

	if (g_nextNextnext.m_Kind[0] > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			int coordinateY = g_nextNextnext.YX[i][0];
			int coordinateX = g_nextNextnext.YX[i][1];
			int kind = g_nextNextnext.m_Kind[i];

			cusV4NextTetmino[0].x = 695.f + coordinateX * (g_nextTetminoState.xScale * 2) - g_nextTetminoState.xScale;
			cusV4NextTetmino[0].y = 320.f + coordinateY * (g_nextTetminoState.yScale * 2) - g_nextTetminoState.yScale;
			cusV4NextTetmino[1].x = 695.f + coordinateX * (g_nextTetminoState.xScale * 2) + g_nextTetminoState.xScale;
			cusV4NextTetmino[1].y = 320.f + coordinateY * (g_nextTetminoState.yScale * 2) - g_nextTetminoState.yScale;
			cusV4NextTetmino[2].x = 695.f + coordinateX * (g_nextTetminoState.xScale * 2) + g_nextTetminoState.xScale;
			cusV4NextTetmino[2].y = 320.f + coordinateY * (g_nextTetminoState.yScale * 2) + g_nextTetminoState.yScale;
			cusV4NextTetmino[3].x = 695.f + coordinateX * (g_nextTetminoState.xScale * 2) - g_nextTetminoState.xScale;
			cusV4NextTetmino[3].y = 320.f + coordinateY * (g_nextTetminoState.yScale * 2) + g_nextTetminoState.yScale;

			SetCatAndMouseUV(cusV4NextTetmino, kind, false);

			g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4NextTetmino, sizeof(CustomVertex));
		}
	}


	//フィーバーゲージブロック
	if (g_lineTotalCount != 0)
	{
		switch (g_lineTotalCount)
		{

		case 1:

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			break;

		case 2:

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);


			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 3:

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));



			break;

		case 4:

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 5:

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			break;

		case 6:

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 7:
			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 8:
			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			break;

		case 9:
			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);

			g_pD3Device->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 10:
			g_pD3Device->SetTexture(0, g_pTexture[g_gaugeFiverTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame_Fiver, sizeof(CustomVertex));

			break;

		default:
			break;

		}

		if (/*g_lineTotalCount <= 9 && */g_lineTotalCount >= 10)
		{
			g_pD3Device->SetTexture(0, g_pTexture[g_gaugeFiverTex]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame_Fiver, sizeof(CustomVertex));

		}

	}

	//ゲームオーバー
	if (g_showGameoverStr)
	{
		//ゲームオーバー文字
		g_pD3Device->SetTexture(0, g_pTexture[g_gameoverStrTex]);

		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GameoverStr, sizeof(CustomVertex));

	}

	g_pD3Device->EndScene();

	return;
}

void SetCatAndMouseUV(CustomVertex vertex[], int kind, bool is_flg_convert)
{
	if (is_flg_convert == true)
	{
		kind = BLOCK_KIND_SHIFT(kind);
	}

	if (kind & 1 << (8 + BLOCK_KIND::CAT_01))
	{
		vertex[0].tu = 0.0f;
		vertex[0].tv = 0.0f;
		vertex[1].tu = 0.5f;
		vertex[1].tv = 0.0f;
		vertex[2].tu = 0.5f;
		vertex[2].tv = 0.5f;
		vertex[3].tu = 0.0f;
		vertex[3].tv = 0.5f;
	}
	else if (kind & 1 << (8 + BLOCK_KIND::CAT_02)) {
		vertex[0].tu = 0.5f;
		vertex[0].tv = 0.0f;
		vertex[1].tu = 1.0f;
		vertex[1].tv = 0.0f;
		vertex[2].tu = 1.0f;
		vertex[2].tv = 0.5f;
		vertex[3].tu = 0.5f;
		vertex[3].tv = 0.5f;
	}
	else if (kind & 1 << (8 + BLOCK_KIND::CAT_03)) {
		vertex[0].tu = 0.0f;
		vertex[0].tv = 0.5f;
		vertex[1].tu = 0.5f;
		vertex[1].tv = 0.5f;
		vertex[2].tu = 0.5f;
		vertex[2].tv = 1.0f;
		vertex[3].tu = 0.0f;
		vertex[3].tv = 1.0f;
	}
	else if (kind & 1 << (8 + BLOCK_KIND::MOUSE)) {
		vertex[0].tu = 0.5f;
		vertex[0].tv = 0.5f;
		vertex[1].tu = 1.0f;
		vertex[1].tv = 0.5f;
		vertex[2].tu = 1.0f;
		vertex[2].tv = 1.0f;
		vertex[3].tu = 0.5f;
		vertex[3].tv = 1.0f;
	}
	else if (kind & 1 << (8 + BLOCK_KIND::KILL_ZONE)) {
		vertex[0].tu = 0.f;
		vertex[0].tv = 0.f;
		vertex[1].tu = 0.f;
		vertex[1].tv = 0.f;
		vertex[2].tu = 0.f;
		vertex[2].tv = 0.f;
		vertex[3].tu = 0.f;
		vertex[3].tv = 0.f;
	}
	else {
		vertex[0].tu = 0.0f;
		vertex[0].tv = 0.0f;
		vertex[1].tu = 0.5f;
		vertex[1].tv = 0.0f;
		vertex[2].tu = 0.5f;
		vertex[2].tv = 0.5f;
		vertex[3].tu = 0.0f;
		vertex[3].tv = 0.5f;
	}
}
