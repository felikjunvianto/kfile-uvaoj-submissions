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

int T,x,y,z,len,ans,a;
char masuk[10100],tes[10100];
char mat[110][110];
string filt,A,B,C,D;
bool palin;

bool oke(string &T)
{
	for(int x=0;2*x<T.size();x++) if(T[x]!=T[(int)T.size()-x-1]) return(false);
	return(true);
}

int main()
{
	scanf("%d",&T);getchar();
	for(z=1;z<=T;z++)
	{
		filt.clear();
		gets(masuk);
		len=strlen(masuk);
		for(x=0;x<len;x++) if((masuk[x]>='a')&&(masuk[x]<='z'))
			filt+=masuk[x];
		
		palin=true;
		ans=(int)sqrt((int)filt.size());
		if(ans*ans!=filt.size()) palin=false;
		
		a=0;
		if(palin)
		{
			for(y=1;y<=ans;y++)
				for(x=1;x<=ans;x++) mat[x][y]=filt[a++];
		
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			
			for(y=1;y<=ans;y++) for(x=1;x<=ans;x++) A+=mat[x][y];
			for(x=1;x<=ans;x++) for(y=1;y<=ans;y++) B+=mat[x][y];
			for(y=ans;y>=1;y--) for(x=ans;x>=1;x--) C+=mat[x][y];
			for(x=ans;x>=1;x--) for(y=ans;y>=1;y--) D+=mat[x][y];
			
			palin=palin&oke(A)&oke(B)&oke(C)&oke(D);
		}
		printf("Case #%d:\n",z);
		if(palin) printf("%d\n",ans); else printf("No magic :(\n");
	}
	return 0;
}

