#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int x,y,z;
unsigned int dp[100];

int main()
{
	dp[1]=1;
	dp[2]=1;
	for(y=3;y<=80;y++) dp[y] = dp[y] + dp[y-2] + dp[y-3];
		
	while(cin >> x) cout << dp[x+2] << endl;
	return 0;
}
