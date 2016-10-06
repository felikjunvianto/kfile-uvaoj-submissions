#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int h,d,f,day;
double height,kurang,u;

int main()
{
	do
	{
		cin >> h >> u >> d >> f;
		if(h>0) 
		{
			day=0;
			height=0;
			kurang=u*f/100;
			do
			{
				day++;
				if(u>0) height += u;
				//cout << day << " " << height << " " << h << " " << u << " " << d << "\n";
				if (height>h) break; else
				{
					height -=d;
					u -=kurang;
				}
			} while((height>=0)&&(height<=h));
			if(height>h) cout << "success on day " << day << "\n"; 
				else cout << "failure on day " << day << "\n";
		}
	} while(h>0);
}
