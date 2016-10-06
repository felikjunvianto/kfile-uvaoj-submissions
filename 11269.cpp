// using Johnson Scheduling Algorithm
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

int N, head, tail, sequence[25], job[25][2];
bool registered[25];

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		for(int i = 1; i <= N; i++) scanf("%d", &job[i][0]);
		for(int i = 1; i <= N; i++) scanf("%d", &job[i][1]);

		head = 1, tail = N;
		memset(registered, false, sizeof(registered));
		while(head <= tail)
		{
			int smallestIdx = -1, smallestP = -1;
			for(int i = 1; i <= N; i++) if(!registered[i])
				for(int j = 0; j < 2; j++)
					if(smallestIdx == -1 || job[smallestIdx][smallestP] > job[i][j])
					{
						smallestIdx = i;
						smallestP = j;
					}

			registered[smallestIdx] = true;
			if(smallestP == 0) sequence[head++] = smallestIdx;
				else sequence[tail--] = smallestIdx;
		}

		int secondFinished = 0, firstFinished = 0;
	
		for(int i = 1; i <= N; i++)
		{
			int now = sequence[i];
			firstFinished += job[now][0];

			if(firstFinished > secondFinished) secondFinished += (firstFinished - secondFinished);
			secondFinished += job[now][1];
		}

		printf("%d\n", secondFinished);
	}
	return 0;
}

/* below is implementation in greedy. Basically the same as Johnson's algorithm */

// int N, sequence[25];
// pii job[25];

// bool cf(int i, int j)
// {
// 	int secondI = job[i].fi + job[i].se + job[j].se;
// 	if(job[j].fi > job[i].se) secondI += job[j].fi - job[i].se;

// 	int secondJ = job[j].fi + job[j].se + job[i].se;
// 	if(job[i].fi > job[j].se) secondJ += job[i].fi - job[j].se;
	
// 	return secondI < secondJ;
// }

// int main()
// {
// 	while(scanf("%d", &N) != EOF)
// 	{
// 		for(int i = 1; i <= N; i++) scanf("%d", &job[i].fi);
// 		for(int i = 1; i <= N; i++) scanf("%d", &job[i].se);

// 		for(int i = 1; i <= N; i++) sequence[i] = i;
// 		sort(sequence + 1, sequence + N + 1, cf);

// 		int firstFin = 0, secondFin = 0;
// 		for(int i = 1; i <= N; i++)
// 		{
// 			int now = sequence[i];
// 			firstFin += job[now].fi;
// 			if(secondFin < firstFin) secondFin += firstFin - secondFin;
// 			secondFin += job[now].se;
// 		}

// 		printf("%d\n", secondFin);
// 	}
// 	return 0;
// }