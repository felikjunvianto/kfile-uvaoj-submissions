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

map<string,int> idx;
int adjmat[210][210];
int ia,ib;
int V,E,i,j,k,now,t;
char a[50],b[50];

int main()
{
	t = 0;
	while(1)
	{
		scanf("%d %d",&V,&E);
		if(!V && !E) break;
		
		for(i=1;i<=V;i++)
			for(j=1;j<=V;j++)
				adjmat[i][j] = (i==j?INF:0);
		
		now = 1;
		idx.clear();		
		while(E--)
		{
			scanf("%s %s %d",a,b,&k);
			if(idx.find(a)==idx.end()) idx[a] = now++;
			if(idx.find(b)==idx.end()) idx[b] = now++;
			
			ia = idx[a],ib = idx[b];
			adjmat[ia][ib] = adjmat[ib][ia] = k;
		}
		
		scanf("%s %s",a,b);
		if(idx.find(a)==idx.end()) idx[a] = now++;
		if(idx.find(b)==idx.end()) idx[b] = now++;
			
		ia = idx[a],ib = idx[b];
		
		for(k=1;k<=V;k++)
			for(i=1;i<=V;i++)
				for(j=1;j<=V;j++)
					adjmat[i][j]=max(adjmat[i][j],min(adjmat[i][k],adjmat[k][j]));
					
		printf("Scenario #%d\n",++t);
		printf("%d tons\n\n",adjmat[ia][ib]);
	}
	return 0;
}

