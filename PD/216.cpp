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

int n;
double X[10], Y[10];

bool vis[10][1024];
int path[10][1024];
double memo[10][1024];

double dist( int i, int j ){
	
	double dx = X[i]-X[j];
	double dy = Y[i]-Y[j];

	return sqrt( dx*dx + dy*dy );
}

double TSP( int v, int mask ){
	if( mask == ( 1 << n )-1 ) return 0;
	if( vis[v][mask] ) return memo[v][mask];
		
	double mn = INF;
	for( int i = 0; i < n; i++ ){
		
		int next = 1 << i;
		if( !( mask & next ) ){
			double c = dist(v,i) + TSP( i, mask | next ) + 16.0;
			
			if( mn > c ){
				mn = c;
				path[v][mask] = i;
			}
		}
	}

	vis[v][mask] = true;
	return memo[v][mask] = mn;
}

void printPT( int v, int mask ){
	if( mask == ( 1 << n )-1 ) return;

	int i = path[v][mask];

	printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",X[v],Y[v],X[i],Y[i],dist(i,v)+16.0);

	printPT( i, mask | ( 1 << i ));
}

int main( void ){
	
	int cs = 0;
	while( scanf("%d", &n ) && n ){
	
		for( int i = 0; i < n; i++ ){
			scanf("%lf %lf", &X[i], &Y[i] );
		}

		int iniV;
		double mn = INF;
		memset( vis, false, sizeof(vis));
		for( int i = 0; i < n; i++ ){
			double route = TSP(i, 1 << i );

			if( mn > route ){
				mn = route;
				iniV = i;
			}
		}
		
		printf("**********************************************************\n");
		cs++;
		printf("Network #%d\n", cs );
		printPT( iniV, 1 << iniV );
		printf("Number of feet of cable required is %.2lf.\n", mn );
	}

    return 0;
}
