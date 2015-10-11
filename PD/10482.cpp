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

int n;
int mset[40], amount;
bool vis[40][650][650];
int memo[40][650][650];

int pd( int i, int s1, int s2 ){
	if( i == n ) {
		int s3 = amount-(s1+s2);				
		return max(s3,max(s1,s2)) - min(s3,min(s1,s2));
	}
	
	if( vis[i][s1][s2] ) return memo[i][s1][s2];
	
	int pd1 = pd( i+1, s1 + mset[i], s2 );
	int pd2 = pd( i+1, s1, s2 + mset[i] );
	int pd3 = pd( i+1, s1, s2 );
	
	vis[i][s1][s2] = true;
	return memo[i][s1][s2] = min( pd1, min(pd2,pd3));
}

int main(void){ 	
	int t;
	scanf("%d", &t );
	
	for( int c = 1; c <= t; c++ ){
		scanf("%d", &n );
		memset( vis, false, sizeof(vis));
		
		amount = 0;
		for( int i = 0; i < n; i++ ){
			scanf("%d", &mset[i] );
			amount += mset[i];
		}
		
		printf("Case %d: %d\n", c, pd(0,0,0) );
	}
 	
    return 0;
} 
