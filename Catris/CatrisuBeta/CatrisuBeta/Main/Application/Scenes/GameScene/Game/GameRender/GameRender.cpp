#include "Main\Application\Scenes\GameScene\Game\GameCommon\GameCommon.h"
#include "Main\Application\Scenes\GameScene\Game\GameRender\GameRender.h"
#include "Main\Application\Scenes\GameScene\Game\GameInitialize\GameInitialize.h"
#include "Main\Main.h"
#include "Library\DirectFont\DirectFont.h"
#include "Library\DirectInput\DirectInput.h"

 
VOID Render(VOID)
{

	//���_�ʒu�̐ݒ�A�Ō�ɐ�΍��W�ւ̕ϊ����s��
	SetViewPointOverall();


	//����p�̐ݒ�A�Ō�ɐ�΍��W�ւ̕ϊ����s��
	SetFocusOfViewOverall();

	//�J�X�^���o�[�e�b�N�X�̐���

	//�ʏ�w�i

	CustomVertex cusV4Background[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�g

	CustomVertex cusV4Frame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i

	CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g

	CustomVertex cusV4FeverFrame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�ʏ�w�i2

	CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�g2

	CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i2

	CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g2

	CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i3

	CustomVertex cusV4FeverBackground3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g3

	CustomVertex cusV4FeverFrame3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i4

	CustomVertex cusV4FeverBackground4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g4

	CustomVertex cusV4FeverFrame4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i5

	CustomVertex cusV4FeverBackground5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g5

	CustomVertex cusV4FeverFrame5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�l�N�X�g�g
	CustomVertex cusV4NextFrame[4]
	{
		{ 650.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 835.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 835.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 650.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�z�[���h�g
	CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�t�B�[�o�[�Q�[�W
	CustomVertex cusV4GaugeFrame[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W�t�B�[�o�[��
	CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�n�C�X�R�A�g
	CustomVertex cusV4HighScoreframe[4]{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�X�R�A�g
	CustomVertex cusV4ScoreFrame[4]{
		{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�t�B�[�o�[�Q�[�W�u���b�N

	CustomVertex cusV4GaugeBlock[4]{
		{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�t�B�[�o�[����
	CustomVertex cusV4FeverStr[4]
	{
		{ 920.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1259.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1259.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 920.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};
	//�Q�[���I�[�o�[����
	CustomVertex cusV4GameoverStr[4]
	{
		{ 150.f,   150.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1107,   150.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1107.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 150.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�l�N�X�g�e�g���~�m
	CustomVertex cusV4NextTetmino[4]
	{
		{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};

	//�e�g���~�m

	CustomVertex cusV4Tetmino[4]
	{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};


	//���݃X�R�A�\��

	RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	//���݃n�C�X�R�A�\��

	RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};

	//���C���J�E���g����

	RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)

	};

	//���C���J�E���g�\������

	RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//�m�[�}�����[�h����

	RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)

	};

	//�t�B�[�o�[�^�C�}�[����

	RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)

	};

	//�t�B�[�o�[�^�C������
	RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//�t�B�[�o�[�Q�[�W����
	RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//�������x���x������
	RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//�������x���x���\������
	RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)
	};

	//��ʕ\���֌W�̏����A�J�X�^���o�[�e�b�N�X��g_tetlisBoard�̔z��ԍ���p���āA
	//���������e�g���X��\�����Ă���
	DisplayScreen(
		cusV4Background, //�ʏ�w�i
		cusV4Frame,      //�g
		cusV4FeverBackground, //�t�B�[�o�[�w�i
		cusV4FeverFrame,      //�t�B�[�o�[�g

		cusV4Background2, //�ʏ�w�i2
		cusV4Frame2,      //�g2

		cusV4FeverBackground2, //�t�B�[�o�[�w�i2
		cusV4FeverFrame2,      //�t�B�[�o�[�g2

		cusV4FeverBackground3, //�t�B�[�o�[�w�i3
		cusV4FeverFrame3,      //�t�B�[�o�[�g3

		cusV4FeverBackground4, //�t�B�[�o�[�w�i4
		cusV4FeverFrame4,      //�t�B�[�o�[�g4

		cusV4FeverBackground5, //�t�B�[�o�[�w�i5
		cusV4FeverFrame5,      //�t�B�[�o�[�g5

		cusV4NextFrame,  //�l�N�X�g�g

		cusV4HoldFrame,  //�z�[���h�g
		cusV4GaugeFrame, //�t�B�[�o�[�Q�[�W
		cusV4GaugeFrame_Fiver, //�t�B�[�o�[�Q�[�W�t�B�[�o�[��

		cusV4FeverStr,//�t�B�[�o�[����

		cusV4GameoverStr,//�Q�[���I�[�o�[����

		cusV4ScoreFrame, //�X�R�A�g
		cusV4HighScoreframe,//�n�C�X�R�A�g
		cusV4GaugeBlock,    //�t�B�[�o�[�Q�[�W�u���b�N
		cusV4Tetmino,       //�e�g���~�m

		cusV4NextTetmino,       //�l�N�X�g�e�g���~�m

		&rectCurrentScoreStr,        //���݃X�R�A����
		&rectCurrentHighScoreStr,    //���݃n�C�X�R�A����
		&rectCountStr,                //���C���J�E���g����
		&rectCountShowStr,                //���C���J�E���g�\������
		&rectNormalStr,                //�m�[�}�����[�h����
		&rectFeverTimerStr,            //�t�B�[�o�[���[�h�^�C�}�[
		&rectFeverTimeShowStr,         //�t�B�[�o�[���[�h�^�C��
		&rectFevergaugeShowStr,        //�t�B�[�o�[�Q�[�W����
		&rectFallLevelStr,              //�������x���x������
		&rectFallLevelShowStr            //�������x���x���\������
	);

	//��ʕ\�����s��ꂽ���Ƃ��o�b�N�o�b�t�@�[�ɓ`����
	g_pD3Device->Present(NULL, NULL, NULL, NULL);

	return;
}

//���_�ʒu�̐ݒ�
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

//����p�̐ݒ�
VOID SetFocusOfViewOverall(VOID)
{
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pD3Device->SetTransform(D3DTS_VIEW, &matProj);

	return;
}

VOID CreateCustomVertex(VOID)
{
	//�ʏ�w�i
	static CustomVertex cusV4Background[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�g
	static CustomVertex cusV4Frame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i
	static CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g
	static CustomVertex cusV4FeverFrame[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�ʏ�w�i2
	static CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�g2
	static CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i2
	static CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g2
	static CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i3
	static CustomVertex cusV4FeverBackground3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g3
	static CustomVertex cusV4FeverFrame3[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i4
	static CustomVertex cusV4FeverBackground4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g4
	static CustomVertex cusV4FeverFrame4[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i5
	static CustomVertex cusV4FeverBackground5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g5
	static CustomVertex cusV4FeverFrame5[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�l�N�X�g�g
	static CustomVertex cusV4NextFrame[4]
	{
		{ 650.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 835.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 835.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 650.f, 440.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�z�[���h�g
	static CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W
	static CustomVertex cusV4GaugeFrame[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W�t�B�[�o�[��
	static CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�X�R�A�g
	static CustomVertex cusV4ScoreFrame[4]{
		{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�n�C�X�R�A�g
	static CustomVertex cusV4HighScoreframe[4]{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[����
	static CustomVertex cusV4FeverStr[4]
	{
		{ 930.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1249.f,   20.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1249.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 930.f, 130.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};
	//�Q�[���I�[�o�[����
	static CustomVertex cusV4GameoverStr[4]
	{
		{ 150.f,   150.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1107,   150.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1107.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 150.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�t�B�[�o�[�Q�[�W�u���b�N

	static CustomVertex cusV4GaugeBlock[4]
	{
		{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�l�N�X�g�e�g���~�m
	static CustomVertex cusV4NextTetmino[4]
	{
		{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y - g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_nextTetminoState.x + g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_nextTetminoState.x - g_nextTetminoState.xScale, g_nextTetminoState.y + g_nextTetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};

	//�e�g���~�m
	static CustomVertex cusV4Tetmino[4]
	{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};


	//���݃X�R�A�\��
	static RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	// ���݃n�C�X�R�A�\��
	static RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};


	//���C���J�E���g����
	static RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)
	};

	//���C���J�E���g�\������

	static RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//�m�[�}�����[�h����
	static RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)
	};


	//�t�B�[�o�[�^�C�}�[����
	static RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)
	};

	//�t�B�[�o�[�^�C������
	static RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//�t�B�[�o�[�Q�[�W����
	static RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//�������x���x������
	static RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//�������x���x���\������
	static RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)

	};
	return;
}


//�`��
VOID DisplayScreen(
	CustomVertex *cusV4Background, //�ʏ�w�i
	CustomVertex *cusV4Frame,      //�g
	CustomVertex *cusV4FeverBackground, //�t�B�[�o�[�w�i
	CustomVertex *cusV4FeverFrame,      //�t�B�[�o�[�g

	CustomVertex *cusV4Background2, //�ʏ�w�i2
	CustomVertex *cusV4Frame2,      //�g2

	CustomVertex *cusV4FeverBackground2, //�t�B�[�o�[�w�i2
	CustomVertex *cusV4FeverFrame2,      //�t�B�[�o�[�g2

	CustomVertex *cusV4FeverBackground3, //�t�B�[�o�[�w�i3
	CustomVertex *cusV4FeverFrame3,      //�t�B�[�o�[�g3

	CustomVertex *cusV4FeverBackground4, //�t�B�[�o�[�w�i4
	CustomVertex *cusV4FeverFrame4,      //�t�B�[�o�[�g4

	CustomVertex *cusV4FeverBackground5, //�t�B�[�o�[�w�i5
	CustomVertex *cusV4FeverFrame5,      //�t�B�[�o�[�g5

	CustomVertex *cusV4NextFrame,  //�l�N�X�g�g

	CustomVertex *cusV4HoldFrame,  //�z�[���h�g
	CustomVertex *cusV4GaugeFrame, //�t�B�[�o�[�Q�[�W

	CustomVertex *cusV4GaugeFrame_Fiver, //�t�B�[�o�[�Q�[�W�t�B�[�o�[��

	CustomVertex *cusV4FeverStr,//�t�B�[�o�[����

	CustomVertex *cusV4GameoverStr,//�Q�[���I�[�o�[����

	CustomVertex *cusV4ScoreFrame, //�X�R�A�g
	CustomVertex *cusV4HighScoreframe,//�n�C�X�R�A�g
	CustomVertex *cusV4GaugeBlock,    //�t�B�[�o�[�Q�[�W�u���b�N
	CustomVertex *cusV4Tetmino,       //�e�g���~�m

	CustomVertex *cusV4NextTetmino,       //�l�N�X�g�e�g���~�m

	RECT *rectCurrentScoreStr,        //���݃X�R�A����
	RECT *rectCurrentHighScoreStr,    //���݃n�C�X�R�A����
	RECT *rectCountStr,                //���C���J�E���g����
	RECT *rectCountShowStr,                //���C���J�E���g�\������
	RECT *rectNormalStr,                //�m�[�}�����[�h����
	RECT *rectFeverTimerStr,            //�t�B�[�o�[���[�h�^�C�}�[
	RECT *rectFeverTimeShowStr,            //�t�B�[�o�[���[�h�^�C��
	RECT *rectFevergaugeShowStr,         //�t�B�[�o�[�Q�[�W����
	RECT *rectFallLevelStr,               //�������x���x������
	RECT *rectFallLevelShowStr            //�������x���x���\������
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

	//���C���̐���10�ȏ�̂Ƃ��t�B�[�o�[�w�i 10�ȉ��Ȃ�ʏ�w�i
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 4 == 0)
		{
			//�t�B�[�o�[�w�i4�\��
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex4]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground4, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 5 == 0)
		{
			//�t�B�[�o�[�w�i5�\��
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex5]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground5, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 2 == 0)
		{
			//�t�B�[�o�[�w�i2�\��
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground2, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 3 == 0)
		{
			//�t�B�[�o�[�w�i3�\��
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex3]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground3, sizeof(CustomVertex));

		}

		else
		{
			//�t�B�[�o�[�w�i1�\��
			g_pD3Device->SetTexture(0, g_pTexture[g_feverbackgroundTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground, sizeof(CustomVertex));

		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//�w�i�\��2
			g_pD3Device->SetTexture(0, g_pTexture[g_backgroundTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background2, sizeof(CustomVertex));

		}

		else
		{
			//�w�i�\��1
			g_pD3Device->SetTexture(0, g_pTexture[g_backgroundTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background, sizeof(CustomVertex));

		}

	}



	//�e�g���~�m�\��
	for (int column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (int row = 0; row < TETLIS_WIDTH; row++)
		{
			//if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
			//{
			//	cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
			//	cusV4Tetmino->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
			//	//��}�X����ĕ`��
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
				//��}�X����ĕ`��
				(cusV4Tetmino + 1)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

				SetCatAndMouseUV(cusV4Tetmino, kind, false);

				//switch (tetBoard.tetlisPattern[column][row])
				//{
				//case 0://�l�Y�~�u���b�N
				//	cusV4Tetmino->tu = 0.5f;
				//	cusV4Tetmino->tv = 1.0f;
				//	/*2
				//	/*(cusV4Tetmino + 2)->tu = 0.5f;
				//	(cusV4Tetmino + 2)->tv = 1.0f;
				//	(cusV4Tetmino + 3)->tu = 0.5f;
				//	(cusV4Tetmino + 3)->tv = 1.0f;*/
				//	break;
				//case 1://�l�R�u���b�N1
				//	cusV4Tetmino->tu = 1.0f;
				//	cusV4Tetmino->tv = 1.0f;
				//	break;
				//case 2://�l�R�u���b�N2
				//	break;
				//case 3://�l�R�u���b�N3
				//	break;
				//default:
				//	break;
				//}
				g_pD3Device->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}
		}
	}


	//���C���̐���10�ȏ�̂Ƃ��t�B�[�o�[�g 10�ȉ��Ȃ�ʏ�g
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 4 == 0)
		{
			//�t�B�[�o�[�g4
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex4]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame4, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 5 == 0)
		{
			//�t�B�[�o�[�g5
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex5]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame5, sizeof(CustomVertex));

		}

		else if (FallSpeedLevel % 2 == 0)
		{
			//�t�B�[�o�[�g2
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame2, sizeof(CustomVertex));
		}

		else if (FallSpeedLevel % 3 == 0)
		{
			//�t�B�[�o�[�g3
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex3]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame3, sizeof(CustomVertex));

		}

		else
		{
			//�t�B�[�o�[�g1
			g_pD3Device->SetTexture(0, g_pTexture[g_feverframeTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame, sizeof(CustomVertex));
		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//�g2
			g_pD3Device->SetTexture(0, g_pTexture[g_frameTex2]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame2, sizeof(CustomVertex));

		}

		else
		{
			//�g
			g_pD3Device->SetTexture(0, g_pTexture[g_frameTex]);

			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame, sizeof(CustomVertex));

		}

	}

	//�l�N�X�g�g
	g_pD3Device->SetTexture(0, g_pTexture[g_nextFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4NextFrame, sizeof(CustomVertex));


	//�z�[���h�g
	g_pD3Device->SetTexture(0, g_pTexture[g_holdFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HoldFrame, sizeof(CustomVertex));

	//�t�B�[�o�[�Q�[�W
	g_pD3Device->SetTexture(0, g_pTexture[g_gaugeTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame, sizeof(CustomVertex));

	//�n�C�X�R�A�g
	g_pD3Device->SetTexture(0, g_pTexture[g_scoreFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4ScoreFrame, sizeof(CustomVertex));

	//�X�R�A�g
	g_pD3Device->SetTexture(0, g_pTexture[g_highScoreFrameTex]);

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HighScoreframe, sizeof(CustomVertex));


	//���݃X�R�A
	g_pFont[g_currentscoreFont]->DrawText(NULL, g_scoreArray, -1, rectCurrentScoreStr, NULL, NORMAL_COLOR);

	//���݃n�C�X�R�A
	g_pFont[g_currenthighscoreFont]->DrawText(NULL, HIGHSCORESHOW, -1, rectCurrentHighScoreStr, NULL, HIGHSCORE_COLOR);

	//�t�B�[�o�[�Q�[�W����
	g_pFont[g_fevergaugeshowFont]->DrawText(NULL, FEVERGAUGE, -1, rectFevergaugeShowStr, NULL, GAMEOVER_COLOR);

	//�������x���x������
	g_pFont[g_falllevelFont]->DrawText(NULL, g_LevelArray, -1, rectFallLevelStr, NULL, FEVERTIMER_COLOR);

	//�������x���x���\������
	g_pFont[g_falllevelshowFont]->DrawText(NULL, FALLLEVEL, -1, rectFallLevelShowStr, NULL, FEVERTIMER_COLOR);


	//���C���̐���10�ȏ�̂Ƃ��ԕ��� 10�ȉ��Ȃ獕���� �t�B�[�o�[���[�h�����\��
	if (g_lineTotalCount >= 10)
	{

		//�t�B�[�o�[�^�C�}�[����
		g_pFont[g_fevertimerFont]->DrawText(NULL, g_feverTimerArray, -1, rectFeverTimerStr, NULL, FEVER_COLOR);

		//�t�B�[�o�[�^�C������
		g_pFont[g_fevertimeshowFont]->DrawText(NULL, FEVERTIME, -1, rectFeverTimeShowStr, NULL, FEVER_COLOR);

		//�t�B�[�o�[���[�h����
		g_pD3Device->SetTexture(0, g_pTexture[g_feverStr]);

		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverStr, sizeof(CustomVertex));

	}

	else
	{
		//���C���J�E���g����
		g_pFont[g_countFont]->DrawText(NULL, g_countArray, -1, rectCountStr, NULL, NORMAL_COLOR);


		//���C���J�E���g�\������
		g_pFont[g_countFont]->DrawText(NULL, LINECOUNT, -1, rectCountShowStr, NULL, NORMAL_COLOR);

		//�m�[�}�����[�h����
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


	//�t�B�[�o�[�Q�[�W�u���b�N
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

	//�Q�[���I�[�o�[
	if (g_showGameoverStr)
	{
		//�Q�[���I�[�o�[����
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
