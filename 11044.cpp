#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m,kasus,x,bawah,samping;

int main()
{
	cin >> kasus;
	for(x=0;x<kasus;x++)
	{
		cin >> n >> m;
		if((n-2)%3==0) bawah=n-2;else bawah=n+1- ((n-2)%3);
		if((m-2)%3==0) samping=m-2;else samping=m+1- ((m-2)%3);
		cout << bawah*samping/9 << "\n";
	}
	return 0;
}
