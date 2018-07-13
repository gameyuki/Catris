#ifndef DIRECTFONT
#define	DIRECTFONT

//ï∂éöêF
#define NORMAL_COLOR (0xFF000000)
#define GAMEOVER_COLOR (0xFFFF0000)
#define HIGHSCORE_COLOR (0xFF0000FF)
#define FEVER_COLOR (0xFFFFFF00)
#define NORMALMODE_COLOR (0xFFFF69B4)
#define FEVERTIMER_COLOR (0xFF4169E1)

//ï∂éö
#define SCORE ("Score")
#define HIGHSCORE ("HighScore")
#define HOLD ("Hold")
#define NEXT ("Next")
#define HIGHSCORESHOW ("100000")
#define FEVERTIME ("FeverTime")
#define NORMALMODE ("NORMAL")
#define LINECOUNT ("LineCount")
#define FEVERGAUGE ("Fever")
#define FALLLEVEL ("FallLevel")

HRESULT InitDfont(HWND hWnd);

#endif