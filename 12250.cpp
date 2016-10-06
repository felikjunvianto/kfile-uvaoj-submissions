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

char msk[20];

int main()
{
	int i = 0;
	while(1)
	{
		scanf("%s",msk);
		if(msk[0]=='#') break;
		
		printf("Case %d: ",++i);
		if(!strcmp(msk,"HELLO")) printf("ENGLISH\n"); else
			if(!strcmp(msk,"HOLA")) printf("SPANISH\n"); else
				if(!strcmp(msk,"HALLO")) printf("GERMAN\n"); else
					if(!strcmp(msk,"BONJOUR")) printf("FRENCH\n"); else
						if(!strcmp(msk,"CIAO")) printf("ITALIAN\n"); else
							if(!strcmp(msk,"ZDRAVSTVUJTE")) printf("RUSSIAN\n"); else
								printf("UNKNOWN\n");
	}
	return 0;
}

