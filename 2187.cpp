#include<iostream>
#include <queue>
using namespace std;
int map[101][101];
int visit[101][101];
int dist[101][101];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> arr;
void BFS(int x, int y)
{
    dist[x][y] = 1;
    visit[x][y] = 1;
    arr.push({x,y});
    
    while(!arr.empty())
    {
        pair<int,int> cur = arr.front();
        arr.pop();
        for(int i = 0 ; i<4;i++)
        {
            int x_pos = cur.first + dx[i];
            int y_pos = cur.second + dy[i];
            if(x_pos <=0 || x_pos>n || y_pos<=0 || y_pos>m)
                continue;
            if(visit[x_pos][y_pos] == 1 || map[x_pos][y_pos] == 0)
                continue;
            else
            {
                dist[x_pos][y_pos] = dist[cur.first][cur.second] + 1;
                arr.push({x_pos,y_pos});
                visit[x_pos][y_pos] = 1;
            }
        }
        
        
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 1; i<=n;i++)
    {
        for(int k = 1;k<=m;k++)
            scanf("%1d",&map[i][k]);
    }
    BFS(1,1);
    cout<<dist[n][m];
    return 0;
}
