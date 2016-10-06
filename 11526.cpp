#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

long long t,n,x,sum;
vector<long long> pembagi_maju,pembagi_mundur;

int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		pembagi_maju.clear();
		pembagi_mundur.clear();
		
		pembagi_maju.push_back(0);
		for(x=1;x*x<=n;x++) 
		{
			pembagi_maju.push_back(x);
			if((long long)n/x!=x) pembagi_mundur.push_back((long long)n/x);
		}
		for(x=pembagi_mundur.size()-1;x>=0;x--) pembagi_maju.push_back(pembagi_mundur[x]);
		
		sum=0;
		for(x=1;x<pembagi_maju.size();x++) sum+= (long long)(n*(pembagi_maju[x]-pembagi_maju[x-1])/pembagi_maju[x]);
		printf("%lld\n",sum);
	}
	return 0;
}
