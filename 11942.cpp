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

int N,arr[15],x;
bool asc,des;

int main()
{
	scanf("%d",&N);
	printf("Lumberjacks:\n");
	while(N--)
	{
		for(x=0;x<10;x++) scanf("%d",&arr[x]);
		asc=des=true;
		
		for(x=1;x<10;x++) if(arr[x]<arr[x-1]) asc=false;
		for(x=1;x<10;x++) if(arr[x]>arr[x-1]) des=false;
		printf("%s\n",(asc||des)?"Ordered":"Unordered");
	}
	return 0;
}

