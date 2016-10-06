#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi 2*acos(0.0)
#define eps 1e-9
#define INF 1000000000
#define LL long long
#define PII pair<int,int> 
#define PDD pair<double,double> 

using namespace std;

int N,x,y,z,len,ans;
char msk[1010];
vector<string> SA;
string prefix,temp;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);
		len=strlen(msk);
		SA.clear();SA.pb("");
		SA[0]+=msk[len-1];
		for(x=len-2;x>=0;x--) SA.pb(msk[x]+SA.back());
		sort(SA.begin(),SA.end());
		
		prefix.clear();
		for(x=0;x+1<SA.size();x++)
		{
			temp.clear();
			z=min((int)SA[x].size(),(int)SA[x+1].size());
			for(y=0;y<z;y++) if(SA[x][y]!=SA[x+1][y]) break;
			for(z=0;z<y;z++) temp+=SA[x][z];
			if(temp.empty()) continue;
			
			if(prefix.size()<temp.size()) prefix=temp; else
				if(prefix.size()==temp.size()) prefix=min(prefix,temp);
		}
		
		if(!prefix.size()) printf("No repetitions found!\n"); else 
		{
			ans=0;
			for(x=0;x<SA.size();x++) if(SA[x].find(prefix)==0) ans++;
			printf("%s %d\n",prefix.c_str(),ans);
		}
	}
	return 0;
}

