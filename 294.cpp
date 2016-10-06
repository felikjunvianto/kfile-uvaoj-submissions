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

int t,a,b,x,y,z,terbesar,faktor,temp;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		terbesar=faktor=0;
		for(x=a;x<=b;x++)
		{
			temp=0;
			for(y=1;y*y<=x;y++) if(x%y==0)
			{
				temp++;
				if(y*y!=x) temp++;
			}
			if(temp>faktor)
			{
				terbesar=x;
				faktor=temp;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,terbesar,faktor);
	}
	return 0;
}

