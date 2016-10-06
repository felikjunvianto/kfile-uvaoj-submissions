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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int dp[30][40];
pair<int,int> jalur[30];
char posisi[2],kiri[2],kanan[2],status[2];
bool special[30];
int n,m,x,y,z;

int jalan(int pos, int langkah)
{
	if(dp[pos][langkah]==-1)
	{
		if((langkah==m)&&(special[pos])) dp[pos][langkah]=1; else
		{
			dp[pos][langkah]=0;
			if (langkah<m)
				dp[pos][langkah]+=jalan(jalur[pos].fi,langkah+1)+jalan(jalur[pos].se,langkah+1);
		}
	}
	return(dp[pos][langkah]);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		memset(special,false,sizeof(special));
		for(x=0;x<n;x++)
		{
			scanf("%s %s %s %s",posisi,kiri,kanan,status);
			jalur[posisi[0]-'A']=mp(kiri[0]-'A',kanan[0]-'A');
			if(status[0]=='x') special[posisi[0]-'A']=true;
		}
		scanf("%d",&m);
		printf("%d\n",jalan(0,0));
	}
	return 0;
}

