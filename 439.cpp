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

queue<pair<pair<int,int>,int> > move;
int x_fin,y_fin;
char koor[10];
bool peta[10][10];
int x,y,z,ver,hor;

int main()
{
	while(scanf("%[^\n]",&koor)!=EOF)
	{
		getchar();
		while(!move.empty()) move.pop();
		move.push(make_pair(make_pair(koor[0]-'a'+1,koor[1]-'0'),0));
		x_fin=koor[3]-'a'+1;
		y_fin=koor[4]-'0';
		memset(peta,true,sizeof(peta));
		peta[move.front().fi.fi][move.front().fi.se]=false;
		
		do
		{
			x=move.front().fi.fi;
			y=move.front().fi.se;
			z=move.front().se;
			
			if((x==x_fin)&&(y==y_fin)) break; else
				for(ver=-2;ver<=2;ver++)
					for(hor=-2;hor<=2;hor++)
						if(abs(ver)+abs(hor)==3)
							if((x+hor>=1)&&(x+hor<=8)&&(y+ver>=1)&&(y+ver<=8))
								if(peta[x+hor][y+ver])
								{
									peta[x+hor][y+ver]=false;
									move.push(make_pair(make_pair(x+hor,y+ver),z+1));
								}
			move.pop();
		}while(!move.empty());
		printf("To get from %c%c to %c%c takes %d knight moves.\n",koor[0],koor[1],koor[3],koor[4],move.front().se);
	}
	return 0;
}
