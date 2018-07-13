#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"
#include "Library\DirectInput\DirectInput.h"
#include "Main\Main.h"
#include <stdio.h>
#include <dinput.h>
enum
{
	MAIN_INIT,
	MAIN_RUN,
};

enum
{
	TETMINO_CONTROL,
	MOUSE_ERASE,
	MOUSE_ERASE_SHIFT,
	LINE_ERASE,
	GAME_OVER,
};

BOOL isGameover = false;

static BOOL canInputLA = true,
canInputDA = true,
canInputRA = true,
canInputR = true,
canInputL = true,
canInputSpace = true,
isNewGame = true,
canHold = true,
wasHold = false,
canCreate = true,
canSetStartTime = true;

static bool g_Isfever = false;

//生成されるのテトリミノ種類を決める
static INT
rACount = 0,
lACount = 0,
dACount = 0,
stopCount = 0,
downCount = 0,
minoIRoatationCount = 0,

prevEKeyState,              //右回転Eキー入力状態を保存

prevTEN9KeyState,           //右回転テンキー9入力状態を保存

prevQKeyState,              //左回転Qキー入力状態を保存

prevTEN7KeyState,           //左回転テンキー7入力状態を保存

prevRKeyState,              //ホールドRキー入力状態を保存

prevTENplusKeyState,        //ホールドテンキー + 入力状態を保存

FeverTimer = 0,

currentTetmino = rand() % 7;

int g_MainStep = 0;
int g_GameStep = 0;


void MainInit()
{
	//ニューゲーム(一番最初のフレーム)時にはg_feverBlock、g_nextとg_nextNext、g_nextNextnextは初期化されていないので初期化し、isNewGameをfalseにする
	InitNextAndFever();

	////ブロックの種類設定
	//SetTetminoPattern(&g_tetminoPattern1);
	//SetTetminoPattern(&g_tetminoPattern2);
	//SetTetminoPattern(&g_tetminoPattern3);
	//SetTetminoPattern(&g_tetminoPattern4);

	InitTetlisBoard();
	InitTetlisBoardBuf();

	ReturnToInitialStateWithTetlis(
		&isGameover,
		&canCreate,
		&canInputRA,
		&canInputLA,
		&canInputDA,
		&canInputR,
		&canInputL,
		&canInputSpace,
		&canHold,
		&wasHold,
		&canSetStartTime,
		&rACount,
		&lACount,
		&dACount,
		&stopCount,
		&downCount,
		&currentTetmino,
		&minoIRoatationCount,
		&g_elapsedTime,
		&g_startTime,
		&FeverTimer,
		&FallSpeedLevel,
		&FlamePerDown,
		&g_tetminoPattern1,
		&g_tetminoPattern2,
		&g_tetminoPattern3,
		&g_tetminoPattern4
	);

	InitNextBlock(&g_movMinoNumOfArBuf, currentTetmino);

	for (int i = 0; i < 4; i++)
	{
		g_movMinoNumOfArBuf.YX[i][1] += 3;
	}

	sprintf(g_scoreArray, "%d", 0);

	g_MainStep = MAIN_RUN;
}


void TetminoControl()
{
	//キーデバイスに入っている情報を読み取る準備
	HRESULT hr = pKeyDevice->Acquire();

	if ((hr != DI_OK) && (hr != S_FALSE))
	{
		return;
	}

	//キー入力情報のバッファー
	BYTE diks[256];

	//入力された情報を読み取る
	pKeyDevice->GetDeviceState(sizeof(diks), &diks);

	INT lineCount = 0;


	//INT lineTotalCount = 0;

	INT LEFT[2] = { 0,diks[DIK_A] & 0x80 },             //左移動 Aキー
		TEN_LEFT[2] = { 0,diks[DIK_NUMPAD4] & 0x80 },      //左移動 テンキー4

		DOWN[2] = { 0,diks[DIK_S] & 0x80 },             //下移動 Sキー
		TEN_DOWN[2] = { 0,diks[DIK_NUMPAD2] & 0x80 },   //下移動 テンキー2

		RIGHT[2] = { 0,diks[DIK_D] & 0x80 },            //右移動 Dキー
		TEN_RIGHT[2] = { 0,diks[DIK_NUMPAD6] & 0x80 };   //右移動 テンキー6


														 //テトリス配列にテトリス配列バッファーの要素全てをコピーしている
														 //memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

	//リセットボタン、初期状態に戻す
	if (diks[DIK_BACK] & 0x80)
	{
		//フラグ、カウント、配列を初期状態に戻しUpdateHoldNextNextNextBoardを用いる
		ReturnToInitialStateWithTetlis(
			&isGameover,
			&canCreate,
			&canInputRA,
			&canInputLA,
			&canInputDA,
			&canInputR,
			&canInputL,
			&canInputSpace,
			&canHold,
			&wasHold,
			&canSetStartTime,
			&rACount,
			&lACount,
			&dACount,
			&stopCount,
			&downCount,
			&currentTetmino,
			&minoIRoatationCount,
			&g_elapsedTime,
			&g_startTime,
			&FeverTimer,
			&FallSpeedLevel,
			&FlamePerDown,
			&g_tetminoPattern1,
			&g_tetminoPattern2,
			&g_tetminoPattern3,
			&g_tetminoPattern4
		);
	}

	sprintf(g_countArray, "%d", g_lineTotalCount);

	sprintf(g_feverTimerArray, "%d", FeverTimer);

	sprintf(g_LevelArray, "%d", FallSpeedLevel);

	//g_lineTotalCountが10以上のときフィーバーモードの開始時間をセット
	if (g_lineTotalCount >= 10)
	{
		SetFeverStartTime(&g_startTime, &canSetStartTime);
		FeverTime(&g_lineTotalCount, &g_elapsedTime, &g_startTime, &canSetStartTime, &FeverTimer, &FallSpeedLevel, &FlamePerDown);
	}
	else
	{
		g_Isfever = false;
	}

	sprintf(g_LevelArray, "%d", FallSpeedLevel);

	for (g_tetminoNum = 0; g_tetminoNum < 7; g_tetminoNum++)
	{
		if (g_tetmino[g_tetminoNum].number != currentTetmino)
		{
			continue;
		}

		//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

		//ブロックの種類定義
		defineTetminoPattern(&g_tetminoPattern1, &g_tetminoPattern2, &g_tetminoPattern3, &g_tetminoPattern4, currentTetmino);

		if (canCreate == false)
		{
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		}
		SynchroTetlisBoardBufToTetlisBoard();

		//g_canCreateを確認しtrueならばg_movMinoNumOfArBufにcurrentTetminoと同じ種類のテトリミノ初期座標を代入し、キー入力のフラグ、
		//I型のテトリミノが何回転したかを確認するカウント、ホールドが行われたか否かのフラグを初期状態に戻し、g_canCreateをfalseにする
		CreateTetlimino(
			currentTetmino,
			&canInputLA,
			&canInputDA,
			&canInputRA,
			&canInputR,
			&canInputL,
			&canInputSpace,
			&wasHold,
			&stopCount,
			&downCount,
			&minoIRoatationCount,
			&canCreate,

			&g_tetminoPattern1,
			&g_tetminoPattern2,
			&g_tetminoPattern3,
			&g_tetminoPattern4
		);

		break;
	}


	//フラグがfalseならばカウントを1増やし、一定値ならばフラグはtrueに変えカウントを初期状態にする
	CountToMakeFlagTrue(&canInputLA, &lACount);
	CountToMakeFlagTrue(&canInputRA, &rACount);
	CountToMakeFlagTrue(&canInputDA, &dACount);

	//ホールド

	//前フレーム時にRキー、+キーが押されていた場合この処理を通さない、
	//とすることによって連続したフレーム毎にこの処理がされるのを防いでいる


	//Rキー
	if (!(prevRKeyState))
	{
		if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//canHoldがtrueならばg_holdに現在のテトリミノの値を代入し、すでに-1(空欄)以外が入っていた場合currentTetminoにg_holdの値を入れる、
			//その後g_canCreateをtrueにしUpdateHoldNextNextNextBoardを呼び出す
			HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
		}
	}

	//+キー
	if (!(prevTENplusKeyState))
	{
		if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//canHoldがtrueならばg_holdに現在のテトリミノの値を代入し、すでに-1(空欄)以外が入っていた場合currentTetminoにg_holdの値を入れる、
			//その後g_canCreateをtrueにしUpdateHoldNextNextNextBoardを呼び出す
			HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
		}
	}

	//ホールドが行われていた場合新しくテトリミノを生成するので、この処理を通さない
	if (!(wasHold))
	{
		if (RIGHT[canInputRA] || TEN_RIGHT[canInputRA])
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//g_movMinoNumOfArBufに引数を足した配列番号をg_tetlisBoardBufで参照し、空欄だった場合g_movMinoNumOfArBufに引数を足した値を代入する
			ShiftTetliminoX(1, &canInputRA);
		}

		if (LEFT[canInputLA] || TEN_LEFT[canInputLA])
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			ShiftTetliminoX(-1, &canInputLA);
		}

		//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		SynchroTetlisBoardBufToTetlisBoard();

		//右回転

		//前フレーム時にEキー、テンキー9が押されていたならば、この処理を通さない、
		//とすることによって連続で同じ処理がされることを防いでいる

		//Eキー
		if (!(prevEKeyState))
		{
			if (diks[DIK_E] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
				//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
				//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
				RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
			}
		}

		//テンキー9
		if (!(prevTEN9KeyState))
		{
			if (diks[DIK_NUMPAD9] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
				//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
				//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
				RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
			}
		}


		//左回転

		//前フレーム時にQキー、テンキー7が押されていたならば、この処理を通さない、
		//とすることによって連続で同じ処理がされることを防いでいる

		//Qキー
		if (!(prevQKeyState))
		{
			if (diks[DIK_Q] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
				//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
				//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
				RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
			}
		}

		//テンキー7
		if (!(prevTEN7KeyState))
		{
			if (diks[DIK_NUMPAD7] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
				//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
				//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
				RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
			}
		}

		if (DOWN[canInputDA] || TEN_DOWN[canInputDA])
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//g_movMinoNumOfArBufのY方向に１足した配列を用いてg_tetlisBoardBufを参照し、空欄の場合移動を行う
			DownTetlimino(&canInputDA);
		}

		////ハードドロップ　テトリミノのブロックを一個づつ下方を確認し、そこが空欄ではない場合、そこから1つ上にワープさせる
		//if (diks[DIK_UP] & 0x80)
		//{
		//	memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//	SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		//	SynchroTetlisBoardBufToTetlisBoard();

		//	
		//	//ループカウンタを用いg_tetlisBoardBufを参照し、空欄ではなかった場合g_movMinoNumOfArBufを
		//	//ループカウンタ-1の場所にテトリミノを移動させる
		//	HardDropTetlimino();
		//}

		//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		SynchroTetlisBoardBufToTetlisBoard();

		//テトリミノの下方を確認し、空欄だった場合カウントをとり、FLAME_PER_DOWNに達した場合一つ下に移動させる

		//g_movMinoNumOfArBuf+1した配列番号を用いてg_tetlisBoardBufを参照し、空欄だった場合カウントを1増やし、
		//一定値ならばg_movMinoNumOfArBufに１を足し、カウントを初期状態にする
		CountToDawnTetlimino(&downCount, &FallSpeedLevel, &FlamePerDown);

		//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		SynchroTetlisBoardBufToTetlisBoard();

		///*テトリミノ下方を確認し、そこが空欄ではない場合カウントをとり、FLAME_PER_STOPに達した場合
		//可動テトリミノのナンバーに10を足し(簡単に可動か非可動を判別するため)、新しい可動テトリミノを生成する*/
		//	
		//g_movMinoNumOfArBuf+1をした配列番号を用いg_tetlisBoardBufを参照し、空欄(-1)以外が入っていた場合
		//カウントを１増やし、一定値ならばcurrentTetmino + 10をg_tetlisBoardに代入し、
		//テトリミノを生成できるか否か、ホールドができるか否かのフラグをtrue、
		//ホールドが行われたかのフラグをfalseにし、currentTetminoにg_next、g_nextにg_nextNext、
		//g_nextNextにg_nextNextnextを代入して、
		//g_nextNextnextにテトリミノ番号の範囲の乱数を代入する
		if (CountToStopTetlimino(&stopCount, &currentTetmino, &canCreate, &canHold, &wasHold) == true)
		{
			g_GameStep = LINE_ERASE;
		}

		////memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		//SynchroTetlisBoardBufToTetlisBoard();

		//そろっている列があるか確認しカウントをとる
		//memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		//SynchroTetlisBoardBufToTetlisBoard();

	}

	//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	if (g_GameStep != LINE_ERASE)
	{
		SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
	}
	SynchroTetlisBoardBufToTetlisBoard();

	//キー入力状態を保存

	//右回転
	prevEKeyState = diks[DIK_E] & 0x80;
	prevTEN9KeyState = diks[DIK_NUMPAD9] & 0x80;

	//左回転
	prevQKeyState = diks[DIK_Q] & 0x80;
	prevTEN7KeyState = diks[DIK_NUMPAD7] & 0x80;

	//ホールド
	prevRKeyState = diks[DIK_R] & 0x80;
	prevTENplusKeyState = diks[DIK_NUMPADPLUS] & 0x80;

	//フィーバーゲージの中身を更新する関数
	UpdateFeverGauge(&lineCount, g_feverBlock);

	//プレイ時の見える範囲内で一番上の部分に非可動テトリミノがある場合isGameoverをtrueにする
	CheckGameover(&isGameover);
}

void LineErase()
{
	static int score = 0;
	int line_count = 0;

	//g_tetlisBoardBuf中身を確認し一列が空欄(-1)以外の場合カウントをとり空欄にする
	line_count = DeleteAndCountFilledLine();
	g_lineTotalCount += line_count;
	sprintf(g_countArray, "%d", g_lineTotalCount);

	//lineCountの値によってscoreBufの増やす値を変え、文字列にしg_scoreArrayに代入する
	score += GetScoreByLineCount(line_count);
	sprintf(g_scoreArray, "%d", score);

	//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

	memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	SynchroTetlisBoardBufToTetlisBoard(true);

	//そろった列を空欄にして下にずらしている

	//g_tetlisBoardBufを参照し、空欄(-1)以外の場合ループカウンタ+1した配列番号を用い、再度参照し、
	//一列全て空欄の場合ループカウンタ+1の配列番号にコピーし、コピー元を空欄に書き換える
	if (line_count > 0)
	{
		ShiftTetlisLine();
	}

	g_movMinoNumOfArBuf = g_next;
	g_next = g_nextNext;
	g_nextNext = g_nextNextnext;
	InitNextBlock(&g_nextNextnext);

	for (int i = 0; i < 4; i++)
	{
		g_movMinoNumOfArBuf.YX[i][1] += 3;
	}

	g_GameStep = TETMINO_CONTROL;
	canCreate = true;
}

// 猫とネズミ
void MouseErase()
{
}

void MouseEraseShift()
{
}

void MainControl()
{
	switch (g_GameStep)
	{
	case TETMINO_CONTROL:
		TetminoControl();
		break;
		// ネズミを消す
	case MOUSE_ERASE:
		MouseErase();
		break;
		// ネズミでできた穴を埋める
	case MOUSE_ERASE_SHIFT:
		MouseEraseShift();
		break;
		// 
	case LINE_ERASE:
		LineErase();
		break;
	case GAME_OVER:
		//ゲームオーバー時に文字列を表示させる
		g_showGameoverStr = true;

		g_lineTotalCount = 0;
		break;
	}
}

//テトリスなどの操作に関する関数
VOID Control(VOID)
{
	switch (g_MainStep)
	{
	case MAIN_INIT:
		MainInit();
		break;
	case MAIN_RUN:
		MainControl();
		break;
	}

	return;
}


//テトリスボードを初期化
//－1は空欄を表し、先に全ての配列の中身を空欄にすることにより、
//壁(9)を上から塗りつぶすだけで表が完成する
VOID InitTetlisBoard(VOID)
{
	for (INT column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (INT row = 0; row < TETLIS_WIDTH; row++)
		{

			//g_tetlisBoard[column][row] = -1;
			tetBoard.tetlisBoard[column][row] = -1;
			if (row == TETLIS_WIDTH - 12 || row == TETLIS_WIDTH - 1)
			{
				//g_tetlisBoard[column][row] = 9;
				tetBoard.tetlisBoard[column][row] = 9;
			}
			if (column == TETLIS_HEIGHT - 1)
			{
				//g_tetlisBoard[column][row] = 9;
				tetBoard.tetlisBoard[column][row] = 9;
			}
		}
	}

	return;
}


//テトリスボードバッファーを初期化
//可動テトリミノ(動いてるやつ)をテトリスボードバッファーに入れないようにすることにより、
//回転、移動などの際、可動テトリミノを考慮せずとも良い
VOID InitTetlisBoardBuf(VOID)
{

	for (INT column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (INT row = 0; row < TETLIS_WIDTH; row++)
		{
			tetBoardBuf.tetlisBoard[column][row] = -1;
			//g_tetlisBoardBuf[column][row] = -1;
			if (row == TETLIS_WIDTH - 12 || row == TETLIS_WIDTH - 1)
			{
				//g_tetlisBoardBuf[column][row] = 9;
				tetBoardBuf.tetlisBoard[column][row] = 9;
			}
			if (column == TETLIS_HEIGHT - 1)
			{
				//g_tetlisBoardBuf[column][row] = 9;
				tetBoardBuf.tetlisBoard[column][row] = 9;
			}
		}
	}

	return;
}


//ホールド、ネクスト、ネクストネクストボードの中身を更新する関数
//テトリミノの初期座標(生成されるときの座標)を用いるため、x座標を-4ずらすことでネクスト等の表との整合性をとり、
//ホールドに入っている値によって、入れるテトリミノを変える
VOID UpdateHoldNextNextNextBoard(VOID)
{
	if (g_next.m_Kind[0] != BLOCK_KIND::NON)
	{
		//if (((column == g_tetmino[g_next].yx[0][0]) && (row == g_tetmino[g_next].yx[0][1] - 4)) ||
		//	((column == g_tetmino[g_next].yx[1][0]) && (row == g_tetmino[g_next].yx[1][1] - 4)) ||
		//	((column == g_tetmino[g_next].yx[2][0]) && (row == g_tetmino[g_next].yx[2][1] - 4)) ||
		//	((column == g_tetmino[g_next].yx[3][0]) && (row == g_tetmino[g_next].yx[3][1] - 4)))
		//{
		//	//g_nextBoard[column][row] = g_next;
		//	nextBoard.tetlisBoard[column][row] = g_next;
		//	SetTetminoPattern(&g_tetminoPattern1);
		//	nextBoard.tetlisPattern[column][row] = g_tetminoPattern1;
		//}

	}

	if (g_nextNext.m_Kind[0] != BLOCK_KIND::NON)
	{
		//if (((column == g_tetmino[g_nextNext].yx[0][0]) && (row == g_tetmino[g_nextNext].yx[0][1] - 4)) ||
		//	((column == g_tetmino[g_nextNext].yx[1][0]) && (row == g_tetmino[g_nextNext].yx[1][1] - 4)) ||
		//	((column == g_tetmino[g_nextNext].yx[2][0]) && (row == g_tetmino[g_nextNext].yx[2][1] - 4)) ||
		//	((column == g_tetmino[g_nextNext].yx[3][0]) && (row == g_tetmino[g_nextNext].yx[3][1] - 4)))
		//{
		//	//g_nextNextBoard[column][row] = g_nextNext;
		//	nextNextBoard.tetlisBoard[column][row] = g_nextNext;
		//	SetTetminoPattern(&g_tetminoPattern1);
		//	nextNextBoard.tetlisPattern[column][row] = g_tetminoPattern1;
		//}
	}

	if (g_nextNextnext.m_Kind[0] != BLOCK_KIND::NON)
	{
		//if (((column == g_tetmino[g_nextNextnext].yx[0][0]) && (row == g_tetmino[g_nextNextnext].yx[0][1] - 4)) ||
		//	((column == g_tetmino[g_nextNextnext].yx[1][0]) && (row == g_tetmino[g_nextNextnext].yx[1][1] - 4)) ||
		//	((column == g_tetmino[g_nextNextnext].yx[2][0]) && (row == g_tetmino[g_nextNextnext].yx[2][1] - 4)) ||
		//	((column == g_tetmino[g_nextNextnext].yx[3][0]) && (row == g_tetmino[g_nextNextnext].yx[3][1] - 4)))
		//{
		//	//g_nextNextNextBoard[column][row] = g_nextNextnext;
		//	nextNextNextBoard.tetlisBoard[column][row] = g_nextNextnext;
		//	SetTetminoPattern(&g_tetminoPattern1);
		//	nextNextNextBoard.tetlisPattern[column][row] = g_tetminoPattern1;
		//}
	}

	for (INT column = 0; column < 4; column++)
	{
		for (INT row = 0; row < 4; row++)
		{
			nextBoard.tetlisBoard[column][row] = -1;
			nextNextBoard.tetlisBoard[column][row] = -1;
			nextNextNextBoard.tetlisBoard[column][row] = -1;

			/*g_nextNextNextBoard[column][row] = -1;
			g_nextNextBoard[column][row] = -1;
			g_holdBoard[column][row] = -1;
			g_nextBoard[column][row] = -1;*/

			//if (0 <= g_next && g_next <= 6)
			//{
			//	if (((column == g_tetmino[g_next].yx[0][0]) && (row == g_tetmino[g_next].yx[0][1] - 4)) ||
			//		((column == g_tetmino[g_next].yx[1][0]) && (row == g_tetmino[g_next].yx[1][1] - 4)) ||
			//		((column == g_tetmino[g_next].yx[2][0]) && (row == g_tetmino[g_next].yx[2][1] - 4)) ||
			//		((column == g_tetmino[g_next].yx[3][0]) && (row == g_tetmino[g_next].yx[3][1] - 4)))
			//	{
			//		//g_nextBoard[column][row] = g_next;
			//		nextBoard.tetlisBoard[column][row] = g_next;
			//		SetTetminoPattern(&g_tetminoPattern1);
			//		nextBoard.tetlisPattern[column][row] = g_tetminoPattern1;
			//	}
			//}

			//if (0 <= g_nextNext && g_nextNext <= 6)
			//{
			//	if (((column == g_tetmino[g_nextNext].yx[0][0]) && (row == g_tetmino[g_nextNext].yx[0][1] - 4)) ||
			//		((column == g_tetmino[g_nextNext].yx[1][0]) && (row == g_tetmino[g_nextNext].yx[1][1] - 4)) ||
			//		((column == g_tetmino[g_nextNext].yx[2][0]) && (row == g_tetmino[g_nextNext].yx[2][1] - 4)) ||
			//		((column == g_tetmino[g_nextNext].yx[3][0]) && (row == g_tetmino[g_nextNext].yx[3][1] - 4)))
			//	{
			//		//g_nextNextBoard[column][row] = g_nextNext;
			//		nextNextBoard.tetlisBoard[column][row] = g_nextNext;
			//		SetTetminoPattern(&g_tetminoPattern1);
			//		nextNextBoard.tetlisPattern[column][row] = g_tetminoPattern1;
			//	}
			//}

			//if (0 <= g_nextNextnext && g_nextNextnext <= 6)
			//{
			//	if (((column == g_tetmino[g_nextNextnext].yx[0][0]) && (row == g_tetmino[g_nextNextnext].yx[0][1] - 4)) ||
			//		((column == g_tetmino[g_nextNextnext].yx[1][0]) && (row == g_tetmino[g_nextNextnext].yx[1][1] - 4)) ||
			//		((column == g_tetmino[g_nextNextnext].yx[2][0]) && (row == g_tetmino[g_nextNextnext].yx[2][1] - 4)) ||
			//		((column == g_tetmino[g_nextNextnext].yx[3][0]) && (row == g_tetmino[g_nextNextnext].yx[3][1] - 4)))
			//	{
			//		//g_nextNextNextBoard[column][row] = g_nextNextnext;
			//		nextNextNextBoard.tetlisBoard[column][row] = g_nextNextnext;
			//		SetTetminoPattern(&g_tetminoPattern1);
			//		nextNextNextBoard.tetlisPattern[column][row] = g_tetminoPattern1;
			//	}
			//}
		}
	}

	return;
}


//可動テトリミノ以外をg_tetlisBoardBufに同期させている 
VOID SynchroTetlisBoardBufToTetlisBoard(bool is_convert)
{
	for (INT column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (INT row = 0; row < TETLIS_WIDTH; row++)
		{
			/*if ((0 <= g_tetlisBoard[column][row]) && (g_tetlisBoard[column][row] <= 6))
			{
			g_tetlisBoardBuf[column][row] = -1;
			}
			else
			{
			g_tetlisBoardBuf[column][row] = g_tetlisBoard[column][row];
			}*/
			int kind = tetBoard.tetlisBoard[column][row];

			if (is_convert == true)
			{
				kind = (tetBoard.tetlisBoard[column][row] & 0xf);
			}

			if ((0 <= tetBoard.tetlisBoard[column][row]) && (tetBoard.tetlisBoard[column][row] <= 6))
			{
				tetBoardBuf.tetlisBoard[column][row] = -1;
			}
			else
			{
				if (is_convert == true &&
					tetBoard.tetlisBoard[column][row] > 9)
				{
					tetBoardBuf.tetlisBoard[column][row] = (tetBoard.tetlisBoard[column][row] & 0xfff0);
					tetBoardBuf.tetlisPattern[column][row] = (tetBoard.tetlisPattern[column][row] & 0xfff0);
				}
				else {
					tetBoardBuf.tetlisBoard[column][row] = tetBoard.tetlisBoard[column][row];
					tetBoardBuf.tetlisPattern[column][row] = tetBoard.tetlisPattern[column][row];
				}
			}
		}
	}


	return;
}


//テトリス配列に可動テトリミノを同期させる関数
//g_tetlisBoardにg_movMinoNumOfArBufを同期させている
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino)
{
	for (INT block = 0; block < 4; block++)
	{
		//g_tetlisBoard[g_movMinoNumOfArBuf.YX[block][0]][g_movMinoNumOfArBuf.YX[block][1]] = currentTetmino;
		tetBoard.tetlisBoard[g_movMinoNumOfArBuf.YX[block][0]][g_movMinoNumOfArBuf.YX[block][1]] = (0xf & g_movMinoNumOfArBuf.m_Kind[block]);

	}

	/*for (INT block = 0; block < 4; block++)
	{
	for (INT YX = 0; YX < 2; YX++)
	{
	tetBoard.tetlisPattern[block][YX] = g_tetmino[currentTetmino].pattern_yx[block][YX];

	}
	}*/

	return;
}


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
	BOOL *canSetStartTime,
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
)
{
	g_showGameoverStr = false;
	*isGameover = false;
	*canCreate = true;
	*canInputRA = true;
	*canInputLA = true;
	*canInputDA = true;
	*canInputR = true;
	*canInputSpace = true;
	*canHold = true;
	*wasHold = false;

	*canSetStartTime = true;

	*rACount = 0;
	*lACount = 0;
	*dACount = 0;
	*stopCount = 0;
	*downCount = 0;

	*FeverTimer = 0;

	*FallSpeedLevel = 1;
	*FlamePerDown = 55;

	*g_CurrentTetminoPattern = 0;
	*g_tetminoPatternNext = 0;
	*g_tetminoPatternNextNext = 0;
	*g_tetminoPatternNextNextNext = 0;

	*g_elapsedTime = 0;
	*g_startTime = 0;

	g_hold.m_Kind[0] = BLOCK_KIND::NON;

	InitNextBlock(&g_next);
	InitNextBlock(&g_nextNext);
	InitNextBlock(&g_nextNextnext);

	*currentTetmino = rand() % 7;
	*minoIRoatationCount = 0;


	InitTetlisBoardBuf();
	UpdateHoldNextNextNextBoard();
	//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	return;
}


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
)
{
	if (*canCreate == false)
	{
		return;
	}

	UpdateHoldNextNextNextBoard();
	*canInputLA = true;
	*canInputDA = true;
	*canInputRA = true;
	*canInputR = true;
	*canInputSpace = true;
	*wasHold = false;
	*stopCount = 0;
	*downCount = 0;
	*minoIRoatationCount = 0;
	*canCreate = false;

	return;
}


//キー入力をカウントをとり可能にする関数
VOID CountToMakeFlagTrue(BOOL *canInputLA, INT *lACount)
{
	if (*canInputLA == true)
	{
		return;
	}
	*lACount += 1;
	if (*lACount != SHIFT_FRAME_COUNTER)
	{
		return;
	}

	*canInputLA = true;
	*lACount = 0;

	return;
}


//ホールド、ネクスト、ネクストネクストを初期化する関数
VOID InitNextAndFever()
{
	InitNextBlock(&g_next);
	InitNextBlock(&g_nextNext);
	InitNextBlock(&g_nextNextnext);

	g_feverBlock = 0; //フィーバーブロックの初期化


	return;
}


//テトリミノをホールドすることに関する関数
VOID HoldTetlimino(BOOL *canHold, INT *currentTetmino, BOOL *canCreate, BOOL *wasHold)
{
	if (*canHold == false)
	{
		return;
	}

	if (g_hold.m_Kind[0] == BLOCK_KIND::NON)
	{
		for (int i = 0; i < 4; i++)
		{
			g_hold.YX[i][0] = g_tetmino[*currentTetmino].yx[i][0];
			g_hold.YX[i][1] = g_tetmino[*currentTetmino].yx[i][1] - 4;
			g_hold.m_Kind[i] = g_movMinoNumOfArBuf.m_Kind[i];
		}

		*currentTetmino = rand() % 7;

		*canHold = false;
	}
	else
	{
		*currentTetmino = g_hold.m_Kind[0] & 0xf;

		for (int i = 0; i < 4; i++)
		{
			g_hold.YX[i][0] = g_tetmino[g_tetmino[g_tetminoNum].number].yx[i][0];
			g_hold.YX[i][1] = g_tetmino[g_tetmino[g_tetminoNum].number].yx[i][1] - 4;
			g_hold.m_Kind[i] = g_movMinoNumOfArBuf.m_Kind[i];
		}
		g_movMinoNumOfArBuf = g_hold;

		//g_hold = g_tetmino[g_tetminoNum].number;


		*canHold = false;
	}

	*wasHold = true;
	*canCreate = true;

	UpdateHoldNextNextNextBoard();

	return;
}


//テトリミノのX軸方向の移動に関する関数
VOID ShiftTetliminoX(INT shiftX, BOOL *canInputRA)
{
	if ((tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[0][0]][g_movMinoNumOfArBuf.YX[0][1] + shiftX] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[1][0]][g_movMinoNumOfArBuf.YX[1][1] + shiftX] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[2][0]][g_movMinoNumOfArBuf.YX[2][1] + shiftX] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[3][0]][g_movMinoNumOfArBuf.YX[3][1] + shiftX] == -1))
	{
		for (INT block = 0; block < 4; block++)
		{
			g_movMinoNumOfArBuf.YX[block][1] += shiftX;
		}

		*canInputRA = false;
	}

	return;
}


//右回転

//テトリミノの回転に関する関数
VOID RotateTetliminoRight(INT *minoIRoatationCount, INT currentTetmino)
{
	INT swap[4];
	INT backupY2X2[2] = { g_movMinoNumOfArBuf.YX[2][0], g_movMinoNumOfArBuf.YX[2][1] };
	*minoIRoatationCount = (*minoIRoatationCount > 3) ? 0 : *minoIRoatationCount;
	if (currentTetmino == 0)
	{
		for (INT block = 0; block < 4; block++)
		{
			switch (*minoIRoatationCount)
			{
			case 0:
				g_movMinoNumOfArBuf.YX[block][0] += 1;
				break;
			case 1:
				g_movMinoNumOfArBuf.YX[block][1] -= 1;
				break;
			case 2:
				g_movMinoNumOfArBuf.YX[block][0] -= 1;
				break;
			case 3:
				g_movMinoNumOfArBuf.YX[block][1] += 1;
				break;
			}
			backupY2X2[0] = g_movMinoNumOfArBuf.YX[2][0];
			backupY2X2[1] = g_movMinoNumOfArBuf.YX[2][1];
		}
	}
	if (currentTetmino != 6)
	{
		if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1*/

			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1)
		{
			for (INT block = 0; block < 4; block++)
			{
				swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
				g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
				g_movMinoNumOfArBuf.YX[block][0] = swap[block];
			}
			*minoIRoatationCount += 1;
		}
		else
		{
			if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1*/

				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1)
			{
				for (INT block = 0; block < 4; block++)
				{
					swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
					g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] + 1;
					g_movMinoNumOfArBuf.YX[block][0] = swap[block];
				}
				*minoIRoatationCount += 1;
			}
			else
			{
				if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1*/

					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1)
				{
					for (INT block = 0; block < 4; block++)
					{
						swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
						g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 1;
						g_movMinoNumOfArBuf.YX[block][0] = swap[block];
					}
					*minoIRoatationCount += 1;
				}
				else
				{
					if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1*/

						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1)
					{
						for (INT block = 0; block < 4; block++)
						{
							swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
							g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
							g_movMinoNumOfArBuf.YX[block][0] = swap[block];
						}
						*minoIRoatationCount += 1;
					}
					else
					{
						if (currentTetmino == 0)
						{
							if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1*/

								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1)
							{
								for (INT block = 0; block < 4; block++)
								{
									swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] - 1;
									g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + 2;
									g_movMinoNumOfArBuf.YX[block][0] = swap[block];
								}
								*minoIRoatationCount += 1;
							}
							else
							{
								if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1*/

									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1)
								{
									for (INT block = 0; block < 4; block++)
									{
										swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
										g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 2;
										g_movMinoNumOfArBuf.YX[block][0] = swap[block];
									}
									*minoIRoatationCount += 1;
								}
								else
								{
									for (INT block = 0; block < 4; block++)
									{
										switch (*minoIRoatationCount)
										{
										case 0:
											g_movMinoNumOfArBuf.YX[block][0] -= 1;
											break;
										case 1:
											g_movMinoNumOfArBuf.YX[block][1] += 1;
											break;
										case 2:
											g_movMinoNumOfArBuf.YX[block][0] += 1;
											break;
										case 3:
											g_movMinoNumOfArBuf.YX[block][1] -= 1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return;
}


//左回転

//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
//テトリミノの回転に関する関数
VOID RotateTetliminoLeft(INT *minoIRoatationCount, INT currentTetmino)
{
	INT swap[4];
	INT backupY2X2[2] = { g_movMinoNumOfArBuf.YX[2][0], g_movMinoNumOfArBuf.YX[2][1] };
	*minoIRoatationCount = (*minoIRoatationCount > 3) ? 0 : *minoIRoatationCount;
	if (currentTetmino == 0)
	{
		for (INT block = 0; block < 4; block++)
		{
			switch (*minoIRoatationCount)
			{
			case 0:
				g_movMinoNumOfArBuf.YX[block][0] += 1;
				break;
			case 1:
				g_movMinoNumOfArBuf.YX[block][1] -= 1;
				break;
			case 2:
				g_movMinoNumOfArBuf.YX[block][0] -= 1;
				break;
			case 3:
				g_movMinoNumOfArBuf.YX[block][1] += 1;
				break;
			}
			backupY2X2[0] = g_movMinoNumOfArBuf.YX[2][0];
			backupY2X2[1] = g_movMinoNumOfArBuf.YX[2][1];
		}
	}
	if (currentTetmino != 6)
	{
		if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1*/

			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1
			)
		{
			for (INT block = 0; block < 4; block++)
			{
				swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
				g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
				g_movMinoNumOfArBuf.YX[block][0] = swap[block];
			}
			*minoIRoatationCount += 1;
		}
		else
		{
			if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1*/

				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1
				)
			{
				for (INT block = 0; block < 4; block++)
				{
					swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
					g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] + 1;
					g_movMinoNumOfArBuf.YX[block][0] = swap[block];
				}
				*minoIRoatationCount += 1;
			}
			else
			{
				if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1*/

					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1
					)
				{
					for (INT block = 0; block < 4; block++)
					{
						swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
						g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 1;
						g_movMinoNumOfArBuf.YX[block][0] = swap[block];
					}
					*minoIRoatationCount += 1;
				}
				else
				{
					if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1*/

						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1
						)
					{
						for (INT block = 0; block < 4; block++)
						{
							swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
							g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
							g_movMinoNumOfArBuf.YX[block][0] = swap[block];
						}
						*minoIRoatationCount += 1;
					}
					else
					{
						if (currentTetmino == 0)
						{
							if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1*/

								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1
								)
							{
								for (INT block = 0; block < 4; block++)
								{
									swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] - 1;
									g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + 2;
									g_movMinoNumOfArBuf.YX[block][0] = swap[block];
								}
								*minoIRoatationCount += 1;
							}
							else
							{
								if (/*g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1*/

									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									tetBoardBuf.tetlisBoard[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1
									)
								{
									for (INT block = 0; block < 4; block++)
									{
										swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
										g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 2;
										g_movMinoNumOfArBuf.YX[block][0] = swap[block];
									}
									*minoIRoatationCount += 1;
								}
								else
								{
									for (INT block = 0; block < 4; block++)
									{
										switch (*minoIRoatationCount)
										{
										case 0:
											g_movMinoNumOfArBuf.YX[block][0] -= 1;
											break;
										case 1:
											g_movMinoNumOfArBuf.YX[block][1] += 1;
											break;
										case 2:
											g_movMinoNumOfArBuf.YX[block][0] += 1;
											break;
										case 3:
											g_movMinoNumOfArBuf.YX[block][1] -= 1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return;
}


//テトリミノのY軸方向の移動に関する関数
VOID DownTetlimino(BOOL *canInputDA)
{
	if (/*(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] == -1)*/

		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] == -1)
		)
	{
		for (int block = 0; block < 4; block++)
		{
			g_movMinoNumOfArBuf.YX[block][0] += 1;
		}
		*canInputDA = false;
	}

	return;
}

//VOID HardDropTetlimino(VOID)
//{
//	for (INT column = 1; column < TETLIS_HEIGHT; column++)
//	{
//		if ((g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0] + column][g_movMinoNumOfArBuf.YX[0][1]] != -1) ||
//			(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0] + column][g_movMinoNumOfArBuf.YX[1][1]] != -1) ||
//			(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0] + column][g_movMinoNumOfArBuf.YX[2][1]] != -1) ||
//			(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0] + column][g_movMinoNumOfArBuf.YX[3][1]] != -1))
//		{
//			for (int block = 0; block < 4; block++)
//			{
//				g_movMinoNumOfArBuf.YX[block][0] += column - 1;
//			}
//			break;
//		}
//	}
//
//	return;
//}


//テトリミノの自動落下に関する関数
VOID CountToDawnTetlimino(INT *downCount, INT *FallSpeedLevel, INT *FlamePerDown)
{
	if (
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] == -1) &&
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] == -1)
		)
	{
		*downCount += 1;

		if (*downCount == *FlamePerDown)
		{
			for (int block = 0; block < 4; block++)
			{
				g_movMinoNumOfArBuf.YX[block][0] += 1;
			}

			*downCount = 0;
		}

	}

	return;
}


//テトリミノ停止に関する関数
bool CountToStopTetlimino(INT *stopCount, INT *currentTetmino, BOOL *canCreate, BOOL *canHold, BOOL *wasHold)
{
	bool is_stop = false;

	if (
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] != -1) ||
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] != -1) ||
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] != -1) ||
		(tetBoardBuf.tetlisBoard[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] != -1)
		)
	{
		*stopCount += 1;
		if (*stopCount == FLAME_PER_STOP)
		{
			tetBoard.tetlisBoard[g_movMinoNumOfArBuf.YX[0][0]][g_movMinoNumOfArBuf.YX[0][1]] = g_movMinoNumOfArBuf.m_Kind[0];
			tetBoard.tetlisBoard[g_movMinoNumOfArBuf.YX[1][0]][g_movMinoNumOfArBuf.YX[1][1]] = g_movMinoNumOfArBuf.m_Kind[1];
			tetBoard.tetlisBoard[g_movMinoNumOfArBuf.YX[2][0]][g_movMinoNumOfArBuf.YX[2][1]] = g_movMinoNumOfArBuf.m_Kind[2];
			tetBoard.tetlisBoard[g_movMinoNumOfArBuf.YX[3][0]][g_movMinoNumOfArBuf.YX[3][1]] = g_movMinoNumOfArBuf.m_Kind[3];

			SynchroTetlisBoardBufToTetlisBoard();

			*canCreate = true;
			*canHold = true;
			*wasHold = false;
			*stopCount = 0;
			*currentTetmino = (g_next.m_Kind[0] & 0xf);

			is_stop = true;
		}
	}

	return is_stop;
}

//g_tetlisBoardBuf中身を確認し一列が空欄(-1)以外の場合カウントをとり空欄にする
//そろったテトリスのラインを消しカウントをとる関数
int DeleteAndCountFilledLine()
{
	int count = 288;
	int vcount = 0;
	bool HabKillZone = true;
	int line_count = 0;
	int KillZonebuf[TETLIS_HEIGHT][TETLIS_WIDTH] = { false };

	for (int g = 0; g < 5; g++)
	{
		for (INT column = 1; column < TETLIS_HEIGHT - 1; column++)
		{
			//前の猫の位置
			int CurrentCat;
			CurrentCat = -1;

			//ネズミと猫の判定
			for (int j = 0; j < TETLIS_WIDTH; ++j)
			{
				if (tetBoardBuf.tetlisBoard[column][j] != -1 &&
				 (((tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(CAT_01)) != 0) ||
				  ((tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(CAT_02)) != 0) ||
				  ((tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(CAT_03)) != 0)))/* 猫であるとして */
				{
					if (CurrentCat != -1)
					{
						for (int k = CurrentCat + 1; k < j; ++k)
						{
							tetBoardBuf.tetlisBoard[column][k] = BLOCK_KIND_SHIFT(KILL_ZONE);
						}
					}

					CurrentCat = j;
				}
				//ねずみならCurrentCatを-1にする
				else if ((tetBoardBuf.tetlisBoard[column][j] == -1) || tetBoardBuf.tetlisBoard[column][j] != -1 && (tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(MOUSE)) == 0)
				{
					CurrentCat = -1;
				}
			}

			/* 上を見ている */
			for (int j = 0; j < TETLIS_WIDTH; ++j)
			{
				if (tetBoardBuf.tetlisBoard[column][j] == BLOCK_KIND_SHIFT(KILL_ZONE))
				{
					for (int c = column; c > 0; c--)
					{
						tetBoardBuf.tetlisBoard[c][j] = tetBoardBuf.tetlisBoard[c - 1][j];
					}
				}
			}

			////もう少し上手い確認の仕方が出来るように
			//for (int l = 0; l < TETLIS_HEIGHT; l++)
			//{
			//	for (int n = 0; n < TETLIS_WIDTH; ++n)
			//	{
			//		if (tetBoardBuf.tetlisBoard[l][n] != BLOCK_KIND_SHIFT(KILL_ZONE))
			//		{
			//			KillZonebuf[l][n] = true;
			//		}
			//		else
			//		{
			//			break;
			//		}
			//	}
			//}

			//vcount = 0;

			//for (int p = 0; p < TETLIS_HEIGHT; p++)
			//{
			//	for (int q = 0; q < TETLIS_WIDTH; ++q)
			//	{
			//		if (KillZonebuf[p][q] == true)
			//		{
			//			vcount++;
			//		}
			//	}
			//}

			//if (vcount == count)
			//{
			//	HabKillZone = false;
			//}

		}
	}

	for (INT column = 1; column < TETLIS_HEIGHT - 1; column++)
	{
		if (tetBoardBuf.tetlisBoard[column][1] != -1 &&
			tetBoardBuf.tetlisBoard[column][2] != -1 &&
			tetBoardBuf.tetlisBoard[column][3] != -1 &&
			tetBoardBuf.tetlisBoard[column][4] != -1 &&
			tetBoardBuf.tetlisBoard[column][5] != -1 &&
			tetBoardBuf.tetlisBoard[column][6] != -1 &&
			tetBoardBuf.tetlisBoard[column][7] != -1 &&
			tetBoardBuf.tetlisBoard[column][8] != -1 &&
			tetBoardBuf.tetlisBoard[column][9] != -1 &&
			tetBoardBuf.tetlisBoard[column][10] != -1
			)
		{
			for (INT row = 1; row < TETLIS_WIDTH - 1; row++)
			{
				tetBoard.tetlisBoard[column][row] = -2;
				tetBoardBuf.tetlisBoard[column][row] = -2;
			}

			line_count++;
		}
	}

	return line_count;
}


//消されたテトリスのライン部分にずらす関数
//消されたテトリスのライン部分にずらす関数
//消されたテトリスのライン部分にずらす関数
void ShiftTetlisLine(void)
{
	int count = 0;

	INT column = TETLIS_HEIGHT - 2;
	bool is_dec = false;

	while (column >= 3)
	{
		is_dec = false;
		if (tetBoardBuf.tetlisBoard[column][1] == -2 &&
			tetBoardBuf.tetlisBoard[column][2] == -2 &&
			tetBoardBuf.tetlisBoard[column][3] == -2 &&
			tetBoardBuf.tetlisBoard[column][4] == -2 &&
			tetBoardBuf.tetlisBoard[column][5] == -2 &&
			tetBoardBuf.tetlisBoard[column][6] == -2 &&
			tetBoardBuf.tetlisBoard[column][7] == -2 &&
			tetBoardBuf.tetlisBoard[column][8] == -2 &&
			tetBoardBuf.tetlisBoard[column][9] == -2 &&
			tetBoardBuf.tetlisBoard[column][10] == -2)
		{
			for (int j = column; j >= 3; j--)
			{
				for (int coordinateX = 1; coordinateX < TETLIS_WIDTH - 1; coordinateX++)
				{
					tetBoardBuf.tetlisBoard[j][coordinateX] = tetBoardBuf.tetlisBoard[j - 1][coordinateX];

					tetBoard.tetlisBoard[j][coordinateX] = tetBoard.tetlisBoard[j - 1][coordinateX];
				}
			}

			is_dec = true;
		}

		if (is_dec == false)
		{
			column--;
		}
	}
}

//テトリスのスコアに関する関数
int GetScoreByLineCount(INT lineCount)
{
	int score = 0;

	switch (lineCount)
	{
	case 1:
		score = 40;
		break;
	case 2:
		score = 100;
		break;
	case 3:
		score = 300;
		break;
	case 4:
		score = 1200;
		break;
	}

	return score;
}

VOID SetFeverStartTime(DWORD *g_startTime, BOOL *canSetStartTime)
{
	//フィーバーモードに入ったら一回だけ開始時間をセットする
	//何回もセットされないようにしている

	g_Isfever = true;

	if (*canSetStartTime)
	{
		*g_startTime = timeGetTime();

		*canSetStartTime = false;
	}

}

//フィーバーモードの時間関数
VOID FeverTime(INT *g_lineTotalCount, DWORD *g_elapsedTime, DWORD *startTime, BOOL *canSetStartTime, INT *FeverTimer, INT *FallSpeedLevel, INT *FlamePerDown)
{
	//22秒後g_lineTotalCountを0にする
	timeBeginPeriod(1);
	//制限時間22秒
	DWORD timeLimit = FEVER_TIME;

	*g_elapsedTime = (timeGetTime() - *startTime) / 1000;

	*FeverTimer = timeLimit - *g_elapsedTime;

	sprintf(g_feverTimerArray, "%d", *FeverTimer);

	if (timeLimit - *g_elapsedTime <= 0)
	{
		*g_lineTotalCount = 0;
		*g_elapsedTime = 0;

		if (*FallSpeedLevel < 19)//18が最高レベル
		{
			*FallSpeedLevel += 1;//落下速度レベルを1上げる

			if (*FallSpeedLevel == 2 || *FallSpeedLevel == 3)
			{
				*FlamePerDown = 50;
			}

			else if (*FallSpeedLevel == 4 || *FallSpeedLevel == 5)
			{
				*FlamePerDown = 40;
			}

			else if (*FallSpeedLevel == 6 || *FallSpeedLevel == 7 || *FallSpeedLevel == 8)
			{
				*FlamePerDown = 30;
			}

			else if (*FallSpeedLevel == 9 || *FallSpeedLevel == 10 || *FallSpeedLevel == 11)
			{
				*FlamePerDown = 20;
			}

			else if (*FallSpeedLevel == 12 || *FallSpeedLevel == 13 || *FallSpeedLevel == 14)
			{
				*FlamePerDown = 10;
			}

			else if (*FallSpeedLevel == 15 || *FallSpeedLevel == 16 || *FallSpeedLevel == 17)
			{
				*FlamePerDown = 5;
			}

			else if (*FallSpeedLevel == 18)
			{
				*FlamePerDown = 1;
			}

		}

		*canSetStartTime = true;
	}

	timeEndPeriod(1);

}

//ブロックの種類設定
VOID SetTetminoPattern(INT *TetminoPattern)
{
	int random = rand() % 100;
	int random2 = rand() % 3;

	if (random > 30)
	{
		*TetminoPattern = tetminoMouse;//ネズミブロック
	}

	else
	{
		if (random2 == 0)
		{
			*TetminoPattern = tetminoCat1;//ネコブロック1
		}
		else if (random2 == 1)
		{
			*TetminoPattern = tetminoCat2;//ネコブロック2
		}

		else
		{
			*TetminoPattern = tetminoCat3;//ネコブロック3
		}
	}
}

//ブロックの種類定義
VOID defineTetminoPattern(INT *g_tetminoPattern1, INT *g_tetminoPattern2, INT *g_tetminoPattern3, INT *g_tetminoPattern4, INT currentTetmino)
{
	for (INT block = 0; block < 4; block++)
	{
		//g_tetlisBoard[g_movMinoNumOfArBuf.YX[block][0]][g_movMinoNumOfArBuf.YX[block][1]] = currentTetmino;
		tetBoard.tetlisPattern[g_movMinoNumOfArBuf.tetminoPattern[block][0]][g_movMinoNumOfArBuf.tetminoPattern[block][1]] = *g_tetminoPattern1;
		//SetTetminoPattern(g_tetminoPattern1);
	}
	for (INT block = 0; block < 4; block++)
	{
		//g_movMinoNumOfArBuf.tetminoPattern[block] = g_tetmino[currentTetmino].pattern_yx[block];

		for (INT YX = 0; YX < 2; YX++)
		{
			g_tetmino[currentTetmino].pattern_yx[block][YX] = *g_tetminoPattern1;
			//SetTetminoPattern(g_tetminoPattern1);
		}

		/*g_tetmino[currentTetmino].pattern_yx[0] = *g_tetminoPattern1;
		g_tetmino[currentTetmino].pattern_yx[1] = *g_tetminoPattern2;
		g_tetmino[currentTetmino].pattern_yx[2] = *g_tetminoPattern3;
		g_tetmino[currentTetmino].pattern_yx[3] = *g_tetminoPattern4;*/
		return;
	}
}



//フィーバーゲージの中身を更新する関数
VOID UpdateFeverGauge(INT *lineCount, INT g_feverBlock)
{


}

//プレイ時の見える範囲内で一番上の部分に非可動テトリミノがある場合isGameoverをtrueにする
//ゲームオーバーか、否かを調べるする関数
VOID CheckGameover(BOOL *isGameover)
{
	for (INT coordinateX = 0; coordinateX < TETLIS_WIDTH; coordinateX++)
	{
		if (tetBoardBuf.tetlisBoard[4][coordinateX] == BLOCK_KIND_SHIFT(CAT_01) ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == BLOCK_KIND_SHIFT(CAT_02) ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == BLOCK_KIND_SHIFT(CAT_03) ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == BLOCK_KIND_SHIFT(MOUSE) ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 10 ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 11 ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 12 ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 13 ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 14 ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 15 ||
			tetBoardBuf.tetlisBoard[4][coordinateX] == 16)
		{
			*isGameover = true;
		}
	}

	SynchroTetlisBoardBufToTetlisBoard();

	return;
}

// NextBlockの初期化を行う
// 初期化時には最初のMovMinoNumoOfArBufの初期化も行ってる
void InitNextBlock(MovMinoNumoOfArBuf *next_block, int block)
{
	// blockの指定がなければ自分で設定
	if (block == -1)
	{
		block = rand() % 7;
	}

	for (int i = 0; i < 4; i++)
	{
		next_block->YX[i][0] = g_tetmino[block].yx[i][0];
		next_block->YX[i][1] = g_tetmino[block].yx[i][1] - 4;
		next_block->m_Kind[i] = block + BLOCK_KIND_SHIFT(GetBlockKind(g_Isfever));
	}
}

// ブロックの取得関数
// ここでブロックをランダムで取得するようにする
// 今の計算はSetTetminoPatternの内容を使用してます
BLOCK_KIND GetBlockKind(bool is_fever)
{
	int random = rand() % 100;
	int random2 = rand() % 3;
	int random_num = 30;

	if (is_fever)
	{
		random_num = 70;
	}

	BLOCK_KIND ret = BLOCK_KIND::NON;

	if (random <= random_num)
	{
		ret = BLOCK_KIND::MOUSE;
	}
	else {
		if (random2 == 0)
		{
			ret = BLOCK_KIND::CAT_01;
		}
		else if (random2 == 1) {
			ret = BLOCK_KIND::CAT_02;
		}
		else {
			ret = BLOCK_KIND::CAT_03;
		}
	}

	return ret;
}
