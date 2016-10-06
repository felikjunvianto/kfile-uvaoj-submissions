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

vector<string> list;
string ans;
char masuk[30];
vector<int> adjlist[30];
bool ada[30];
int x,y,small,indegree[30];

void toposort(int x)
{
	ans+=(char)(x+'A');
	for(int i=0;i<adjlist[x].size();i++)
	{
		int next=adjlist[x][i];
		indegree[next]--;
		if(indegree[next]==0) toposort(next);
	}
}

int main()
{
	memset(ada,false,sizeof(ada));
	while(1)
	{
		scanf("%s",masuk);
		if(masuk[0]=='#') break;
		
		small=strlen(masuk);
		for(x=0;x<small;x++) ada[masuk[x]-'A']=true;
		list.pb(masuk);
	}
	
	memset(indegree,0,sizeof(indegree));
	
	for(x=0;x<list.size()-1;x++)
	{
		small=min(list[x].size(),list[x+1].size());
		for(y=0;y<small;y++) if(list[x][y]!=list[x+1][y])
		{
			indegree[list[x+1][y]-'A']++;
			adjlist[list[x][y]-'A'].pb(list[x+1][y]-'A');
			break;
		}
	}
	
	for(x=0;x<30;x++) if((indegree[x]==0)&&(ada[x])) break;
	toposort(x);
	printf("%s\n",ans.c_str());
	return 0;
}

