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

int N,len,x,y,chain;
int A, B;
int cnt[11];
char tmp[20];
map<int,bool> visited;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		visited.clear();
		chain=0;
		printf("Original number was %d\n",N);
		while(1)
		{
			sprintf(tmp,"%d",N);
			len=strlen(tmp);
			memset(cnt,0,sizeof(cnt));
			
			for(x=0;x<len;x++) cnt[tmp[x]-'0']++;
			A = B = 0;
			for(x=0;x<10;x++)
				for(y=0;y<cnt[x];y++) B = B*10 + x;
				
			for(x=9;x>=0;x--)
				for(y=0;y<cnt[x];y++) A = A*10 + x;
				
			N = A-B;
			printf("%d - %d = %d\n",A,B,N);
			chain++;
			if(visited.find(N)!=visited.end()) break;
				else visited[N]=true;
		}
		printf("Chain length %d\n\n",chain);
	}
	return 0;
}

