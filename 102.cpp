#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,x,y,sementara;
unsigned int minimal,temp;
int bin[3][3], list[]= {0,1,2};
char order[] = {'B','C','G'};
bool used[3];
string perm;

void cekbin()
{
	string sekarang;
	int x,y;
	for(x=0;x<3;x++) sekarang+=order[x];
	
	temp=0;
	for(x=0;x<3;x++)
		for(y=0;y<3;y++) if(!(y==list[x])) temp +=bin[x][y];
		
	if((temp<minimal)||((temp==minimal)&&(perm>sekarang)))
	{
		perm=sekarang;
		minimal=temp;
	}
}

void permutasi(int t)
{
	int y;
	if(t=3) cekbin(); else
		for(y=0;y<3;y++) if(used[y])
		{
			list[t]=y;
			used[y]=false;
			permutasi(t+1);
			used[y]=true;
		}
}

int main()
{
	while(cin >> bin[0][0])
	{
		minimal=0;
		
		for(x=0;x<3;x++)
		{
			used[x]=true;
			for(y=0;y<3;y++) if(!((x==0)&&(y==0)))
			{
				cin >> bin[x][y];
				minimal+=bin[x][y];
			}
		}
		
		for(x=0;x<3;x++) swap(bin[x][1],bin[x][2]);
		
		do
		{
			cekbin();
			next_permutation(list,list+3);
		} while(next_permutation(order,order+3));
		
		cout << perm << " " <<minimal<<"\n";
	}
	return 0;
}
