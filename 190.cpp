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

double xa,ya,xb,yb,xc,yc,a,b,c,R;
double A,B,C,D,E,F;
double hitung(int code)
{
	
}

int main()
{
	while(scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc)!=EOF)
	{
		A=pow(xc,2)+pow(yc,2)-pow(xa,2)-pow(ya,2);
		B=pow(xb,2)+pow(yb,2)-pow(xa,2)-pow(ya,2);
		C=xb-xa,D=yb-ya;
		E=xc-xa,F=yc-ya;
		a=(A*D-B*F)/(2.00*(E*D-C*F));
		b=(A*C-B*E)/(2.00*(F*C-D*E));
		R=sqrt(pow(xa-a,2)+pow(ya-b,2));
		
		printf("(x ");if(a<0) printf("+ "); else printf("- ");printf("%.3lf)^2 + ",fabs(a));
		printf("(y ");if(b<0) printf("+ "); else printf("- ");printf("%.3lf)^2 = %.3lf^2\n",fabs(b),R);
		
		printf("x^2 + y^2 ");if(a<0) printf("+ "); else printf("- ");printf("%.3lfx ",fabs(2.00*a));
		if(b<0) printf("+ "); else printf("- ");printf("%.3lfy ",fabs(2.00*b));
		c=pow(a,2)+pow(b,2)-pow(R,2);
		if(c<0) printf("- "); else printf("+ ");printf("%.3lf = 0\n\n",fabs(c));
	}
	return 0;
}

