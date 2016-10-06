#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string masuk;
int waktu,x,y,z;
int kali[]={3600000,360000,60000,6000,1000,100,10,1};
int konversi[]={1000000,100000,10000,1000,100,10,1};

int main()
{
	while(cin >> masuk)
	{
		waktu=0;
		for(x=0;x<8;x++) waktu +=((int)(masuk[x])-48)*kali[x];
		waktu = (int) waktu*125/108;
		for(x=0;x<7;x++)
		{
			cout << (char)((int)(waktu/konversi[x])+48);
			waktu %= konversi[x];
		}
		cout <<"\n";
	}
	return 0;
}
