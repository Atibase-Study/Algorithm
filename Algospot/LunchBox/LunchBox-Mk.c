#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTICIPANT 10000

void func(void);

typedef struct timeStruct
{
	int M;
	int E;
} timeStruct;

/* E 내림차순, E 가 같다면 M 오름차순 정렬 */
int compare( const void *a, const void *b )
{
	timeStruct * A = (timeStruct*)a;
	timeStruct * B = (timeStruct*)b;

	if ( A->E > B->E )
	{
		return -1;
	}
	else if ( A->E == B->E )
	{
		if ( A->M < B->M )
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}

	return 1;

}

int main()
{
	int i = 0;
	int sNumTest = 0;

	scanf( "%d", &sNumTest );
	for ( i = 0; i < sNumTest; i++ )
	{
		func();
	}

	return 0;
}

void func( void )
{
	int i = 0;
	
	int sTemp = 0;
	int sNumMan = 0;
	int sSum = 0;
	int sMax = 0;

	timeStruct sTimeStruct[MAX_PARTICIPANT];

	scanf( "%d", &sNumMan );
	for ( i = 0; i < sNumMan; i++ )
	{
		scanf( "%d", &( sTimeStruct[i].M ) );
	}

	for ( i = 0; i < sNumMan; i++ )
	{
		scanf( "%d", &( sTimeStruct[i].E ) );
	}
	
	qsort( sTimeStruct, sNumMan, sizeof( timeStruct ), compare );

	for ( i = 0; i < sNumMan; i++ )
	{
		sSum += sTimeStruct[i].M;
		sTemp = sSum + sTimeStruct[i].E;

		if ( sTemp > sMax )
			sMax = sTemp;
	}

	printf( "%d\n", sMax );
}

