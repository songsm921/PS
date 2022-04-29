#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int vertex,edge;
int map[1001][1001];
int visited[1001];
vector<int> e_list[1001];
queue<int> next_v;
void DFS(int v, int n)
{
    visited[v] = 1;
    cout<<v<<" ";
    for(int i = 1; i<=n;i++)
    {
        if(map[v][i] == 1 && !visited[i])
            DFS(i,n);
    }
}
void BFS(int v)
{
    visited[v] = 1;
    next_v.push(v);
    while(!next_v.empty())
    {   int now =next_v.front();
        cout<<now<<" ";
        next_v.pop();
        for(int i = 0; i<e_list[now].size();i++)
        {
            if(visited[e_list[now][i]]==0)
            {
                next_v.push(e_list[now][i]);
                visited[e_list[now][i]] =1;
            }
        }
        
    }
    
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int start;
    cin>>vertex>>edge>>start;
    memset(visited,false,sizeof(visited));
    for(int i = 0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
        e_list[a].push_back(b);
        e_list[b].push_back(a);
    }
    DFS(start,vertex);
    memset(visited,false,sizeof(visited));
    for(int i = 0; i<vertex; i++)
        sort(e_list[i].begin(),e_list[i].end());
    cout<<"\n";
    BFS(start);
    return 0;
}
