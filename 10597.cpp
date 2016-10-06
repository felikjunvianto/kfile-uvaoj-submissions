/*
 * Algoritma : DP[non terminal saat ini][range kiri][range kanan]. Nilainya adalah true apabila string dari
			   [kiri .. kanan] bisa diganti menjadi non terminal saat ini, dan false bila sebaliknya.
			   
			   kasus rekursif: dari semua rule dari non terminal yang mungkin (A -> BC), coba brute force lokasi
			   memisah string sehingga bisa diubah menjadi token (ditandai dengan tengah).
			   
			   DP[A][kiri][kanan] |= DP[B][kiri][tengah] && DP[C][tengah + 1][kanan]
			   
			   kasus dasar: jika kiri = kanan, periksa apakah token saat ini bisa diubah menjadi terminal yang
			   ditunjuk saat ini (A -> a).
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <set>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LL long long
#define INF 1000000000
#define pi 2*acos(0.0)
#define PII pair<int, int> 

using namespace std;

bool dp[50][60][60], visited[50][60][60];
map<char, vector<string> > rule;
char root, V[50], T[300], s1[10], s2[10], words[60];

bool solve(int key, int left, int right)
{
	if(visited[key][left][right]) return dp[key][left][right];
	
	vector<string> temp = rule[(char)(key + 'A')];
	
	if(left == right)
	{
		for(int i = 0; i < temp.size(); i++) 
			if(temp[i].size() == 1 && temp[i][0] == words[left]) return true;
		return false;
	}
	
	visited[key][left][right] = true;
	bool &ret = dp[key][left][right] = false;
	
	for(int i = 0; i < temp.size(); i++) if(temp[i].size() == 2)
		for(int j = left; j < right; j++) 
			ret = ret || (solve(temp[i][0] - 'A', left, j) && solve(temp[i][1] - 'A', j + 1, right));
	
	return ret;
}

int main()
{
	while(scanf("%s", s1) != EOF)
	{
		root = s1[0];
		scanf("%s", V);
		scanf("%s", T);
		rule.clear();
		
		while(1)
		{
			scanf("%s -> %s", s1, s2);
			if(s1[0] == '#' && s2[0] == '#') break;
			
			if(rule.find(s1[0]) == rule.end()) 
			{
				vector<string> vs;
				rule[s1[0]] = vs;
			}
			rule[s1[0]].pb(s2);
		}
					
		/*strcpy(words, "a");
		printf("%d\n", solve('C' - 'A', 0, 0));
		
		memset(visited, false, sizeof(visited));
		memset(dp, false, sizeof(dp));*/
		
		while(1)
		{
			scanf("%s", words);
			if(words[0] == '#') break;
			
			memset(visited, false, sizeof(visited));
			memset(dp, false, sizeof(dp));
			bool res = solve(root - 'A', 0, strlen(words) - 1);
			
			printf("%s is", words);
			if(!res) printf(" not");
			printf(" in L(G)\n");
		} printf("\n");
	}
	return 0;
}

