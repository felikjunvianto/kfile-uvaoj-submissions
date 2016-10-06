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

using namespace std;

int dx[]={ 0, 1, 1, 1, 0,-1,-1,-1};
int dy[]={-1,-1, 0, 1, 1, 1, 0,-1};
int T,bawah,samping,x,y,N,panjang;
char peta[60][60],tes[60];
bool ketemu;

bool oke(int x,int y)
{
	for(int t=0;t<8;t++)
	{
		int px=x+dx[t]*(panjang-1),py=y+dy[t]*(panjang-1);
		if((px>=1)&&(px<=samping)&&(py>=1)&&(py<=bawah))
		{
			bool cocok=true;
			for(int m=0;(m<panjang)&&cocok;m++) 
				if(tes[m]!=peta[x+m*dx[t]][y+m*dy[t]]) cocok=false;	
			if(cocok) return(true);
		}
	}
	return(false);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d\n",&bawah,&samping);
		for(y=1;y<=bawah;y++)
		{
			for(x=1;x<=samping;x++) 
			{
				scanf("%c",&peta[x][y]);
				if((peta[x][y]>='A')&&(peta[x][y]<='Z')) peta[x][y]=peta[x][y]-'A'+'a';
			}
			getchar();
		}
		
		scanf("%d",&N);
		while(N--)
		{
			scanf("%s",tes);
			panjang=strlen(tes);
			for(x=0;x<panjang;x++) if((tes[x]>='A')&&(tes[x]<='Z')) tes[x]=tes[x]-'A'+'a';
			ketemu=false;
			for(y=1;(y<=bawah)&&(!ketemu);y++)
				for(x=1;(x<=samping)&&(!ketemu);x++) if((peta[x][y]==tes[0])&&(oke(x,y)))
				{
					printf("%d %d\n",y,x);
					ketemu=true;
				}
		}
		if(T) printf("\n");
	}
	return 0;
}

