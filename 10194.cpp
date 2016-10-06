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

using namespace std;

typedef struct
{
	int point,win,tie,loss,goal_scored,goal_against,game_played;
	string team_name,team_kecil;
} data;

data tim[40];
int n,t,x,y,z,panjang,satu,dua,tiga,tanding;
int gol1,gol2,a,b;
string tim1,tim2;
char masuk[200];

string kecilin(string t)
{
	string ganti="";
	int x;
	for(x=0;x<t.size();x++) if((t[x]>='A')&&(t[x]<='Z'))
		ganti+=t[x]-'A'+'a'; else ganti+=t[x];
	return(ganti);
}

bool cf(data a,data b)
{
	if(a.point!=b.point) return(a.point>b.point); else
	if(a.win!=b.win) return(a.win>b.win); else
	if(a.goal_scored-a.goal_against!=b.goal_scored-b.goal_against) return(a.goal_scored-a.goal_against>b.goal_scored-b.goal_against); else
	if(a.goal_scored!=b.goal_scored) return(a.goal_scored>b.goal_scored); else
	if(a.game_played!=b.game_played) return(a.game_played<b.game_played); else
	return(a.team_kecil<b.team_kecil);
}

int main()
{
	scanf("%d\n",&n);
	while(n--)
	{
		gets(masuk);
		printf("%s\n",masuk);
		scanf("%d\n",&t);
		for(x=0;x<t;x++)
		{
			gets(masuk);
			tim[x].team_name=masuk;
			tim[x].team_kecil=kecilin(tim[x].team_name);
			tim[x].point=tim[x].win=tim[x].tie=tim[x].loss=
				tim[x].goal_scored=tim[x].goal_against=tim[x].game_played=0;
		}
		
		scanf("%d\n",&tanding);
		while(tanding--)
		{
			gets(masuk);
			tim1=tim2="";
			gol1=gol2=0;
			panjang=strlen(masuk);
			for(satu=0;satu<panjang;satu++) if(masuk[satu]=='#') break;
			for(dua=satu+1;dua<panjang;dua++) if(masuk[dua]=='@') break;
			for(tiga=dua+1;tiga<panjang;tiga++) if(masuk[tiga]=='#') break;
			
			for(x=0;x<satu;x++) tim1+=masuk[x];
			for(x=tiga+1;x<panjang;x++) tim2+=masuk[x];
			for(x=satu+1;x<=dua-1;x++) gol1=gol1*10+(masuk[x]-'0');
			for(x=dua+1;x<=tiga-1;x++) gol2=gol2*10+(masuk[x]-'0');
			
			for(a=0;a<t;a++) if(tim[a].team_name==tim1) break;
			for(b=0;b<t;b++) if(tim[b].team_name==tim2) break;
			
			tim[a].game_played++;
			tim[a].goal_scored+=gol1;
			tim[a].goal_against+=gol2;
			
			tim[b].game_played++;
			tim[b].goal_scored+=gol2;
			tim[b].goal_against+=gol1;
			
			if(gol1>gol2)
			{
				tim[a].win++;
				tim[a].point+=3;
				tim[b].loss++;
			} else 
			
			if(gol1<gol2)
			{
				tim[a].loss++;
				tim[b].win++;
				tim[b].point+=3;
			} else
			
			{
				tim[a].tie++;
				tim[a].point+=1;
				tim[b].tie++;
				tim[b].point+=1;
			}
		}
		
		sort(tim,tim+t,cf);
		for(x=0;x<t;x++) 
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				x+1,tim[x].team_name.c_str(),tim[x].point,tim[x].game_played,
					tim[x].win,tim[x].tie,tim[x].loss,tim[x].goal_scored-tim[x].goal_against,
						tim[x].goal_scored,tim[x].goal_against);
		if(n>0) printf("\n");
	}
	return 0;
}

