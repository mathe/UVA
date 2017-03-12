/*Binary search the answer and bipartite matching.*/
#include <bits/stdc++.h>
    
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define sz(v) ((int)v.size())   
#define rad(a) a * PI / 180  

typedef long long ll;
typedef vector<int> vi;	
typedef pair<int,int> ii;
typedef pair<double,double> dd;

const int MAX = 51;
const int P = 1000000007;
const double INF = 1000000001;
const double EPS = 1e-7;
const double PI = 3.14159265358979;

int cmpf(double a,double b){
    if(fabs(a-b) < EPS) return 0;
    if(a < b) return -1;
    return 1;
}

double dist(dd A,dd B){
    double dx = A.f-B.f;
    double dy = A.s-B.s;
    return sqrt(dx*dx + dy*dy);
}

bool cmp(double a,double b){
    return (cmpf(a,b) == -1);
}

int T,n,m,k,d;
dd hole[MAX], gopher[MAX];
double graph[MAX][MAX],ans[MAX*MAX];
void generate(){
    d = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            ans[d++] = graph[i][j] = dist(gopher[i],hole[j]);
}

bool vis[MAX];
int matching[MAX];
bool dfs(int v,double bound){
    if(vis[v]) return false;
    vis[v] = true;
    for(int j = 0; j < n; j++){
        if(cmpf(graph[v][j],bound) <= 0 && (matching[j] == -1 || dfs(matching[j],bound))){
            matching[j] = v;
            return true;
        }
    }
    return false;
}

bool check(double bound){
    int matched = 0;
    memset(matching,-1,sizeof(matching));
    for(int i = 0; i < m; i++){
        memset(vis,false,sizeof(vis));
        matched += dfs(i,bound);
    }
    return (matched >= m-k);
}

double search(){
    double a = 0;
    int lo = 0,hi = d-1;
    while(lo <= hi){
        int mid = (lo+hi) >> 1;
        if(check(ans[mid])) a = ans[mid], hi = mid-1;        
        else lo = mid+1;
    }
    return a;
}

int main (){
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d %d",&m,&n,&k);
        for(int i = 0; i < m; i++)
             scanf("%lf %lf",&gopher[i].f,&gopher[i].s);        
        for(int i = 0; i < n; i++)
            scanf("%lf %lf",&hole[i].f,&hole[i].s);        
        printf("Case #%d:\n",t);
        if(n < m-k){
            printf("Too bad.\n\n");
            continue;
        }
        generate();
        sort(ans,ans+d,cmp);   
        printf("%.3lf\n\n",search());
    }
    return 0;
}
