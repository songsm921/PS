#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;
int V,E;
int visit[20001];

vector<pair<int,int>> edge[20001]; // edge[u][x] = {v,w}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ready; // {dist,vertex}
void dijkstra(int start,int *dist)
{
    ready.push({dist[start],start});
    while(!ready.empty())
    {
        pair<int,int> cur = ready.top();
        ready.pop();
        for(int i = 0; i<edge[cur.second].size() ;i++)
        {
            if(edge[cur.second][i].second !=0)
            {
                if(dist[edge[cur.second][i].first] >cur.first + edge[cur.second][i].second)
                {
                    dist[edge[cur.second][i].first] = cur.first + edge[cur.second][i].second;
                    ready.push({dist[edge[cur.second][i].first],edge[cur.second][i].first});
                    visit[edge[cur.second][i].first] = 1;
                }
            }
            
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>V>>E;
    int dist[V+1];
    fill(dist,dist+V+1,INF);
    memset(edge,0,sizeof(edge));
    int start;
    cin>>start;
    dist[start] = 0;
    for(int i = 0 ; i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w}); // u ->v = w
    }
    dijkstra(start,dist);
    for(int i = 1 ; i<=V;i++)
    {
        if(dist[i] == INF)
            cout<<"INF";
        else
            cout<<dist[i];
        cout<<"\n";
    }
    return 0;
}
