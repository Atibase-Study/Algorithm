#include <stdio.h>

#define MAX_TEST 50
#define MAX_N 500

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

void func()
{
	int i = 0;
	int j = 0;

	int sNumber[MAX_N] = {0, };
	int sLis[MAX_N] = {0, };

	int sNumOfNumber = 0;
	int sMax = 0;

	scanf( "%d", &sNumOfNumber );
	for ( i = 0; i < sNumOfNumber; i++ )
	{
		scanf( "%d", &sNumber[i] );
		sLis[i] = 1;
	}

	for ( i = 0; i < sNumOfNumber - 1; i++ )
	{
		for ( j = i + 1; j < sNumOfNumber; j++ )
		{
			if ( sNumber[i] < sNumber[j] )
			{
				if ( sLis[i] >= sLis[j] )
				{
					sLis[j] = sLis[i] + 1;
				}
				
				if ( sLis[j] > sMax )
					sMax = sLis[j];
			}
		}
	}

	printf( "%d\n", sMax );
}
