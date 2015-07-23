#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
using namespace std;
 
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

#define INF 200000000
 
typedef unsigned long long lli;

int Q[25], m;
double P[25];
double memo[22][120];
bool vis[22][120];

double S( int i, int k ){
	if( k <= 0 ) return 0;
	if( i > m ) return INF;

	if( vis[i][k] ) return memo[i][k]; 

	vis[i][k] = true;

	return memo[i][k] = min( S(i+1,k), S( i, k - Q[i] ) + P[i] );
}

int main( void ){

	int cs = 0;
	while( cin >> P[0] >> m ){
		cin.ignore();
		
		Q[0] = 1;
		for( int i = 1; i <= m; i++ ){
			cin >> Q[i] >> P[i];
			cin.ignore();
		}
		
		string k, num;
		getline(cin,k);

		cs++;
		printf("Case %d:\n", cs);
		memset(vis,false,sizeof(vis));
		for( size_t j = 0; j < k.size(); j++ ){
			
			if( k[j] == ' ' ){
				int qtd = atoi( num.c_str() );
				printf("Buy %d for $%.2lf\n", qtd, S( 0, qtd ) );
				num.clear();
			}
			else{
				num.push_back(k[j]);
			}
		}

		int qtd = atoi( num.c_str() );
		printf("Buy %d for $%.2lf\n", qtd, S( 0, qtd ) );
	}

    return 0;
}
