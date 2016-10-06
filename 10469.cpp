#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned int a,b;

int main()
{
	while(scanf("%u %u",&a,&b) != EOF) printf("%u\n",a^b);
	return 0;
}
