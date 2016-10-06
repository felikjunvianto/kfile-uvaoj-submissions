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

int T,len,x,y;
LL big,small,a,b;
char msk[100];
stack<char> op;
stack<LL> num;
string tmp;
vector<string> token;

void clearStack()
{
	while(!op.empty()) op.pop();
	while(!num.empty()) num.pop();
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",msk);
		len=strlen(msk);
		token.clear();
		
		x=-1;
		do
		{
			x++;
			tmp=msk[x];
			if((msk[x]!='+')&&(msk[x]!='*'))
			{
				y=x+1;
				while((y<len)&&(msk[y]!='+')&&(msk[y]!='*')) tmp+=msk[y++];
				x=y-1;
			}
			token.pb(tmp);
		} while(x+1<len);
		
		//find maximum
		clearStack();
		for(x=0;x<token.size();x++) switch(token[x][0])
		{
			case('+') : while((!op.empty())&&(op.top()=='+'))
						{
							op.pop();
							b = num.top();num.pop();
							a = num.top();num.pop();
							num.push(a+b);
						} op.push('+');break;
						
			case('*') : while(!op.empty())
						{
							char todo = op.top(); op.pop();
							b = num.top();num.pop();
							a = num.top();num.pop();
							num.push(todo=='+'?a+b:a*b);
						} op.push('*');break;
			
			default   : sscanf(token[x].c_str(),"%lld",&a);
						num.push(a);
						break;
		}
		
		while(!op.empty())
		{
			char todo = op.top(); op.pop();
			b = num.top();num.pop();
			a = num.top();num.pop();
			num.push(todo=='+'?a+b:a*b);
		}
		big = num.top();num.pop();
		
		//find minimum
		clearStack();
		for(x=0;x<token.size();x++) switch(token[x][0])
		{
			case('*') : while((!op.empty())&&(op.top()=='*'))
						{
							op.pop();
							b = num.top();num.pop();
							a = num.top();num.pop();
							num.push(a*b);
						} op.push('*');break;
						
			case('+') : while(!op.empty())
						{
							char todo = op.top(); op.pop();
							b = num.top();num.pop();
							a = num.top();num.pop();
							num.push(todo=='+'?a+b:a*b);
						} op.push('+');break;
			
			default   : sscanf(token[x].c_str(),"%lld",&a);
						num.push(a);
						break;
		}
		
		while(!op.empty())
		{
			char todo = op.top(); op.pop();
			b = num.top();num.pop();
			a = num.top();num.pop();
			num.push(todo=='+'?a+b:a*b);
		}
		small = num.top();num.pop();
		
		printf("The maximum and minimum are %lld and %lld.\n",big,small);
	}
	return 0;
}

