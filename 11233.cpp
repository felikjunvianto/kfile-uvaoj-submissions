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

int L,N,x,y,z;
char a[30],b[30];
string ans;
map<string,string> dict;

bool es()
{
	char C=ans[ans.size()-1];
	if((C=='o')||(C=='s')||(C=='x')) return(true);
	
	if((int)ans.size()<2) return(false);
	string temp;
	temp+=ans[ans.size()-2];
	temp+=ans[ans.size()-1];
	if((temp=="ch")||(temp=="sh")) return(true);
	return(false);
}

bool yey()
{
	char C=ans[ans.size()-1];
	if((C!='y')||((int)ans.size()<2)) return(false);
	char D=ans[ans.size()-2];
	
	if((D=='a')||(D=='i')||(D=='u')||(D=='o')||(D=='e')) return(false);
	return(true);
}

int main()
{
	scanf("%d %d",&L,&N);
	while(L--)
	{
		scanf("%s %s",a,b);
		dict[a]=b;
	}
	
	while(N--)
	{
		scanf("%s",a);
		ans=a;
		if(dict.find(ans)!=dict.end()) ans=dict[ans]; else
			if(yey()) ans[ans.size()-1]='i',ans.append("es"); else 
				if(es()) ans.append("es"); else ans+='s';
		printf("%s\n",ans.c_str());
	}
	return 0;
}

