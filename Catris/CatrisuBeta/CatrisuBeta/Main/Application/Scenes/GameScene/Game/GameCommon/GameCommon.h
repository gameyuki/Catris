#ifndef GAME_COMMON_H
#define	GAME_COMMON_H

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <d3dx9.h>

//�e�g���X�T�C�Y
#define TETLIS_WIDTH 12
#define TETLIS_HEIGHT 24

#define SHIFT_FRAME_COUNTER 6
#define DOWN_FRAME_COUNTER 2

#define FLAME_PER_DOWN 55 //�e�g���~�m�̗����鑬��
#define FLAME_PER_STOP 30 //�e�g���~�m���ݒu�܂ł̎���

#define FEVERGAUGEBLOCK_TOTAL 10 //�t�B�[�o�[�Q�[�W�u���b�N�̐�

#define FEVER_TIME 22 //�t�B�[�o�[���[�h�̎���

// �u���b�N�̎��
typedef enum
{
	NON,
	CAT_01,		// �L�P
	CAT_02,		// �L�Q
	CAT_03,		// �L�R
	MOUSE,		// �l�Y�~
	KILL_ZONE,	// �l�Y�~������ċ󂢂���
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

//�e�g���~�m�p�^�[��
typedef struct
{
	INT number;
	CHAR name;
	INT yx[4][2];

	INT pattern_yx[4][2];

} Tetmino;

//�l�Y�~�u���b�N
typedef struct
{
	INT number;
	CHAR name;
	INT yx[2][2];
} TetminoMouse;


//�e�g���X�{�[�h
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
	INT tetminoPattern[4][2];//�u���b�N�̎�ސ�
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

extern INT g_feverBlock;//�t�B�[�o�[�u���b�N

extern INT g_lineTotalCount;//���C���̍��v

extern DWORD g_elapsedTime;//�t�B�[�o�[���[�h�̌o�ߎ���
extern DWORD g_startTime;//�t�B�[�o�[���[�h�̊J�n����
extern INT FallSpeedLevel;
extern INT FlamePerDown;

extern INT g_tetminoPattern1;//�u���b�N�̎�ސݒ�
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

extern INT g_fevergaugeBoard[1][10]; //�t�B�[�o�[�Q�[�W�u���b�N

extern BOOL g_showGameoverStr;

extern CHAR g_scoreArray[8];

extern CHAR g_countArray[4];

extern CHAR g_feverTimerArray[2];

extern CHAR g_LevelArray[2];

extern MovMinoNumoOfArBuf g_hold, g_next, g_nextNext, g_nextNextnext;


//�e�g���X�Ȃǂ̑���Ɋւ���֐�
VOID Control(VOID);

//�e�g���X�{�[�h������������֐�
VOID InitTetlisBoard(VOID);

//�e�g���X�{�[�h�o�b�t�@�[������������֐�
VOID InitTetlisBoardBuf(VOID);



//�t�B�[�o�[�Q�[�W�̒��g���X�V����֐�
VOID UpdateFeverGauge(INT *lineCount, INT g_feverBlock);

//���������C���̍��v�Ńt�B�[�o�[�Q�[�W�u���b�N��\������֐�
VOID FeverGaugeBlock(VOID);

//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g������������֐�
VOID InitNextAndFever();

//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g�{�[�h�̒��g���X�V����֐�
VOID UpdateHoldNextNextNextBoard(VOID);

//�e�g���X�z��o�b�t�@�[�ɉ��e�g���~�m���������e�g���X�z��̗v�f�𓯊�������֐�
VOID SynchroTetlisBoardBufToTetlisBoard(bool is_convert = false);

//�e�g���X�z��ɉ��e�g���~�m�𓯊�������֐�
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino);

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
);

//�L�[���͂��J�E���g���Ƃ�\�ɂ���֐�
VOID CountToMakeFlagTrue(BOOL *canInputLA, INT *lACount);

//�e�g���~�m���z�[���h���邱�ƂɊւ���֐�
VOID HoldTetlimino(
	BOOL *canHold,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *wasHold
);

//�e�g���~�m��X�������̈ړ��Ɋւ���֐�
VOID ShiftTetliminoX(INT shiftX, BOOL *canInputRA);

//�e�g���~�m�̉�]�Ɋւ���֐�(�E��])
VOID RotateTetliminoRight(BOOL *minoIRoatationCount, INT currentTetmino);

//�e�g���~�m�̉�]�Ɋւ���֐�(����])
VOID RotateTetliminoLeft(BOOL *minoIRoatationCount, INT currentTetmino);

//�e�g���~�m��Y�������̈ړ��Ɋւ���֐�
VOID DownTetlimino(BOOL *canInputDA);

//�e�g���~�m�̃n�[�h�h���b�v�Ɋւ���֐�
//VOID HardDropTetlimino(VOID);

//�e�g���~�m�̎��������Ɋւ���֐�
VOID CountToDawnTetlimino(INT *downCount, INT *FallSpeedLevel, INT *FlamePerDown);

//�e�g���~�m��~�Ɋւ���֐�
bool CountToStopTetlimino(
	INT *stopCount,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *canHold,
	BOOL *wasHold
);

//��������e�g���X�̃��C���������J�E���g���Ƃ�֐�
int DeleteAndCountFilledLine();

//�����ꂽ�e�g���X�̃��C�������ɂ��炷�֐�
void ShiftTetlisLine(void);

bool LineDelete(VOID);


//�e�g���X�̃X�R�A�Ɋւ���֐�
int GetScoreByLineCount(INT lineCount);

//�Q�[���I�[�o�[���A�ۂ��𒲂ׂ邷��֐�
VOID CheckGameover(BOOL *isGameover);

//�t�B�[�o�[���[�h�̎��Ԋ֐� �t�B�[�o�[���[�h���I����FallSpeedLevel�� +1�AFlamePerDown��-2�ɂ���
VOID FeverTime(INT *g_lineTotalCount, DWORD *g_elapsedTime, DWORD *g_startTime, BOOL *canSetStartTime, INT *FeverTimer, INT *FallSpeedLevel, INT *FlamePerDown);

//�t�B�[�o�[���[�h�̊J�n���Ԋ֐�
VOID SetFeverStartTime(DWORD *g_startTime, BOOL *canSetStartTime);

//�u���b�N�̎�ސݒ�
VOID SetTetminoPattern(INT *TetminoPattern);

//�u���b�N�̎�ޒ�`
VOID defineTetminoPattern(INT *g_tetminoPattern1, INT *g_tetminoPattern2, INT *g_tetminoPattern3, INT *g_tetminoPattern4, INT currentTetmino);

void InitNextBlock(MovMinoNumoOfArBuf *next_block, int block = -1);

BLOCK_KIND GetBlockKind(bool is_fever = false);

#define BLOCK_KIND_SHIFT(kind) (1 << (8 + kind))



#endif