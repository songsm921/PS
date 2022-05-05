#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cycle = false;
vector<pair<int,int>> Q[501];
int n,m;
long long dist[501];
const int INF = 987654321;

void floyd()
{
    dist[1] = 0;
    for(int i = 1; i<=n ; i++)
    {
        for(int j =1 ;j<=n;j++)
        {
            for(int k = 0 ; k<Q[j].size();k++)
            {
                int dest = Q[j][k].first;
                int weight = Q[j][k].second;
                if(dist[j]!=INF && dist[dest]> dist[j] + weight){
                    dist[dest] = dist[j] + weight;
                    if(i==n)
                    {
                        cycle = true;
                        return;
                    }
                }
            }
        }
    }
    
    
}
int main()
{
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 0; i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Q[u].push_back({v,w});
    }
    for(int i = 1 ; i<=500;i++)
        dist[i] = INF;
    floyd();
    if(cycle)
        cout<<"-1";
    else{
        for(int i = 2;i<=n;i++)
        {
            if(dist[i]!=INF)
                cout<<dist[i];
            else
                cout<<"-1";
            cout<<"\n";
        }
    }
    return 0;
}
