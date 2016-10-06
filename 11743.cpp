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

int T,x,y,num;
string code;
char msk[10];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		code.clear();
		for(x=0;x<4;x++) 
		{
			scanf("%s",msk);
			code.append(msk);
		}
		
		num=0;
		for(x=0;x<code.length();x++)
			if(x&1) num+=(int)(code[x]-'0'); else 
			{
				y = (int)(code[x]-'0');
				num+=y*2;
				if(y>4) num-=9;
			}
			
		printf("%s\n",num%10?"Invalid":"Valid");
	}
	return 0;
}

