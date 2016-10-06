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

vector<int> num;
int x,y,z;
char c;
bool mat;
stack<PII> s;

int main()
{
	while(scanf("%d%c",&x,&c)!=EOF)
	{
		num.clear();num.pb(x);
		while(c!='\n')
		{
			scanf("%d%c",&x,&c);
			num.pb(x);
		}
		
		while(!s.empty()) s.pop();
		mat=true;
		for(x=0;x<num.size() && mat;x++)
			if(num[x]<0)
			{
				if(s.empty()) s.push(mp(-num[x],0)); else
				{
					s.top().se-=num[x];
					if(s.top().se>=s.top().fi) mat=false; 
						else s.push(mp(-num[x],0));
				}
			} else
			{
				if(s.empty() || s.top().fi!=num[x]) mat=false; 
					else s.pop();
			}
		if(!s.empty()) mat=false;
		
		printf("%s\n",mat?":-) Matrioshka!":":-( Try again.");
	}
	return 0;
}

