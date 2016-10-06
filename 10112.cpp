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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

PII point[20];
char nama[20][2];
int t,x,y,z,dicek,a,b,c,terbesar,temp;
bool kosong,nocol_a,nocol_b,nocol_c;
string area;

int det(PII p, PII q, PII r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

bool nocol(int a,PII p,PII q,PII r)
{
	if(a!=0) return(true); else
		if((q.fi>=min(p.fi,r.fi))&&(q.fi<=max(p.fi,r.fi))
		 &&(q.se>=min(p.se,r.se))&&(q.se<=max(p.se,r.se))) return(false); 
			else return(true);
}

int main()
{
	do
	{
		scanf("%d",&t);
		if(t==0) break;
		
		for(x=0;x<t;x++) scanf("%s %d %d",nama[x],&point[x].fi,&point[x].se);
		
		terbesar=0;
		for(x=0;x<t-2;x++)
			for(y=x+1;y<t-1;y++)
				for(z=y+1;z<t;z++) if(det(point[x],point[y],point[z])!=0)
				{
					kosong=true;
					for(dicek=0;dicek<t;dicek++) if((dicek!=x)&&(dicek!=y)&&(dicek!=z))
					{
						a=det(point[x],point[dicek],point[y]);
						nocol_a=nocol(a,point[x],point[dicek],point[y]);
						b=det(point[y],point[dicek],point[z]);
						nocol_b=nocol(b,point[y],point[dicek],point[z]);
						c=det(point[z],point[dicek],point[x]);
						nocol_c=nocol(c,point[z],point[dicek],point[x]);
						
						if(((a<0)&&(b<0)&&(c<0))||((a>0)&&(b>0)&&(c>0))||(!nocol_a)||(!nocol_b)||(!nocol_c))
						{
							kosong=false;
							break;
						}
					}
					
					if(kosong)
					{
						temp=abs(det(point[x],point[y],point[z]));
						if(terbesar<temp)
						{
							terbesar=temp;
							area=nama[x][0];
							area+=nama[y][0];
							area+=nama[z][0];
						}
					}
				}
		sort(area.begin(),area.end());
		printf("%s\n",area.c_str());
	}while(t!=0);
	return 0;
}

