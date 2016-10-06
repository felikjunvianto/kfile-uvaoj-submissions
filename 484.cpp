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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

vector<int> bil;
vector<bool> visited;
int x,y,total;
char c;

int main()
{
	while(scanf("%d",&x)!=EOF)
	{
		bil.pb(x);
		visited.pb(false);
	}
	
	for(x=0;x<bil.size();x++) if(!visited[x])
	{
		visited[x]=true;
		total=1;
		for(y=x+1;y<bil.size();y++) if((!visited[y])&&(bil[y]==bil[x]))
		{
			total++;
			visited[y]=true;
		}
		printf("%d %d\n",bil[x],total);
	}
	return 0;
}

