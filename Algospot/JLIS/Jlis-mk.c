#include <stdio.h>

#define MAX_TEST 50
#define MAX_N 101

#define MAX(a, b) ( a > b ? a : b )

int gLis[MAX_N + 1][MAX_N + 1] = {0, };

void func();
int jlis( int  aNumOfNumA, int aNumOfNumB, 
		  int  aNumA[], int aNumB[], 
		  int  aAIdx, int aBIdx );

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

void func()
{
	int i = 0;
	int j = 0;

	int sNumOfNumA = 0;
	int sNumOfNumB = 0;
	int sNumA[MAX_N] = { 0, };
	int sNumB[MAX_N] = { 0, };

	int sMax = 0;

	scanf( "%d %d", &sNumOfNumA, &sNumOfNumB );

	for ( i = 1; i < sNumOfNumA + 1; i++ )
	{
		scanf( "%d", &sNumA[i] );
	}

	for ( i = 1; i < sNumOfNumB + 1; i++ )
	{
		scanf( "%d", &sNumB[i] );
	}

	for ( i = 0; i < sNumOfNumA + 1; i++ )
	{
		for ( j = 0; j < sNumOfNumB + 1; j++ )
			gLis[i][j] = 0;
	}

	if ( sNumA[1] <= sNumB[1] )
		sMax = jlis( sNumOfNumA, sNumOfNumB, sNumA, sNumB, 1, 0 );
	else
		sMax = jlis( sNumOfNumA, sNumOfNumB, sNumA, sNumB, 0, 1 );

	printf( "%d\n", sMax );
}

int jlis( int  aNumOfNumA, int aNumOfNumB, 
		  int  aNumA[], int aNumB[], 
		  int  aAIdx, int aBIdx )
{
	int i = 0;
	int *ret = &( gLis[aAIdx][aBIdx] );
	int curNum = MAX( aNumA[aAIdx], aNumB[aBIdx] );

	if ( *ret != 0 )
		return *ret;

	*ret = 1;

	for ( i = aAIdx + 1; i < aNumOfNumA + 1; i++ )
	{
		if ( aNumA[i] > curNum )
			*ret = MAX( *ret, jlis( aNumOfNumA, aNumOfNumB, aNumA, aNumB, i, aBIdx ) + 1 );
	}

	for ( i = aBIdx + 1; i < aNumOfNumB + 1; i++ )
	{
		if ( aNumA[i] > curNum )
			*ret = MAX( *ret, jlis( aNumOfNumA, aNumOfNumB, aNumA, aNumB, aAIdx, i ) + 1 );
	}

	return *ret;
}

