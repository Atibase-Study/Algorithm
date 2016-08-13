#include <stdio.h>

#define MAX_TEST_CASE 60
#define MAX_PRESENT 100000
#define MAX_CHILDREN 100000
#define MAX_DOLL 100000

#define MAX_DIV 20091101

void divideChildren( const int aPresent, const int aChildren );

void Choice( const int  aPresent,
             const int *aRemainder,
                   int *aFind,
                   int *aEdgeSum,
                   int *aEdgeIdx );

int main( void )
{
    int i = 0;

    int sTestCase = 0;
    int sPresent = 0;
    int sChildren = 0;

    scanf( "%d", &sTestCase );
    for ( i = 0; i < sTestCase; i++ )
    {
        scanf( "%d %d", &sPresent, &sChildren );
        divideChildren( sPresent, sChildren );
    }

    return 0;
}

void Choice( const int  aPresent,
             const int *aRemainder,
                   int *aFind,
                   int *aEdgeSum,
                   int *aEdgeIdx )
{
    int i = 0;
    int sStartIdx = 0;
    int sOneChoice = 0;
    int sOtherChoice = 0;
    int sAddSum = 1;

    int sMax = 0;
    int sSum[MAX_PRESENT] = {0, };

    for( i = 0; i < aPresent; i++ )
    {
        sStartIdx = aFind[aRemainder[i]];
        if ( ( aRemainder[i] == 0 ) ||
                ( sStartIdx > -1 ) )
        {
            if ( sStartIdx > -1 )
            {
                sAddSum = aEdgeSum[sStartIdx] + 1;
                sSum[i] = sSum[sStartIdx] + 1;
            }
            else /* sStartIdx == -1 인 경우 즉 합계가 4의 배수인 집합이 처음 나왔을 때 */
            {
                if ( i > 0 )
                {
                    sSum[i] = sSum[i - 1];
                }
                else
                {
                    sSum[i] = 1;
                }

                sAddSum = 1;

            }

            sOneChoice += sAddSum;
            sOneChoice = sOneChoice % MAX_DIV;
            aEdgeSum[i] = sAddSum;

            aEdgeIdx[i] = sStartIdx + 1;

            if ( sSum[i] > sMax )
                sMax = sSum[i];
            else
                sSum[i] = sMax;
        }
        else
        {
            sSum[i] = sMax;
        }

        aFind[aRemainder[i]] = i;
    }

    sOtherChoice = sMax;

    printf( "%d %d\n", sOneChoice, sOtherChoice );
}

void divideChildren( const int aPresent, const int aChildren )
{
    int i = 0;
    int sTemp = 0;
    int sInputTemp = 0;

    const int sPresent = aPresent;
    const int sChildren = aChildren;

    int sRemainder[MAX_CHILDREN] = {0, };
    int sFind[MAX_CHILDREN] = {0, };
    int sEdgeSum[MAX_PRESENT] = {0, };
    int sEdgeIdx[MAX_PRESENT] = {0, };

    int sOneChoice = 0;
    int sOtherChoice = 0;

    for( i = 0; i < sPresent; i++ )
    {
        scanf( "%d", &sInputTemp );
        sRemainder[i] += ( sTemp + sInputTemp ) % sChildren;
        sTemp = sRemainder[i];

        sFind[i] = -1;
        sEdgeIdx[i] = -1;
    }

    Choice( sPresent, sRemainder, sFind, sEdgeSum, sEdgeIdx );
}
