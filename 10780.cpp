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

int facN[10010],facM[10010];
int T,M,N,i,temp,x,y,z,power;
bool impossible,prime[111];
vector<int> num;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x*x<=100;x++) if(prime[x])
		for(y=2;y*x<=100;y++) prime[x*y]=false;
	for(x=2;x<=100;x++) if(prime[x]) num.pb(x);
	
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&M,&N);
		memset(facN,0,sizeof(facN));
		
		for(z=1;z<=N;z++)
		{
			temp=z;
			for(x=0;x<num.size() && num[x]*num[x]<=N;x++)
				while(temp%num[x]==0)
				{
					facN[num[x]]++;
					temp/=num[x];
				}
			if(temp>1) facN[temp]++;
		}
		
		memset(facM,0,sizeof(facM));
		temp=M;
		for(x=0;x<num.size() && num[x]*num[x]<=M;x++)
			while(temp%num[x]==0)
			{
				facM[num[x]]++;
				temp/=num[x];
			}
		if(temp>1) facM[temp]++;
		
		impossible=false;
		power=INF;
		for(x=0;x<10000 && !impossible;x++) if(facM[x])
		{
			if(facN[x]>=facM[x]) power=min(power,facN[x]/facM[x]);
				else impossible=true;
		}
		
		printf("Case %d:\n",i);
		if(impossible) printf("Impossible to divide\n"); else printf("%d\n",power);
	}
	return 0;
}

