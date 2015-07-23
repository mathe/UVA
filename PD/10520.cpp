#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
using namespace std;
 
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>

#define INF 200000000
 
typedef unsigned long long lli;

lli memo[30][30];

int main( void ){

	int n;
	while( scanf("%d", &n ) != EOF ){
		memset(memo,0,sizeof(memo));

		scanf("%llu", &memo[n][1] );
	
		for( int i = n; i >= 0; i-- ){

			for( int j = 1; j <= n; j++ ){
				
				if( i >= j ){
					lli mx0 = 0;
					for( int k = 1; k < j; k++ ){
						mx0 = max(mx0, memo[i][k]+memo[n][k] );
					}

					lli mx1 = 0;
					for( int k = i+1; k <= n; k++ ){
						mx1 = max(mx1, memo[k][1]+memo[k][j] );
					}

					//instead of just memo[i][j] = mx0+mx1 as the problem says.
					memo[i][j] = max(memo[i][j],mx0+mx1);
				}
				else{
					for( int k = i; k < j; k++ ){
						memo[i][j] = max(memo[i][j], memo[i][k] + memo[k+1][j] );
					}
				}
			}
		}

		printf("%llu\n", memo[1][n] );
	}

    return 0;
}
