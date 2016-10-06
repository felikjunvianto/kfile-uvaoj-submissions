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
#define PDD pair<double,double> 

using namespace std;

typedef struct
{
	char tipe[2];
	double xa,ya,xb,yb,xc,yc,r;
} objek;

objek bangun[15];
PDD titik[4];
char masuk[2];
int t,m,a,b,c;
double x,y;
bool ada;

double det(PDD p,PDD q,PDD r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

bool coli(double nilai,PDD p,PDD q,PDD r)
{
	if(fabs(nilai)>eps) return(false); else
		if((q.fi-min(p.fi,r.fi)>eps)&&(max(p.fi,r.fi)-q.fi>eps)&&
		   (q.se-min(p.se,r.se)>eps)&&(max(p.se,r.se)-q.se>eps))return(true); 
				else return(false);
}

int main()
{
	t=0;
	do
	{
		scanf("%s",masuk);
		if(masuk[0]=='*') break;
		
		t++;
		bangun[t].tipe[0]=masuk[0];
		switch(masuk[0])
		{
			case('r') : scanf("%lf %lf %lf %lf",&bangun[t].xa,&bangun[t].ya,&bangun[t].xb,&bangun[t].yb);break;
			case('c') : scanf("%lf %lf %lf",&bangun[t].xc,&bangun[t].yc,&bangun[t].r);break;
			case('t') : scanf("%lf %lf %lf %lf %lf %lf",&bangun[t].xa,&bangun[t].ya,&bangun[t].xb,&bangun[t].yb,&bangun[t].xc,&bangun[t].yc);break;
		}
	}while(masuk[0]!='*');
	
	m=0;
	do
	{
		scanf("%lf %lf",&x,&y);
		if(!(fabs(x-9999.9)>eps)&&!(fabs(y-9999.9)>eps)) break;
		
		m++;
		ada=false;
		for(a=1;a<=t;a++) switch(bangun[a].tipe[0])
		{
			case('r') : if((x-bangun[a].xa>eps)&&(bangun[a].xb-x>eps)&&(bangun[a].ya-y>eps)&&(y-bangun[a].yb>eps))
						{
							ada=true;
							printf("Point %d is contained in figure %d\n",m,a);
						}break;
			
			case('c') : if(pow(bangun[a].r,2)-(pow(x-bangun[a].xc,2)+pow(y-bangun[a].yc,2))>eps)
						{
							ada=true;
							printf("Point %d is contained in figure %d\n",m,a);
						}break;
			
			case('t') : {
							titik[0]=mp(bangun[a].xa,bangun[a].ya);
							titik[1]=mp(bangun[a].xb,bangun[a].yb);
							titik[2]=mp(bangun[a].xc,bangun[a].yc);
							titik[3]=mp(x,y);
							
							double d=det(titik[0],titik[3],titik[1]);
							double e=det(titik[1],titik[3],titik[2]);
							double f=det(titik[2],titik[3],titik[0]);
							bool col_d=coli(d,titik[0],titik[3],titik[1]);
							bool col_e=coli(e,titik[1],titik[3],titik[2]);
							bool col_f=coli(f,titik[2],titik[3],titik[0]);
							if((((d>eps)&&(e>eps)&&(f>eps))||((d<eps)&&(e<eps)&&(f<eps)))
								&&(!col_d)&&(!col_e)&&(!col_f))
								{
									ada=true;
									printf("Point %d is contained in figure %d\n",m,a);
								}
						}break;
		}
		
		if(!ada) printf("Point %d is not contained in any figure\n",m);
	}while((fabs(x-9999.9)>eps)&&(fabs(y-9999.9)>eps));
	return 0;
}

