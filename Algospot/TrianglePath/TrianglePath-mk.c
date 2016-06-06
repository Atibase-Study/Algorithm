#include <stdio.h>

#define MAX_TEST 50
#define MAX_SIZE 100

void func( void );

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

	int sSize = 0;
	int sTemp = 0;
	int sTempL = 0;
	int sTempR = 0;

	int sInput[MAX_SIZE + 1] = {0, };
	int sSum[MAX_SIZE + 1] = {0, };

	int sMax = 0;

	scanf( "%d", &sSize );

	scanf( "%d", &sInput[0] );
	sSum[0] = sInput[0];
	for ( i = 1; i < sSize; i++ )
	{
		sTempL = sSum[0];
		sTempR = sSum[1];
		for ( j = 0; j <= i; j++ )
		{
			scanf( "%d", &sInput[j] );
			if ( j == 0 )
			{
				sSum[0] = sTempL + sInput[0];
			}
			else
			{
				if ( sTempL > sTempR )
				{
					sSum[j] = sTempL + sInput[j];
				}
				else
				{
					sSum[j] = sTempR + sInput[j];
				}

				sTempL = sTempR;
				sTempR = sSum[j + 1];
			}

			if ( sSum[j] > sMax )
				sMax = sSum[j];
		}
	}

	printf( "%d\n", sMax );

}

