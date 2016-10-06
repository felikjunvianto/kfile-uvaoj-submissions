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

vector<pair<int,char> > urutan;
int bawah,samping,x,y,z;
char peta[100][100];

void ff(int x,int y)
{
	peta[y][x]='.';
	urutan.back().fi++;
	
	int ver,hor;
	
	for(ver=-1;ver<=1;ver++)
		for(hor=-1;hor<=1;hor++)
			if((ver==0)^(hor==0))
				if((x+hor>=0)&&(x+hor<samping)&&(y+ver>=0)&&(y+ver<bawah))
					if(peta[y+ver][x+hor]==urutan.back().se) ff(x+hor,y+ver);
}

bool cf(pair<int,char> a, pair<int,char> b)
{
	if(a.fi!=b.fi) return(a.fi>b.fi);
		else return(a.se<b.se);
}

int main()
{
	z=0;
	do
	{
		scanf("%d %d",&bawah,&samping);
		if((bawah==0)&&(samping==0)) break;
		
		z++;
		getchar();
		for(y=0;y<bawah;y++) gets(peta[y]);
		urutan.clear();
		
		for(y=0;y<bawah;y++)
			for(x=0;x<samping;x++) if(peta[y][x]!='.')
			{
				urutan.push_back(make_pair(0,peta[y][x]));
				ff(x,y);
			}
		sort(urutan.begin(),urutan.end(),cf);
		printf("Problem %d:\n",z);
		for(x=0;x<urutan.size();x++) printf("%c %d\n",urutan[x].se,urutan[x].fi);
	}while((bawah!=0)&&(samping!=0));
	return 0;
}
