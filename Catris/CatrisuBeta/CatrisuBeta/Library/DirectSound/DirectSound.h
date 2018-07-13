#ifndef DIRECTSOUND_H
#define	DIRECTSOUND_H

#include <Windows.h>
#include <dsound.h>

/**
* 音声操作列挙子
*/
enum SOUND_OPERATION
{
	PLAY,		//!< サウンドの再生.
	STOP,		//!< サウンドの停止.
	LOOP,		//!< サウンドのループ再生.
	RESET,		//!< サウンドのリセット.
	STOP_RESET	//!< サウンドの停止とリセット.
};


/**
* DirectSoundの初期化
* @param[in] hWnd ウィンドウハンドル
* @param[out] pDS8 DirectSoundオブジェクト
* @return 成功した場合はS_OKを、失敗した場合はエラーコードを返す
*/
HRESULT InitDSound(HWND hWnd, IDirectSound8** pDS8);

int SoundLoad(char* filename, IDirectSound8** pDS8, IDirectSoundBuffer8** pDSBuffer);

void SoundOperation(IDirectSoundBuffer8* pDSBuffer, SOUND_OPERATION operation);

bool OpenWave(TCHAR* filepath, WAVEFORMATEX &waveFormatEx, char** ppData, DWORD &dataSize);


#endif