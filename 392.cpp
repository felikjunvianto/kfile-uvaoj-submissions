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

using namespace std;

int coe[10];
int x;
bool pertama;

int main()
{
	while(scanf("%d",&coe[8])!=EOF)
	{
		for(x=7;x>=0;x--) scanf("%d",&coe[x]);
		pertama=true;
		
		for(x=8;x>=0;x--) if(coe[x]!=0)
		{
			if(pertama) 
			{
				switch(coe[x])
				{
					case(1) : if(x==0) printf("1"); break;
					case(-1) : if(x==0) printf("-1"); else printf("-");break;
					default : printf("%d",coe[x]);
				}
				pertama=false; 
			}
			else
				
			{
				if(coe[x]<0) printf(" - "); else printf(" + ");
				if(x==0) printf("%d",abs(coe[x])); else
					if(abs(coe[x])!=1) printf("%d",abs(coe[x]));
			}
			
			if(x>0) printf("x");
			if(x>1) printf("^%d",x);
		}
		
		if(pertama) printf("0");
		printf("\n");
	}
	return 0;
}

