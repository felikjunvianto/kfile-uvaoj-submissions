#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long

using namespace std;

int N,x,y,z;
PDD org[20];
char masuk[30];
double dp[70000],adjmat[20][20];
bool visited[70000];

double solve(int conf)
{
	if(conf==(1<<N)-1) return(0.0);
	if(visited[conf]) return(dp[conf]);
	
	visited[conf]=true;
	double &ret=dp[conf]=50000.0;
	for(int x=0;x<N;x++) if((conf&(1<<x))==0)
		for(int y=0;y<N;y++) if(((conf&(1<<y))==0)&&(y!=x))
			ret=min(ret,adjmat[x][y]+solve(conf|(1<<x)|(1<<y)));
	
	return(ret);
}

int main()
{
	z=1;
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;
		
		N*=2;
		for(x=0;x<N;x++) scanf("%s %lf %lf",masuk,&org[x].fi,&org[x].se);
		for(x=0;x<N;x++)
			for(y=x;y<N;y++)
			{
				double dx=org[x].fi-org[y].fi;
				double dy=org[x].se-org[y].se;
				adjmat[x][y]=adjmat[y][x]=sqrt(dx*dx+dy*dy);
			}
			
		memset(visited,false,sizeof(visited));
		
		printf("Case %d: %.2lf\n",z++,solve(0));
	}
	return 0;
}

