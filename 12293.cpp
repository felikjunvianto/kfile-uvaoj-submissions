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

int N, A, x;
vector<int> Bob;

int main()
{
	A = 1;
	while(A<=1000000000)
	{
		Bob.pb(A);
		A += A+1;
	}
	
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		x = lower_bound(Bob.begin(),Bob.end(),N) - Bob.begin();
		printf("%s\n",Bob[x]==N?"Bob":"Alice");
	}
	return 0;
}

