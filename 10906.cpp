/*
 *	Algoritma : gunakan pattern BNF yang telah disediakan. Tiap pattern dibuat fungsi tersendiri.
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
#define LL long long
#define INF 1000000000

using namespace std;

int T, N;
map<string, vector<string> > maper;
char s1[11], s2[11], s3[11], s4[11], s5[11];

string expr(string var);

string factor(string var)
{
	//cout << "factor " << var << endl;
	if(maper.find(var) == maper.end()) return var;	// <factor> -> num
	return("(" + expr(var) + ")");					// <factor> -> (<expr>)
}

string term(string var)
{
	//cout << "term " << var << endl;
	if(maper.find(var) == maper.end() || maper[var][1][0] != '*') return factor(var);	// <term> -> <factor>
	return(term(maper[var][0]) + "*" + factor(maper[var][2]));							// <term> -> <term> * <factor>
}

string expr(string var)
{
	//cout << "expr " << var << endl;
	if(maper.find(var) == maper.end() || maper[var][1][0] != '+') return term(var);	// <expr> -> <term>
	return(expr(maper[var][0]) + "+" + term(maper[var][2]));							// <expr> -> <expr> + <term>
}

int main()
{
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		maper.clear();
		while(N--)
		{
			scanf("%s %s %s %s %s", s1, s2, s3, s4, s5);
			vector<string> temp;
			temp.pb(s3); temp.pb(s4); temp.pb(s5);
			maper[s1] = temp;
		}
		
		printf("Expression #%d: %s\n", i, expr(s1).c_str());
	}
	return 0;
}

