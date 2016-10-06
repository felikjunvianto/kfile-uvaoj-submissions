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

string check[] = {"one","two"};
int T,x,len;
char msk[10];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",msk);len=strlen(msk);
		if(len==5) printf("3\n"); else
		{
			for(x=0;x<2;x++) 
			{
				int wrong=0;
				for(int i=0;i<3;i++) if(check[x][i]!=msk[i]) wrong++;
				if(wrong<=1) break;
			} printf("%d\n",x+1);
		}
	}
	return 0;
}

