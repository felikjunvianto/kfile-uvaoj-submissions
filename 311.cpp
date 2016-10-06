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

int box[10], ans, x, req1, req2, added;

int main()
{
	while(1)
	{
		for(x=1;x<=6;x++) scanf("%d", &box[x]);
		if(!box[1] && !box[2] && !box[3] && !box[4] && !box[5] && !box[6]) break;
		
		ans = box[6] + box[5] + box[4];
		
		req1 = box[5]*11;
		box[1] -= min(req1,box[1]);
		
		req2 = box[4]*5;
		added = min(box[2], req2);
		box[2] -= added; req2 -= added;		
		if(req2)
		{
			req1 = req2*4;
			box[1] -= min(box[1], req1);
		}
		
		ans += box[3]/4; box[3] %= 4;
		if(box[3])
		{
			ans++;
			req2 = (3 - box[3])*2 + 1;
			added = min(box[2], req2);
			box[2] -= added;
			
			int left = (4 - box[3])*9 - added*4;
			if(left) 
			{
				req1 = left;
				added = min(box[1], req1);
				box[1] -= added;
			}
		}
		
		ans += box[2]/9; box[2] %= 9;
		if(box[2])
		{
			ans++;
			req1 = (9 - box[2])*4;
			box[1] -= min(box[1],req1);
		}
		
		ans+= box[1]/36; if(box[1]%36) ans++;
		
		printf("%d\n",ans);
	}
	return 0;
}

