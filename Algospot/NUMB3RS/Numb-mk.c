#include <stdio.h>

#define MAX_TEST 50
#define MAX_TOWN 50
#define MAX_DAY 100

void Prob( int      aTown[MAX_TOWN][MAX_TOWN], 
		   double   aProb[MAX_TOWN],
		   double * aResult, 
		   int      aNumTown )
{
	int i = 0;
	int j = 0;

	double * sResult = NULL;
	double sTemp[MAX_TOWN] = { 0.0, };	

	sResult = aResult;

	for ( i = 0; i < aNumTown; i++ )
	{
		if ( sResult[i] > 0.0 )
		{
			for ( j = 0; j < aNumTown; j++ )
			{
				if ( aTown[i][j] == 1 )
				{
					sTemp[j] = sTemp[j] + ( aProb[i] * sResult[i] );
				}
			}
		}
	}

	for ( i = 0; i < aNumTown; i++ )
	{
		sResult[i] = sTemp[i];
	}
}

void NUMB( void )
{
	int i = 0;
	int j = 0;

	int sTown[MAX_TOWN][MAX_TOWN] = { { 0 }, };

	int sNumTown = 0;
	int sAfterDay = 0;
	int sJailNum = 0;

	int sResultNum = 0;
	int sResultTown[MAX_TOWN] = { 0, };
	double sResult[MAX_TOWN] = { 0.0, };

	double sProb[MAX_TOWN] = { 0, };

	scanf( "%d %d %d", &sNumTown,  &sAfterDay, &sJailNum );
	
	for ( i = 0; i < sNumTown; i++ )
	{
		for ( j = 0; j < sNumTown; j ++ )
		{
			scanf( "%d", &sTown[i][j] );
			sProb[i] += sTown[i][j];
		}
		sProb[i] = 1 / sProb[i];
	}

	scanf( "%d", &sResultNum );
	for ( i = 0; i < sResultNum; i++ )
	{
		scanf( "%d", &sResultTown[i] );
	}

	sResult[sJailNum] = 1.0;
	for ( i = 0; i < sAfterDay; i++ )
	{
		Prob( sTown, 
			  sProb,
			  sResult,
			  sNumTown );	
	}

	for ( i = 0; i < sResultNum; i++ )
	{
		printf( "%.8lf\n", sResult[sResultTown[i]] );
	}
}

int main( void )
{
	int i = 0;
	int sNumTest = 0;

	scanf( "%d", &sNumTest );
	for ( i = 0; i < sNumTest; i++ )
	{
		NUMB();
	}

	return 0;
}
