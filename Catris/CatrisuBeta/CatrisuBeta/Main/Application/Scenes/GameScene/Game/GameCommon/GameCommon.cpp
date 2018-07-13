#include "GameCommon.h"

//テトリミノ座標
ImageState g_tetminoState = { 0.f, 0.f, 32.f / 2, 32.f / 2 };

//ネクストテトリミノ座標
ImageState g_nextTetminoState = { 0.f, 0.f, 24.f / 2, 24.f / 2 };

//現在スコア座標
ImageState g_CurrentScoreStrState = { 910.f,700.f,200.f, 225.f };

//現在ハイスコア座標
ImageState g_CurrentHighScoreStrState = { 1170.f,820.f,400.f, 225.f };

//ホールド枠文字座標
ImageState g_HoldStrState = { 200.f,150.f,170.f, 140.f };

//ラインカウント文字座標
ImageState g_CountStrState = { 1550.f,445.f,400.f, 200.f };

//ラインカウント表示文字座標
ImageState g_CountShowStrState = { 1380.f,385.f,400.f, 200.f };

//ノーマルモード文字座標
ImageState g_NormalStrState = { 1200.f,220.f,300.f, 200.f };

//フィーバーモード文字座標
ImageState g_FeverStrState = { 1200.f,220.f,300.f, 200.f };

//フィーバータイマー座標
ImageState g_FeverTimerStrState = { 1165.f,500.f,50.f, 50.f };

//フィーバータイム座標
ImageState g_FeverTimeShowStrState = { 1100.f,435.f,150.f, 50.f };

//フィーバーゲージ文字座標
ImageState g_FevergaugeStrState = { 335.f,370.f,150.f, 50.f };

//落下速度レベル文字座標
ImageState g_FallLevelStrState = { 1190.f,190.f,50.f, 50.f };

//落下速度レベル表示文字座標
ImageState g_FallLevelShowStrState = { 1140.f,150.f,150.f, 50.f };

//フィーバーゲージブロック
ImageState g_GaugeBlockState = { 215.f, 655.f, 32.f / 2, 32.f / 2 };


//テトリミノパターン
Tetmino g_tetmino[7] =
{
	{ 0,'I',1,4,1,5,1,6,1,7 },
{ 1,'J',1,5,2,5,2,6,2,7 },
{ 2,'L',1,7,2,7,2,6,2,5 },
{ 3,'S',1,7,1,6,2,6,2,5 },
{ 4,'Z',1,5,1,6,2,6,2,7 },
{ 5,'T',2,5,1,6,2,6,2,7 },
{ 6,'O',1,5,2,5,1,6,2,6 }
};

//ネズミブロック
TetminoMouse g_tetminoM[1] =
{
	{ 0,'M',1,4,1,5 }
};

TetBoard tetBoard;
TetBoardBuf tetBoardBuf;
TetIBuf tetIBuf;
HoldBoard holdBoard;
NextBoard nextBoard;
NextNextBoard nextNextBoard;
NextNextNextBoard nextNextNextBoard;


MovMinoNumoOfArBuf g_movMinoNumOfArBuf;

INT g_tetminoNum;
//INT g_hold = -1 g_next, g_nextNext,g_nextNextnext;

MovMinoNumoOfArBuf g_hold, g_next, g_nextNext, g_nextNextnext;

INT g_feverBlock;//フィーバーブロック

INT g_lineTotalCount;//ラインの合計

DWORD g_elapsedTime;//フィーバーモードの経過時間

DWORD g_startTime;//フィーバーモードの開始時間

INT FallSpeedLevel = 1000;
INT FlamePerDown = 1000;

INT g_tetminoPattern1;//ブロックの種類設定
INT g_tetminoPattern2;
INT g_tetminoPattern3;
INT g_tetminoPattern4;

INT g_minoIRoatationCount = 0;
INT g_tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
INT g_tetlisBoardBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
INT g_tetminoIBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
INT g_holdBoard[4][4];
INT g_nextBoard[4][4];
INT g_nextNextBoard[4][4];
INT g_nextNextNextBoard[4][4];



BOOL g_showGameoverStr = false;

CHAR g_scoreArray[8];

CHAR g_countArray[4];

CHAR g_feverTimerArray[2];

CHAR g_LevelArray[2];//レベル