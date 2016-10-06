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
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int N, Q, dis[50][50];
char msk[200];
bool included[50];
vector<int> input;

void crunchInput()
{
	int temp;
	input.clear();

	gets(msk);
	for(char *p = strtok(msk, " "); p; p = strtok(NULL, " "))
	{
		sscanf(p, "%d", &temp);
		input.pb(temp);
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			dis[i][j] = (i == j ? 0 : INF);

	getchar();
	for(int i = 1; i <= N; i++)
	{
		crunchInput();
		for(int j = 0; j < input.size(); j++) dis[i][input[j]] = 1;
	}

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	scanf("%d", &Q); getchar();
	while(Q--)
	{
		crunchInput();
		memset(included, false, sizeof(included));
		int unik = 0;

		for(int i = 0; i < input.size(); i++)
			for(int j = i; j < input.size(); j++)
				for(int k = 1; k <= N; k++)
				{
					int I = input[i], J = input[j];
					if(dis[I][J] == dis[I][k] + dis[k][J])
					{
						if(!included[k]) unik++;
						included[k] = true;
					}
				}

		printf("%s\n", unik == N ? "yes" :  "no");
	}
	
	return 0;
}

