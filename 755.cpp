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

int T,N,x,y,z;
char masuk[200];
vector<string> phone;
bool ada;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		phone.clear();
		while(N--)
		{
			scanf("%s",masuk);
			int panjang=strlen(masuk);
			string temp="";
			for(x=0;x<panjang;x++) if(masuk[x]!='-')
			{
				if((masuk[x]>='0')&&(masuk[x]<='9')) temp+=masuk[x]; else
				switch(masuk[x])
				{
					case('A') : case('B') : case('C') : temp+='2';break;
					case('D') : case('E') : case('F') : temp+='3';break;
					case('G') : case('H') : case('I') : temp+='4';break;
					case('J') : case('K') : case('L') : temp+='5';break;
					case('M') : case('N') : case('O') : temp+='6';break;
					case('P') : case('R') : case('S') : temp+='7';break;
					case('T') : case('U') : case('V') : temp+='8';break;
					case('W') : case('X') : case('Y') : temp+='9';break;
				}
				if(temp.size()==3) temp+='-';
			}
			phone.pb(temp);
		}
		
		sort(phone.begin(),phone.end());
		ada=false;
		x=-1;
		do
		{
			x++;
			y=x;
			while((y<phone.size())&&(phone[x]==phone[y])) y++;y--;
			if(y>x) 
			{
				printf("%s %d\n",phone[x].c_str(),y-x+1);
				ada=true;
			}
			x=y;
		}while(x+1<phone.size());
		if(!ada) printf("No duplicates.\n");
		if(T) printf("\n");
	}
	return 0;
}

