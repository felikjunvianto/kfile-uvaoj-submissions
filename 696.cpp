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

int bawah,samping,x,z,ans;

int main()
{
	while(1)
	{
		scanf("%d %d",&bawah,&samping);
		if(bawah+samping==0) break;
		
		if((bawah==1)||(samping==1)) ans=max(bawah,samping); else
		if((bawah==2)||(samping==2)) 
		{
			ans=0;
			z=max(bawah,samping);
			for(x=0;x<z;x++) if(x%4<2) ans+=2;
		} else ans=(bawah*samping)/2+(bawah*samping)%2;
		
		printf("%d knights may be placed on a %d row %d column board.\n",ans,bawah,samping);
	}
	return 0;
}

