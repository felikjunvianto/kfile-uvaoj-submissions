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

int N,len,x,y,z;
char msk[300];

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%s",msk);len=strlen(msk);
		printf("Case %d: ",i);
		x=-1;
		do
		{
			x++;
			y=x+1;
			while((y<len)&&(msk[y]>='0')&&(msk[y]<='9')) y++;
			int loop=0;
			for(z=x+1;z<y;z++) loop=loop*10+msk[z]-48;
			for(z=0;z<loop;z++) printf("%c",msk[x]);
			x=y-1;
		} while(x+1<len);
		printf("\n");
	}
	return 0;
}

