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

//���������̃e�g���~�m��ނ����߂�
static INT
rACount = 0,
lACount = 0,
dACount = 0,
stopCount = 0,
downCount = 0,
minoIRoatationCount = 0,

prevEKeyState,              //�E��]E�L�[���͏�Ԃ�ۑ�

prevTEN9KeyState,           //�E��]�e���L�[9���͏�Ԃ�ۑ�

prevQKeyState,              //����]Q�L�[���͏�Ԃ�ۑ�

prevTEN7KeyState,           //����]�e���L�[7���͏�Ԃ�ۑ�

prevRKeyState,              //�z�[���hR�L�[���͏�Ԃ�ۑ�

prevTENplusKeyState,        //�z�[���h�e���L�[ + ���͏�Ԃ�ۑ�

FeverTimer = 0,

currentTetmino = rand() % 7;

int g_MainStep = 0;
int g_GameStep = 0;


void MainInit()
{
	//�j���[�Q�[��(��ԍŏ��̃t���[��)���ɂ�g_feverBlock�Ag_next��g_nextNext�Ag_nextNextnext�͏���������Ă��Ȃ��̂ŏ��������AisNewGame��false�ɂ���
	InitNextAndFever();

	////�u���b�N�̎�ސݒ�
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
	//�L�[�f�o�C�X�ɓ����Ă������ǂݎ�鏀��
	HRESULT hr = pKeyDevice->Acquire();

	if ((hr != DI_OK) && (hr != S_FALSE))
	{
		return;
	}

	//�L�[���͏��̃o�b�t�@�[
	BYTE diks[256];

	//���͂��ꂽ����ǂݎ��
	pKeyDevice->GetDeviceState(sizeof(diks), &diks);

	INT lineCount = 0;


	//INT lineTotalCount = 0;

	INT LEFT[2] = { 0,diks[DIK_A] & 0x80 },             //���ړ� A�L�[
		TEN_LEFT[2] = { 0,diks[DIK_NUMPAD4] & 0x80 },      //���ړ� �e���L�[4

		DOWN[2] = { 0,diks[DIK_S] & 0x80 },             //���ړ� S�L�[
		TEN_DOWN[2] = { 0,diks[DIK_NUMPAD2] & 0x80 },   //���ړ� �e���L�[2

		RIGHT[2] = { 0,diks[DIK_D] & 0x80 },            //�E�ړ� D�L�[
		TEN_RIGHT[2] = { 0,diks[DIK_NUMPAD6] & 0x80 };   //�E�ړ� �e���L�[6


														 //�e�g���X�z��Ƀe�g���X�z��o�b�t�@�[�̗v�f�S�Ă��R�s�[���Ă���
														 //memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

	//���Z�b�g�{�^���A������Ԃɖ߂�
	if (diks[DIK_BACK] & 0x80)
	{
		//�t���O�A�J�E���g�A�z���������Ԃɖ߂�UpdateHoldNextNextNextBoard��p����
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

	//g_lineTotalCount��10�ȏ�̂Ƃ��t�B�[�o�[���[�h�̊J�n���Ԃ��Z�b�g
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

		//�u���b�N�̎�ޒ�`
		defineTetminoPattern(&g_tetminoPattern1, &g_tetminoPattern2, &g_tetminoPattern3, &g_tetminoPattern4, currentTetmino);

		if (canCreate == false)
		{
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		}
		SynchroTetlisBoardBufToTetlisBoard();

		//g_canCreate���m�F��true�Ȃ��g_movMinoNumOfArBuf��currentTetmino�Ɠ�����ނ̃e�g���~�m�������W�������A�L�[���͂̃t���O�A
		//I�^�̃e�g���~�m������]���������m�F����J�E���g�A�z�[���h���s��ꂽ���ۂ��̃t���O��������Ԃɖ߂��Ag_canCreate��false�ɂ���
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


	//�t���O��false�Ȃ�΃J�E���g��1���₵�A���l�Ȃ�΃t���O��true�ɕς��J�E���g��������Ԃɂ���
	CountToMakeFlagTrue(&canInputLA, &lACount);
	CountToMakeFlagTrue(&canInputRA, &rACount);
	CountToMakeFlagTrue(&canInputDA, &dACount);

	//�z�[���h

	//�O�t���[������R�L�[�A+�L�[��������Ă����ꍇ���̏�����ʂ��Ȃ��A
	//�Ƃ��邱�Ƃɂ���ĘA�������t���[�����ɂ��̏����������̂�h���ł���


	//R�L�[
	if (!(prevRKeyState))
	{
		if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//canHold��true�Ȃ��g_hold�Ɍ��݂̃e�g���~�m�̒l�������A���ł�-1(��)�ȊO�������Ă����ꍇcurrentTetmino��g_hold�̒l������A
			//���̌�g_canCreate��true�ɂ�UpdateHoldNextNextNextBoard���Ăяo��
			HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
		}
	}

	//+�L�[
	if (!(prevTENplusKeyState))
	{
		if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//canHold��true�Ȃ��g_hold�Ɍ��݂̃e�g���~�m�̒l�������A���ł�-1(��)�ȊO�������Ă����ꍇcurrentTetmino��g_hold�̒l������A
			//���̌�g_canCreate��true�ɂ�UpdateHoldNextNextNextBoard���Ăяo��
			HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
		}
	}

	//�z�[���h���s���Ă����ꍇ�V�����e�g���~�m�𐶐�����̂ŁA���̏�����ʂ��Ȃ�
	if (!(wasHold))
	{
		if (RIGHT[canInputRA] || TEN_RIGHT[canInputRA])
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//g_movMinoNumOfArBuf�Ɉ����𑫂����z��ԍ���g_tetlisBoardBuf�ŎQ�Ƃ��A�󗓂������ꍇg_movMinoNumOfArBuf�Ɉ����𑫂����l��������
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

		//�E��]

		//�O�t���[������E�L�[�A�e���L�[9��������Ă����Ȃ�΁A���̏�����ʂ��Ȃ��A
		//�Ƃ��邱�Ƃɂ���ĘA���œ�������������邱�Ƃ�h���ł���

		//E�L�[
		if (!(prevEKeyState))
		{
			if (diks[DIK_E] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
				//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
				//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
				RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
			}
		}

		//�e���L�[9
		if (!(prevTEN9KeyState))
		{
			if (diks[DIK_NUMPAD9] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
				//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
				//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
				RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
			}
		}


		//����]

		//�O�t���[������Q�L�[�A�e���L�[7��������Ă����Ȃ�΁A���̏�����ʂ��Ȃ��A
		//�Ƃ��邱�Ƃɂ���ĘA���œ�������������邱�Ƃ�h���ł���

		//Q�L�[
		if (!(prevQKeyState))
		{
			if (diks[DIK_Q] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
				//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
				//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
				RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
			}
		}

		//�e���L�[7
		if (!(prevTEN7KeyState))
		{
			if (diks[DIK_NUMPAD7] & 0x80)
			{
				//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
				//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
				//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
				RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
			}
		}

		if (DOWN[canInputDA] || TEN_DOWN[canInputDA])
		{
			//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			//g_movMinoNumOfArBuf��Y�����ɂP�������z���p����g_tetlisBoardBuf���Q�Ƃ��A�󗓂̏ꍇ�ړ����s��
			DownTetlimino(&canInputDA);
		}

		////�n�[�h�h���b�v�@�e�g���~�m�̃u���b�N����Â������m�F���A�������󗓂ł͂Ȃ��ꍇ�A��������1��Ƀ��[�v������
		//if (diks[DIK_UP] & 0x80)
		//{
		//	memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//	SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		//	SynchroTetlisBoardBufToTetlisBoard();

		//	
		//	//���[�v�J�E���^��p��g_tetlisBoardBuf���Q�Ƃ��A�󗓂ł͂Ȃ������ꍇg_movMinoNumOfArBuf��
		//	//���[�v�J�E���^-1�̏ꏊ�Ƀe�g���~�m���ړ�������
		//	HardDropTetlimino();
		//}

		//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		SynchroTetlisBoardBufToTetlisBoard();

		//�e�g���~�m�̉������m�F���A�󗓂������ꍇ�J�E���g���Ƃ�AFLAME_PER_DOWN�ɒB�����ꍇ����Ɉړ�������

		//g_movMinoNumOfArBuf+1�����z��ԍ���p����g_tetlisBoardBuf���Q�Ƃ��A�󗓂������ꍇ�J�E���g��1���₵�A
		//���l�Ȃ��g_movMinoNumOfArBuf�ɂP�𑫂��A�J�E���g��������Ԃɂ���
		CountToDawnTetlimino(&downCount, &FallSpeedLevel, &FlamePerDown);

		//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		SynchroTetlisBoardBufToTetlisBoard();

		///*�e�g���~�m�������m�F���A�������󗓂ł͂Ȃ��ꍇ�J�E���g���Ƃ�AFLAME_PER_STOP�ɒB�����ꍇ
		//���e�g���~�m�̃i���o�[��10�𑫂�(�ȒP�ɉ�������𔻕ʂ��邽��)�A�V�������e�g���~�m�𐶐�����*/
		//	
		//g_movMinoNumOfArBuf+1�������z��ԍ���p��g_tetlisBoardBuf���Q�Ƃ��A��(-1)�ȊO�������Ă����ꍇ
		//�J�E���g���P���₵�A���l�Ȃ��currentTetmino + 10��g_tetlisBoard�ɑ�����A
		//�e�g���~�m�𐶐��ł��邩�ۂ��A�z�[���h���ł��邩�ۂ��̃t���O��true�A
		//�z�[���h���s��ꂽ���̃t���O��false�ɂ��AcurrentTetmino��g_next�Ag_next��g_nextNext�A
		//g_nextNext��g_nextNextnext�������āA
		//g_nextNextnext�Ƀe�g���~�m�ԍ��͈̗̔͂�����������
		if (CountToStopTetlimino(&stopCount, &currentTetmino, &canCreate, &canHold, &wasHold) == true)
		{
			g_GameStep = LINE_ERASE;
		}

		////memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
		//SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
		//SynchroTetlisBoardBufToTetlisBoard();

		//������Ă���񂪂��邩�m�F���J�E���g���Ƃ�
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

	//�L�[���͏�Ԃ�ۑ�

	//�E��]
	prevEKeyState = diks[DIK_E] & 0x80;
	prevTEN9KeyState = diks[DIK_NUMPAD9] & 0x80;

	//����]
	prevQKeyState = diks[DIK_Q] & 0x80;
	prevTEN7KeyState = diks[DIK_NUMPAD7] & 0x80;

	//�z�[���h
	prevRKeyState = diks[DIK_R] & 0x80;
	prevTENplusKeyState = diks[DIK_NUMPADPLUS] & 0x80;

	//�t�B�[�o�[�Q�[�W�̒��g���X�V����֐�
	UpdateFeverGauge(&lineCount, g_feverBlock);

	//�v���C���̌�����͈͓��ň�ԏ�̕����ɔ���e�g���~�m������ꍇisGameover��true�ɂ���
	CheckGameover(&isGameover);
}

void LineErase()
{
	static int score = 0;
	int line_count = 0;

	//g_tetlisBoardBuf���g���m�F����񂪋�(-1)�ȊO�̏ꍇ�J�E���g���Ƃ�󗓂ɂ���
	line_count = DeleteAndCountFilledLine();
	g_lineTotalCount += line_count;
	sprintf(g_countArray, "%d", g_lineTotalCount);

	//lineCount�̒l�ɂ����scoreBuf�̑��₷�l��ς��A������ɂ�g_scoreArray�ɑ������
	score += GetScoreByLineCount(line_count);
	sprintf(g_scoreArray, "%d", score);

	//memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

	memcpy(tetBoard.tetlisBoard, tetBoardBuf.tetlisBoard, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
	SynchroTetlisBoardBufToTetlisBoard(true);

	//�����������󗓂ɂ��ĉ��ɂ��炵�Ă���

	//g_tetlisBoardBuf���Q�Ƃ��A��(-1)�ȊO�̏ꍇ���[�v�J�E���^+1�����z��ԍ���p���A�ēx�Q�Ƃ��A
	//���S�ċ󗓂̏ꍇ���[�v�J�E���^+1�̔z��ԍ��ɃR�s�[���A�R�s�[�����󗓂ɏ���������
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

// �L�ƃl�Y�~
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
		// �l�Y�~������
	case MOUSE_ERASE:
		MouseErase();
		break;
		// �l�Y�~�łł������𖄂߂�
	case MOUSE_ERASE_SHIFT:
		MouseEraseShift();
		break;
		// 
	case LINE_ERASE:
		LineErase();
		break;
	case GAME_OVER:
		//�Q�[���I�[�o�[���ɕ������\��������
		g_showGameoverStr = true;

		g_lineTotalCount = 0;
		break;
	}
}

//�e�g���X�Ȃǂ̑���Ɋւ���֐�
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


//�e�g���X�{�[�h��������
//�|1�͋󗓂�\���A��ɑS�Ă̔z��̒��g���󗓂ɂ��邱�Ƃɂ��A
//��(9)���ォ��h��Ԃ������ŕ\����������
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


//�e�g���X�{�[�h�o�b�t�@�[��������
//���e�g���~�m(�����Ă���)���e�g���X�{�[�h�o�b�t�@�[�ɓ���Ȃ��悤�ɂ��邱�Ƃɂ��A
//��]�A�ړ��Ȃǂ̍ہA���e�g���~�m���l�������Ƃ��ǂ�
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


//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g�{�[�h�̒��g���X�V����֐�
//�e�g���~�m�̏������W(���������Ƃ��̍��W)��p���邽�߁Ax���W��-4���炷���ƂŃl�N�X�g���̕\�Ƃ̐��������Ƃ�A
//�z�[���h�ɓ����Ă���l�ɂ���āA�����e�g���~�m��ς���
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


//���e�g���~�m�ȊO��g_tetlisBoardBuf�ɓ��������Ă��� 
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


//�e�g���X�z��ɉ��e�g���~�m�𓯊�������֐�
//g_tetlisBoard��g_movMinoNumOfArBuf�𓯊������Ă���
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


//�e�g���X�Ɋւ���f�[�^��������Ԃɖ߂��֐�
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


//�e�g���~�m�𐶐��Ɋւ���֐�
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


//�L�[���͂��J�E���g���Ƃ�\�ɂ���֐�
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


//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g������������֐�
VOID InitNextAndFever()
{
	InitNextBlock(&g_next);
	InitNextBlock(&g_nextNext);
	InitNextBlock(&g_nextNextnext);

	g_feverBlock = 0; //�t�B�[�o�[�u���b�N�̏�����


	return;
}


//�e�g���~�m���z�[���h���邱�ƂɊւ���֐�
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


//�e�g���~�m��X�������̈ړ��Ɋւ���֐�
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


//�E��]

//�e�g���~�m�̉�]�Ɋւ���֐�
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


//����]

//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
//�e�g���~�m�̉�]�Ɋւ���֐�
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


//�e�g���~�m��Y�������̈ړ��Ɋւ���֐�
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


//�e�g���~�m�̎��������Ɋւ���֐�
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


//�e�g���~�m��~�Ɋւ���֐�
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

//g_tetlisBoardBuf���g���m�F����񂪋�(-1)�ȊO�̏ꍇ�J�E���g���Ƃ�󗓂ɂ���
//��������e�g���X�̃��C���������J�E���g���Ƃ�֐�
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
			//�O�̔L�̈ʒu
			int CurrentCat;
			CurrentCat = -1;

			//�l�Y�~�ƔL�̔���
			for (int j = 0; j < TETLIS_WIDTH; ++j)
			{
				if (tetBoardBuf.tetlisBoard[column][j] != -1 &&
				 (((tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(CAT_01)) != 0) ||
				  ((tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(CAT_02)) != 0) ||
				  ((tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(CAT_03)) != 0)))/* �L�ł���Ƃ��� */
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
				//�˂��݂Ȃ�CurrentCat��-1�ɂ���
				else if ((tetBoardBuf.tetlisBoard[column][j] == -1) || tetBoardBuf.tetlisBoard[column][j] != -1 && (tetBoardBuf.tetlisBoard[column][j] & BLOCK_KIND_SHIFT(MOUSE)) == 0)
				{
					CurrentCat = -1;
				}
			}

			/* ������Ă��� */
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

			////����������肢�m�F�̎d�����o����悤��
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


//�����ꂽ�e�g���X�̃��C�������ɂ��炷�֐�
//�����ꂽ�e�g���X�̃��C�������ɂ��炷�֐�
//�����ꂽ�e�g���X�̃��C�������ɂ��炷�֐�
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

//�e�g���X�̃X�R�A�Ɋւ���֐�
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
	//�t�B�[�o�[���[�h�ɓ��������񂾂��J�n���Ԃ��Z�b�g����
	//������Z�b�g����Ȃ��悤�ɂ��Ă���

	g_Isfever = true;

	if (*canSetStartTime)
	{
		*g_startTime = timeGetTime();

		*canSetStartTime = false;
	}

}

//�t�B�[�o�[���[�h�̎��Ԋ֐�
VOID FeverTime(INT *g_lineTotalCount, DWORD *g_elapsedTime, DWORD *startTime, BOOL *canSetStartTime, INT *FeverTimer, INT *FallSpeedLevel, INT *FlamePerDown)
{
	//22�b��g_lineTotalCount��0�ɂ���
	timeBeginPeriod(1);
	//��������22�b
	DWORD timeLimit = FEVER_TIME;

	*g_elapsedTime = (timeGetTime() - *startTime) / 1000;

	*FeverTimer = timeLimit - *g_elapsedTime;

	sprintf(g_feverTimerArray, "%d", *FeverTimer);

	if (timeLimit - *g_elapsedTime <= 0)
	{
		*g_lineTotalCount = 0;
		*g_elapsedTime = 0;

		if (*FallSpeedLevel < 19)//18���ō����x��
		{
			*FallSpeedLevel += 1;//�������x���x����1�グ��

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

//�u���b�N�̎�ސݒ�
VOID SetTetminoPattern(INT *TetminoPattern)
{
	int random = rand() % 100;
	int random2 = rand() % 3;

	if (random > 30)
	{
		*TetminoPattern = tetminoMouse;//�l�Y�~�u���b�N
	}

	else
	{
		if (random2 == 0)
		{
			*TetminoPattern = tetminoCat1;//�l�R�u���b�N1
		}
		else if (random2 == 1)
		{
			*TetminoPattern = tetminoCat2;//�l�R�u���b�N2
		}

		else
		{
			*TetminoPattern = tetminoCat3;//�l�R�u���b�N3
		}
	}
}

//�u���b�N�̎�ޒ�`
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



//�t�B�[�o�[�Q�[�W�̒��g���X�V����֐�
VOID UpdateFeverGauge(INT *lineCount, INT g_feverBlock)
{


}

//�v���C���̌�����͈͓��ň�ԏ�̕����ɔ���e�g���~�m������ꍇisGameover��true�ɂ���
//�Q�[���I�[�o�[���A�ۂ��𒲂ׂ邷��֐�
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

// NextBlock�̏��������s��
// ���������ɂ͍ŏ���MovMinoNumoOfArBuf�̏��������s���Ă�
void InitNextBlock(MovMinoNumoOfArBuf *next_block, int block)
{
	// block�̎w�肪�Ȃ���Ύ����Őݒ�
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

// �u���b�N�̎擾�֐�
// �����Ńu���b�N�������_���Ŏ擾����悤�ɂ���
// ���̌v�Z��SetTetminoPattern�̓��e���g�p���Ă܂�
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
