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

bool self[1000010];
int x;

int main()
{
	memset(self,true,sizeof(self));
	for(x=1;x<=1000000;x++)
	{
		int temp=x,digit=x;
		while(digit)
		{
			temp+=digit%10;
			digit/=10;
		}
		if(temp<=1000000) self[temp]=false;
		if(self[x]) printf("%d\n",x);
	}
	return 0;
}

