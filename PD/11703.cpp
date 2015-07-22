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

int memo[1000010];

int main( void ){

	memo[0] = 1;
	for( int i = 1; i <= 1000000; i++ ){
		int idx0 = i - sqrt(i);
		int idx1 = log(i);
		int idx2 = i*sin(i)*sin(i);

		memo[i] = ( (memo[idx0]%1000000) + (memo[idx1]%1000000) + (memo[idx2]%1000000) ) % 1000000;
	}

	int n;
	while( scanf("%d", &n ) && n != -1 ){
		printf("%d\n", memo[n] );
	}

    return 0;
}

