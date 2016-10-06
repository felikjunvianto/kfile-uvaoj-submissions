#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int mat[150][150];
int sum[150][150];
int kadane[150];
int x,y,z,row1,row2,col1,col2,n,temp;
int maks = -1270000;

int main()
{
	scanf("%d",&n);
	for(y=1;y<=n;y++)
		for(x=1;x<=n;x++) scanf("%d",&mat[x][y]);
		
	for(x=1;x<=n;x++)
	{
		sum[x][0]=0;
		for(y=1;y<=n;y++) sum[x][y] = mat[x][y]+sum[x][y-1];
	}
	
	for(row1=1;row1<=n;row1++)
		for(row2=row1;row2<=n;row2++)
		{
			for(x=1;x<=n;x++) kadane[x]=sum[x][row2]-sum[x][row1-1];
			int now=0;
			int temp=kadane[1];
			
			for(x=1;x<=n;x++)
			{
				now+=kadane[x];
				temp=max(temp,now);
				if(now<0) now=0;
			}
			maks=max(maks,temp);
		}
				
	printf("%d\n",maks);
	return 0;
}
