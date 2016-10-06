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

typedef struct
{
	int a,b;
} jalan;

int T,N,i,x,y,z,state;
int par[1010];
bool visited[1010];
pair<LL,LL> city[1010];
vector<jalan> edge;
LL R,R2,dis[1010][1010];
double road,railway;

void ff(int now)
{
	for(int i=0;i<N;i++) if((now!=i)&&(!visited[i])&&(dis[now][i]<=R2))
	{
		visited[i]=true;
		ff(i);
	}
}

bool cf(jalan i,jalan j)
{
	if(dis[i.a][i.b]!=dis[j.a][j.b]) return(dis[i.a][i.b]<dis[j.a][j.b]);
	return(i.a<j.a);
}

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti=i;
		while(ti!=par[ti]) ti=par[ti];
		par[i]=ti;
	} return(par[i]);
}

bool setunion(int i,int j)
{
	if(find(i)!=find(j))
	{
		par[par[i]]=par[j];
		return(false);
	}return true;
}

void kruskal()
{
	memset(par,-1,sizeof(par));
	road=railway=0;
	int tot,i;
	for(i=0;i<edge.size();i++) if(!setunion(edge[i].a,edge[i].b))
	{
		LL ans=dis[edge[i].a][edge[i].b];
		if(ans<=R2) road+=sqrt((double)ans); else railway+=sqrt((double)ans);
		tot++;
		if(tot+1==N) break;
	}
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %lld",&N,&R);R2=R*R;
		for(x=0;x<N;x++) scanf("%lld %lld",&city[x].fi,&city[x].se);
		
		edge.clear();
		for(x=0;x+1<N;x++)
			for(y=x+1;y<N;y++)
			{
				LL dx=city[x].fi-city[y].fi;
				LL dy=city[x].se-city[y].se;
				
				dis[x][y]=dis[y][x]=dx*dx+dy*dy;
				edge.pb((jalan){x,y});
			}
		
		state=0;
		memset(visited,false,sizeof(visited));
		for(x=0;x<N;x++) if(!visited[x])
		{
			state++;
			visited[x]=true;
			ff(x);
		}
		
		sort(edge.begin(),edge.end(),cf);
		kruskal();
		
		printf("Case #%d: %d %d %d\n",i,state,(int)floor(road+0.5),(int)floor(railway+0.5));
	}
	return 0;
}

