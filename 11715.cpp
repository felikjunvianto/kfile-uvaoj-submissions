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

double u,v,t,a,s;
int code,i;

int main()
{
	i=0;
	while(1)
	{
		scanf("%d",&code);
		if(!code) break;
		
		switch(code)
		{
			case(1) : scanf("%lf %lf %lf",&u,&v,&t);
					  a=(v-u)/t;
					  s=(v*v-u*u)/(2.0*a);
					  printf("Case %d: %.3lf %.3lf\n",++i,s,a);
					  break;
					  
			case(2) : scanf("%lf %lf %lf",&u,&v,&a);
					  t=(v-u)/a;
					  s=(v*v-u*u)/(2.0*a);
					  printf("Case %d: %.3lf %.3lf\n",++i,s,t);
					  break;
					  
			case(3) : scanf("%lf %lf %lf",&u,&a,&s);
					  v=sqrt(2.0*a*s+u*u);
					  t=(v-u)/a;
					  printf("Case %d: %.3lf %.3lf\n",++i,v,t);
					  break;
					  
			case(4) : scanf("%lf %lf %lf",&v,&a,&s);
					  u=sqrt(v*v-2.0*a*s);
					  t=(v-u)/a;
					  printf("Case %d: %.3lf %.3lf\n",++i,u,t);
					  break;
		}
	}
	return 0;
}

