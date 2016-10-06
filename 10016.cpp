/*
	Algoritma : simulasi refleksi matriks sederhana. Untuk setiap query kompleksitasnya O(N) (dengan N
	            ukuran matriks) karena refleksi hanya dilakukan pada cincin saja (tidak termasuk isinya).
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

int T, N, M, C;
int mat[111][111];

void rotate(int ring, int mode)
{
	switch(mode)
	{
		case(1) : for(int i = ring; i <= N - ring + 1; i++)
				  	if(i != ring && i != N - ring + 1) swap(mat[ring][i], mat[N - ring + 1][i]); else
				  		for(int j = ring; 2 * j <= N; j++) swap(mat[j][i], mat[N - j + 1][i]);
				  break;
		
		case(2) : for(int i = ring; i <= N -ring + 1; i++)
					if(i != ring && i != N - ring + 1) swap(mat[i][ring], mat[i][N - ring + 1]); else
						for(int j = ring; 2 * j <= N; j++) swap(mat[i][j], mat[i][N - j + 1]);
				  break;
				  
		case(3) : for(int i = ring; i <= N - ring + 1; i++) swap(mat[ring][i], mat[i][ring]);
		          for(int i = ring + 1; i <= N - ring + 1; i++) swap(mat[i][N - ring + 1], mat[N - ring + 1][i]);
			      break;
			      
	    case(4) : for(int i = ring; i <= N - ring + 1; i++) swap(mat[ring][i], mat[N - i + 1][N - ring + 1]);
	    		  for(int i = ring + 1; i <= N - ring + 1; i++) swap(mat[i][ring], mat[N - ring + 1][N - i + 1]);
	    		  break;                
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d", &N);
	    for(int i = 1; i <= N; i++)
	        for(int j = 1; j <= N; j++) scanf("%d", &mat[i][j]);
	        
	    int ring = N / 2 + N % 2;
	   	for(int i = 1; i <= ring; i++)
	   	{
	   		scanf("%d", &M);
	   		while(M--)
	   		{
	   			scanf("%d", &C);
	   			rotate(i, C);
			}
	   	}
	   	
	   	for(int i = 1; i <= N; i++)
	   		for(int j = 1; j <= N; j++) 
	   			printf("%d%c",mat[i][j],j==N?'\n':' ');
	}  
	return 0;
}
