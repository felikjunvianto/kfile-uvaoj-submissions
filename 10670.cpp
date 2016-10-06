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

int T,awal,akhir,N,A,B,i,j,x,y,z,temp,now,len;
pair<int,string> ans[111];
char msk[300];
string nama;

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d %d",&awal,&akhir,&N);
		for(x=0;x<N;x++)
		{
			scanf("%s",msk);len=strlen(msk);
			
			for(y=0;y<len;y++) if(msk[y]==':') break;
			nama.clear();for(z=0;z<y;z++) nama+=msk[z];
			
			for(j=y+1;j<len;j++) if(msk[j]==',') break;
			A=0;for(z=y+1;z<j;z++) A=A*10+(msk[z]-'0');
			B=0;for(z=j+1;z<len;z++) B=B*10+(msk[z]-'0');
			
			now=awal;
			temp=0;
			while(1)
			{
				if(now<akhir*2) break;
				z=now-(int)(now/2);
				
				if(A*z>B) temp+=B; else temp+=A*z;
				now/=2;
			}
			
			z=now-akhir;
			temp+=A*z;
			ans[x]=mp(temp,nama);
		}
		
		sort(ans,ans+N);
		printf("Case %d\n",i);
		for(x=0;x<N;x++) printf("%s %d\n",ans[x].se.c_str(),ans[x].fi);
	}
	return 0;
}

