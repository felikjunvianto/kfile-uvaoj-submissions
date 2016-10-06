#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,x,x1,x2,s,d;

int main()
{
	cin >> n;
	for(x=0;x<n;x++)
	{
		cin >> s >> d;
		x1=(int) (s+d)/2;
		x2=(int) (s-d)/2;
		if((x1>=0)&&(x2>=0)&&(x1+x2==s)&&(x1-x2==d)) cout << x1 << " " << x2 << "\n";
			else cout <<"impossible\n";
	}
	return 0;
}
