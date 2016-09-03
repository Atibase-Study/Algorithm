#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

#define TRUE 1
#define FALSE 0

void Pancakes( int aNum )
{
	int i = 0;
	int sLen = 0;
	int sIsCurrentMinus = FALSE;

	int sNumOfMinus = 0;
	char sStr[MAX_LEN] = { 0, };

	int sResult = 0;

	scanf( "%s", sStr );
	sLen = strlen( sStr );

	for ( i = 0; i < sLen; i++ )
	{
		if ( sStr[i] == '+' )
		{
			sIsCurrentMinus = FALSE;
		}
		else
		{
			if ( sIsCurrentMinus == FALSE )
			{
				sNumOfMinus++;
			}

			sIsCurrentMinus = TRUE;
		}
	}
	
	sResult = sNumOfMinus * 2;
	if ( sStr[0] == '-' )
	{
		sResult = sResult - 1;
	}

	printf( "Case #%d: %d\n", aNum, sResult );
}


int main( void )
{
	int i = 0;
	int sNumTest = 0;

	scanf( "%d", &sNumTest );

	for( i = 0; i < sNumTest; i++ )
	{
		Pancakes( i + 1 );
	}

	return 0;
}
