#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

vector<int> teman[30100];
int x,y,z,temp,maks,t,orang,relasi;
bool visited[300100];

void ff(int t)
{
	int x;
	for(x=0;x<teman[t].size();x++) if((!visited[teman[t][x]]))
	{
		temp++;
		visited[teman[t][x]]=true;
		ff(teman[t][x]);
	}
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&orang,&relasi);
		memset(visited,false,sizeof(visited));
		for(x=1;x<=orang;x++) teman[x].clear();
		
		for(x=0;x<relasi;x++)
		{
			scanf("%d %d",&y,&z);
			teman[y].push_back(z);
			teman[z].push_back(y);
		}
		
		maks=0;
		for(x=1;x<=orang;x++) if(!visited[x])
		{
			visited[x]=true;
			temp=1;
			ff(x);
			maks=max(maks,temp);
		}
		printf("%d\n",maks);
	}
	return 0;
}
