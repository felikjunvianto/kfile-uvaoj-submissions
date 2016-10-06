/**
 Algoritma : proses masukan sesuai BNF. Ada 2 pendekatan untuk menyelesaikan soal ini:
			 1. Baca dulu semua masukan dalam 1 kasus hingga selesai (pengecekan mirip parentheses balance
			    dengan {BEGIN, LOOP} = '(' dan {END} = ')'. Kemudian proses vector of string tersebut. 
				Pendekatan ini yang saya lakukan saat mengerjakan soal ini sewaktu UTS.
				
			 2. Sembari membaca masukan langsung diproses. Pendekatan ini disertakan sebagai komentar di
			    bagian bawah program.
				
			Kedua pendekatan telah dicoba dan ACCEPTED.
			
 Kesalahan pada UTS : Untuk kasus di mana kompleksitas akhirnya memiliki koefisien 1 untuk x^0, seperti
                      kasus di bawah ini:
					  
					  BEGIN OP 1 END
					  
					  maka keluaran yang dicetak adalah: Runtime = 
					  Padahal seharusnya: Runtime = 1.
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

typedef struct { LL coef[11]; } cell;

int T;
vector<string> token;
char inp[5555];

cell statementList(int s, int f);

cell opStatement(int s, int f)
{
	int num;
	sscanf(token[f].c_str(), "%d", &num);
	
	cell ret;
	memset(ret.coef, 0LL, sizeof(ret.coef));
	ret.coef[0] = (LL) num;
	return ret;
}

cell loopHeader(int s, int f)
{
	cell ret;
	memset(ret.coef, 0, sizeof(ret.coef));
	
	if(token[f] == "n") ret.coef[1] = 1LL; else
	{
		int num;
		sscanf(token[f].c_str(), "%d", &num);
		ret.coef[0] = (LL) num;
	}
	
	return ret;
}

cell loopStatement(int s, int f)
{
	cell temp1 = loopHeader(s, s + 1);
	cell temp2 = statementList(s + 2, f - 1);
	
	if(temp1.coef[1] == 0) for(int i = 0; i < 11; i++) temp2.coef[i] *= (LL) temp1.coef[0]; else 
	{
		for(int i = 10; i >= 0; i--) temp2.coef[i] = temp2.coef[i-1];
		temp2.coef[0] = 0LL;
	}
	
	return temp2;
}

cell statementList(int s, int f)
{
	cell ret;
	memset(ret.coef, 0, sizeof(ret.coef));

	if(token[s] == "OP") 
	{
		ret = opStatement(s, s + 1);
		if(s + 1 < f) 
		{
			cell temp = statementList(s + 2, f);
			for(int j = 0; j < 11; j++) ret.coef[j] += temp.coef[j];
		}
	} 
	
	else if(token[s] == "LOOP")
	{
		int i, brcnt = 1;
		for(i = s + 1; i <= f; i++)
		{
			if(token[i] == "BEGIN" || token[i] == "LOOP") brcnt++;
				else if(token[i] == "END") brcnt--;
			if(brcnt == 0) break;		
		}
		
		ret = loopStatement(s, i);
		if(i < f) 
		{
			cell temp = statementList(i + 1, f);
			for(int j = 0; j < 11; j++) ret.coef[j] += temp.coef[j];
		}
	}
	
	return ret;
}

cell program(int s, int f) { return statementList(s + 1, f - 1); }

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		token.clear();
		int brcnt = 0;
		
		do
		{
			scanf("%s", inp);
			token.pb(inp);
			
			if(!strcmp(inp, "BEGIN") || !strcmp(inp, "LOOP")) brcnt++;
				else if(!strcmp(inp, "END")) brcnt--;
		} while(brcnt != 0);
		
		cell ans = program(0, token.size()-1);
		
		printf("Program #%d\nRuntime = ", t);
		
		bool allZero = true;
		for(int i = 0; i < 11 && allZero; i++) if(ans.coef[i]) allZero = false;
		if(allZero) printf("0"); else
		{
			bool awal = true;
			for(int i = 10; i >= 0; i--)
			{
				if(ans.coef[i] == 0) continue;
				
				if(!awal) printf("+");
				awal = false;
				if(ans.coef[i] > 1 || (ans.coef[i] == 1 && !i)) printf("%lld", ans.coef[i]);
				if(ans.coef[i] > 1 && i) printf("*");
				if(i == 1) printf("n"); else if(i != 0) printf("n^%d", i);
			}
		}	
		printf("\n\n");
	}
	return 0;
}

/**
alternatif solusi (credits to Ashar Fuadi for giving hints)

int T;
char inp[50];

vector<LL> statementList();

vector<LL> mul(LL n, vector<LL> a)
{
	if(n == -1LL) for(int i = 10; i >= 0; i--) a[i] = !i ? 0 : a[i - 1];
		else for(int i = 0; i < 11; i++) a[i] *= n;
		
	return a;
}

vector<LL> add(vector<LL> a, vector<LL> b)
{
	for(int i = 0; i < 11; i++) a[i] += b[i];
	return a;
}

vector<LL> OpStatement()
{
	vector<LL> ret;
	ret.assign(11, 0LL);
	
	scanf("%s", inp); 
	sscanf(inp, "%lld", &ret[0]);
	return ret;
}

vector<LL> loopStatement()
{
	scanf("%s", inp); 
	
	LL i;
	if(inp[0] == 'n') i = -1LL; else sscanf(inp, "%lld", &i);
	return mul(i, statementList());
}

vector<LL> statement(char *p)
{
	vector<LL> ret; 
	if(!strcmp(p, "LOOP")) ret = loopStatement();
		else ret = OpStatement();
	return ret;
}

vector<LL> statementList()
{
	vector<LL> ret; ret.assign(11, 0LL);
	while(1)
	{
		scanf("%s", inp); 
		if(!strcmp(inp, "END")) break;
		ret = add(ret, statement(inp));
	}
	return ret;
}

int main()
{
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		scanf("%s", inp); 
		vector<LL> res = statementList();
		
		printf("Program #%d\n", i);
		printf("Runtime = "); 
		
		bool allZero = true;
		for(int i = 0; i < 11 && allZero; i++) if(res[i] > 0) allZero = false;
		
		if(allZero) printf("0"); else
		{
			bool awal = true;
			for(int i = 10; i >= 0; i--)
			{
				if(!res[i]) continue;
				if(!awal) printf("+");
				awal = false;
				
				if(res[i] > 1 || (res[i] == 1 && !i)) printf("%lld", res[i]);
				if(res[i] > 1 && i) printf("*");
				if(i == 1) printf("n"); else if(i != 0) printf("n^%d", i);
			}
		}
		printf("\n\n");
	}
	return 0;
}
*/