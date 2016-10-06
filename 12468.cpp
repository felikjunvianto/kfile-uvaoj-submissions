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
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

int A, B;

int main()
{
	while(1)
	{
		scanf("%d %d",&A,&B);
		if(A==-1 && B==-1) break;
		
		printf("%d\n",min((B-A+100)%100,(A-B+100)%100));
	}
	return 0;
}

