#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_NUM 10

int checkInsomnia( int aNum )
{
	if ( aNum == aNum * 2 )
		return TRUE;

	return FALSE;
}

void countingSheep( int aNum )
{
	int i = 1;
	int sTempNum = 0;
	int sMod = 0;
	int sStartNum = 0;

	int sCheckNum[MAX_NUM] = { 0, };
	int sCheckSum = 0;

	scanf( "%d", &sStartNum );

	if ( checkInsomnia( sStartNum ) == TRUE )
	{
		printf( "Case #%d: INSOMNIA\n", aNum );
		return;
	}

	while ( sCheckSum < MAX_NUM )
	{
		sTempNum = sStartNum * i;
		while( sTempNum > 0 )
		{
			sMod = sTempNum % 10;
			if ( sCheckNum[sMod] < 1 )
			{
				sCheckNum[sMod] = 1;
				sCheckSum++;

				if ( sCheckSum == MAX_NUM )
					break;
			}

			sTempNum = sTempNum / 10; 
		}
		i++;
	}

	printf( "Case #%d: %d\n", aNum, sStartNum * ( i - 1 ) );
}

int main( void )
{
	int i = 0;
	int sNumTest = 0;

	scanf( "%d", &sNumTest );
	
	for ( i = 0; i < sNumTest; i++ )
	{
		countingSheep( i + 1 );
	}

	return 0;
}
