#include <stdio.h>

#define MAX_TEST 100
#define MAX_N 6
#define MAX_M 6
#define MAX_MIN 36

#define MAX_ROUTE 1000000007

void func( void );
int calRoute( int (*sMap)[MAX_M], int N, int M );
int diff( int destX, int destY );
int isPossible( int destX, int destY, int destMin );
int nextRoute( int (*sMap)[MAX_M], int (*sCheck)[MAX_M], int destX, int destY, int destMin, int N, int M );

int main( void )
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
	int j = 0;

	int N = 0;
	int M = 0;
	int sMap[MAX_N][MAX_M] = { {0}, };

	scanf( "%d %d", &N, &M );
	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < M; j++ )
		{
			scanf( "%d", &( sMap[i][j] ) );
		}
	}

	calRoute( sMap, N, M );
}

int calRoute( int (*sMap)[MAX_M], int N, int M )
{
	int i = 0;
	int j = 0;
	int sSum = 0;

	int sIsPossible = 0;
	int sCheck[MAX_N][MAX_M] = { {0}, };
	int destX = M - 1;
	int destY = N - 1;
	int startMin = 0; // start minute
	int destMin = sMap[destY][destX]; // dest minute
	int sMinDiff = 0;

	destMin = sMap[destY][destX];

	sIsPossible = isPossible( destX, destY, destMin );
	if ( sIsPossible == 1 )
	{
		sSum += nextRoute( sMap, sCheck, destX, destY - 1, destMin - 1, N, M ); //UP
		sSum += nextRoute( sMap, sCheck, destX - 1, destY, destMin - 1, N, M ); //LEFT

		printf( "%d\n", sSum % MAX_ROUTE );
	}
	else
	{
		printf( "0\n" );
	}
}

int isPossible( int destX, int destY, int destMin )
{
	int minDiff = 0;

	minDiff = diff( destX, destY );

	if ( ( minDiff <= destMin ) && ( ( destMin - minDiff ) % 2 ) == 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int diff( int destX, int destY )
{
	return destX + destY;
}

int nextRoute( int (*sMap)[MAX_M], int (*sCheck)[MAX_M], int destX, int destY, int destMin, int N, int M )
{
	int sIsPossible = 0;
	int sSum = 0;

	if ( sCheck[destY][destX] == 1 ) // 이미 한번 온 길
	{
		return 0;
	}

	if ( ( destX == 0 ) && 
		 ( destY == 0 ) && 
		 ( destMin == 0 ) ) // 출발점 도착
	{
		return 1;
	}

	if ( ( destX >= M ) || 
		 ( destY >= N ) || 
		 ( destX < 0 ) || 
		 ( destY < 0 ) || 
		 ( destMin < 0 ) ) // 가로 세로 한계를 넘어섬
	{
		return 0;
	}

	if ( ( sMap[destY][destX] > -1 ) && 
		 ( sMap[destY][destX] != destMin ) ) // 기록된 정보와 다르다
	{
		return 0;
	}

	sIsPossible = isPossible( destX, destY, destMin );
	if ( sIsPossible == 1 )
	{
		sCheck[destY][destX] = 1;

		sSum += nextRoute( sMap, sCheck, destX, destY - 1, destMin - 1, N, M ); //UP
		sSum += nextRoute( sMap, sCheck, destX, destY + 1, destMin - 1, N, M ); //Down
		sSum += nextRoute( sMap, sCheck, destX - 1, destY, destMin - 1, N, M ); //Left
		sSum += nextRoute( sMap, sCheck, destX + 1, destY, destMin - 1, N, M ); //Right
	}
	else
	{
		return 0; // 도달할 수 없는 경로
	}

	sCheck[destY][destX] = 0;

	return sSum;
}


