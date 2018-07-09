#ifndef MAIN_H
#define	MAIN_H

#include <Windows.h>
#include <d3dx9.h>


#define SAFE_RELEASE(p){if(p){(p)->Release();(p)=NULL;}}

/* ���_�\���� */
typedef struct _CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CUSTOMVERTEX;

/* �摜��� */
enum TEXTURE
{
	BACKGROUND_TEX,					//<<�S�̂̔w�i1
	BACKGROUND_TEX2,				//<<�S�̂̔w�i2
	TITLE_LOGO_TEX,					//<<�^�C�g���̃��S
	TITLE_TEAMLOGO_TEX,				//<<�`�[���̃��S
	TITLE_ARROW_TEX,				//<<�^�C�g����ʂ̖��
	TITLE_CONFIGRATION_TEX,			//<<�^�C�g���̐ݒ��ʑJ�ڗp
	TITLE_NEXT_TEX,					//<<�^�C�g���̃Q�[���J�n
	TITLE_END_TEX,					//<<�^�C�g���̏I��
	GAME_FEVERBACKGROUND_TEX1,		//<<�Q�[����ʂ̃t�B�[�o�[���[�h�̔w�i1
	GAME_FEVERBACKGROUND_TEX2,		//<<�Q�[����ʂ̃t�B�[�o�[���[�h�̔w�i2
	GAME_MAINFRAME_TEX,				//<<�Q�[����ʂ̃��C���t���[��
	GAME_HOLDFRAME_TEX,				//<<�Q�[����ʂ̃z�[���h�p�̃t���[��
	GAME_NEXTFRAME_TEX,				//<<�Q�[����ʂ̎��̃u���b�N�p�̃t���[��
	GAME_NOMALSCOREFRAME_TEX,		//<<�Q�[����ʂ̃X�R�A�p�t���[��
	GAME_HIGHTSCOREFRAME_TEX,		//<<�Q�[����ʂ̃n�C�X�R�A�p�̃t���[��
	GAME_FEVERFRAME_TEX,			//<<�Q�[����ʂ̃t�B�[�o�[�Q�[�W�p�̃t���[��
	CONFIG_BACKGROUND_TEX,			//<<�ݒ��ʗp�̔w�i
	RESULT_BACKGROUND_TEX1,			//<<���U���g��ʂ̔w�i1
	RESULT_BACKGROUND_TEX2,			//<<���U���g��ʂ̔w�i2
	RESULT_BACKGROUND_TEX3,			//<<���U���g��ʂ̔w�i3
	RESULT_BACKGROUND_TEX4,			//<<���U���g��ʂ̔w�i4
	RESULT_LOGO_TEX,				//<<���U���g��ʂ̃��S
	RESULT_CONTINUE_TEX,			//<<���U���g��ʂ̃R���e�j���[
	RESULT_NOMALSCOREFRAME_TEX,		//<<���U���g��ʂ̃m�[�}���X�R�A�p�t���[��
	RESULT_HIGHTSCOREFRAME_TEX,		//<<���U���g��ʂ̃n�C�X�R�A�p�t���[��
	RESULT_RETURNTITLE_TEX,			//<<���U���g��ʂ̃^�C�g����ʂ֖߂�p
	TEXMAX
};

/* �V�[����� */
enum Scenes
{
	EMPTY_SCENE,
	TITLE_SCENE,
	GAME_SCENE,
	RESULT_SCENE,
	CONFIG_SCENE,
	SCENE_MAX
};

//	�u���b�N�̐������߂鐔���͒萔�����Ă����܂�
#define BLOCK_HEIGHT	4
#define BLOCK_WIDTH		4

//�t�B�[���h�̏c���E����
#define FIELD_HEIGHT	20
#define FIELD_WIDTH		10


extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	�摜�̏������Ă����ׂ̔z��
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3D�̃f�o�C�X
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	�p�����[�^
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X


#endif