#include <stdio.h>

#define MAX_TEST 50
#define MAX_N 101

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

void lis( int aNum, int *aNumber, int aLisVal, int *aLis, int aIdx, int aLast )
{
	int i = 0;

	for ( i = aIdx; i < aLast; i++ )
	{
		if ( aNumber[i] > aNum )
		{
			if ( aLisVal >= aLis[i] )
			{
				aLis[i] = aLisVal + 1;
			}
		}
	}
}

void func()
{
	int i = 0;
	int j = 0;

	int sNum[2][MAX_N] = {{0}, };
	int sLis[2][MAX_N] = {{0}, };

	int sNumOfNum[2] = {0, };

	int sIdx[2] = {0, };

	int sMax = 1;

	scanf( "%d %d", &(sNumOfNum[0]), &(sNumOfNum[1]) );

	for ( i = 0; i < sNumOfNum[0]; i++ )
	{
		scanf( "%d", &sNum[0][i] );
		sLis[0][i] = 1;
	}

	for ( i = 0; i < sNumOfNum[1]; i++ )
	{
		scanf( "%d", &sNum[1][i] );
		sLis[1][i] = 1;
	}

	while ( sIdx[0] < sNumOfNum[0] || sIdx[1] < sNumOfNum[1] )
	{
		if ( sIdx[1] == sNumOfNum[1] || ( sIdx[0] < sNumOfNum[0] && sNum[0][sIdx[0]] < sNum[1][sIdx[1]] ) )
		{
			lis( sNum[0][sIdx[0]], sNum[0], sLis[0][sIdx[0]], sLis[0], sIdx[0] + 1, sNumOfNum[0] );
			lis( sNum[0][sIdx[0]], sNum[1], sLis[0][sIdx[0]], sLis[1], 0, sNumOfNum[1] );
			sIdx[0]++;
		}
		else 
		{	
			lis( sNum[1][sIdx[1]], sNum[1], sLis[1][sIdx[1]], sLis[1], sIdx[1] + 1, sNumOfNum[1] );
			lis( sNum[1][sIdx[1]], sNum[0], sLis[1][sIdx[1]], sLis[0], 0, sNumOfNum[0] );

			sIdx[1]++;
		}

		if ( sIdx[0] == sNumOfNum[0] && sIdx[1] == sNumOfNum[1] )
			break;
	}

	for ( i = 0; i < sNumOfNum[0]; i++ )
	{
		if ( sLis[0][i] > sMax )
			sMax = sLis[0][i];
	}

	for ( i = 0; i < sNumOfNum[1]; i++ )
	{
		if ( sLis[1][i] > sMax )
			sMax = sLis[1][i];
	}

	printf( "%d\n", sMax );
}
