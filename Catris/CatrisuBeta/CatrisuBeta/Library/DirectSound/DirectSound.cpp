#include <dsound.h>
#include "DirectSound.h"
#include "Main\Main.h"

#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dsound.lib")
#pragma comment(lib,"winmm.lib")

//SE
IDirectSoundBuffer8* BGM_title01;

HRESULT InitDSound(HWND hWnd, IDirectSound8 **pDS8)
{
	// サウンドデバイス作成
	if (FAILED(DirectSoundCreate8(NULL, pDS8, NULL)))
	{
		MessageBox(0, "サウンドデバイスの生成に失敗しました", "", MB_OK);
	}

	if (FAILED((*pDS8)->SetCooperativeLevel(hWnd, DSSCL_PRIORITY)))
	{
		MessageBox(0, "サウンドデバイスの生成に失敗しました", "", MB_OK);
	}

	return S_OK;
}

int SoundLoad(char* filename, IDirectSound8** pDS8, IDirectSoundBuffer8** pDSBuffer)
{
	WAVEFORMATEX wFmt;
	char *pWaveData = 0;
	DWORD waveSize = 0;

	if (!OpenWave((filename), wFmt, &pWaveData, waveSize))
	{
		return 0;
	}

	DSBUFFERDESC DSBufferDesc;
	DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufferDesc.dwFlags = 0;
	DSBufferDesc.dwBufferBytes = waveSize;
	DSBufferDesc.dwReserved = 0;
	DSBufferDesc.lpwfxFormat = &wFmt;
	DSBufferDesc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer *ptmpBuf = 0;
	(*pDS8)->CreateSoundBuffer(&DSBufferDesc, &ptmpBuf, NULL);
	ptmpBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)pDSBuffer);

	ptmpBuf->Release();
	if (pDSBuffer == 0)
	{
		(*pDS8)->Release();
		return 0;
	}

	LPVOID lpvWrite = 0;
	DWORD dwLength = 0;

	if (DS_OK == (*pDSBuffer)->Lock(0, 0, &lpvWrite, &dwLength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
	{
		memcpy(lpvWrite, pWaveData, dwLength);
		(*pDSBuffer)->Unlock(lpvWrite, dwLength, NULL, 0);
	}

	delete[] pWaveData;

	return 0;
}

void SoundFileOpen()
{
	//SoundLoad("Resourse\SE\TitleBGM.wav",&pDS8,&BGM_title01);
}

void SoundOperation(IDirectSoundBuffer8* pDSBuffer, SOUND_OPERATION operation)
{
	if (operation == PLAY)
	{
		pDSBuffer->Play(0, 0, 0);
	}

	if (operation == LOOP)
	{
		pDSBuffer->Play(0, 0, DSBPLAY_LOOPING);
	}

	if (operation == STOP)
	{
		pDSBuffer->Stop();
	}

	if (operation == RESET)
	{
		pDSBuffer->SetCurrentPosition(0);
	}

	if (operation == STOP_RESET)
	{
		pDSBuffer->Stop();
		pDSBuffer->SetCurrentPosition(0);
	}
}

bool OpenWave(TCHAR *filename, WAVEFORMATEX &wFmt, char** pWaveData, DWORD &waveSize)
{
	if (filename == 0)
	{
		return false;
	}

	HMMIO hMmio = NULL;
	MMIOINFO mmioInfo;
	memset(&mmioInfo, 0, sizeof(MMIOINFO));
	hMmio = mmioOpen(filename, &mmioInfo, MMIO_READ);
	if (!hMmio)
	{
		return false; // ファイルオープン失敗
	}

	MMRESULT mmRes;
	MMCKINFO riffChunk;
	riffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmRes = mmioDescend(hMmio, &riffChunk, NULL, MMIO_FINDRIFF);
	if (mmRes != MMSYSERR_NOERROR)
	{
		mmioClose(hMmio, 0);
		return false;
	}

	MMCKINFO formatChunk;
	formatChunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmRes = mmioDescend(hMmio, &formatChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR)
	{
		mmioClose(hMmio, 0);
		return false;
	}

	DWORD fmsize = formatChunk.cksize;
	DWORD size = mmioRead(hMmio, (HPSTR)&wFmt, fmsize);
	if (size != fmsize)
	{
		mmioClose(hMmio, 0);
		return false;
	}

	mmioAscend(hMmio, &formatChunk, 0);


	MMCKINFO dataChunk;
	dataChunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmRes = mmioDescend(hMmio, &dataChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR)
	{
		mmioClose(hMmio, 0);
		return false;
	}


	*pWaveData = new char[dataChunk.cksize];
	size = mmioRead(hMmio, (HPSTR)*pWaveData, dataChunk.cksize);
	if (size != dataChunk.cksize)
	{
		delete[] * pWaveData;
		return false;
	}

	waveSize = size;

	mmioClose(hMmio, 0);

	return true;
}