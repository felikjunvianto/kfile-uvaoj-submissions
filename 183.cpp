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

char tipe[3], inp[100], grid[222][222];
string bit;
int R, C, i, j, k, mat[222][222];
int p, len, cnt;

void decode(int ra, int ca, int rb, int cb)
{
	p++;
	if(p==len) 
	{
		scanf("%s",inp);len=strlen(inp);
		p = 0;
	}
	
	if(inp[p]=='D')
	{
		int rmid = (ra+rb)/2;
		int cmid = (ca+cb)/2;
		
		if(ra==rb) {decode(ra,ca,rb,cmid); decode(ra,cmid+1,rb,cb);} else
		if(ca==cb) {decode(ra,ca,rmid,cb); decode(rmid+1,ca,rb,cb);} else
		{
			decode(ra,ca,rmid,cmid);
			decode(ra,cmid+1,rmid,cb);
			decode(rmid+1,ca,rb,cmid);
			decode(rmid+1,cmid+1,rb,cb);
		}
	} else
	
		for(int r = ra; r <= rb; r++)
			for(int c = ca; c <= cb; c++)
				grid[r][c] = inp[p];
}

void encode(int ra, int ca, int rb, int cb)
{
	int ans = mat[rb][cb] - mat[ra-1][cb] - mat[rb][ca-1] + mat[ra-1][ca-1];
	if(!ans) 
	{
		printf("0"); 
		if(++cnt==50) 
		{
			printf("\n");
			cnt = 0;
		}
	} else 
	
	if(ans==(rb-ra+1)*(cb-ca+1)) 
	{
		printf("1");
		if(++cnt==50) 
		{
			printf("\n");
			cnt = 0;
		}
	} else
	
	{
		printf("D");
		if(++cnt==50) 
		{
			printf("\n");
			cnt = 0;
		}
		
		int rmid = (ra+rb)/2;
		int cmid = (ca+cb)/2;
		
		if(ra==rb) {encode(ra,ca,rb,cmid); encode(ra,cmid+1,rb,cb);} else
		if(ca==cb) {encode(ra,ca,rmid,cb); encode(rmid+1,ca,rb,cb);} else
		{
			encode(ra,ca,rmid,cmid);
			encode(ra,cmid+1,rmid,cb);
			encode(rmid+1,ca,rb,cmid);
			encode(rmid+1,cmid+1,rb,cb);
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%s",tipe);
		if(tipe[0]=='#') break;
		scanf("%d %d",&R, &C);
		cnt = 0;
		
		if(tipe[0]=='B')
		{
			bit.clear();
			while(bit.size()<R*C) 
			{
				scanf("%s",inp);
				bit += inp;
			}
			
			memset(mat,0,sizeof(mat));
			k = 0;
			for(i=1;i<=R;i++)
				for(j=1;j<=C;j++)
					mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + (int)(bit[k++]-'0');
			
			printf("D%4d%4d\n",R, C);
			if(R>0 && C>0) encode(1,1,R,C);
			if(cnt) printf("\n");
		} else
		
		{
			printf("B%4d%4d\n",R, C);
			p = -1;
			scanf("%s",inp);len=strlen(inp);
			decode(1,1,R,C);
			for(i=1;i<=R;i++)
				for(j=1;j<=C;j++)
				{
					printf("%c",grid[i][j]);
					if(++cnt==50) 
					{
						printf("\n");
						cnt = 0;
					}
				}
			if(cnt) printf("\n");
		}
	}
	return 0;
}

