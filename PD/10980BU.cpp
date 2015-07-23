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

void S(){

	for( int i = m; i >= 0; i-- ){
		
		for( int j = 0; j <= 100; j++ ){
			
			if( i == m ){
				int qtd = j / Q[i];

				if( qtd*Q[i] < j ) qtd++;

				memo[i][j] = qtd*P[i];
			}
			else{
				double maisDoMesmo = P[i];

				if( j >= Q[i] ){	
					maisDoMesmo += memo[i][j-Q[i]];
				}

				memo[i][j] = min( memo[i+1][j], maisDoMesmo );
			}
		}		
	}	
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

		S();
		
		string k, num;
		getline(cin,k);
		
		cs++;
		printf("Case %d:\n", cs);
		for( size_t j = 0; j < k.size(); j++ ){
			
			if( k[j] == ' ' ){
				int qtd = atoi( num.c_str() );
				printf("Buy %d for $%.2lf\n", qtd, memo[0][qtd] );
				num.clear();
			}
			else{
				num.push_back(k[j]);
			}
		}

		int qtd = atoi( num.c_str() );
		printf("Buy %d for $%.2lf\n", qtd, memo[0][qtd] );
	}

    return 0;
}
