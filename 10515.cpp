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

char M[150],N[150];
int pola[]={1,1,4,4,2,1,1,4,4,2};
int last[10][4]={{0,0,0,0},{1,0,0,0},{6,2,4,8},{1,3,9,7},{6,4,0,0},
				 {5,0,0,0},{6,0,0,0},{1,7,9,3},{6,8,4,2},{1,9,0,0}};
int bil,sisa,x;

int main()
{
	while(1)
	{
		scanf("%s %s",M,N);
		if((M[0]=='0')&&(N[0]=='0')) break;
		
		bil=M[strlen(M)-1]-'0';
		sisa=0;
		int panjang=strlen(N);
		for(x=0;x<panjang;x++) sisa=((sisa*10)+(N[x]-'0'))%pola[bil];
		printf("%d\n",last[bil][sisa]);
	}
	return 0;
}

