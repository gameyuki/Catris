#include "GameCommon.h"

//�e�g���~�m���W
ImageState g_tetminoState = { 0.f, 0.f, 32.f / 2, 32.f / 2 };

//�l�N�X�g�e�g���~�m���W
ImageState g_nextTetminoState = { 0.f, 0.f, 24.f / 2, 24.f / 2 };

//���݃X�R�A���W
ImageState g_CurrentScoreStrState = { 910.f,700.f,200.f, 225.f };

//���݃n�C�X�R�A���W
ImageState g_CurrentHighScoreStrState = { 1170.f,820.f,400.f, 225.f };

//�z�[���h�g�������W
ImageState g_HoldStrState = { 200.f,150.f,170.f, 140.f };

//���C���J�E���g�������W
ImageState g_CountStrState = { 1550.f,445.f,400.f, 200.f };

//���C���J�E���g�\���������W
ImageState g_CountShowStrState = { 1380.f,385.f,400.f, 200.f };

//�m�[�}�����[�h�������W
ImageState g_NormalStrState = { 1200.f,220.f,300.f, 200.f };

//�t�B�[�o�[���[�h�������W
ImageState g_FeverStrState = { 1200.f,220.f,300.f, 200.f };

//�t�B�[�o�[�^�C�}�[���W
ImageState g_FeverTimerStrState = { 1165.f,500.f,50.f, 50.f };

//�t�B�[�o�[�^�C�����W
ImageState g_FeverTimeShowStrState = { 1100.f,435.f,150.f, 50.f };

//�t�B�[�o�[�Q�[�W�������W
ImageState g_FevergaugeStrState = { 335.f,370.f,150.f, 50.f };

//�������x���x���������W
ImageState g_FallLevelStrState = { 1190.f,190.f,50.f, 50.f };

//�������x���x���\���������W
ImageState g_FallLevelShowStrState = { 1140.f,150.f,150.f, 50.f };

//�t�B�[�o�[�Q�[�W�u���b�N
ImageState g_GaugeBlockState = { 215.f, 655.f, 32.f / 2, 32.f / 2 };


//�e�g���~�m�p�^�[��
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

//�l�Y�~�u���b�N
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

INT g_feverBlock;//�t�B�[�o�[�u���b�N

INT g_lineTotalCount;//���C���̍��v

DWORD g_elapsedTime;//�t�B�[�o�[���[�h�̌o�ߎ���

DWORD g_startTime;//�t�B�[�o�[���[�h�̊J�n����

INT FallSpeedLevel = 1000;
INT FlamePerDown = 1000;

INT g_tetminoPattern1;//�u���b�N�̎�ސݒ�
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

CHAR g_LevelArray[2];//���x��