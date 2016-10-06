#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

char puzzle[6][6],com[1000];
int r,c,x,y,z,len;

int main()
{
	z=0;
	while(1)
	{
		gets(puzzle[0]);
		if(strlen(puzzle[0])==1 && puzzle[0][0]=='Z') break;
		
		for(x=1;x<5;x++) gets(puzzle[x]);
		for(r=0;r<5;r++)
		{
			for(c=0;c<5;c++) if(puzzle[r][c]==' ') break;
			if(puzzle[r][c]==' ') break;
		}
		
		bool findZero=false;
		bool invalid=false;
		while(!findZero)
		{
			gets(com);len=strlen(com);
			for(x=0;x<len;x++) switch(com[x])
			{
				case('A') : if(invalid) break;
							if(!r) invalid=true; else
							{
								swap(puzzle[r-1][c],puzzle[r][c]);
								r--;
							} break;
							
				case('B') : if(invalid) break;
							if(r==4) invalid=true; else
							{
								swap(puzzle[r+1][c],puzzle[r][c]);
								r++;
							} break;
							
				case('R') : if(invalid) break;
							if(c==4) invalid=true; else
							{
								swap(puzzle[r][c+1],puzzle[r][c]);
								c++;
							} break;
							
				case('L') : if(invalid) break;
							if(!c) invalid=true; else
							{
								swap(puzzle[r][c-1],puzzle[r][c]);
								c--;
							} break;
							
				case('0') : findZero=true;break;
			}
		}
		
		if(z) printf("\n");
		printf("Puzzle #%d:\n",++z);
		if(invalid) printf("This puzzle has no final configuration.\n"); else
			for(r=0;r<5;r++)
				for(c=0;c<5;c++)
					printf("%c%c",puzzle[r][c],c==4?'\n':' ');
	}	
	return 0;
}

