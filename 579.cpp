#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int jam,menit;
double sudut;
char dummy;

int main()
{
	do
	{
		cin>>jam>>dummy>>menit;
		if((jam==0)&&(menit==0)) break;
		
		sudut = (double)(jam*60 - 11*menit);
		sudut = (double) sudut/2;
		if(sudut<0) sudut = (double) sudut * -1;
		if(sudut>180) sudut=(double) 360-sudut;
		printf("%.3f\n",sudut);
	} while(!((jam==0)&&(menit==0)));
	return 0;
}
