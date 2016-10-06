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

struct titik { int x, y, z; };

int N, MAX_X, MAX_Y, MAX_Z;
vector<pair<titik, titik> > balok;
vector<int> tempx, tempy, tempz;
int occupied[50][50][50];

int search(int num, int code)
{
	switch(code)
	{
		case(0) : return lower_bound(tempx.begin(), tempx.begin() + MAX_X, num) - tempx.begin();
				  break;
		
		case(1) : return lower_bound(tempy.begin(), tempy.begin() + MAX_Y, num) - tempy.begin();
				  break;
		
		default : return lower_bound(tempz.begin(), tempz.begin() + MAX_Z, num) - tempz.begin();
				  break;
	}
}

int main()
{
	while(scanf("%d", &N) != EOF) 
	{
		balok.clear();
		for(int i = 0; i < N; i++)
		{
			int x1, y1, z1, x2, y2, z2;
			scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			balok.pb(mp((titik) {x1, y1, z1}, (titik) {x2, y2, z2}));
		}
		
		// compressing x coordinate
		tempx.clear();
		for(int i = 0; i < N; i++)
		{
			tempx.pb(balok[i].fi.x);
			tempx.pb(balok[i].se.x);
		}
		sort(tempx.begin(), tempx.end());
		MAX_X = unique(tempx.begin(), tempx.end()) - tempx.begin();
			
		// compressing y coordinate
		tempy.clear();
		for(int i = 0; i < N; i++)
		{
			tempy.pb(balok[i].fi.y);
			tempy.pb(balok[i].se.y);
		}
		sort(tempy.begin(), tempy.end());
		MAX_Y = unique(tempy.begin(), tempy.end()) - tempy.begin();
			
		// compressing z coordinate
		tempz.clear();
		for(int i = 0; i < N; i++)
		{
			tempz.pb(balok[i].fi.z);
			tempz.pb(balok[i].se.z);
		}
		sort(tempz.begin(), tempz.end());
		MAX_Z = unique(tempz.begin(), tempz.end()) - tempz.begin();
			
		memset(occupied, 0, sizeof(occupied));
		for(int i = 0; i < N; i++)
		{
			int XA = search(balok[i].fi.x, 0), XB = search(balok[i].se.x, 0);
			int YA = search(balok[i].fi.y, 1), YB = search(balok[i].se.y, 1);
			int ZA = search(balok[i].fi.z, 2), ZB = search(balok[i].se.z, 2);
					
			for(int x = XA; x < XB; x++)
				for(int y = YA; y < YB; y++)
					for(int z = ZA; z < ZB; z++)
						occupied[x][y][z]++;
		}
			
		int volume = 0;
		for(int i = 0; i < MAX_X; i++)
			for(int j = 0; j < MAX_Y; j++)
				for(int k = 0; k < MAX_Z; k++)
					if(occupied[i][j][k] >= 2)
						volume += (tempx[i + 1] - tempx[i]) * (tempy[j + 1] - tempy[j]) * (tempz[k + 1] - tempz[k]);
						
		printf("%d\n", volume);
	}
	return 0;
}

