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

int dr[]={-2,-1, 1, 2, 2, 1,-1,-2};
int dc[]={ 1, 2, 2, 1,-1,-2,-2,-1};

int N,x,y,z,ans;
char msk[10];
string temp,final="111110111100 110000100000";
queue<pair<string,int> > q;
map<string,int> visited;

int main()
{
	visited[final]=0;
	q.push(mp(final,0));
	while(!q.empty())
	{
		pair<string,int> now = q.front();q.pop();
		if(now.se==10) continue;

		z=0;
		temp = now.fi;
		int r,c;
		for(y=0;y<5;y++)
			for(x=0;x<5;x++) if(temp[y*5+x]==' ')
			{
				r=y;
				c=x;
				break;
			}
				
		for(z=0;z<8;z++)
		{
			int sr=r+dr[z],sc=c+dc[z];
			if((sr>-1)&&(sc>-1)&&(sr<5)&&(sc<5))
			{
				swap(temp[r*5+c],temp[sr*5+sc]);	
				if(visited.find(temp)==visited.end())
				{
					visited[temp]=now.se+1;
					q.push(mp(temp,now.se+1));
				}
				swap(temp[r*5+c],temp[sr*5+sc]);
			}
		}
	}

	scanf("%d",&N);getchar();
	while(N--)
	{
		temp.clear();
		for(x=0;x<5;x++)
		{
			gets(msk);
			temp.append(msk);
		}
		
		ans=-1;
		if(visited.find(temp)!=visited.end()) ans=visited[temp];
		if(ans==-1) printf("Unsolvable in less than 11 move(s).\n");
			else printf("Solvable in %d move(s).\n",ans);
	}
	return 0;
}

