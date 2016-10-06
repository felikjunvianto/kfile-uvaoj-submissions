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

int T,H,M,totalMinute;;
int Hi,Mi;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d:%d",&H,&M);
		
		totalMinute = 1440 - (H*60+M);
		Hi = (totalMinute/60);
		if(Hi>12) Hi-=12;
		Mi = totalMinute%60;
		printf("%02d:%02d\n",Hi,Mi);
	}
	return 0;
}

