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

int N,give,x,y,z;
char msk[30];
map<string,int> wallet;
vector<string> list;
bool awal;

int main()
{
	awal=true;
	while(scanf("%d",&N)!=EOF)
	{
		wallet.clear();
		list.clear();
		for(x=0;x<N;x++)
		{
			scanf("%s",msk);
			list.pb(msk);
			wallet[msk]=0;
		}
		
		for(x=0;x<N;x++)
		{
			scanf("%s %d %d",msk,&give,&y);
			if(!y) continue;
			
			wallet[msk]-=give;
			wallet[msk]+=give%y;give/=y;
			for(z=0;z<y;z++)
			{
				scanf("%s",msk);
				wallet[msk]+=give;
			}
		}
		
		if(!awal) printf("\n");awal=false;
		for(x=0;x<N;x++) printf("%s %d\n",list[x].c_str(),wallet[list[x]]);
	}
	return 0;
}

