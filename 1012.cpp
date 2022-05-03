/*BOJ 1012*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int map[50][50];
bool visit[50][50];

void DFS(int x, int y)
{
    visit[x][y] = true;
    for(int i = 0 ; i<4 ;i++)
    {
        int x_pos = x+dx[i];
        int y_pos = y+dy[i];
        if(x_pos <0 || x_pos>=50 || y_pos < 0 || y_pos>=50)
            continue;
        if(visit[x_pos][y_pos] == false && map[x_pos][y_pos] == 1)
            DFS(x_pos,y_pos);     
    }
}
int main()
{
    int T;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>T;
    for(int i = 0 ; i <T ; i++)
    {
        int ans = 0;
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        int M,N,K;
        cin>>M>>N>>K;
        for(int j = 0; j<K ;j++)
        {
            int x,y;
            cin>>x>>y;
            map[y][x] = 1;
        }
        for(int n = 0 ; n<N;n++)
        {
            for(int m = 0; m<M;m++)
            {
                if(visit[n][m] == false && map[n][m] == 1)
                {
                   ans++;
                   DFS(n,m); 
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}