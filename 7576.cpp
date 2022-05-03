#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[1000][1000];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int M,N;
queue<pair<int,int>> ready;
void BFS()
{
    while(!ready.empty())
    {
       
        pair<int,int> cur = ready.front();
        ready.pop();
        for(int i = 0; i <4 ; i++)
        {
            int x_pos = cur.first + dx[i];
            int y_pos = cur.second + dy[i];
            if(x_pos <0 || x_pos >=N || y_pos <0 || y_pos >=M)
                continue;
            if(map[x_pos][y_pos] == 0)
            {
                map[x_pos][y_pos] = map[cur.first][cur.second] + 1;
                ready.push({x_pos,y_pos});
            }
        }
        
       
    }
}
int main()
{
    int ans = 0;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>M>>N;
    memset(map,0,sizeof(map));
    for(int i = 0; i<N ; i++){
        for(int k = 0 ; k<M; k++)
        {
            int b;
            cin>>b;
            if(b == 1)
                ready.push({i,k});
            map[i][k] = b;
        }
    }
    BFS();
    for(int i = 0; i<N;i++)
    {
       for(int k = 0 ; k<M; k++)
        {
            if(map[i][k] == 0)
            {
                cout<<"-1";
                return 0;
            }
            if(ans<map[i][k])
                ans = map[i][k];

        } 
    }
        cout<<ans-1;
    return 0;
}
