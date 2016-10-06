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

int N,T,len,x,y,i,now;
char msk[50];
map<int,bool> visited;
bool happy;

int main()
{
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&now);
		printf("Case #%d: %d is ",i,now);
		
		visited.clear();
		visited[now]=true;
		
		happy=false;
		while(1)
		{
			if(now==1)
			{
				happy=true;
				break;
			}
			
			sprintf(msk,"%d",now);len=strlen(msk);now=0;
			for(x=0;x<len;x++)
			{
				y=msk[x]-'0';
				now+=y*y;
			}
			
			if(visited.find(now)!=visited.end()) break; else visited[now]=true;
		}
		
		printf("%s\n",happy?"a Happy number.":"an Unhappy number.");
	}
	return 0;
}

