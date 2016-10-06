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

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

long long a,b;
int term,x;

int main()
{
	x=0;
	do
	{
		scanf("%lld %lld",&a,&b);
		if((a<0)&&(b<0)) break;
		x++;
		term=0;
		printf("Case %d: A = %lld, limit = %lld, number of terms = ",x,a,b);
		do
		{
			term++;
			if(a%2==0) a/=2; else a=a*3+1;
		}while((a>1)&&(a<=b));
		if(a==1) printf("%d\n",term+1); else printf("%d\n",term);
	}while(!((a<0)&&(b<0)));
	return 0;
}

