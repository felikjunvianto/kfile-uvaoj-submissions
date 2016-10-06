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

int f,w,x,y;
char msk[60];
vector<string> dict,ans;
bool typed[130];

bool cf(string i,string j)
{
	if(i.size()!=j.size()) return(i.size()>j.size());
	return(i<j);
}

bool cantype(string s)
{
	for(int j=0;j<s.size();j++) if(!typed[(int)s[j]]) return false;
	return true;
}

int main()
{
	while(scanf("%d %d",&f,&w)!=EOF)
	{
		memset(typed,true,sizeof(typed));
		while(f--)
		{
			scanf("%d",&x);
			switch(x)
			{
				case(1) : typed[(int)'q'] = typed[(int)'a'] = typed[(int)'z'] = false;break;
				case(2) : typed[(int)'w'] = typed[(int)'s'] = typed[(int)'x'] = false;break;
				case(3) : typed[(int)'e'] = typed[(int)'d'] = typed[(int)'c'] = false;break;
				case(4) : typed[(int)'r'] = typed[(int)'f'] = typed[(int)'v'] =
						  typed[(int)'t'] = typed[(int)'g'] = typed[(int)'b'] = false;break;
				case(5) : case(6) : typed[(int)' '] = false;break;
				case(7) : typed[(int)'y'] = typed[(int)'h'] = typed[(int)'n'] =
						  typed[(int)'u'] = typed[(int)'j'] = typed[(int)'m'] = false;break;
				case(8) : typed[(int)'i'] = typed[(int)'k'] = typed[(int)','] = false;break;
				case(9) : typed[(int)'o'] = typed[(int)'l'] = typed[(int)'.'] = false;break;
				case(10) : typed[(int)'p'] = typed[(int)';'] = typed[(int)'/'] = false;break;
			}
		}
		
		dict.clear();
		while(w--)
		{
			scanf("%s",msk);
			dict.pb(msk);
		}
		sort(dict.begin(),dict.end(),cf);
		
		ans.clear();
		for(x=0;x<dict.size();x++) if(cantype(dict[x]))
		{
			ans.pb(dict[x]);
			y = x+1;
			while(y<dict.size() && dict[y].size()==dict[x].size()) 
			{
				if(dict[y]!=dict[y-1] && cantype(dict[y])) ans.pb(dict[y]);
				y++;
			}
			break;
		}
		
		printf("%d\n",ans.size());
		if(!ans.empty()) for(int i=0;i<ans.size();i++) printf("%s\n",ans[i].c_str());
	}
	return 0;
}

