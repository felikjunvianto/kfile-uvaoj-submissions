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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int>

using namespace std;

PII atas,bawah;
int lama,baru,arah,x,y,z,n,total;

int main()
{
	do
	{
		scanf("%d",&lama);
		if(lama==0) break;
		
		n=1;
		arah=total=0;
		atas=mp(0,0);
		bawah=mp(0,0);
		do
		{
			scanf("%d",&baru);
			if(baru==0) break;
			
			n++;
			if(baru==lama) total++; else
			if(baru>lama)
			{
				if(arah==0) //tengah
				{
					arah=1;
					total++;
				} else
				
				if(arah==1) //ke atas
				{
					total++;
				} else
				
				if(arah==-1) //ke bawah
				{
					bawah.fi+=total;
					bawah.se++;
					total=1;
					arah=1;
				}
			} else
			
			if(baru<lama)
			{
				if(arah==0) //tengah
				{
					arah=-1;
					total++;
				} else
				
				if(arah==-1) //ke bawah
				{
					total++;
				} else
				
				if(arah==1) //ke atas
				{
					atas.fi+=total;
					atas.se++;
					total=1;
					arah=-1;
				}
			}
			lama=baru;
		}while(baru!=0);
		
		if(arah==1)
		{
			atas.fi+=total;
			atas.se++;
		} else
		
		if(arah==-1)
		{
			bawah.fi+=total;
			bawah.se++;
		}
		printf("Nr values = %d:  ",n);
		if(atas.se==0) printf("0.000000 "); else printf("%.6lf ",(double)atas.fi/atas.se);
		if(bawah.se==0) printf("0.000000\n"); else printf("%.6lf\n",(double)bawah.fi/bawah.se);
	}while(lama!=0);
	return 0;
}

