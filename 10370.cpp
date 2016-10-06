#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,x,y,z,banyak;
double mean,value[1100];

int main()
{
	scanf("%d",&n);
	for(x=0;x<n;x++)
	{
		scanf("%d",&banyak);
		mean=0;
		for(y=0;y<banyak;y++)
		{
			scanf("%lf",&value[y]);
			mean += value[y];
		}
		mean /= banyak;
		
		z=0;
		for(y=0;y<banyak;y++) if(value[y]>mean) z++;
		mean=(double)z/banyak;
		printf("%.3f",mean*100);
		cout << "%" << endl;
	}
	return 0;
}
