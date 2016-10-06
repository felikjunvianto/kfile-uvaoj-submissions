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

int xa,ya,xb,yb;

int main()
{
	while(1)
	{
		scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
		if(xa+ya+xb+yb==0) break;
		
		if((xa==xb)&&(ya==yb)) printf("0\n"); else
		if((xa==xb)||(ya==yb)||(ya-xa==yb-xb)||(xa+ya==xb+yb)) printf("1\n"); else
		printf("2\n");
	}
	return 0;
}

