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
#define eps 1e-9

using namespace std;

typedef struct
{
	char bangun[2];
	double xa,ya,xb,yb;
	double x,y,r;
} poli;

poli bentuk[12];
double x,y;
int a,b,n;
char masuk[2];
bool ada;

int main()
{
	n=0;
	do
	{
		scanf("%s",masuk);
		if(masuk[0]=='*') break;
		switch(masuk[0])
		{
			case('r') : scanf("%lf %lf %lf %lf",&bentuk[n].xa,&bentuk[n].ya,&bentuk[n].xb,&bentuk[n].yb);
						break;
			case('c') : scanf("%lf %lf %lf",&bentuk[n].x,&bentuk[n].y,&bentuk[n].r);
						break;
		}
		bentuk[n].bangun[0]=masuk[0];
		n++;
	}while(masuk[0]!='*');
	
	b=0;
	do
	{
		scanf("%lf %lf",&x,&y);
		if((fabs(x-9999.9)<eps)&&(fabs(y-9999.9)<eps)) break;
		
		ada=false;
		b++;
		for(a=0;a<=n;a++) 
		{
			switch(bentuk[a].bangun[0])
			{
				case('r') : if((x-bentuk[a].xa>=eps)&&(bentuk[a].xb-x>=eps)&&(bentuk[a].ya-y>=eps)&&(y-bentuk[a].yb>=eps))
							{
								printf("Point %d is contained in figure %d\n",b,a+1);
								ada=true;
							}
							break;
							
				case('c') : if((x-bentuk[a].x)*(x-bentuk[a].x)+(y-bentuk[a].y)*(y-bentuk[a].y)-(bentuk[a].r*bentuk[a].r)<=eps)
							{
								printf("Point %d is contained in figure %d\n",b,a+1);
								ada=true;
							}
							break;
			}
		}
		if(!ada) printf("Point %d is not contained in any figure\n",b);
	}while(1);
	return 0;
}

