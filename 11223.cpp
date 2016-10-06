#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

char huruf[] = {'A','B','C','D','E','F','G','H','I',
				'J','K','L','M','N','O','P','Q','R',
				'S','T','U','V','W','X','Y','Z','0',
				'1','2','3','4','5','6','7','8','9',
				'.',',','?',(char)(39),'!','/','(',')','&',
				':',';','=','+','-','_','"','@'}; //53 karakter
				
string kode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
				 ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
				 "...","-","..-","...-",".--","-..-","-.--","--..","-----",
				 ".----","..---","...--","....-",".....","-....","--...","---..","----.",
				 ".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...",
				 "---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};

string kata;
int x,y,z,n,t,a;
 
bool cocok()
{
	int m;
	bool sama;
	
	sama=true;
	for(m=0;m<z;m++) if(kode[t][m]!=kata[x+m])
	{
		sama=false;
		break;
	}
	return sama;
}
 
int main()
{
	scanf("%d\n",&n);
	for(a=1;a<=n;a++)
	{
		getline(cin,kata);
		printf("Message #%d\n",a);
		
		x=-1;
		do
		{
			x++;
			if(kata[x]==' ') printf(" "); else
			{
				y=x+1;
				while((kata[y]!=' ')&&(y<kata.size())) y++;
				y--;
				z=y-x+1;
				//cout << y << z;
				for(t=0;t<54;t++) if((kode[t].size()==z)&&(cocok()))
				{
					cout << huruf[t];
					break;
				}
				x=y+1;
			}
		} while(x<kata.size()-1);
		
		if(a<n) printf("\n");
		printf("\n");
	}
	return 0;
}
