/*
	Algoritma : Lakukan sliding window untuk menentukan ukuran minimal window yang diperlukan agar tepat
	            terdapat posisi di mana bilangan dari 1 hingga K ada dalam window tersebut.

				Algoritmanya secara kasar adalah, selama belum ada K bilangan pertama dalam window saat ini, 
				majukan head (perbesar window). Jika sudah terdapat K bilangan pertama, coba majukan tail
				(perkecil window) hingga batas maksimal (tidak bisa dimajukan lagi jika tetap ingin K bilangan
				pertama ada dalam window). Jika sudah mendapat 1 konfigurasi window, majukan tail tepat 1 kali
				dan lakukan ulang algoritma di atas hingga head mencapai akhir array.
				
				Algoritma ini berjalan dengan kompleksitas O(N). Setiap kali window dimajukan, kondisi apakah
				K bilangan pertama sudah dalam window dapat diketahui dengan O(1) dengan bantuan variabel counter
				dan array counter.
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

int arr[1000010];
int exist[1111];
int N, M, K, T;

int main()
{
	scanf("%d", &T);
	for(int i = 1; i <= 3; i++) arr[i] = i;
	for(int j = 1; j <= T; j++)
	{
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 4; i <= N; i++) arr[i] = ((arr[i-1] + arr[i-2] + arr[i-3])%M) + 1;
        
        memset(exist,0,sizeof(exist));
        int unique = 0, head = 1, tail = 1, ans = INF;
        
        while(head <= N)
        {
            exist[arr[head]]++;
            if(exist[arr[head]] == 1 && arr[head] <= K) unique++;
            
            if(unique == K)
            {
                while(tail <= N)
                {
                    if(arr[tail] <= K && exist[arr[tail]] == 1) break;
                    exist[arr[tail++]]--;
                }
                
                ans = min(ans, head - tail + 1);
                exist[arr[tail]]--;
                if(!exist[arr[tail]] && arr[tail] <= K) unique--;
                if(tail < N) tail++; else break;
            } head++;
        }
        
        printf("Case %d: ",j);
        if(ans == INF) printf("sequence nai\n"); else printf("%d\n",ans);
    }
	return 0;
}

/* Solusi binary search (surprisingly low)

int arr[1000010];
int exist[1111];
int N, M, K, T;

bool coba(int Size)
{
    if(Size < K) return false;

    memset(exist,0,sizeof(exist));
    int unique = 0;
    for(int i = 1; i < Size; i++) 
    {
        exist[arr[i]]++;
        if(exist[arr[i]] == 1 && arr[i] <= K) unique++;
    }
    
    for(int i = Size; i <= N; i++)
    {
        if(i != Size) 
        {
            exist[arr[i - Size]]--;
            if(!exist[arr[i - Size]] && arr[i - Size] <= K) unique--;
        }
        
        exist[arr[i]]++;
        if(exist[arr[i]] == 1 && arr[i] <= K) unique++;
        
        if(unique == K) return true;
    }
    
    return false;
}

int search(int L, int R)
{
    while(L <= R)
    {
        int mid = (L + R)/2;
        bool okeNow = coba(mid);
        bool okePrev = coba(mid - 1); 
        
        //printf("%d %d %d %d %d\n",L, R, mid, okeNow, okePrev);
        
        if(okeNow && !okePrev) return mid; else
            if(okeNow && okePrev) R = mid - 1; else
                if(!okeNow) L = mid + 1;
    } return R;
}   

int main()
{
	scanf("%d", &T);
	for(int i = 0; i <= 3; i++) arr[i] = i;
	for(int j = 1; j <= T; j++)
	{
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 4; i <= N; i++) arr[i] = ((arr[i-1] + arr[i-2] + arr[i-3])%M) + 1;
        
        //for(int i = 1; i <= N; i++) printf("%d%c",arr[i],i==N?'\n':' ');
        
        memset(exist,0,sizeof(exist));
        for(int i = 1; i <= N; i++) exist[arr[i]]++;
        
        bool allExist = true;
        for(int i = 1; i <= K && allExist; i++) if(!exist[i]) allExist = false;
        
        printf("Case %d: ",j);
        if(!allExist) printf("sequence nai\n"); else printf("%d\n",search(K, N));
    }
	return 0;
}

*/
