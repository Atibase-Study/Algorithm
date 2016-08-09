#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define MAX_K 5000000
#define MAX_N 50000000

/* 2^32 로 mod 연산을 해야하지만 unsigned int 이므로 mod 하지 않아도 된다. */
#define MAKE_A( A ) ( A * 214013 + 2531011 ) 
#define MAKE_SIGNAL( A ) ( A % 10000 + 1 )

void itesFunc( void )
{
	int i = 0;
	int sNumOfSignal = 0;
	
	uint32_t sTotalSum = 0;
	uint32_t sResultSum = 0;

	uint32_t sInputSignal = 1983;
	uint32_t sSignal = 0;

	uint32_t sPrevInput = 1983;
	uint32_t sPrevSignal = 0;

	int sResult = 0;

	scanf( "%d %d", &sResultSum, &sNumOfSignal );

	for ( i = 1; i <= sNumOfSignal; i++ )
	{
		sSignal = MAKE_SIGNAL( sInputSignal );
		sInputSignal = MAKE_A( sInputSignal );

		sTotalSum += sSignal;
		
		while( sTotalSum > sResultSum )
		{
			sPrevSignal = MAKE_SIGNAL( sPrevInput );
			sPrevInput = MAKE_A( sPrevInput );
			sTotalSum -= sPrevSignal;
		}

		if ( sTotalSum == sResultSum )
		{
			sResult+= 1;
		}
	}

	printf( "%d\n", sResult );
}

int main( void )
{
	int i = 0;

	int sNumOfTest = 0;

	scanf( "%d", &sNumOfTest );
	for ( i = 0; i < sNumOfTest; i++ )
	{
		itesFunc();
	}

	return 0;
}
