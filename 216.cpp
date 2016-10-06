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
#define INF 1000000000

using namespace std;

double dp[10][1<<8],dis[10][10],ans;
bool visited[10][1<<8];
PII path[10][1<<8],koor[10];
int T,x,y,z,i;

double solve(int now, int state)
{
	if(state+1==1<<T) return(0.00);
	if(visited[now][state]) return(dp[now][state]);
	
	double &ret = dp[now][state] = INF,temp;
	visited[now][state]=true;
	for(int i=0;i<T;i++) if(!(state&(1<<i)))
	{
		temp=dis[now][i]+solve(i,state+(1<<i));
		if(ret>temp)
		{
			ret=temp;
			path[now][state]=mp(i,state+(1<<i));
		}
	}
	return(ret);
}

int main()
{
	i=1;
	while(1)
	{
		scanf("%d",&T);
		if(!T) break;
		
		for(x=0;x<T;x++) scanf("%d %d",&koor[x].fi,&koor[x].se);
		for(x=0;x<T;x++)
			for(y=x+1;y<T;y++)
			{
				double dx=(double)(koor[x].fi-koor[y].fi);
				double dy=(double)(koor[x].se-koor[y].se);
				dis[x][y]=dis[y][x]=sqrt(dx*dx+dy*dy)+16.00;
			}
			
		memset(visited,false,sizeof(visited));
		ans=(double)INF;
		z=0;
		for(x=0;x<T;x++) if(solve(x,1<<x)<ans)
		{
			ans=solve(x,1<<x);
			z=x;
		}
		
		printf("**********************************************************\n");
		printf("Network #%d\n",i++);
		int next,now=z,state=1<<z;
		
		while(state+1!=1<<T)
		{
			next=path[now][state].fi;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
				koor[now].fi,koor[now].se,koor[next].fi,koor[next].se,dis[now][next]);
			now=next;
			state+=(1<<next);
		}
		printf("Number of feet of cable required is %.2lf.\n",ans);
	}
	return 0;
}

