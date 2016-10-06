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

int T;
LL a, b, c;

int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{	
		printf("Case %d: ",i);
		scanf("%lld %lld %lld",&a,&b,&c);
		
		if(a>=b+c || b>=a+c || c>=a+b) printf("Invalid\n"); else
			if(a == b && b == c) printf("Equilateral\n"); else
				if(a == b || b == c || a == c) printf("Isosceles\n"); else
					printf("Scalene\n");
	}
	return 0;
}

