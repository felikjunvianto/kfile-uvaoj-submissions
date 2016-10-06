/* Algoritma : gunakan modified KMP dengan pattern string yang sama namun dibalik.
			   saat proses pencocokan, jika pointer indeks string asli sudah mencapai akhir string,
			   maka pointer indeks pattern adalah panjang dari suffix terpanjang yang merupakan
			   palindrom.
			   
			   Versi lain meunggunakan hashing (yang disubmit ke UVa saat pengerjaan week 11, ada
			   di bagian bawah kode ini sebagai komentar). Versi KMP adalah yang saya kerjakan kurang
			   lebih 2 tahun lalu.
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi 2*acos(0.0)
#define eps 1e-9
#define INF 1000000000
#define LL long long
#define PII pair<int,int> 
#define PDD pair<double,double> 

using namespace std;

int b[100010],len,x;
char msk[100010];
string inv;

void KMP_prep()
{
	int i=0,j=-1;
	b[0]=-1;
	while(i<len)
	{
		while((j>=0)&&(inv[i]!=inv[j])) j=b[j];
		i++,j++;
		b[i]=j;
	}
}

void KMP_search()
{
	int i=0,j=0;
	while(i<len)
	{
		while((j>=0)&&(msk[i]!=inv[j])) j=b[j];
		i++,j++;
	}
	printf("%s",msk);
	for(int x=j;x<len;x++) printf("%c",inv[x]);
	printf("\n");
}

int main()
{
	while(scanf("%s",msk)!=EOF)
	{
		len=strlen(msk);
		inv=msk;
		reverse(inv.begin(),inv.end());
		KMP_prep();
		KMP_search();
	}
	return 0;
}

/* versi dengan hashing (slower)

#include <cstdio>
#include <cstdlib>
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
#include <set>

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

struct tuple
{
	int fi, se, tr;
	bool operator< (const tuple &o) const
	{
		if(fi != o.fi) return fi < o.fi;
		if(se != o.se) return se < o.se;
		return tr < o.tr;
	}
};

const int hasher[] = {1000000007, 1000000009, 1000000021};
vector<tuple> hashresult;
char inp[1000010];
int len;

int convert(char x)
{
	if(x >= 'A' && x <= 'Z') return x - 'A' + 1;
	return x - 'a' + 27;
}

int main()
{
	while(scanf("%s", inp) != EOF)
	{
		len = strlen(inp);
		hashresult.clear();
		hashresult.pb((tuple){0, 0, 0});
		
		int multiplier[] = {1, 1, 1};
		for(int i = len - 1; i >= 0; i--)
		{
			tuple la = hashresult.back();
			int kali = convert(inp[i]);
			
			tuple ne = (tuple) {(int)(((((LL) multiplier[0] * (LL) kali) % (LL) hasher[0]) + (LL) la.fi) % (LL) hasher[0]),
								(int)(((((LL) multiplier[1] * (LL) kali) % (LL) hasher[1]) + (LL) la.se) % (LL) hasher[1]),
								(int)(((((LL) multiplier[2] * (LL) kali) % (LL) hasher[2]) + (LL) la.tr) % (LL) hasher[2])};
								
			hashresult.pb(ne);
			for(int j = 0; j < 3; j++)
				multiplier[j] = (int) (((LL) multiplier[j] * 53LL) % (LL) hasher[j]);
		}
		
		sort(hashresult.begin(), hashresult.end());
		
		int start = len - 1;
		tuple now = (tuple) {0, 0, 0};
		for(int i = len - 1; i >= 0; i--)
		{
			int tambah = convert(inp[i]);
			now.fi = (int)(((((LL) now.fi * 53LL) % (LL) hasher[0]) + (LL) tambah) % (LL) hasher[0]);
			now.se = (int)(((((LL) now.se * 53LL) % (LL) hasher[1]) + (LL) tambah) % (LL) hasher[1]);
			now.tr = (int)(((((LL) now.tr * 53LL) % (LL) hasher[2]) + (LL) tambah) % (LL) hasher[2]);
			
			if(binary_search(hashresult.begin(), hashresult.end(), now))
				start = min(start, i - 1);
		}
		
		printf("%s", inp);
		for(int i = start; i >= 0; i--) printf("%c", inp[i]);
		printf("\n");
	}
	return 0;
}

*/

