/*
   Algorithm : Lakukan backtracking untuk mencetak semua permutasi. Agar hasilnya terurut dan
               tidak ada hasil permutasi duplikat, urutkan dulu semua elemen permutasi secara
			   leksikografis dan suatu karakter hanya bisa dimasukkan jika dia karakter unik
			   atau duplikat sebelumnya telah dimasukkan.              
 */

#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int T,panjang,x,y,z;
char masuk[200],list[200];
bool used[200];

char upcase(char c)
{
	if((c>='a')&&(c<='z')) return(c-'a'+'A');
	return(c);
}

bool cf(char a,char b)
{
	if(upcase(a)!=upcase(b)) return(upcase(a)<upcase(b));
		else return(a<b);
}

void permut(int N)
{
	int y;
	if(N==panjang) 
	{
		for(y=0;y<panjang;y++) printf("%c",list[y]);
		printf("\n");
	}else for(y=0;y<panjang;y++) if(!used[y])
		if((y==0)||(masuk[y]!=masuk[y-1])||((masuk[y]==masuk[y-1])&&(used[y-1])))
		{
			used[y]=true;
			list[N]=masuk[y];
			permut(N+1);
			used[y]=false;
		}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",masuk);
		panjang=strlen(masuk);
		sort(masuk,masuk+panjang,cf);
		memset(used,false,sizeof(used));
		permut(0);
	}
	return 0;
}

