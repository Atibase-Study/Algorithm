#include <stdio.h>

#define MAX_TEST 50
#define MAX_N 500

#define MAX(a, b) ( a > b ? a : b )

int binarySearch( const int *arr, const int aNum, const int sStartIdx, const int aLastIdx );
int lis( const int *aNum, int aLastIdx );
void func();


int main( void )
{
	int i = 0;
	int sNum = 0;
	scanf( "%d", &sNum );
	for ( i = 0; i < sNum; i++ )
	{
		func();
	}
	return 0;
}

int binarySearch( const int *arr, const int aNum, const int sStartIdx, const int aLastIdx )
{
	int sMid = ( sStartIdx + aLastIdx )	/ 2;

	int sUp = arr[sMid + 1];
	int sDown = arr[sMid - 1];
	int sCur = arr[sMid];

	if ( ( aLastIdx == 0 ) && ( arr[aLastIdx] >= aNum ) )
		return 0;

	if ( sCur == aNum )
		return sMid;
	else if ( sCur > aNum )
	{
		if ( aNum > sDown )
			return sMid;
		else
			return binarySearch( arr, aNum, 0, sMid );
	}
	else if ( sCur < aNum )
	{
		if ( aNum < sUp )
			return sMid;
		else
			return binarySearch( arr, aNum, sMid, aLastIdx );
	}
}

int lis( const int *aNum, int aLastIdx )
{
	int i = 0;

	int sIdx = 0;
	int sTempIdx = 0;
	int sNumList[MAX_N] = {0, };
	int sNumIdx[MAX_N] = {0, };
	int sLis[MAX_N] = {0, };

	int sMax = 0;

	for ( i = 0; i < aLastIdx; i++ )
	{
		sLis[i] = 1;
	}

	sNumList[0] = aNum[0];
	sNumIdx[0] = 0;

	for ( i = 1; i < aLastIdx; i++ )
	{
		if ( aNum[i] > sNumList[sIdx] )
		{
			sLis[i] = sLis[sNumIdx[sIdx]] + 1;
		
			sIdx++;
			sNumList[sIdx] = aNum[i];
			sNumIdx[sIdx] = i;

		}
		else if ( aNum[i] < sNumList[sIdx] )
		{
			sTempIdx = binarySearch( sNumList, aNum[i], 0, sIdx );
			sNumList[sTempIdx] = aNum[i];
			sNumIdx[sTempIdx] = i;

			if ( sTempIdx > 0 )
			{
				sLis[i] = sLis[sNumIdx[sTempIdx - 1]] + 1;
			}
			else
			{
				sLis[i] = 1;
			}
		}
		else
		{
			sLis[i] = sLis[sNumIdx[sIdx]];
		}
		
		if ( sLis[i] > sMax )
				sMax = sLis[i];
	}

	return sMax;
}

void func()
{
	int i = 0;
	int j = 0;

	int sNumber[MAX_N] = {0, };

	int sNumOfNumber = 0;
	int sMax = 0;

	scanf( "%d", &sNumOfNumber );
	for ( i = 0; i < sNumOfNumber; i++ )
	{
		scanf( "%d", &sNumber[i] );
	}

	sMax = lis( sNumber, sNumOfNumber );

	printf( "%d\n", sMax );
}
