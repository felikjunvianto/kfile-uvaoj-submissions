/*
	Algoritma : Ada 3 bagian vertex yang saling lepas: kumpulan orang, klub, dan partai. Pada soal ini
	            semua nama orang, klub dan partai diberikan dalam string sehingga harus dilakukan hashing
				agar mempermudah proses max flow. Karena namanya tidak unik (nama orang bisa sama dengan nama 
				klub dan seterusnya), ada 2 map terpisah yang digunakan untuk indexing string yang digunakan.
				Perhatikan nama orang yang berbeda bisa saja sama sehingga tidak dilakukan hashing pada orang,
				namun indeks yang digunakan berdasarkan urutan masuk (1 .. banyak baris).
				
				Urutan penempatan adalah: Super Source -> club (source) -> people -> party (sink) -> Supersink, dengan
				kapasitas setiap link adalah 1 kecuali kapasitas dari partai ke Supersink yaitu (banyak club berbeda-1)/2.
				
				Setelah itu lakukan maxflow dari Super Source. Jika bisa dilakukan max flow sejumlah banyak club berbeda,
				maka dijamin ada solusi, namun jika tidak dipastikan tidak ada solusi yang mungkin.
				
				Untuk menentukan mana pasangan orang-club yang digunakan, lakukan looping pada setiap orang dan club. Jika
				ada link dari club ke orang yang kapasitasnya 0 namun backflow nya 1, maka orang tersebut mewakili club tersebut.
				
	Tricky : karena kode yang rumit dan panjang sering ada kesalahan, yang paling fatal adalah penentuan batas partai.
	         Batas partai = (banyak club yang berbeda - 1) /2, bukan (banyak orang - 1) /2 atau (banyak semua club - 1)/2.

	Credits to Ashar Fuadi, Kemal Maulana, & William Gozali for giving hints
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

vector<string> name, party;
vector<vector<string> > club;
map<string, int> idParty, idClub;
map<int, string> naClub;

vector<int> adjlist[1510];
int adjmat[1510][1510];
int par[1510];
bool visited[1510];
int Nflow, f;

int T, source, sink; // 0 = source, 1 .. Sparty-1 = name
int Sparty, Sclub;   // Sparty .. Sclub-1 = party, Sclub .. sink-1 = club, club = [name] + [party] + [club]
char inp[1111];

void augment(int now)
{
	if(now == source) f = 1; else if(par[now] != -1)
	{
		augment(par[now]);
		adjmat[par[now]][now] -= f;
		adjmat[now][par[now]] += f;
	}
}

int main()
{
	scanf("%d", &T);getchar();getchar();
	
	while(T--)
	{
		name.clear(); party.clear(); club.clear(); 
		idParty.clear(); idClub.clear(); naClub.clear();
		memset(adjmat, 0, sizeof(adjmat));
		for(int i = 0; i < 4010; i++) adjlist[i].clear();
		
		while(gets(inp))
		{
			if(strlen(inp) == 0) break;
			
			char *token = strtok(inp," "); name.pb(token);
			token = strtok(NULL," "); party.pb(token);
			
			vector<string> temp;
			token = strtok(NULL," ");
			while(token) 
			{
				temp.pb(token);
				token = strtok(NULL," ");
			} club.pb(temp);
		}
		
		int now = name.size() + 1;
		Sparty = now;
		for(int i = 0; i < party.size(); i++) 
			if(idParty.find(party[i]) == idParty.end()) idParty[party[i]] = now++;
			
		Sclub = now;
		for(int i = 0; i < club.size(); i++)
			for(int j = 0; j < club[i].size(); j++)
				if(idClub.find(club[i][j]) == idClub.end()) 
				{
					idClub[club[i][j]] = now;
					naClub[now++] = club[i][j];
				}
				
		source = 0; sink = now;
		
		//connect supersource to source (club)
		for(int i = Sclub; i < sink; i++)
		{
			adjlist[source].pb(i);
			adjlist[i].pb(source);
			adjmat[source][i] = 1;
		}
		
		for(int p = 1; p < Sparty; p++)
		{   //connect set of club to set of people
			for(int j = 0; j < club[p-1].size(); j++)
			{
				int c = idClub[club[p-1][j]];
				if(adjmat[c][p] != 0) continue;
				
				adjlist[c].pb(p);
				adjlist[p].pb(c);
				adjmat[c][p] = 1;
			}
			
			//connect set of people to set of party
			int pa = idParty[party[p-1]];
			adjlist[p].pb(pa);
			adjlist[pa].pb(p);
			adjmat[p][pa] = 1;
		}
		
		//connect party to supersink
		int lim = ((int)idClub.size() - 1) / 2;
		for(int i = Sparty; i < Sclub; i++)
		{
			adjlist[i].pb(sink);
			adjlist[sink].pb(i);
			adjmat[i][sink] = lim;
		}
		
		Nflow = 0;
		do
		{
			memset(visited,false,sizeof(visited));
			visited[source] = true;
			memset(par,-1,sizeof(par));
			queue<int> q; q.push(source);
			
			while(!q.empty())
			{
				int x = q.front(); q.pop();
				for(int i = 0; i < adjlist[x].size(); i++)
				{
					int y = adjlist[x][i];
					if(!visited[y] && adjmat[x][y] > 0)
					{
						visited[y] = true;
						par[y] = x;
						q.push(y);
					}
				}
			}
			
			f = 0;
			augment(sink);
			if(f) Nflow++;
		} while(Nflow < sink - Sclub && f);
		
		if(Nflow < sink - Sclub) printf("Impossible.\n"); else
			for(int i = 1; i < Sparty; i++)
			{
				int c, p;
				for(c = Sclub; c < sink; c++) if(!adjmat[c][i] && adjmat[i][c]) break;
				//for(p = Sparty; p < Sclub; p++) if(!adjmat[i][p] && adjmat[p][i]) break;
				//cout << c << " " << p << endl;
				
				if(c < sink && p < Sclub) printf("%s %s\n", name[i-1].c_str(), naClub[c].c_str());
			} 
			
		if(T) printf("\n");
	}
	return 0;
}

