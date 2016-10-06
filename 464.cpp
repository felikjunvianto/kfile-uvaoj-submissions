/*
 *	Algoritma : proses setiap pattern yang didapat menjadi semua sub patternnya, begitu seterusnya
 *              hingga didapat bentuk terminal (noun, empty, trans-verb, adjective, dst).
 *
 *				Hati hati terhadap pemilihan. inisialisasi k = 0. Setiap ada kasus pemilihan sub 
 *              pattern pilih pattern ke (k + 1) % N;
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
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

map<string, vector<vector<string> > > pattern;
int kth;
vector<string> vs;
vector<vector<string> > vvs;
char inp[111];

void makeTable()
{
	vs.pb("trans-sentence"); vvs.pb(vs); vs.clear(); 
	vs.pb("intrans-sentence"); vvs.pb(vs); vs.clear(); 
	pattern["sentence"] = vvs; vvs.clear();
	
	vs.pb("subject"); vs.pb("verb-phrase"); vs.pb("object"); vs.pb("prep-phrase"); vvs.pb(vs); vs.clear();
	pattern["trans-sentence"] = vvs; vvs.clear();
	
	
	vs.pb("subject"); vs.pb("intrans-verb-phrase"); vs.pb("prep-phrase"); vvs.pb(vs); vs.clear();
	pattern["intrans-sentence"] = vvs; vvs.clear();
	
	
	vs.pb("noun-phrase"); vvs.pb(vs); vs.clear();
	pattern["subject"] = pattern["object"] = vvs; vvs.clear();
	
	
	vs.pb("article"); vs.pb("modified-noun"); vvs.pb(vs); vs.clear();
	pattern["noun-phrase"] = vvs; vvs.clear();
	
	
	vs.pb("noun"); vvs.pb(vs); vs.clear();
	vs.pb("modifier"); vs.pb("noun"); vvs.pb(vs); vs.clear();
	pattern["modified-noun"] = vvs; vvs.clear();
	
	
	vs.pb("adjective"); vvs.pb(vs); vs.clear();
	vs.pb("adverb"); vs.pb("adjective"); vvs.pb(vs); vs.clear();
	pattern["modifier"] = vvs; vvs.clear();
	
	
	vs.pb("trans-verb"); vvs.pb(vs); vs.clear();
	vs.pb("adverb"); vs.pb("trans-verb"); vvs.pb(vs); vs.clear();
	pattern["verb-phrase"] = vvs; vvs.clear();
	
	
	vs.pb("intrans-verb"); vvs.pb(vs); vs.clear();
	vs.pb("adverb"); vs.pb("intrans-verb"); vvs.pb(vs); vs.clear();
	pattern["intrans-verb-phrase"] = vvs; vvs.clear();
	
	
	vs.pb("preposition"); vs.pb("noun-phrase"); vvs.pb(vs); vs.clear();
	vs.pb("empty"); vvs.pb(vs); vs.clear();
	pattern["prep-phrase"] = vvs; vvs.clear();
	
	
	vs.pb("man"); vvs.pb(vs); vs.clear();
	vs.pb("dog"); vvs.pb(vs); vs.clear();
	vs.pb("fish"); vvs.pb(vs); vs.clear();
	vs.pb("computer"); vvs.pb(vs); vs.clear();
	vs.pb("waves"); vvs.pb(vs); vs.clear();
	pattern["noun"] = vvs; vvs.clear();
	
	
	vs.pb("struck"); vvs.pb(vs); vs.clear();
	vs.pb("saw"); vvs.pb(vs); vs.clear();
	vs.pb("bit"); vvs.pb(vs); vs.clear();
	vs.pb("took"); vvs.pb(vs); vs.clear();
	pattern["trans-verb"] = vvs; vvs.clear();
	
	
	vs.pb("slept"); vvs.pb(vs); vs.clear();
	vs.pb("jumped"); vvs.pb(vs); vs.clear();
	vs.pb("walked"); vvs.pb(vs); vs.clear();
	vs.pb("swam"); vvs.pb(vs); vs.clear();
	pattern["intrans-verb"] = vvs; vvs.clear();
	
	
	vs.pb("the"); vvs.pb(vs); vs.clear();
	vs.pb("a"); vvs.pb(vs); vs.clear();
	pattern["article"] = vvs; vvs.clear();
	
	
	vs.pb("green"); vvs.pb(vs); vs.clear();
	vs.pb("small"); vvs.pb(vs); vs.clear();
	vs.pb("rabid"); vvs.pb(vs); vs.clear();
	vs.pb("quick"); vvs.pb(vs); vs.clear();
	pattern["adjective"] = vvs; vvs.clear();
	
	
	vs.pb("nearly"); vvs.pb(vs); vs.clear();
	vs.pb("suddenly"); vvs.pb(vs); vs.clear();
	vs.pb("restlessly"); vvs.pb(vs); vs.clear();
	pattern["adverb"] = vvs; vvs.clear();
	
	
	vs.pb("on"); vvs.pb(vs); vs.clear();
	vs.pb("over"); vvs.pb(vs); vs.clear();
	vs.pb("through"); vvs.pb(vs); vs.clear();
	pattern["preposition"] = vvs; vvs.clear();
	
	vs.pb(""); vvs.pb(vs); vs.clear();
	pattern["empty"] = vvs; vvs.clear();
}

string parse(string pat)
{
	if(pattern.find(pat) == pattern.end()) 
	{
		if(pat == "") return pat; 
			else return (string)(" " + pat);
	}
	
	int now = 0;
	vector<vector<string> > choice = pattern[pat];
	if(choice.size() > 1) now = ++kth % (int) choice.size();
	
	string ret = "";
	for(int i = 0; i < choice[now].size(); i++) ret.append(parse(choice[now][i]));
		
	return ret;
}

int main()
{
	makeTable();
	kth = 0;
	
	while(scanf("%s", inp) != EOF) {
		string ans = parse(inp);
		printf("%s\n", ans.size() > 0 ? ans.substr(1).c_str():"");
	}
	return 0;
}
