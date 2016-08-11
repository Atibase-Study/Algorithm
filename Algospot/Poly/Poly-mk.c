#include <stdio.h>

#define MOD 10000000
#define MAX_P 100
#define RESULT_IDX 0

/* 첫째줄의 도형 갯수와 둘째줄의 도형 갯수로 나오는 가지수 */
#define K( First, Second ) ( First + Second - 1 )

/* poly( N, First ) N 개의 정사각형을 포함하되, 첫 줄에
 First 개의 정사각형이 들어가는 폴리도미노의 수 */
int cache[MAX_P + 1][MAX_P + 1] = {0, };

void poly()
{
	int i = 0;
	int j = 0;
	int n = 0;

	int ret = 0;

	for ( n = 1; n <= MAX_P; n++ )
	{
		for ( i = 1; i <= n; i++ ) // First
		{
			if ( n != i )
			{
				for ( j = 1; j <= n - i; j++ ) // Second
				{
					cache[n][i] += K( i, j ) * cache[n - i][j];
					cache[n][i] %= MOD;
				}
			}
			else
			{
				cache[n][i] = 1;

			}
			cache[n][RESULT_IDX] += cache[n][i];
			cache[n][RESULT_IDX] %= MOD;
		}
	}
}


int main( void )
{
	int i = 0;
	int sNumOfTest = 0;
	int sNumOfPoly = 0;

	scanf( "%d", &sNumOfTest );
		
	poly();
	for ( i = 0; i < sNumOfTest; i++ )
	{
		scanf( "%d", &sNumOfPoly );
		printf( "%d\n", cache[sNumOfPoly][RESULT_IDX] );
	}

	return 0;
}
