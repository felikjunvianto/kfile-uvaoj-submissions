#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,x,y;

int main()
{
	cin >> n;
	for(x=0;x<n;x++)
	{
		cin >> y;
		cout << abs(((315*y+36962)%100 - (315*y+36962)%10)/10) << "\n";
	}
	return 0;
}
