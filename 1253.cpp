#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <map>
 
#define fi first
#define se second
#define pi 2*acos(0.0)
#define eps 1e-9
#define INF 2000000000
#define PII pair<int,int> 
#define mp make_pair
#define pb push_back
#define LL long long
 
using namespace std;
 
typedef struct
{
        int x,y,t;
        LL state;
} cell;
 
int dx[]={ 1, 1, 0,-1,-1,-1, 0, 1};
int dy[]={ 0, 1, 1, 1, 0,-1,-1,-1};
 
map<LL,bool> visited[10][10];
char grid[10][10],next[10][10],msk[10];
string awal;
queue<cell> q;
int N,x,y,z,virus,ans,a,b;
LL hehe;
 
LL ubah(string T)
{
        LL ret=0LL;
        for(int i=0;i<T.size();i++)
        {
                ret*=3LL;
                switch(T[i])
                {
                        case('#') : ret+=1LL;break;
                        case('@') : ret+=2LL;break;
                }
        }
        return(ret);
}
 
int main()
{
        while(1)
        {
                scanf("%d",&N);
                if(!N) break;
                
                for(x=1;x<=N;x++)
                        for(y=1;y<=N;y++) visited[x][y].clear();
                        
                awal.clear();
                for(y=1;y<=N;y++)
                {
                        scanf("%s",msk);
                        for(x=1;x<=N;x++) if(msk[x-1]=='@'){a=x;b=y;}
                        awal.append(msk);
                }
                
                hehe=ubah(awal);
                visited[a][b][hehe]=true;
                while(!q.empty()) q.pop();
                q.push((cell){a,b,0,hehe});
                ans=-1;
                
                while(!q.empty())
                {
                        cell now=q.front();q.pop();
                        z=virus=0;
                        for(y=N;y;y--) for(x=N;x;x--)
                        {
                                switch(now.state%3LL)
                                {
                                        case(0) : grid[x][y]='.';break;
                                        case(1) : grid[x][y]='#';break;
                                        case(2) : grid[x][y]='@';break;
                                }
                                now.state/=3LL;
                                if(grid[x][y]=='#') virus++;
                                
                        }       
 
                        if(!virus)
                        {
                                ans=now.t;
                                break;
                        }
                        
                        for(z=0;z<8;z++)
                        {
                                int sx=now.x+dx[z],sy=now.y+dy[z];
                                if((sx)&&(sy)&&(sx<=N)&&(sy<=N)&&(grid[sx][sy]=='.'))
                                {
                                        grid[now.x][now.y]='.';
                                        grid[sx][sy]='@';
                                        for(x=1;x<=N;x++)
                                                for(y=1;y<=N;y++) if(grid[x][y]!='@')
                                                {
                                                        int adj=0;
                                                        for(int i=0;i<8;i++)
                                                        {
                                                                int nx=x+dx[i],ny=y+dy[i];
                                                                if((nx)&&(ny)&&(nx<=N)&&(ny<=N))
                                                                        if(grid[nx][ny]!='.') adj++;
                                                        }
                                                        
                                                        if((grid[x][y]=='.')&&(adj==3)) next[x][y]='#'; else
                                                        if((grid[x][y]=='#')&&(adj>1)&&(adj<4)) next[x][y]='#'; else
                                                        next[x][y]='.';
                                                } else next[x][y]='@';
                                        
                                        awal.clear();
                                        for(y=1;y<=N;y++)
                                                for(x=1;x<=N;x++) awal+=next[x][y];
                                        
                                        hehe=ubah(awal);        
                                        if(visited[sx][sy].find(hehe)==visited[sx][sy].end())
                                        {
                                                visited[sx][sy][hehe]=true;
                                                q.push((cell){sx,sy,now.t+1,hehe});
                                        }
                                        grid[now.x][now.y]='@';
                                        grid[sx][sy]='.';
                                }
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}

