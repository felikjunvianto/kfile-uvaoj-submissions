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

using namespace std;

vector<int> humble;
priority_queue<PII,vector<PII>,greater<PII> > pq;
int prime[]={2,3,5,7};
string akhiran[]={"th","st","nd","rd","th","th","th","th","th","th"};
long long batas=2147483647LL;
int x,y,z,now;

int main()
{
	pq.push(mp(1,0));
	do
	{
		humble.pb(pq.top().fi);
		y=pq.top().fi;
		now=pq.top().se;
		pq.pop();
		for(x=now;x<4;x++) if((long long) y*prime[x]<=batas)
			pq.push(mp(y*prime[x],x));
	}while(humble.size()<5842);
	
	do
	{
		scanf("%d",&x);
		if(x==0) break;
		
		y=x%100;
		printf("The %d",x);
		if((y>=11)&&(y<=19)) printf("th "); else printf("%s ",akhiran[x%10].c_str());
		printf("humble number is %d.\n",humble[x-1]);
	}while(x>0);
	return 0;
}

