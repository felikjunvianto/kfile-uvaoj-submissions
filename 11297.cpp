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

int N,Q,x,y,z;
int XA,XB,YA,YB;
int grid[510][510];
char comm[3];
vector<PII> tree;

void build(int node,int xa,int xb,int ya,int yb)
{
	if((xa==xb)&&(ya==yb))
	{
		tree[node]=mp(grid[xa][ya],grid[xa][ya]);
		return;
	}
	
	PII child1,child2,child3,child4;
	int nextx,nexty;
	if(xa==xb) nextx=xa; else nextx=(xa+xb)/2 +1;
	if(ya==yb) nexty=ya; else nexty=(ya+yb)/2 +1;
	
	build(node*4+1,xa,(xa+xb)/2,ya,(ya+yb)/2); child1=tree[node*4+1];
	build(node*4+2,nextx,xb,ya,(ya+yb)/2); child2=tree[node*4+2];
	build(node*4+3,xa,(xa+xb)/2,nexty,yb); child3=tree[node*4+3];
	build(node*4+4,nextx,xb,nexty,yb); child4=tree[node*4+4];
	
	tree[node].fi=min(min(child1.fi,child2.fi),min(child3.fi,child4.fi));
	tree[node].se=max(max(child1.se,child2.se),max(child3.se,child4.se));
}

PII query(int node,int xa,int xb,int ya,int yb)
{
	if((xa>=XA)&&(xb<=XB)&&(ya>=YA)&&(yb<=YB)) return(tree[node]);
	if((xa>XB)||(xb<XA)||(ya>YB)||(yb<YA)) return(mp(2*INF,-2*INF));
	
	PII child1,child2,child3,child4,ans;
	int nextx,nexty;
	if(xa==xb) nextx=xa; else nextx=(xa+xb)/2 +1;
	if(ya==yb) nexty=ya; else nexty=(ya+yb)/2 +1;
	
	child1=query(node*4+1,xa,(xa+xb)/2,ya,(ya+yb)/2);
	child2=query(node*4+2,nextx,xb,ya,(ya+yb)/2);
	child3=query(node*4+3,xa,(xa+xb)/2,nexty,yb);
	child4=query(node*4+4,nextx,xb,nexty,yb);
	
	ans.fi=min(min(child1.fi,child2.fi),min(child3.fi,child4.fi));
	ans.se=max(max(child1.se,child2.se),max(child3.se,child4.se));
	return(ans);
}

void update(int node,int xa,int xb,int ya,int yb)
{
	if((xa==x)&&(xb==x)&&(ya==y)&&(yb==y))
	{
		tree[node]=mp(z,z);
		return;
	}
	
	if((xa>x)||(xb<x)||(ya>y)||(yb<y)) return;
	
	PII child1,child2,child3,child4;
	int nextx,nexty;
	if(xa==xb) nextx=xa; else nextx=(xa+xb)/2 +1;
	if(ya==yb) nexty=ya; else nexty=(ya+yb)/2 +1;
	
	update(node*4+1,xa,(xa+xb)/2,ya,(ya+yb)/2); child1=tree[node*4+1];
	update(node*4+2,nextx,xb,ya,(ya+yb)/2); child2=tree[node*4+2];
	update(node*4+3,xa,(xa+xb)/2,nexty,yb); child3=tree[node*4+3];
	update(node*4+4,nextx,xb,nexty,yb); child4=tree[node*4+4];
	
	tree[node].fi=min(min(child1.fi,child2.fi),min(child3.fi,child4.fi));
	tree[node].se=max(max(child1.se,child2.se),max(child3.se,child4.se));
}

int main()
{
	scanf("%d %d",&N,&N);
	tree.resize(4*N*N,mp(0,0));
	for(x=1;x<=N;x++)
		for(y=1;y<=N;y++) scanf("%d",&grid[x][y]);
		
	build(0,1,N,1,N);
	
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%s",comm);
		if(comm[0]=='q')
		{
			scanf("%d %d %d %d",&XA,&YA,&XB,&YB);
			PII ans=query(0,1,N,1,N);
			printf("%d %d\n",ans.se,ans.fi);
		}
						
		else
		{
			scanf("%d %d %d",&x,&y,&z);
			update(0,1,N,1,N);
		}
	}
	return 0;
}

