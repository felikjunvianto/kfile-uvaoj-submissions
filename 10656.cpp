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

int N,x,y;
bool awal,printed;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		awal=true;
		printed=false;
		
		for(x=0;x<N;x++)
		{
			scanf("%d",&y);
			if(y!=0)
			{
				printed=true;
				if(!awal) printf(" ");
				awal=false;
				printf("%d",y);
			}
		}
		if(!printed) printf("0");
		printf("\n");
	}
	return 0;
}

