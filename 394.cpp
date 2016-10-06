#include <cstdio>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int n,r,x,y,z,pa;
pair <int,int> bound[100][11];
string masuk,array_name[100];
int base[100],byte[100],dimension[100];
int i[11],c[11];


int main()
{
	cin >> n >> r;
	for(x=0;x<n;x++)
	{
		cin >> array_name[x] >> base[x] >> byte[x] >> dimension[x];
		for(y=1;y<=dimension[x];y++) cin >> bound[x][y].first >> bound[x][y].second; //indeks bound mulai dari 1
	}
	
	for(x=0;x<r;x++)
	{
		cin >> masuk;
		for(z=0;z<n;z++) if(masuk==array_name[z]) break; //mencari array
		
		for(y=1;y<=dimension[z];y++) cin >> i[y]; //output awal
		cout << masuk << "[" <<i[1];
		for(y=2;y<=dimension[z];y++) cout << ", " << i[y];
		cout << "] = ";
		
		c[dimension[z]] = byte[z];
		c[0] = base[z] - c[dimension[z]]*bound[z][dimension[z]].first;
		
		for(y=dimension[z]-1;y>0;y--) 
		{
			c[y]=c[y+1]*(bound[z][y+1].second-bound[z][y+1].first+1);
			c[0] -= c[y]*bound[z][y].first;
		}

		pa=c[0];
		for(y=1;y<=dimension[z];y++) pa +=c[y]*i[y];
		cout << pa << "\n";
	}
	return 0;
}
