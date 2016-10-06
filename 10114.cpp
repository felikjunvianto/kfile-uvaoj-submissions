#include <cstdio>
#include <cstdlib>
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
#include <set>

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

int Nmonth, Ndep, cur_dep;
double DP, loan, payment, car_val;
vector<pair<int, double> > dep_list;

int main()
{
	while(true)
	{
		scanf("%d %lf %lf %d", &Nmonth, &DP, &loan, &cur_dep);
		if(Nmonth < 0) break;
		
		int month; double dep_per;
		dep_list.clear();
		for(int i = 0; i < cur_dep; i++)
		{
			scanf("%d %lf", &month, &dep_per);
			dep_list.pb(mp(month, dep_per));
		}
		
		car_val = (DP + loan) * (1.00 - dep_list[0].se);
		payment = loan / (double) Nmonth;
		
		int ans = 0; cur_dep = 0;
		if(car_val <= loan) for(ans = 1; ans <= Nmonth; ans++)
		{
			if(cur_dep + 1 < dep_list.size() && dep_list[cur_dep + 1].fi == ans) cur_dep++;
			loan -= payment;
			car_val *= (1.00 - dep_list[cur_dep].se);
			
			if(car_val > loan) break;
		}
		
		printf("%d %s\n", ans, ans == 1 ? "month" : "months");
	}
	return 0;
}

