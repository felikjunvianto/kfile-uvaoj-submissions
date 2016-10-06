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

vector<int> edge[30];
bool visited[30];
string masuk;
int x,y,z,t,banyak,panjang;

void ff(int t)
{
	int x;
	visited[t]=true;
	for(x=0;x<edge[t].size();x++) if(!visited[edge[t][x]])
		ff(edge[t][x]);
}

int main()
{
	scanf("%d\n",&t);
	while(t--)
	{
		getline(cin,masuk);
		z=masuk[0]-'A';
		for(x=0;x<26;x++) edge[x].clear();
		
		do
		{
			getline(cin,masuk);
			panjang=masuk.size();
			if(panjang==0) break;
			edge[masuk[0]-'A'].push_back(masuk[1]-'A');
			edge[masuk[1]-'A'].push_back(masuk[0]-'A');
		}while(panjang!=0);
		
		banyak=0;
		memset(visited,false,sizeof(visited));
		for(x=0;x<=z;x++) if(!visited[x])
		{
			banyak++;
			ff(x);
		}
		printf("%d\n",banyak);
		if(t>0) printf("\n");
	}
	return 0;
}
