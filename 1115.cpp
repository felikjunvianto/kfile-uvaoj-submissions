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

typedef struct
{
	double base,height,width,depth;
} box;

int T,N,x;
double a,b,c,d,high,total,temp;
vector<box> tank;

bool check(double H)
{
	double volume = 0;
	for(int i = 0;i < tank.size(); i++)
	{
		if(tank[i].base >= H + eps) continue;
		double htmp = min(H, tank[i].base + tank[i].height);
		volume += (htmp - tank[i].base) * tank[i].width * tank[i].depth;
	}
	if(volume > total+eps) return false;
	return true;
}

double binser(double L, double R)
{
	while(fabs(R-L)>eps)
	{
		double mid = (R+L)/2.00;
		bool now = check(mid);
		bool next = check(mid+0.001);
		//cout << mid << " " << L << " " << R << " " << now << " " << next << endl;
		
		if(now && !next) return mid; else
			if(now && next) L = mid; else
				if(!now) R = mid;
	} return R;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		tank.clear();
		temp = high = 0;
		
		for(x=0;x<N;x++)
		{
			scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
			tank.pb((box){a,b,c,d});
			temp += b*c*d;
			high = max(high, a + b);
		} scanf("%lf",&total);
		
		if(total>=temp+eps) printf("OVERFLOW\n");
			else printf("%.2lf\n",binser(0,high));
		if(T) printf("\n");
	}
	return 0;
}

