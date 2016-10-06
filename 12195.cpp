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

char notes[] = {'W', 'H', 'Q', 'E', 'S', 'T', 'X'};
char inp[300];
int len,x,y,z,ans;
int num,denom;

int main()
{
	while(1)
	{
		scanf("%s",inp);
		if(inp[0]=='*') break;
		
		len=strlen(inp);
		ans=0;
		num=0;denom=1;
		
		for(x=1;x<len;x++) 
		{
			if(inp[x]=='/') 
			{
				if(num==denom) ans++;
				num=0;denom=1;
			} else
			
			{
				for(z=0;z<7;z++) if(notes[z]==inp[x]) break;
				int gcd = __gcd(denom,(1<<z));
				int lcm = (denom/gcd)*(1<<z);
				
				num = num*lcm/denom + lcm/(1<<z);
				denom = lcm;
				
				gcd = __gcd(num,denom);
				num/=gcd;denom/=gcd;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

