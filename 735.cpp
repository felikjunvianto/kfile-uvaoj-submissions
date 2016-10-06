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

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define eps 1e-9
#define LL long long
#define PII pair<int,int> 

int N;
int dp[1000][4];
int dp2[4][1000][70];
bool pos[70];

int solve2(int dart, int score, int last)
{
	if(!dart && !score) return 1;
	if(!dart && score) return 0;
	if(dp2[dart][score][last]!=-1) return (dp2[dart][score][last]);
	
	int &ret = dp2[dart][score][last] = 0;
	for(int i = last;i<=60;i++) if(pos[i] && i<=score)
		ret+=solve2(dart-1,score-i,i);
	return ret;
}

int solve(int score,int dart)
{
	if(!dart && !score) return 1;
	if(!dart && score) return 0;
	if(dp[score][dart]!=-1) return dp[score][dart];
	
	int &ret = dp[score][dart] = 0;
	for(int x=0;x<=60;x++) if((pos[x])&&(x<=score))
		ret+=solve(score-x,dart-1);
	return ret;
}

int main()
{
	memset(pos,false,sizeof(pos));
	for(int x=0;x<=20;x++) pos[x]=pos[2*x]=pos[3*x]=true;
	pos[50]=true;
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	
	while(1)
	{
		scanf("%d",&N);
		if(N<=0) break;
		
		int com = solve2(3,N,0);
		int per = solve(N,3);
		
		if(!com && !per) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",N); else
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",N,com);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",N,per);
		}
		for(int i =0;i<70;i++) printf("*");
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
