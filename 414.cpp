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

int N,arr[20],ans,x,y,z,kecil;
char msk[30];

int main()
{
	while(1)
	{
		scanf("%d",&N);getchar();
		if(!N) break;
		
		kecil=INF;
		for(x=0;x<N;x++)
		{
			gets(msk);
			for(y=0;y<25;y++) if(msk[y]==' ') break;
			z=y;
			while((z<25)&&(msk[z]==' ')) z++;
			arr[x]=z-y;
			kecil=min(kecil,arr[x]);
		}
		
		ans=0;
		for(x=0;x<N;x++) ans+=arr[x]-kecil;
		printf("%d\n",ans);
	}
	return 0;
}

