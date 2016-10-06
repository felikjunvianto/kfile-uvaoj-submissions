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

char msk[40];
int a,b;

int hitung()
{
	int res=0,i,len=strlen(msk);
	for(i=0;i<len;i++)
	{
		if((msk[i]>='a')&&(msk[i]<='z')) msk[i]^=32;
		if((msk[i]>='A')&&(msk[i]<='Z')) res+=msk[i]-'A'+1;
	}
	
	while(res>9)
	{
		int temp=0;
		while(res)
		{
			temp+=res%10;
			res/=10;
		}
		res=temp;
	}
	return(res);
}

int main()
{
	while(gets(msk))
	{
		a=hitung();
		gets(msk);
		b=hitung();
		double c;
		if(a<b) c=a*100/(double)b; else c=b*100/(double)a;
		printf("%.2lf ",c);
		printf("%c\n",37);
	}
	return 0;
}

