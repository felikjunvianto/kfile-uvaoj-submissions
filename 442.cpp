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

int M,a,b,len,x,y,tot;
PII size[30];
stack<PII> s,calc;
char mat[3],equ[500];;
bool error;

int main()
{
	scanf("%d",&M);
	while(M--)
	{
		scanf("%s %d %d",mat,&a,&b);
		size[mat[0]-'A'] = mp(a,b);
	}
	
	while(scanf("%s",equ)!=EOF)
	{
		len=strlen(equ);
		while(!s.empty()) s.pop();
		error = false;
		tot = 0;
		
		for(x=0;x<len && !error;x++) switch(equ[x])
		{
			case('(') : s.push(mp(-1,-1));break;
			
			case(')') : while(!calc.empty()) calc.pop();
						while(1)
						{
							PII now = s.top();s.pop();
							if(now==mp(-1,-1)) break;
							
							calc.push(now);
						}
						
						while(calc.size()>1 && !error)
						{
							PII A = calc.top();calc.pop();
							PII B = calc.top();calc.pop();
							
							if(A.se!=B.fi) error = true; else
							{
								calc.push(mp(A.fi,B.se));
								tot += A.fi*A.se*B.se;
							}
						}
						
						if(error) break; else
						{
							s.push(calc.top());
							calc.pop();
						}
						break;
					
			default   : s.push(size[equ[x]-'A']);
		}
		
		if(error) printf("error\n"); else printf("%d\n",tot);
	}
	return 0;
}

