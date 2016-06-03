#include <stdio.h>
#include <string.h>

#define ALPHABET_NUM 26
#define NUMBER_NUM 11

#define MAX_STR 10 

typedef unsigned int uInt; 

char *gNum[NUMBER_NUM] =
{
	"zero\0",
	"one\0",
	"two\0",
	"three\0",
	"four\0",
	"five\0",
	"six\0",
	"seven\0",
	"eight\0",
	"nine\0",
	"ten\0"
};

uInt gAlphValue[NUMBER_NUM] = {0, };
int gCheck[NUMBER_NUM][ALPHABET_NUM + 1] = { 0, };

void func( void );

int cal( int a, int b, char op )
{
	int c = 0;
	if ( op == '+' )
	{
		c = a + b;
	}
	else if ( op== '-' )
	{		
		c = a - b;
	}
	else if ( op == '*' )
	{
		c = a * b;
	}
	else if ( op == '/' )
	{
		c = a / b;
	}

	return c;
}

int alphaToNum( char str )
{
	char a = 'a';

	return str - a + 1;
}

int findNum( char *str, int len )
{
	int i = 0;
	int j = 0;
	int alphNum = 0;
	int sNum = -1;

	int sCheck[ALPHABET_NUM + 1] = {0, };
	uInt sVal = 0;

	for ( i = 0; i < len; i++ )
	{
		alphNum = alphaToNum( str[i] );
		sCheck[alphNum]++;

		sVal = sVal + ( 1 << alphNum );
	}

	for ( i = 0; i < NUMBER_NUM; i++ )
	{
		if ( gAlphValue[i] - sVal == 0 )
		{
			sNum = i;
			for ( j = 0; j < ALPHABET_NUM + 1; j++ )
			{
				if ( sCheck[j] != gCheck[i][j] )
				{
					sNum = -1;
					break;
				}
			}

			break;
		}
	}

	return sNum;
}

void initializeAlphabet( void )
{
	int alphNum = 0;

	int i = 0;
	int j = 0;

	for ( i = 0; i < NUMBER_NUM; i++ )
	{
		for ( j = 0; j < MAX_STR; j++ )
		{
			if ( gNum[i][j] == '\0' )
			{
				break;
			}
			else
			{
				alphNum = alphaToNum( gNum[i][j] );
				gAlphValue[i] = gAlphValue[i] + ( 1 << alphNum );
				gCheck[i][alphNum]++;
			}
		}
	}
}

int main( void )
{
	int i = 0;
	int sNumTest = 0;
	
	initializeAlphabet();

	scanf( "%d", &sNumTest );
	for ( i = 0; i < sNumTest; i++ )
	{
		func();
	}
	
	return 0;
}

void func( void )
{
	int ALen = 0;
	int BLen = 0;
	int CLen = 0;

	char A[MAX_STR] = {0, };
	char B[MAX_STR] = {0, };
	char C[MAX_STR] = {0, };
	char op[1];
	char eq[1];

	int sANum = 0;
	int sBNum = 0;
	int sCNum = 0;
	int sDNum = 0;

	scanf( "%s %s %s %s %s", A, op, B, eq, C );

	ALen = strlen( A );
	BLen = strlen( B );
	CLen = strlen( C );

	sANum = findNum( A, ALen );
	sBNum = findNum( B, BLen );
	sCNum = findNum( C, CLen );
	
	sDNum = cal( sANum, sBNum, op[0] );

	if ( sDNum < 0 || sDNum > 10 || sCNum == -1 )
		printf( "No\n" );
	else if ( sDNum == sCNum )
		printf( "Yes\n" );
	else
		printf( "No\n" );
}
