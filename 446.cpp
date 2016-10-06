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
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int t,x,y,bil1,bil2;
char satu[10],tanda[3],dua[10];

int dec(string t)
{
	int kali=1;
	int hasil=0;
	for(int x=t.size()-1;x>=0;x--)
	{
		if((t[x]>='0')&&(t[x]<='9')) hasil+=(t[x]-'0')*kali;
			else hasil+=(t[x]-'A'+10)*kali;
		kali*=16;
	}
	return hasil;
}

string bin(int t)
{
	string hasil="";
	while(t>0)
	{
		hasil+=(char)(t%2+'0');
		t/=2;
	}
	while(hasil.size()<13) hasil+='0';
	reverse(hasil.begin(),hasil.end());
	return(hasil);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s %s",satu,tanda,dua);
		bil1=dec(satu);
		bil2=dec(dua);
		printf("%s %s %s = %d\n",bin(bil1).c_str(),tanda,bin(bil2).c_str(),
			tanda[0]=='+'?bil1+bil2:bil1-bil2);
	}
	return 0;
}

