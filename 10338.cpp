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

int prime[]={2,3,5,7,11,13,17,19};
int faktor[10];

int T,len,x,y,z;
int cnt[30];
int fak[25];
char msk[30];

int main()
{
	scanf("%d",&T);
	for(int i = 1;i<=T;i++)
	{
		scanf("%s",msk);len=strlen(msk);
		printf("Data set %d: ",i);
		if(len==1) 
		{
			printf("1\n");
			continue;
		}
		
		memset(cnt,0,sizeof(cnt));
		memset(fak,0,sizeof(fak));
		memset(faktor,0,sizeof(faktor));
		
		for(x=1;x<=len;x++) fak[x]++; //hitung faktorial 
		for(x=0;x<len;x++) cnt[msk[x]-'A']++; //hitung yang sama di string
		
		for(x=0;x<26;x++) if(cnt[x]>1)
			for(y=2;y<=cnt[x];y++) fak[y]--; //kurangin yang sama di string
			
		for(x=2;x<=len;x++) if(fak[x]!=0)
		{
			int temp = x;
			int now = -1;
			do
			{
				now++;
				int banyak = 0;
				while(temp%prime[now]==0)
				{
					banyak++;
					temp/=prime[now];
				}
				
				faktor[now]+=fak[x]*banyak;
			} while(temp>1);
		}
			
		//for(x=0;x<8;x++) if(faktor[x]) cout << prime[x] << " " << faktor[x] << endl;
			
		unsigned int ans = 1u;
		for(x=0;x<8;x++) 
			for(y=0;y<faktor[x];y++)
				ans*=(unsigned int)prime[x];
			
		printf("%u\n",ans);
	}
	return 0;
}

