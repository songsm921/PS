#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int map[25][25];
int visit[25][25];
int visited = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
void DFS(int x, int y);
int main(){
    int n;
    vector<int> village;
    cin>>n;
    memset(map,0,sizeof(visit));
    for(int i = 0;i<n;i++)
    {
        for(int k = 0; k<n ; k++)
        {
            scanf("%1d",&map[i][k]);
        }
    }
    for(int i = 0 ; i<n ; i++)
    {
        for(int k = 0; k<n ; k++)
        {
            if(visit[i][k] == 0 && map[i][k])
            {
                int tmp = visited;
                DFS(i,k);
                village.push_back(visited - tmp);
            }
        }
    }
    sort(village.begin(),village.end());
    cout<<village.size()<<"\n";
    for(int i = 0 ; i< village.size();i++)
        cout<<village[i]<<"\n";
}
void DFS(int x, int y)
{
    visit[x][y] = 1;
    visited++;
    for(int i = 0 ; i<4;i++)
    {
        int x_pos = x + dx[i];
        int y_pos = y + dy[i];
        if(x_pos >=25 || x_pos <0 || y_pos >=25 || y_pos<0)
            continue;
        if(visit[x_pos][y_pos]==0 && map[x_pos][y_pos])
            DFS(x_pos,y_pos);
    }
}