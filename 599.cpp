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

int T,len,x,tree,acorn,sum;
vector<int> adjlist[30];
bool visited[30];
char msk[111];

void ff(int now)
{
	for(int i=0;i<adjlist[now].size();i++)
		if(!visited[adjlist[now][i]])
		{
			visited[adjlist[now][i]]=true;
			sum++;
			ff(adjlist[now][i]);
		}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(x=0;x<30;x++) adjlist[x].clear();
		while(1)
		{
			scanf("%s",msk);
			if(msk[0]=='*') break;
			
			adjlist[msk[1]-'A'].pb(msk[3]-'A');
			adjlist[msk[3]-'A'].pb(msk[1]-'A');
		}
		
		scanf("%s",msk);len=strlen(msk);
		memset(visited,false,sizeof(visited));
		tree=acorn=0;
		for(x=0;x<len;x+=2) if(!visited[msk[x]-'A'])
		{
			visited[msk[x]-'A']=true;
			sum=1;
			ff(msk[x]-'A');
			
			if(sum==1) acorn++; else tree++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
	}
	return 0;
}

