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

int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0,-1};

int A, B, C;
int rk, ck, rq, cq, mr, mc;
int allowed[10][10];

bool insideGrid(int r, int c)
{
	return (r >= 0 && c >= 0 && r < 8 && c < 8);
}

int main()
{
	while(scanf("%d %d %d", &A, &B, &C) != EOF)
	{
		rk = A / 8; ck = A % 8;
		rq = B / 8; cq = B % 8;
		mr = C / 8; mc = C % 8;
		memset(allowed, 0, sizeof(allowed));
		
		if(A == B) 
		{
			printf("Illegal state\n");
			continue;
		}
		
		int rdis = abs(mr - rq), cdis = abs(mc - cq);
		if(!((rdis > 0) ^ (cdis > 0)))
		{
			printf("Illegal move\n");
			continue;
		}
		
		int r = rdis ? (mr - rq) / rdis : 0, c = cdis ? (mc - cq) / cdis : 0;
		int rtemp = rq, ctemp = cq;
		bool tabrak = false;
		while(rtemp != mr || ctemp != mc)
		{
			rtemp += r; ctemp += c;
			if(rtemp * 8 + ctemp == A) 
			{
				printf("Illegal move\n");
				tabrak = true;
				break;
			}
		} if(tabrak) continue;
		
		for(int i = 0; i < 4; i++)
		{
			int sr = rk + dr[i], sc = ck + dc[i];
			if(insideGrid(sr, sc)) allowed[sr][sc] += 1;
		}
		
		for(int i = 0; i < 4; i++)
			for(int j = 1; j < 8; j++)
			{
				int sr = rq + dr[i] * j, sc = cq + dc[i] * j;
				if(insideGrid(sr, sc)) allowed[sr][sc] += 2;
			}
		
		if(allowed[mr][mc] != 2) 
		{
			printf("Move not allowed\n");
			continue;
		}
		
		bool lolos = false;
		for(int i = 0; i < 4 && !lolos; i++)	
		{
			int sr = rk + dr[i], sc = ck + dc[i];
			if(insideGrid(sr, sc) && !((abs(sr - mr) > 0) ^ (abs(sc - mc) > 0))) lolos = true;
		}
			
		printf("%s\n", lolos ? "Continue" : "Stop");
	}
	return 0;
}

