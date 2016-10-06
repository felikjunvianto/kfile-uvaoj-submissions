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

char idx[]={' ','.','x','W'};
int T,x,y,z,next;
int dna[15];
char seg[2][50];

int main()
{
	scanf("%d",&T);
	for(x=0;x<T;x++)
	{
		for(y=0;y<10;y++) scanf("%d",&dna[y]);
		memset(seg[0],' ',sizeof(seg[0]));seg[0][19]='.';
		
		if(x) printf("\n");
		for(z=0;z<50;z++)
		{
			for(y=0;y<40;y++) 
			{
				printf("%c",seg[z&1][y]);
				next=0;
				for(int i=-1;i<2;i++) 
					if((y+i>=0)&&(y+i<40)) switch(seg[z&1][y+i])
					{
						case('.') : next++;break;
						case('x') : next+=2;break;
						case('W') : next+=3;break;
					}
				seg[(z+1)&1][y]=idx[dna[next]];
			} printf("\n");
		}
	}
	return 0;
}

