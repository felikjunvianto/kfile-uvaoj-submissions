/*
   Algorithm : Soal ini dapat diselesaikan dengan brute force O(N^2) dengan memeriksa setiap
               pasang kata. Untuk memeriksa apakah pasangan kata tersebut anagram atau tidak,
			   lihat apakah kedua kata memiliki banyak huruf 'a' yang sama, 'b' yang sama, 
			   dan seterusnya dengan teknik counting.
*/

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

int x,y,z,len;
int cnt[500];
char msk[500];
vector<string> dict;

bool spasi()
{
	for(int i=0;i<len;i++) if(msk[i]!=' ') return(false);
	return(true);
}

void solve()
{
	sort(dict.begin(),dict.end());
	for(x=0;x<dict.size();x++)
		for(y=x+1;y<dict.size();y++)
		{
			memset(cnt,0,sizeof(cnt));
			for(z=0;z<dict[x].size();z++) if(dict[x][z]!=' ') cnt[(int)dict[x][z]+150]++;
			for(z=0;z<dict[y].size();z++) if(dict[y][z]!=' ') cnt[(int)dict[y][z]+150]--;
			
			bool oke=true;
			for(z=0;z<500;z++) if(cnt[z]!=0) oke=false;
			if(oke) printf("%s = %s\n",dict[x].c_str(),dict[y].c_str());
		}
	dict.clear();
}

int main()
{
	scanf("%d",&x);getchar();getchar();
	while(gets(msk))
	{
		len=strlen(msk);
		if((!len)||(spasi()))
		{
			solve();
			printf("\n");
		} else dict.pb(msk);
	}
	solve();
	return 0;
}

