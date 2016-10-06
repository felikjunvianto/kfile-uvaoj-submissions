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
#define LL long long
#define INF 1000000000

using namespace std;

typedef struct
{
	string title,fname,lname,address,depart,homephone,workphone,cbox;
} data;

int T,x,y,z,len;
char msk[1000];
string faculty;
vector<data> arr;

bool cf(data i,data j)
{
	if(i.lname!=j.lname) return(i.lname<j.lname);
	return(i.fname<j.fname);
}

int main()
{
	scanf("%d",&T);getchar();
	while(T--)
	{
		gets(msk);faculty=msk;
		while(gets(msk))
		{
			len=strlen(msk);
			if(!len) break;
			
			data temp;
			temp.depart=faculty;
			for(z=0;z<len;z++) if(msk[z]==',') break;
			for(x=0;x<z;x++) temp.title+=msk[x];
			
			for(y=z+1;y<len;y++) if(msk[y]==',') break;
			for(x=z+1;x<y;x++) temp.fname+=msk[x];
			
			for(z=y+1;z<len;z++) if(msk[z]==',') break;
			for(x=y+1;x<z;x++) temp.lname+=msk[x];
			
			for(y=z+1;y<len;y++) if(msk[y]==',') break;
			for(x=z+1;x<y;x++) temp.address+=msk[x];
			
			for(z=y+1;z<len;z++) if(msk[z]==',') break;
			for(x=y+1;x<z;x++) temp.homephone+=msk[x];
			
			for(y=z+1;y<len;y++) if(msk[y]==',') break;
			for(x=z+1;x<y;x++) temp.workphone+=msk[x];
			for(x=y+1;x<len;x++) temp.cbox+=msk[x];
			
			arr.pb(temp);
		}
	}
	
	sort(arr.begin(),arr.end(),cf);
	for(x=0;x<arr.size();x++)
	{
		printf("----------------------------------------\n");
		printf("%s %s %s\n",arr[x].title.c_str(),arr[x].fname.c_str(),arr[x].lname.c_str());
		printf("%s\n",arr[x].address.c_str());
		printf("Department: %s\n",arr[x].depart.c_str());
		printf("Home Phone: %s\n",arr[x].homephone.c_str());
		printf("Work Phone: %s\n",arr[x].workphone.c_str());
		printf("Campus Box: %s\n",arr[x].cbox.c_str());
	}
	return 0;
}

