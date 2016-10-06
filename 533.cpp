/*
 *	Algoritma : menggunakan pattern BNF yang sudah disediakan. Setiap pattern dijadikan sebuah fungsi
 *              yang mengembalikan Ax + B dalam bentuk pair<LL, LL>.
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
#define PLL pair<LL, LL> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

PLL expression(string var);

PLL factor(string var)
{
	if(var == "x") return mp(1LL, 0LL);
	
	bool allNum = true;
	for(int i = 0; i < var.size() && allNum; i++) if(var[i] < '0' || var[i] > '9') allNum = false;
	if(allNum)
	{
		LL ret;
		sscanf(var.c_str(), "%lld", &ret);
		return mp(0LL, ret);
	}
	
	if(var[0] == '(' && var[var.size()-1] == ')') return expression(var.substr(1, var.length() - 2));
	return expression(var);
}

PLL term(string var)
{
	bool awal = true;
	PLL fact1;
	int start = 0, i, bracket_cnt = 0;
	do
	{
		i = -1; bracket_cnt = 0;
		for(int c = start; c < var.size() && i == -1; c++)
			if(var[c] == '(') bracket_cnt++; else
				if(var[c] == ')') bracket_cnt--; else
					if(!bracket_cnt && var[c] == '*') i = c;
		
		PLL fact2;
		if(i != -1) fact2 = factor(var.substr(start, i - start));
			else fact2 = factor(var.substr(start));
	
		if(awal) fact1 = fact2;
			else fact1 = mp(fact1.fi * fact2.se + fact1.se * fact2.fi, fact1.se * fact2.se);
		
		awal = false;
		if(i == -1) break;
		start = i + 1;
	} while(1);
	
	return fact1;
}

PLL expression(string var)
{
	PLL term1 = mp(0LL, 0LL);
	char op = '+';
	int start = 0, i, bracket_cnt;
	
	do
	{
		i = -1; bracket_cnt = 0;
		for(int c = start; c < var.size() && i == -1; c++)
			if(var[c] == '(') bracket_cnt++; else
				if(var[c] == ')') bracket_cnt--; else
					if(!bracket_cnt && (var[c] == '+' || var[c] == '-')) i = c;
					
		PLL term2;
		if(i != -1) term2 = term(var.substr(start, i - start)); 	
			else term2 = term(var.substr(start));
		
		if(op == '+') {term1.fi += term2.fi; term1.se += term2.se;}
			else {term1.fi -= term2.fi; term1.se -= term2.se;};
			
		if(i == -1) break;
		
		op = var[i];
		start = i + 1;
	} while(1);
	
	return term1;
}

void equation(string var)
{
	int i = var.find_first_of("=");
	PLL expr1 = expression(var.substr(0, i)); 
	PLL expr2 = expression(var.substr(i + 1));
	
	LL A = expr1.fi - expr2.fi, B = expr2.se - expr1.se;
	if(A != 0LL) printf("x = %.6lf\n", B / (double) A); else
		if(A == 0LL && B != 0LL) printf("No solution.\n"); else
			if(A == 0LL && B == 0LL) printf("Infinitely many solutions.\n");
}

int main()
{
	int T = 0;
	char eq[111111];
	
	while(scanf("%s", eq) != EOF)
	{
		if(T) printf("\n");
		printf("Equation #%d\n", ++T);
		equation(eq);
	}
	return 0;
}

