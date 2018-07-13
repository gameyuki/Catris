#ifndef GAME_COMMON_H
#define	GAME_COMMON_H

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <d3dx9.h>

//テトリスサイズ
#define TETLIS_WIDTH 12
#define TETLIS_HEIGHT 24

#define SHIFT_FRAME_COUNTER 6
#define DOWN_FRAME_COUNTER 2

#define FLAME_PER_DOWN 55 //テトリミノの落ちる速さ
#define FLAME_PER_STOP 30 //テトリミノが設置までの時間

#define FEVERGAUGEBLOCK_TOTAL 10 //フィーバーゲージブロックの数

#define FEVER_TIME 22 //フィーバーモードの時間

// ブロックの種類
typedef enum
{
	NON,
	CAT_01,		// 猫１
	CAT_02,		// 猫２
	CAT_03,		// 猫３
	MOUSE,		// ネズミ
	KILL_ZONE,	// ネズミが狩られて空いた穴
} BLOCK_KIND;

typedef struct
{
	FLOAT x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CustomVertex;

typedef struct
{
	FLOAT x, y, xScale, yScale;
}ImageState;

extern ImageState g_nextTetminoState;

extern ImageState g_tetminoState;
extern ImageState g_GameoverStrState;
extern ImageState g_CurrentScoreStrState;

extern ImageState g_HoldStrState;
extern ImageState g_NextStrState;
extern ImageState g_CountStrState;
extern ImageState g_CountShowStrState;
extern ImageState g_GaugeBlockState;
extern ImageState g_CurrentHighScoreStrState;

extern ImageState g_NormalStrState;
extern ImageState g_FeverStrState;
extern ImageState g_FeverTimerStrState;
extern ImageState g_FeverTimeShowStrState;
extern ImageState g_FevergaugeStrState;
extern ImageState g_FallLevelStrState;
extern ImageState g_FallLevelShowStrState;

typedef struct
{
	INT tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
	INT tetlisPattern[TETLIS_HEIGHT][TETLIS_WIDTH];
}TetBoard;

typedef struct
{
	INT tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
	INT tetlisPattern[TETLIS_HEIGHT][TETLIS_WIDTH];
}TetBoardBuf;

typedef struct
{
	INT tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
	INT tetlisPattern[TETLIS_HEIGHT][TETLIS_WIDTH];
}TetIBuf;

typedef struct
{
	INT tetlisBoard[4][4];
	INT tetlisPattern[4][4];
}HoldBoard;

typedef struct
{
	INT tetlisBoard[4][4];
	INT tetlisPattern[4][4];
}NextBoard;

typedef struct
{
	INT tetlisBoard[4][4];
	INT tetlisPattern[4][4];
}NextNextBoard;

typedef struct
{
	INT tetlisBoard[4][4];
	INT tetlisPattern[4][4];
}NextNextNextBoard;


extern TetBoard tetBoard;
extern TetBoardBuf tetBoardBuf;
extern TetIBuf tetIBuf;
extern HoldBoard holdBoard;
extern NextBoard nextBoard;
extern NextNextBoard nextNextBoard;
extern NextNextNextBoard nextNextNextBoard;

//テトリミノパターン
typedef struct
{
	INT number;
	CHAR name;
	INT yx[4][2];

	INT pattern_yx[4][2];

} Tetmino;

//ネズミブロック
typedef struct
{
	INT number;
	CHAR name;
	INT yx[2][2];
} TetminoMouse;


//テトリスボード
typedef struct
{
	INT g_tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
	CHAR name;
	INT yx[2][2];
} TetlisBoard;

extern Tetmino g_tetmino[7];
extern TetminoMouse g_tetmioM[1];

typedef struct
{
	INT YX[4][2];
	INT tetminoPattern[4][2];//ブロックの種類設
	int m_Kind[4];
}MovMinoNumoOfArBuf;

extern MovMinoNumoOfArBuf g_movMinoNumOfArBuf;

enum tetminoType
{
	tetminoMouse,
	tetminoCat1,
	tetminoCat2,
	tetminoCat3
};

extern INT g_tetminoNum;
//extern INT g_hold, g_next, g_nextNext,g_nextNextnext;

extern INT g_feverBlock;//フィーバーブロック

extern INT g_lineTotalCount;//ラインの合計

extern DWORD g_elapsedTime;//フィーバーモードの経過時間
extern DWORD g_startTime;//フィーバーモードの開始時間
extern INT FallSpeedLevel;
extern INT FlamePerDown;

extern INT g_tetminoPattern1;//ブロックの種類設定
extern INT g_tetminoPattern2;
extern INT g_tetminoPattern3;
extern INT g_tetminoPattern4;

extern INT g_tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_tetlisBoardBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_tetminoIBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_holdBoard[4][4];
extern INT g_nextBoard[4][4];
extern INT g_nextNextBoard[4][4];
extern INT g_nextNextNextBoard[4][4];

extern INT g_fevergaugeBoard[1][10]; //フィーバーゲージブロック

extern BOOL g_showGameoverStr;

extern CHAR g_scoreArray[8];

extern CHAR g_countArray[4];

extern CHAR g_feverTimerArray[2];

extern CHAR g_LevelArray[2];

extern MovMinoNumoOfArBuf g_hold, g_next, g_nextNext, g_nextNextnext;


//テトリスなどの操作に関する関数
VOID Control(VOID);

//テトリスボードを初期化する関数
VOID InitTetlisBoard(VOID);

//テトリスボードバッファーを初期化する関数
VOID InitTetlisBoardBuf(VOID);



//フィーバーゲージの中身を更新する関数
VOID UpdateFeverGauge(INT *lineCount, INT g_feverBlock);

//消したラインの合計でフィーバーゲージブロックを表示する関数
VOID FeverGaugeBlock(VOID);

//ホールド、ネクスト、ネクストネクストを初期化する関数
VOID InitNextAndFever();

//ホールド、ネクスト、ネクストネクストボードの中身を更新する関数
VOID UpdateHoldNextNextNextBoard(VOID);

//テトリス配列バッファーに可動テトリミノを除いたテトリス配列の要素を同期させる関数
VOID SynchroTetlisBoardBufToTetlisBoard(bool is_convert = false);

//テトリス配列に可動テトリミノを同期させる関数
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino);

//テトリスに関するデータを初期状態に戻す関数
VOID ReturnToInitialStateWithTetlis(
	BOOL *isGameover,
	BOOL *canCreate,
	BOOL *canInputRA,
	BOOL *canInputLA,
	BOOL *canInputDA,
	BOOL *canInputR,
	BOOL *canInputL,
	BOOL *canInputSpace,
	BOOL *canHold,
	BOOL *wasHold,
	BOOL *canSetStatrTime,
	INT *rACount,
	INT *lACount,
	INT *dACount,
	INT *stopCount,
	INT *downCount,
	INT *currentTetmino,
	INT *minoIRoatationCount,
	DWORD *g_elapsedTime,
	DWORD *g_startTime,
	INT *FeverTimer,
	INT *FallSpeedLevel,
	INT *FlamePerDown,
	INT *g_CurrentTetminoPattern,
	INT *g_tetminoPatternNext,
	INT *g_tetminoPatternNextNext,
	INT *g_tetminoPatternNextNextNext
);

//テトリミノを生成に関する関数
VOID CreateTetlimino(
	INT currentTetmino,
	BOOL *canInputLA,
	BOOL *canInputDA,
	BOOL *canInputRA,
	BOOL *canInputR,
	BOOL *canInputL,
	BOOL *canInputSpace,
	BOOL *wasHold,
	INT *stopCount,
	INT *downCount,
	INT *minoIRoatationCount,
	BOOL *canCreate,

	INT *g_tetminoPattern1,
	INT *g_tetminoPattern2,
	INT *g_tetminoPattern3,
	INT *g_tetminoPattern4
);

//キー入力をカウントをとり可能にする関数
VOID CountToMakeFlagTrue(BOOL *canInputLA, INT *lACount);

//テトリミノをホールドすることに関する関数
VOID HoldTetlimino(
	BOOL *canHold,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *wasHold
);

//テトリミノのX軸方向の移動に関する関数
VOID ShiftTetliminoX(INT shiftX, BOOL *canInputRA);

//テトリミノの回転に関する関数(右回転)
VOID RotateTetliminoRight(BOOL *minoIRoatationCount, INT currentTetmino);

//テトリミノの回転に関する関数(左回転)
VOID RotateTetliminoLeft(BOOL *minoIRoatationCount, INT currentTetmino);

//テトリミノのY軸方向の移動に関する関数
VOID DownTetlimino(BOOL *canInputDA);

//テトリミノのハードドロップに関する関数
//VOID HardDropTetlimino(VOID);

//テトリミノの自動落下に関する関数
VOID CountToDawnTetlimino(INT *downCount, INT *FallSpeedLevel, INT *FlamePerDown);

//テトリミノ停止に関する関数
bool CountToStopTetlimino(
	INT *stopCount,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *canHold,
	BOOL *wasHold
);

//そろったテトリスのラインを消しカウントをとる関数
int DeleteAndCountFilledLine();

//消されたテトリスのライン部分にずらす関数
void ShiftTetlisLine(void);

bool LineDelete(VOID);


//テトリスのスコアに関する関数
int GetScoreByLineCount(INT lineCount);

//ゲームオーバーか、否かを調べるする関数
VOID CheckGameover(BOOL *isGameover);

//フィーバーモードの時間関数 フィーバーモードが終わるとFallSpeedLevelが +1、FlamePerDownが-2にする
VOID FeverTime(INT *g_lineTotalCount, DWORD *g_elapsedTime, DWORD *g_startTime, BOOL *canSetStartTime, INT *FeverTimer, INT *FallSpeedLevel, INT *FlamePerDown);

//フィーバーモードの開始時間関数
VOID SetFeverStartTime(DWORD *g_startTime, BOOL *canSetStartTime);

//ブロックの種類設定
VOID SetTetminoPattern(INT *TetminoPattern);

//ブロックの種類定義
VOID defineTetminoPattern(INT *g_tetminoPattern1, INT *g_tetminoPattern2, INT *g_tetminoPattern3, INT *g_tetminoPattern4, INT currentTetmino);

void InitNextBlock(MovMinoNumoOfArBuf *next_block, int block = -1);

BLOCK_KIND GetBlockKind(bool is_fever = false);

#define BLOCK_KIND_SHIFT(kind) (1 << (8 + kind))



#endif