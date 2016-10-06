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

vector<int> data;
int N,a,b;
char c;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%c",&a,&c);
		if(c=='\n') 
		{
			double R=a/(double)2;
			double r=a/(double)4;
			printf("%.4lf\n",pi*(R*R-(double)2*r*r));
		} else
		{
			scanf("%d",&b);
			double dalam=(double)pi*(double)(a*a+b*b);
			double R=(double)(a+b);
			printf("%.4lf\n",pi*R*R-dalam);
		}
	}
	return 0;
}

