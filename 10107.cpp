#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<unsigned int> num;
int x;

int main()
{
	while(scanf("%d",&x) != EOF)
	{
		num.push_back(x);
		sort(num.begin(),num.end());
		x=num.size();
		if(x%2==1) printf("%d\n",num[x/2]);
			else printf("%d\n",(num[(x/2)-1]+num[(x/2)])/2);
	}
	return 0;
}
