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
#define PII pair<int,int> 

using namespace std;

int T, len, ans;
char inp[100], pat[100];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", inp); len = strlen(inp);
		for(ans = 1; ans <= len; ans++)
		{
			pat[ans-1] = inp[ans-1];
			
			bool oke = true;
			for(int i = 0; i < len && oke; i += ans)
				for(int j = 0; j < ans && oke; j++) 
					if(pat[j] != inp[i + j]) oke = false;
			
			if(oke) break;
		}
		
		printf("%d\n", ans);
		if(T) printf("\n");
	}
	return 0;
}
