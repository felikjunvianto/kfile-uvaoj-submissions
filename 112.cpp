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

typedef struct
{
	int val,l,r;
} cell;

vector<cell> node;
int N,cnt,idx,x,y,z,len;
char msk[10010];
bool ans;
stack<PII> s;
queue<PII> q;

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		while(!s.empty()) s.pop();
		cnt=idx=0;
		node.clear();
		do
		{
			scanf("%s",msk);
			len=strlen(msk);
			x=-1;
			do
			{
				x++;
				if(msk[x]=='(') cnt++;
				else if(msk[x]==')')
				{
					cnt--;
					if(s.size())
					{
						PII now=s.top();s.pop();
						if(!now.se) 
						{
							now.se++;
							s.push(now);
						}
					}
				} else
				{
					z=0;
					bool minus=false;
					if(msk[x]=='-') 
					{
						minus=true;
						x++;
					}
					
					while((x<len)&&(msk[x]>='0')&&(msk[x]<='9'))
					{
						z=z*10+(msk[x]-'0');
						x++;
					}x--;
					
					if(minus) z*=-1;
					node.pb((cell){z,-1,-1});
					if(s.size())
					{
						PII now=s.top();
						if(!now.se) node[now.fi].l=idx; else 
						if(now.se==1) node[now.fi].r=idx;
					}
					s.push(mp(idx,0));
					idx++;
				}
			} while(x+1<len);
		} while(cnt);
		
		ans=false;
		if(node.size()) q.push(mp(0,node[0].val));
		while(!q.empty())
		{
			PII now=q.front();q.pop();
			if((node[now.fi].l==-1)&&(node[now.fi].r==-1))
			{
				if(now.se==N) ans=true;
			} else
			{
				if(node[now.fi].l!=-1) q.push(mp(node[now.fi].l,node[node[now.fi].l].val+now.se));
				if(node[now.fi].r!=-1) q.push(mp(node[now.fi].r,node[node[now.fi].r].val+now.se));
			}
		}
		if(ans) printf("yes\n"); else printf("no\n");
	}
	return 0;
}

