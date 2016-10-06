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

using namespace std;

int t,x,y,z,total;
map<string,int> pohon;
vector<string> jenis;
char masuk[50];
string temp;

void hitung()
{
	sort(jenis.begin(),jenis.end());
	for(int x=0;x<jenis.size();x++) 
		printf("%s %.4lf\n",jenis[x].c_str(),(double)pohon[jenis[x]]*100/total);
}

int main()
{
	scanf("%d\n",&t);
	total=0;
	while(gets(masuk))
	{
		temp=masuk;
		if(temp.size()==0) 
		{
			hitung();
			printf("\n");
			total=0;
			pohon.clear();
			jenis.clear();
		} else
		
		{
			if(pohon.find(temp)==pohon.end())
			{
				pohon[temp]=1;
				jenis.pb(temp);
			} else pohon[temp]++;
			total++;
		}
	}
	hitung();
	return 0;
}

