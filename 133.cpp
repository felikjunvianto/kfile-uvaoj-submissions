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

PII sambung[40];
int N,k,m,x,y,z,lastk,lastm;

int main()
{
	while(1)
	{
		scanf("%d %d %d",&N,&k,&m);
		if(N+k+m==0) break;
		
		for(x=0;x<N;x++)
		{
			sambung[x].fi=(x+1)%N;
			sambung[x].se=(x-1+N)%N;
		}
		
		lastk=x=0,lastm=N-1,z=1;
		while(x<N)
		{
			z^=1;
			switch(z)
			{
				case(0) :	for(y=0;y+1<k;y++) lastk=sambung[lastk].fi;
							x++;
							printf("%3d%c",lastk+1,x==N?'\n':',');
							break;
							
				case(1) :	for(y=0;y+1<m;y++) lastm=sambung[lastm].se;
							if(lastk!=lastm)
							{
								x++;
								printf("%3d%c",lastm+1,x==N?'\n':',');
							}
							
							sambung[sambung[lastk].fi].se=sambung[lastk].se;
							sambung[sambung[lastk].se].fi=sambung[lastk].fi;
							lastk=sambung[lastk].fi;
							if(lastk==lastm) lastk=sambung[lastk].fi;
							
							sambung[sambung[lastm].fi].se=sambung[lastm].se;
							sambung[sambung[lastm].se].fi=sambung[lastm].fi;
							lastm=sambung[lastm].se;
							break;
			}
		}
	}
	return 0;
}

