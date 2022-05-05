#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
vector<pair<int,int>> e[801]; //(v,w)
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
int dijkstra(int start, int s,int* dist)
{
    fill(dist,dist+sizeof(dist),INF);
    dist[start] = 0;
    Q.push({dist[start],start});
    while(!Q.empty())
    {
        pair<int,int> cur = Q.top();
        int cw = cur.first;
        int cv = cur.second;
        Q.pop();
        for(int i = 0;i<e[cv].size();i++)
        {
            if(dist[e[cv][i].first] > dist[cv] + e[cv][i].second)
            {
                dist[e[cv][i].first] = dist[cv] + e[cv][i].second;
                Q.push({dist[e[cv][i].first],e[cv][i].first});
            }
        }
    }
    return dist[s];

}
int main()
{   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    bool flag1 = true;
    bool flag2 = true;
    cin>>n>>k;
    for(int i = 0;i<k;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    int s,t;
    int edge;
    cin>>s>>t;
    for(int i = 0 ; i<e[s].size();i++)
    {
        if(e[s][i].first == t){
            edge = e[s][i].second;
            break;
        }
    }
    int r1,r2,p1,p2;
    int dist[801];
    if(dijkstra(1,s,dist)==INF || dijkstra(n,t,dist) == INF )
        flag1 = false;
    if(dijkstra(1,t,dist)==INF || dijkstra(n,s,dist) == INF )
        flag1 = false;
    if(flag1 == false && flag2 == false){
        cout<<"-1";
        return 0;
    }
    r1 = dijkstra(1,s,dist) + dijkstra(s,t,dist) + dijkstra(n,t,dist);
    r2 = dijkstra(1,t,dist) + dijkstra(t,s,dist) + dijkstra(n,s,dist);
    if(r1<r2)
        cout<<r1;
    else
        cout<<r2;
    return 0;
}