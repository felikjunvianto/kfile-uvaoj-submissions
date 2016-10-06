#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

#define fi first
#define se second

using namespace std;

vector<pair<int,char> > lang;
int bahasa[30];
char acuan,peta[1000][1000];
int bawah,samping,x,y,z,t,temp;

void ff(int x,int y)
{
	peta[y][x]='.';
	int ver,hor;
	
	for(ver=-1;ver<=1;ver++)
		for(hor=-1;hor<=1;hor++)
			if((ver==0)^(hor==0))
				if((x+hor>=0)&&(x+hor<samping)&&(y+ver>=0)&&(y+ver<bawah))
					if(peta[y+ver][x+hor]==acuan) ff(x+hor,y+ver);
}

bool cf(pair<int,char> a,pair<int,char> b)
{
	return(a.fi!=b.fi ? a.fi>b.fi : a.se<b.se);
}

int main()
{
	scanf("%d",&z);
	for(t=1;t<=z;t++)
	{
		scanf("%d %d\n",&bawah,&samping);
		for(y=0;y<bawah;y++) gets(peta[y]);
		memset(bahasa,0,sizeof(bahasa));
		lang.clear();
		
		for(y=0;y<bawah;y++)
			for(x=0;x<samping;x++) if(peta[y][x]!='.')
			{
				acuan=peta[y][x];
				bahasa[acuan-'a']++;
				ff(x,y);
			}
			
		for(x=0;x<26;x++) if(bahasa[x]>0) lang.push_back(make_pair(bahasa[x],x+'a'));
		sort(lang.begin(),lang.end(),cf);
		printf("World #%d\n",t);
		for(x=0;x<lang.size();x++) printf("%c: %d\n",lang[x].se,lang[x].fi);
	}
	return 0;
}
