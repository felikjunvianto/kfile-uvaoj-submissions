#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dua[] = {"00","01","81"};
string empat[] = {"0000","0001","2025","3025","9801"};
string enam[] = {"000000","000001","088209","494209","998001"};
string delapan[] = {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};

int t,x,y;

int main()
{
	while(scanf("%d",&t) != EOF) switch(t)
	{
		case(2) : for(x=0;x<3;x++)
				  {
					for(y=0;y<t;y++) printf("%c",dua[x][y]);
					printf("\n");
				  }
				  break;
		
		case(4) : for(x=0;x<5;x++)
				  {
					for(y=0;y<t;y++) printf("%c",empat[x][y]);
					printf("\n");
				  }
				  break;

		case(6) : for(x=0;x<5;x++)
				  {
					for(y=0;y<t;y++) printf("%c",enam[x][y]);
					printf("\n");
				  }
				  break;

		case(8) : for(x=0;x<9;x++)
				  {
					for(y=0;y<t;y++) printf("%c",delapan[x][y]);
					printf("\n");
				  }
				  break;
	}
	return 0;
}

/*nilainya di-generate dulu di program lain, contoh
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t,a,b,x,y,panjang,akhir,pembagi;
int banyak[5];
string list1[5][10],list2[5][10];

int main()
{
	for(t=2;t<=8;t+=2)
	{
		akhir=0;
		pembagi=1;
		for(x=0;x<t;x++) akhir = akhir*10+9;
		for(x=0;2*x<t;x++) pembagi *= 10;
				
		banyak[t/2]=-1;
		for(x=0;x<=akhir;x++)
		{
			a=x/pembagi;
			b=x%pembagi;
			if(((a+b)*(a+b))==x) 
			{
				banyak[t/2]++;
				list1[t/2][banyak[t/2]]="";
				while(a>0) 
				{
					list1[t/2][banyak[t/2]]=(char)((a%10)+'0')+list1[t/2][banyak[t/2]];
					a/=10;
				}
				panjang=list1[t/2][banyak[t/2]].size();
				if(2*panjang<t) for(y=panjang;2*y<t;y++) list1[t/2][banyak[t/2]]='0'+list1[t/2][banyak[t/2]];
				
				list2[t/2][banyak[t/2]]="";
				while(b>0) 
				{
					list2[t/2][banyak[t/2]]=(char)((b%10)+'0')+list2[t/2][banyak[t/2]];
					b/=10;
				}
				panjang=list2[t/2][banyak[t/2]].size();
				if(2*panjang<t) for(y=panjang;2*y<t;y++) list2[t/2][banyak[t/2]]='0'+list2[t/2][banyak[t/2]];
			}
		}
	}
	while(scanf("%d",&t)!=EOF)
	{
		for(x=0;x<=banyak[t/2];x++)
			cout << list1[t/2][x] << list2[t/2][x] << endl;
	}
	return 0;
}*/