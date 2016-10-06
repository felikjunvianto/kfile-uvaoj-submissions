#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

typedef struct { int bitmask, tot, cap;} obj;

int N, K, M, T;
int i, j, k, tmp, bit;
int chosen, final, ans;
bool used[30];
vector<obj> reg;

bool cf(obj i, obj j)
{
	if(i.tot != j.tot) return i.tot < j.tot;
	return i.bitmask < j.bitmask;
}

string toBiner(int num)
{
	string biner = "";
	while(num)
	{
		biner = (char)('0' + num%2) + biner;
		num/=2;
	} 
	while(biner.size() < N ) biner = "0" + biner;
	
	return biner;
}

void compute()
{
	//cout << toBiner(chosen) << endl;
	
	int sum = 0;
	for(int i = 0; i < reg.size(); i++)
		if((chosen & reg[i].bitmask) != 0)
		{
			//cout << "---> " << toBiner(reg[i].bitmask) << " " << reg[i].cap << endl;
			sum += reg[i].cap;
		}
			
	if(sum > ans)
	{
		ans = sum;
		final = chosen;
	} //cout << sum << endl << endl;
}

void backtrack(int now, int start)
{
	if(now == K) compute(); else
		for(int i = start; i < N; i++) if(!used[i])
		{
			chosen += (1 << i);
			used[i] = true;
			backtrack(now+1, i+1);
			
			chosen -= (1 << i);
			used[i] = false;
		}
}

int main()
{
	T = 0;
	while(1)
	{
		scanf("%d %d",&N, &K);
		if(!N && !K) break;
		
		reg.clear();
		for(i = 0; i < N; i++) 
		{
			scanf("%d", &tmp);
			reg.pb((obj){1 << i, 1, tmp});
		}
		
		scanf("%d", &M);
		while(M--)
		{
			scanf("%d", &tmp);
			bit = 0;
			for( i = 0; i < tmp; i++)
			{
				scanf("%d",&j);
				bit += (1 << (j - 1));
			}
			scanf("%d", &j);
			reg.pb((obj){bit, tmp, j});
		}
		
		sort(reg.begin(), reg.end(), cf);
		
		for(i = 0; i < reg.size(); i++)
		{
			if(reg[i].tot > 1) break;
			for( j = i + 1; j < reg.size(); j++)
				if((reg[i].bitmask & reg[j].bitmask) == reg[i].bitmask)
					reg[i].cap -= reg[j].cap;
		}
				
		/*for(i = 0; i < reg.size(); i++)
			cout << toBiner(reg[i].bitmask) << " " << reg[i].cap << endl;*/
	
		memset(used,false,sizeof(used));
		chosen = ans = 0;
		backtrack(0,0);
		
		printf("Case Number  %d\n",++T);
		printf("Number of Customers: %d\n",ans);
		printf("Locations recommended:");
		for(i=0;i<N;i++) if(final & (1 << i)) printf(" %d",i+1);
		printf("\n\n");
	}
	return 0;
}
