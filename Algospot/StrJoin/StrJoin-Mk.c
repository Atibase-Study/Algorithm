#include <stdio.h>
#include <stdlib.h>

#define MAX_TEST 50
#define MAX_LEN 1000
#define MAX_STRING 100

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

	int sTempInput;
	int sNumString = 0;

	int sSum = 0;
	int sMax = 0;
	int sStrLens[ ( MAX_LEN + 1 ) * ( MAX_LEN ) / 2 + 1] = {0, };

	int sRemainString = 0;
	int sSumA = 0;
	int sSumB = 0;

	scanf( "%d", &sNumString );
	for ( i = 0; i < sNumString; i++ )
	{
		scanf( "%d", &sTempInput );
		sStrLens[sTempInput] += 1;

		if ( sTempInput > sMax )
			sMax = sTempInput;
	}

	i = 0;
	sRemainString = sNumString;

	while( sRemainString > 1 )
	{
		sSumA = 0;
		sSumB = 0;
		while ( i < sMax + 1 )
		{
			if ( sStrLens[i] > 0 )
			{
				if ( sSumA == 0 )
				{
					sSumA = i;
					sStrLens[i]--;
				}
				else
				{
					sSumB = i;
					sStrLens[i]--;
					break;
				}
			}
			else
			{
				i++;
			}
		}

		sSum += sSumA + sSumB;
		sStrLens[sSumA + sSumB]++;
		sRemainString--;

		if ( sSumA + sSumB > sMax )
			sMax = sSumA + sSumB;
	}

	printf( "%d\n", sSum );
}
