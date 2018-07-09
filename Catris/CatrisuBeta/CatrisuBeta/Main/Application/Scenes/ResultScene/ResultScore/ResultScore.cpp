#include "ResultScore.h"
#include "ResultNomalScore\ResultNomalScore.h"
#include "ResultHightScore\ResultHightScore.h"

void ResultScoreDraw()
{
	ResultNomalScoreRun();
	ResultHightScoreRun();
}

void ResultScoreUpdate()
{

}

void ResultScoreRun()
{
	ResultScoreUpdate();
	ResultScoreDraw();
}