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

int N,T;
map<string,int> dict;
char msk[1000];
int val,cost;

int main()
{
	scanf("%d %d",&N,&T);
	while(N--)
	{
		scanf("%s %d",msk,&val);
		dict[msk]=val;
	}
	
	while(T--)
	{
		cost=0;
		while(1)
		{
			scanf("%s",msk);
			if(msk[0]=='.') break;
			
			if(dict.find(msk)!=dict.end()) cost+=dict[msk];
		}
		printf("%d\n",cost);
	}
	return 0;
}

