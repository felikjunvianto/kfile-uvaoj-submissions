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

int T,x,cnt,lastChosen,gray;

int main()
{
	while(1)
	{
		scanf("%d",&T);
		if(!T) break;
		
		while(T--)
		{
			cnt=0;
			for(x=0;x<5;x++)
			{
				scanf("%d",&gray);
				if(gray<128)
				{
					cnt++;
					lastChosen=x;
				}
			}
		
			printf("%c\n",cnt==1?(char)(lastChosen+'A'):'*');
		}
	}
	return 0;
}

