#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

typedef struct
{
	int a, b, c, s;
} kel;

kel team[100];
int T, N, x, y, z;
int cnt[15];
bool crash[100][100];

int main()
{
	T = 0;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=0;x<N;x++)
			scanf("%d %d %d %d",&team[x].a,&team[x].b,&team[x].c,&team[x].s);
		
		memset(crash,false,sizeof(crash));
		
		for(x=0;x<N;x++)
			for(y=x+1;y<N;y++)
			{
				memset(cnt,0,sizeof(cnt));
				cnt[team[x].a]++; cnt[team[x].b]++; cnt[team[x].c]++;
				cnt[team[y].a]++; cnt[team[y].b]++; cnt[team[y].c]++;
				
				bool oke = true;
				for(z=1;z<10 && oke;z++) if(cnt[z]>1) oke = false;
				
				if(!oke) crash[x][y] = crash[y][x] = true;
			}
			
		int ans = -1;
		for(x=0;x<N;x++)
			for(y=x+1;y<N;y++)
				for(z=y+1;z<N;z++)
					if(!crash[x][y] && !crash[y][z] && !crash[x][z]) 
						ans = max(ans, team[x].s + team[y].s + team[z].s);
						
		printf("Case %d: %d\n", ++T, ans);
	}
	return 0;
}

