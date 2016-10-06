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

int N, i;
char tmp[200];
string num[200];

bool cf(string i, string j)
{
	return(i + j > j + i);
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(i=0;i<N;i++) 
		{
			scanf("%s",tmp);
			num[i] = tmp;
		}
		
		sort(num,num+N,cf);
		for(i=0;i<N;i++) printf("%s",num[i].c_str());
		printf("\n");
	}
	return 0;
}

