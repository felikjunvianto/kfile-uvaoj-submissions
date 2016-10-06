#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,masuk,bawah,atas,batas,area,x;
bool naik;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		area=0;
		batas=0;
		do
		{
			batas++;
			area+=batas;
		} while(area<n);	
		naik=batas%2;

		if(naik)
		{
			atas=1;
			bawah=batas;
			for(x=area;x>n;x--)
			{
				atas++;
				bawah--;
			}
			
		} else
		
		{
			atas=batas;
			bawah=1;
			for(x=area;x>n;x--)
			{
				atas--;
				bawah++;
			}
		}
		
		printf("TERM %d IS %d/%d\n",n,atas,bawah);
	}
	return 0;
}
