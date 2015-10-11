#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
                           
using namespace std;
                           
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
                  
#define EPS 1e-6
#define eq(x, y) (fabs((x) - (y)) < EPS)
#define lt(x, y) ((x) < (y) && !eq(x, y))
#define gt(x, y) ((x) > (y) && !eq(x, y))
#define lteq(x, y) ((x) < (y) || eq(x, y))
#define gtqe(x, y) ((x) > (y) || eq(x, y))           
 
#define INF (1 << 25)
#define P 1000000009
#define MAX 910
#define MAXN 50010

typedef long long int lli;
typedef pair< lli, bool > llib;
typedef pair< lli, lli > pll;
typedef pair< int, int > ii;

bool vis[305][105][55];
int memo[305][105][55], n[3], money;

int dp( int coke, int j, int k ){
	if( !coke ) return 0;
	if( vis[coke][j][k] ) return memo[coke][j][k];
	
	int mn = INF;
	if( k >= 1 ){
		mn = dp( coke-1, j, k-1 ) + 1;
	}
	
	int i = money-( (n[2]-k)*10 + (n[1]-j)*5 );
	if( j >= 2 ){
		mn = min( mn, dp( coke-1,j-2, k ) + 2 );
	}
	
	if( k >= 1 && i >= 3 ){		
		mn = min( mn, dp( coke-1, j+1, k-1 ) + 4 );
	}
	
	if( j >= 1 && i >= 3 ){		
		mn = min( mn, dp( coke-1, j-1, k ) + 4 );
	}	
	
	if( i >= 8 ){
		mn = min( mn, dp( coke-1, j, k ) + 8 );
	}
		
	vis[coke][j][k] = true;
	return memo[coke][j][k] = mn;
}

int main(void){ 	

	int coke, t;
	scanf("%d", &t );
	
	while(t--){
		scanf("%d %d %d %d", &coke, &n[0],&n[1],&n[2]);		
		memset(vis,false,sizeof(vis));			
		money = n[0] + n[1]*5 + n[2]*10;
		printf("%d\n", dp(coke,n[1],n[2]));
	}
 	
    return 0;
} 
	
