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

int T,i,j;
int pop,sum;
string chosen[10010],kelas[5];
char tmp[10];

int main()
{
	while(1)
	{
		scanf("%d",&T);
		if(!T) break;
		
		for(i=0;i<T;i++)
		{
			for(j=0;j<5;j++) 
			{
				scanf("%s",tmp);
				kelas[j]=tmp;
			}
			sort(kelas,kelas+5);
			
			chosen[i]=kelas[0];
			for(j=1;j<5;j++) chosen[i]+=" "+kelas[j];
		}
		sort(chosen,chosen+T);
		
		pop=sum=0;
		i=-1;
		do
		{
			i++;j=i;
			while(j<T && chosen[i]==chosen[j]) j++;
			if(pop==j-i) sum+=j-i; else
				if(pop<j-i) pop=sum=j-i;
			i=j-1;
		} while(i+1<T);
		printf("%d\n",sum);
	}
	return 0;
}

