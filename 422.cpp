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

int dr[]={ 1, 1, 0,-1,-1,-1, 0, 1};
int dc[]={ 0, 1, 1, 1, 0,-1,-1,-1};

int N,r,c,z,i,len;
char msk[111];
char mat[111][111];

int main()
{
	while(1)
	{
		scanf("%s",msk);
		if(msk[0]=='0') break;
		
		if((msk[0]>='0')&&(msk[0]<='9'))
		{
			sscanf(msk,"%d",&N);
			for(r=0;r<N;r++) scanf("%s",mat[r]);
		}
		
		else 
		{
			len = strlen(msk);
			bool found = false;
			
			for(r=0;!found && r<N;r++)
				for(c=0;!found && c<N;c++) if(mat[r][c]==msk[0])
					for(z=0;!found && z<8;z++)
					{
						int sr=r+(len-1)*dr[z],sc=c+(len-1)*dc[z];
						if((sr<0)||(sr>=N)||(sc<0)||(sc>=N)) continue;
						
						found=true;
						for(i=0;i<len;i++) if(mat[r+i*dr[z]][c+i*dc[z]]!=msk[i])
						{
							found=false;
							break;
						}
						
						if(found) printf("%d,%d %d,%d\n",r+1,c+1,sr+1,sc+1);
					}
			if(!found) printf("Not found\n");
		}
	}
	return 0;
}

