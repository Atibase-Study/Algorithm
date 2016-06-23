#include <stdio.h>
#include <string.h>

#define MAX_TEST 10
#define MAX_NAME_NUM 50
#define MAX_NAME_LEN 100

void func( void );
int matching( const char *aStr, const char *aStrOrig, int aEndIdx ); 
/* return -1 not matched return 1  correct matching*/

int main( void )
{
	int sTestNum = 0;
	int i = 0;

	scanf( "%d", &sTestNum );
	for ( i = 0; i < sTestNum; i++ )
	{
		func();
	}
}

void func( void )
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int sNumStr = 0;

	int sOrigLen = 0;
	int sLen = 0;
	char sStrOrig[MAX_NAME_LEN] = {0, };
	char sStr[MAX_NAME_NUM][MAX_NAME_LEN];

	scanf( "%d", &sNumStr );
	scanf( "%s", sStrOrig );

	int sOrigLen = strlen( sStrOrig );
	for ( i = 0; i < sNumStr; i++ )
	{
		scanf( "%d", sStr[i] );
	}

	for ( i = 0; i < sNumStr; i++ )
	{
		sLen = strlen( sStr[i] );
	}

}
