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
#define PII pair<int,int> 

using namespace std;

int T,N,a,b,c;
bool dapat;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		
		dapat=false;
		for(a=0;a*a<=N;a++)
		{
			int a2=a*a;
			for(b=a;a2+b*b<=N;b++)
			{
				c=(int)sqrt(N-a2-b*b);
				if(a2+b*b+c*c==N)
				{
					dapat=true;
					break;
				}	
			}
			if(dapat) break;
		}
		
		if(dapat) printf("%d %d %d\n",a,b,c);
			else printf("-1\n");
	}
	return 0;
}

