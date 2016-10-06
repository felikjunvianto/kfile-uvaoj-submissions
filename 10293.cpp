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

string total,filted;
char msk[100];
int x,y,z,cnt[40];

int main()
{
	total="";
	while(gets(msk))
	{
		if(msk[0]!='#') 
		{
			if((total.length()>0)&&(total[total.length()-1]!='-')) total+=' ';
			total+=msk; 
		}
		
		else
		{
			filted.clear();
			for(x=0;x<total.size();x++) if((total[x]!='-')&&(total[x]!=(char)39))
			{
				if((total[x]>='A')&&(total[x]<='Z')) total[x]^=32;
				filted+=total[x];
			}
			
			memset(cnt,0,sizeof(cnt));
			x=-1;
			do
			{
				x++;
				if((filted[x]<'a')||(filted[x]>'z')) continue;
				
				y=x;
				while((y<filted.length())&&(filted[y]>='a')&&(filted[y]<='z')) y++;
				cnt[y-x]++;
				x=y-1;
			}while(x+1<filted.length());
			
			for(x=1;x<=30;x++) if(cnt[x]>0) printf("%d %d\n",x,cnt[x]);
			printf("\n");
			total.clear();
		}
	}
	return 0;
}

