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
#define VVI vector<vector<int> > 

using namespace std;

VVI mat,now;
vector<int> temp;
int digit[]={1,10,100,1000,10000};
int t,a,b,n,m;

VVI kali(VVI i,VVI j)
{
	VVI jawab;
	temp[0]=((i[0][0]*j[0][0])%digit[m]+(i[1][0]*j[0][1])%digit[m])%digit[m];
	temp[1]=((i[0][1]*j[0][0])%digit[m]+(i[1][1]*j[0][1])%digit[m])%digit[m];
	jawab.pb(temp);
	temp[0]=((i[0][0]*j[1][0])%digit[m]+(i[1][0]*j[1][1])%digit[m])%digit[m];
	temp[1]=((i[0][1]*j[1][0])%digit[m]+(i[1][1]*j[1][1])%digit[m])%digit[m];
	jawab.pb(temp);
	return(jawab);
}

VVI bigmod(int n)
{
	if(n==1) return(mat);
	VVI pangkat=bigmod(n/2);
	if(n%2==0) return(kali(pangkat,pangkat)); 
		else return(kali(kali(pangkat,pangkat),mat));
}

int main()
{
	temp.pb(0);
	temp.pb(1);
	mat.pb(temp);
	temp[0]=temp[1]=1;
	mat.pb(temp);
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a,&b,&n,&m);
		switch(n)
		{
			case(0) : printf("%d\n",a%digit[m]);break;
			case(1) : printf("%d\n",b%digit[m]);break;
			default : now=bigmod(n-1);
					  printf("%d\n",((a*now[1][0])%digit[m]+(b*now[1][1])%digit[m])%digit[m]);
					  break;
		}
	}
	return 0;
}

