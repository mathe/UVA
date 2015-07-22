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

int n;
int rod[31];
int C[31][21][2];
int choice[301][301][2];
int memo[31][301][301];

int pd( int k, int ncpc, int bcew ){
	if( !ncpc && !bcew ) return 0;
	if( k == n ) return INF;

	if( memo[k][ncpc][bcew] != -1 ) return memo[k][ncpc][bcew];

	int mn = INF;
	for( int i = 0, j = rod[k]; i <= rod[k]; i++, j-- ){
	
		if( ncpc >= i && bcew >= j ){	
			int nxt = pd( k+1, ncpc - i, bcew - j )+C[k][i][0]+C[k][j][1];

			if( mn > nxt ){
				mn = nxt;
				choice[ncpc][bcew][0] = i;
				choice[ncpc][bcew][1] = j;
			}
		}
		else if( ncpc >= i ){
			
			int nxt = pd( k+1, ncpc - i, bcew ) + C[k][i][0];

			if( mn > nxt ){
				mn = nxt;
				choice[ncpc][bcew][0] = i;
				choice[ncpc][bcew][1] = 0;
			}
		}
		else if( bcew >= j ){
			int nxt = pd( k+1, ncpc, bcew - j )+C[k][j][1];

			if( mn > nxt ){
				mn = nxt;
				choice[ncpc][bcew][0] = 0;
				choice[ncpc][bcew][1] = j;
			}
		}
	}

	return memo[k][ncpc][bcew] = mn;
}

void printPT( int k, int t1, int t2 ){
	if( k == n ) return;
	if( k ) printf(" ");
	printf("%d", choice[t1][t2][0] );
	printPT( k+1, t1-choice[t1][t2][0], t2-choice[t1][t2][1] );
}

int main( void ){

	int t1, t2;
	while( scanf("%d %d", &t1, &t2 ) && ( t1 | t2 ) ){
			
		scanf("%d", &n );

		for( int i = 0; i < n; i++ ){
			scanf("%d", &rod[i] );

			C[i][0][0] = 0;
			for( int j = 1; j <= rod[i]; j++ ){
				scanf("%d", &C[i][j][0] );
			}

			C[i][0][1] = 0;
			for( int j = 1; j <= rod[i]; j++ ){
				scanf("%d", &C[i][j][1] );
			}
		}
		
		memset(memo,-1,sizeof(memo));

		printf("%d\n", pd(0,t1,t2) );
		printPT(0,t1,t2);
		printf("\n\n");
	}

    return 0;
}

