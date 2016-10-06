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

int T,N,d,x,y,len,rem;
char msk[1010];
bool oke;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",msk);len=strlen(msk);
		scanf("%d",&N);
		
		oke = true;
		while(N--)
		{
			scanf("%d",&d);
			if(!oke) continue;
			
			rem = 0;
			for(x=0;x<len;x++) rem=(rem*10+msk[x]-'0')%d;
			if(rem!=0) oke=false;
		}
		
		printf("%s - %s\n",msk,oke?"Wonderful.":"Simple.");
	}
	return 0;
}

