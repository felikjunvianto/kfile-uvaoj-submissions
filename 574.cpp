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

int T,N,x,y,z,largComb;
int arr[15];
vector<vector<int> > comb;
vector<int> now;

int main()
{
	while(1)
	{
		scanf("%d %d",&T,&N);
		if(!T && !N) break;
		for(x=0;x<N;x++) scanf("%d",&arr[x]);
		
		comb.clear();
		largComb=1<<N;
		
		for(y=0;y<largComb;y++)
		{
			z=0;
			now.clear();
			for(x=0;x<N;x++) if(y&(1<<x)) 
			{
				z+=arr[x];
				now.pb(arr[x]);
			}
			
			if(z==T) comb.pb(now);
		} sort(comb.begin(),comb.end());
		
		printf("Sums of %d:\n",T);
		if(comb.empty()) printf("NONE\n"); else
		{
			z=comb.size()-1;
			for(x=z;x>=0;x--) if(x==z || comb[x]!=comb[x+1])
				for(y=0;y<comb[x].size();y++)
					printf("%d%c",comb[x][y],y+1==(int)comb[x].size()?'\n':'+');
		}
	}
	return 0;
}

