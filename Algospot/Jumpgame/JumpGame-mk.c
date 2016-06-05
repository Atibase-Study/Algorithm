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

	int sNums[MAX_SIZE][MAX_SIZE] = { {0}, };
	int sCheck[MAX_SIZE][MAX_SIZE] = { {0}, };

	int tempX = 0;
	int tempY = 0;

	sCheck[0][0] = 1;


	scanf( "%d", &sSize );

	for ( i = 0; i < sSize; i++ )
	{
		for ( j = 0; j < sSize; j++ )
		{
			scanf( "%d", &sNums[i][j] );

			if ( sCheck[i][j] == 1 )
			{
				tempX = j + sNums[i][j];
				tempY = i + sNums[i][j];

				if ( tempX < sSize )
				{
					sCheck[i][tempX] = 1;
				}

				if ( tempY < sSize )
				{
					sCheck[tempY][j] = 1;
				}
			}
		}
	}

	if ( sCheck[sSize - 1][sSize - 1] == 1 )
		printf( "YES\n" );
	else
		printf( "NO\n" );
}
