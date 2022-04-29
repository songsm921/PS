#include <iostream>
using namespace std;
int cnt = 0;
int visited[101];
int map[101][101];
void DFS(int v,int n)
{
    visited[v] = 1;
    for(int i = 1;i<=n;i++)
    {
        if(map[v][i] == 1 && !visited[i]){
            cnt++;
            DFS(i,n);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int v,e;
    cin>>v>>e;
    for(int i = 0; i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    DFS(1,v);
    cout<<cnt;
    return 0;
}